/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  SDL_main.c, placed in the public domain by Sam Lantinga  4/13/98
 *  The WinMain function -- calls your program's main() function
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#ifdef _WIN32_WCE
#define DIR_SEPERATOR TEXT("\\")
#undef _getcwd
#define _getcwd(str,len)    wcscpy(str,TEXT(""))
#define setbuf(f,b)
#define setvbuf(w,x,y,z)
#define fopen        _wfopen
#define freopen    _wfreopen
#define remove(x)    DeleteFile(x)
#else
#define DIR_SEPERATOR TEXT("/")
#include <direct.h>
#endif

// proff
#define HAVE_MALLOC 1
#define HAVE_STRLEN 1
#define HAVE_STRRCHR 1
#define HAVE_STRLCPY 1
#define HAVE_STRLCAT 1

size_t strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t srclen = strlen(src);
	if (maxlen > 0) {
		size_t len = min(srclen, maxlen - 1);
		memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return srclen;
}

size_t strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t dstlen = strlen(dst);
	size_t srclen = strlen(src);
	if (dstlen < maxlen) {
		strlcpy(dst + dstlen, src, maxlen - dstlen);
	}
	return dstlen + srclen;
}

// proff - end of additions
/* Include the SDL main definition header */
#include "SDL.h"
#include "SDL_main.h"

#ifdef main
#ifndef _WIN32_WCE_EMULATION
#undef main
#endif				/* _WIN32_WCE_EMULATION */
#endif				/* main */

/* The standard output files */
#define STDOUT_FILE    TEXT("stdout.txt")
#define STDERR_FILE    TEXT("stderr.txt")

#ifndef NO_STDIO_REDIRECT
#ifdef _WIN32_WCE
static wchar_t stdoutPath[MAX_PATH];
static wchar_t stderrPath[MAX_PATH];
#else
static char stdoutPath[MAX_PATH];
static char stderrPath[MAX_PATH];
#endif
#endif

#if defined(_WIN32_WCE) && _WIN32_WCE < 300
/* seems to be undefined in Win CE although in online help */
#define isspace(a) (((CHAR)a == ' ') || ((CHAR)a == '\t'))
#endif				/* _WIN32_WCE < 300 */

/* Parse a command line buffer into arguments */
static int ParseCommandLine(char *cmdline, char **argv)
{
	char *bufp;
	int argc;

	argc = 0;
	for (bufp = cmdline; *bufp;) {
		/* Skip leading whitespace */
		while (isspace(*bufp)) {
			++bufp;
		}
		/* Skip over argument */
		if (*bufp == '"') {
			++bufp;
			if (*bufp) {
				if (argv) {
					argv[argc] = bufp;
				}
				++argc;
			}
			/* Skip over word */
			while (*bufp && (*bufp != '"')) {
				++bufp;
			}
		} else {
			if (*bufp) {
				if (argv) {
					argv[argc] = bufp;
				}
				++argc;
			}
			/* Skip over word */
			while (*bufp && !isspace(*bufp)) {
				++bufp;
			}
		}
		if (*bufp) {
			if (argv) {
				*bufp = '\0';
			}
			++bufp;
		}
	}
	if (argv) {
		argv[argc] = NULL;
	}
	return (argc);
}

/* Show an error message */
static void ShowError(const char *title, const char *message)
{
/* If USE_MESSAGEBOX is defined, you need to link with user32.lib */
#ifdef USE_MESSAGEBOX
	MessageBox(NULL, message, title, MB_ICONEXCLAMATION | MB_OK);
#else
	fprintf(stderr, "%s: %s\n", title, message);
#endif
}

/* Pop up an out of memory message, returns to Windows */
static BOOL OutOfMemory(void)
{
	ShowError("Fatal Error", "Out of memory - aborting");
	return FALSE;
}

/* SDL_Quit() shouldn't be used with atexit() directly because
   calling conventions may differ... */
static void cleanup(void)
{
	SDL_Quit();
}

/* Remove the output files if there was no output written */
static void cleanup_output(void)
{
#ifndef NO_STDIO_REDIRECT
	FILE *file;
	int empty;
#endif

	/* Flush the output in case anything is queued */
	fclose(stdout);
	fclose(stderr);

#ifndef NO_STDIO_REDIRECT
	/* See if the files have any output in them */
	if (stdoutPath[0]) {
		file = fopen(stdoutPath, TEXT("rb"));
		if (file) {
			empty = (fgetc(file) == EOF) ? 1 : 0;
			fclose(file);
			if (empty) {
				remove(stdoutPath);
			}
		}
	}
	if (stderrPath[0]) {
		file = fopen(stderrPath, TEXT("rb"));
		if (file) {
			empty = (fgetc(file) == EOF) ? 1 : 0;
			fclose(file);
			if (empty) {
				remove(stderrPath);
			}
		}
	}
#endif
}

#if defined(_MSC_VER) && !defined(_WIN32_WCE)
/* The VC++ compiler needs main defined */
#define console_main main
#endif

/* This is where execution begins [console apps] */
int console_main(int argc, char *argv[])
{
	size_t n;
	char *bufp, *appname;
	int status;

	/* Get the class name from argv[0] */
	appname = argv[0];
	if ((bufp = SDL_strrchr(argv[0], '\\')) != NULL) {
		appname = bufp + 1;
	} else if ((bufp = SDL_strrchr(argv[0], '/')) != NULL) {
		appname = bufp + 1;
	}

	if ((bufp = SDL_strrchr(appname, '.')) == NULL)
		n = SDL_strlen(appname);
	else
		n = (bufp - appname);

	bufp = SDL_stack_alloc(char, n + 1);
	if (bufp == NULL) {
		return OutOfMemory();
	}
	SDL_strlcpy(bufp, appname, n + 1);
	appname = bufp;

	/* Load SDL dynamic link library */
	if (SDL_Init(SDL_INIT_NOPARACHUTE) < 0) {
		ShowError("WinMain() error", SDL_GetError());
		return (FALSE);
	}
	atexit(cleanup_output);
	atexit(cleanup);

	/* Sam:
	   We still need to pass in the application handle so that
	   DirectInput will initialize properly when SDL_RegisterApp()
	   is called later in the video initialization.
	 */

    // MP2E 03012014: As of SDL2, SetModuleHandle is obsolete
#if !SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_SetModuleHandle(GetModuleHandle(NULL));
#endif

	/* Run the application main() code */
	status = SDL_main(argc, argv);

	/* Exit cleanly, calling atexit() functions */
	exit(status);

	/* Hush little compiler, don't you cry... */
	return 0;
}

/* This is where execution begins [windowed apps] */
#ifdef _WIN32_WCE
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPWSTR szCmdLine, int sw)
#else
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int sw)
#endif
{
	HINSTANCE handle;
	char **argv;
	int argc;
	char *cmdline;
	DWORD pathlen;
#ifdef _WIN32_WCE
	wchar_t path[MAX_PATH];
#else
	char path[MAX_PATH];
#endif
#ifdef _WIN32_WCE
	wchar_t *bufp;
	int nLen;
#else
	char *bufp;
	size_t nLen;
#endif
#ifndef NO_STDIO_REDIRECT
	FILE *newfp;
#endif

	/* Start up DDHELP.EXE before opening any files, so DDHELP doesn't
	   keep them open.  This is a hack.. hopefully it will be fixed 
	   someday.  DDHELP.EXE starts up the first time DDRAW.DLL is loaded.
	 */
	handle = LoadLibrary(TEXT("DDRAW.DLL"));
	if (handle != NULL) {
		FreeLibrary(handle);
	}
#ifndef NO_STDIO_REDIRECT
	pathlen = GetModuleFileName(NULL, path, SDL_arraysize(path));
	while (pathlen > 0 && path[pathlen] != '\\') {
		--pathlen;
	}
	path[pathlen] = '\0';

#ifdef _WIN32_WCE
	wcsncpy(stdoutPath, path, SDL_arraysize(stdoutPath));
	wcsncat(stdoutPath, DIR_SEPERATOR STDOUT_FILE,
		SDL_arraysize(stdoutPath));
#else
	SDL_strlcpy(stdoutPath, path, SDL_arraysize(stdoutPath));
	SDL_strlcat(stdoutPath, DIR_SEPERATOR STDOUT_FILE,
		    SDL_arraysize(stdoutPath));
#endif

	/* Redirect standard input and standard output */
	newfp = freopen(stdoutPath, TEXT("w"), stdout);

#ifndef _WIN32_WCE
	if (newfp == NULL) {	/* This happens on NT */
#if !defined(stdout)
		stdout = fopen(stdoutPath, TEXT("w"));
#else
		newfp = fopen(stdoutPath, TEXT("w"));
		if (newfp) {
			*stdout = *newfp;
		}
#endif
	}
#endif				/* _WIN32_WCE */

#ifdef _WIN32_WCE
	wcsncpy(stderrPath, path, SDL_arraysize(stdoutPath));
	wcsncat(stderrPath, DIR_SEPERATOR STDOUT_FILE,
		SDL_arraysize(stdoutPath));
#else
	SDL_strlcpy(stderrPath, path, SDL_arraysize(stderrPath));
	SDL_strlcat(stderrPath, DIR_SEPERATOR STDERR_FILE,
		    SDL_arraysize(stderrPath));
#endif

	newfp = freopen(stderrPath, TEXT("w"), stderr);
#ifndef _WIN32_WCE
	if (newfp == NULL) {	/* This happens on NT */
#if !defined(stderr)
		stderr = fopen(stderrPath, TEXT("w"));
#else
		newfp = fopen(stderrPath, TEXT("w"));
		if (newfp) {
			*stderr = *newfp;
		}
#endif
	}
#endif				/* _WIN32_WCE */

	setvbuf(stdout, NULL, _IOLBF, BUFSIZ);	/* Line buffered */
	setbuf(stderr, NULL);	/* No buffering */
#endif				/* !NO_STDIO_REDIRECT */

#ifdef _WIN32_WCE
	nLen = wcslen(szCmdLine) + 128 + 1;
	bufp = SDL_stack_alloc(wchar_t, nLen * 2);
	wcscpy(bufp, TEXT("\""));
	GetModuleFileName(NULL, bufp + 1, 128 - 3);
	wcscpy(bufp + wcslen(bufp), TEXT("\" "));
	wcsncpy(bufp + wcslen(bufp), szCmdLine, nLen - wcslen(bufp));
	nLen = wcslen(bufp) + 1;
	cmdline = SDL_stack_alloc(char, nLen);
	if (cmdline == NULL) {
		return OutOfMemory();
	}
	WideCharToMultiByte(CP_ACP, 0, bufp, -1, cmdline, nLen, NULL, NULL);
#else
	/* Grab the command line */
	bufp = GetCommandLine();
	nLen = SDL_strlen(bufp) + 1;
	cmdline = SDL_stack_alloc(char, nLen);
	if (cmdline == NULL) {
		return OutOfMemory();
	}
	SDL_strlcpy(cmdline, bufp, nLen);
#endif

	/* Parse it into argv and argc */
	argc = ParseCommandLine(cmdline, NULL);
	argv = SDL_stack_alloc(char *, argc + 1);
	if (argv == NULL) {
		return OutOfMemory();
	}
	ParseCommandLine(cmdline, argv);

	/* Run the main program (after a little SDL initialization) */
	console_main(argc, argv);

	/* Hush little compiler, don't you cry... */
	return 0;
}