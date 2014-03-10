// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright(C) 1993-1997 Id Software, Inc.
// Copyright(C) 2007-2014 Samuel Villarreal
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
// 02111-1307, USA.
//
//-----------------------------------------------------------------------------
//
// DESCRIPTION: System Interface
//
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#endif

#include <stdarg.h>

#include "SDL.h"

#include "doomstat.h"
#include "doomdef.h"
#include "con_console.h"
#include "g_demo.h"
#include "g_game.h"
#include "d_main.h"
#include "d_net.h"
#include "gl_draw.h"
#include "i_audio.h"
#include "i_joystick.h"
#include "i_keyboard.h"
#include "i_mouse.h"
#include "i_system.h"
#include "i_video.h"
#include "m_misc.h"
#include "z_zone.h"

#ifdef _WIN32
#include "i_xinput.h"
#endif

CVAR(i_interpolateframes, 0);

int init_systems = 0;

#ifdef USESYSCONSOLE
#include <windows.h>
//#include "i_launcher.h"

// System Console (win32 only)

#define EDIT_ID     100
#define COPY_ID     102
#define QUIT_ID     103
#define READY_ID    104

HWND hwndMain;			//Main window handle
HWND hwndBuffer;
HWND hwndButtonCopy;
HWND hwndButtonReady;
HWND hwndButtonQuit;
HFONT hfBufferFont;
HFONT hfButtonFont;
HBRUSH hbrEditBackground;
HDC hdc = 0;
HINSTANCE hwndMainInst;		//Main window instance

char d64SysConsoleClass[] = "D64SysConsole";

//
// I_DestroySysConsole
//

void I_DestroySysConsole(void)
{
	if (hwndMain) {
		I_ShowSysConsole(false);
		CloseWindow(hwndMain);
		DestroyWindow(hwndMain);
		hwndMain = 0;
	}
}

LRESULT CALLBACK SysConsoleProc(HWND hwnd, UINT msg, WPARAM wParam,
				LPARAM lParam)
{
	switch (msg) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case QUIT_ID:
			I_DestroySysConsole();
			I_ShutdownVideo;
			exit(0);
			break;

		case COPY_ID:
			SendMessage(hwndBuffer, EM_SETSEL, 0, -1);
			SendMessage(hwndBuffer, WM_COPY, 0, 0);
			break;

		case READY_ID:
			NET_CL_StartGame();
			DestroyWindow(hwndButtonReady);
			break;
		}
		break;

	case WM_SETFOCUS:
	case WM_SHOWWINDOW:
		UpdateWindow(hwndMain);
		break;

	case WM_CREATE:
		hbrEditBackground = CreateSolidBrush(RGB(64, 64, 64));
		break;

	case WM_CTLCOLORSTATIC:
		if ((HWND) lParam == hwndBuffer) {
			SetBkColor((HDC) wParam, RGB(64, 64, 64));
			SetTextColor((HDC) wParam, RGB(0xff, 0xff, 0x00));

			return (long)hbrEditBackground;
		}
		break;

	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

//
// I_SpawnSysConsole
//

void I_SpawnSysConsole(void)
{
	WNDCLASSEX wcx;
	RECT rect;
	int swidth;
	int sheight;

	hwndMainInst = GetModuleHandle(NULL);
	memset(&wcx, 0, sizeof(WNDCLASSEX));

	wcx.cbSize = sizeof(WNDCLASSEX);
	wcx.style = CS_OWNDC;
	wcx.lpfnWndProc = (WNDPROC) SysConsoleProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hwndMainInst;
	wcx.hIcon = NULL;
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH) COLOR_WINDOW;
	wcx.lpszClassName = d64SysConsoleClass;
	wcx.hIconSm = NULL;

	if (!RegisterClassEx(&wcx))
		return;

	rect.left = 0;
	rect.right = 384;
	rect.top = 0;
	rect.bottom = 480;

	AdjustWindowRect(&rect, WS_POPUPWINDOW, FALSE);

	hdc = GetDC(GetDesktopWindow());
	swidth = GetDeviceCaps(hdc, HORZRES);
	sheight = GetDeviceCaps(hdc, VERTRES);
	ReleaseDC(GetDesktopWindow(), hdc);

	// Create the window
	hwndMain = CreateWindowEx(0,	//Extended window style
				  d64SysConsoleClass,	// Window class name
				  NULL,	// Window title
				  WS_POPUPWINDOW,	// Window style
				  (swidth - 400) / 2, (sheight - 480) / 2, rect.right - rect.left + 1, rect.bottom - rect.top + 1,	// Width and height of the window
				  NULL,	// HWND of the parent window (can be null also)
				  NULL,	// Handle to menu
				  hwndMainInst,	// Handle to application instance
				  NULL	// Pointer to window creation data
	    );

	if (!hwndMain)
		return;

	hwndBuffer =
	    CreateWindow("edit", NULL,
			 WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER |
			 ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
			 6, 16, 370, 400, hwndMain, (HMENU) EDIT_ID,
			 hwndMainInst, NULL);

	hwndButtonCopy =
	    CreateWindow("button", NULL,
			 BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD |
			 BS_DEFPUSHBUTTON, 5, 445, 64, 24, hwndMain,
			 (HMENU) COPY_ID, hwndMainInst, NULL);
	SendMessage(hwndButtonCopy, WM_SETTEXT, 0, (LPARAM) "copy");

	if (M_CheckParm("-server") > 0) {
		hwndButtonReady =
		    CreateWindow("button", NULL,
				 BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD |
				 BS_DEFPUSHBUTTON, 82, 445, 64, 24, hwndMain,
				 (HMENU) READY_ID, hwndMainInst, NULL);
		SendMessage(hwndButtonReady, WM_SETTEXT, 0, (LPARAM) "ready");
	}

	hwndButtonQuit =
	    CreateWindow("button", NULL,
			 BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD |
			 BS_DEFPUSHBUTTON, 312, 445, 64, 24, hwndMain,
			 (HMENU) QUIT_ID, hwndMainInst, NULL);
	SendMessage(hwndButtonQuit, WM_SETTEXT, 0, (LPARAM) "quit");

	hdc = GetDC(hwndMain);
	hfBufferFont =
	    CreateFont(-MulDiv(8, GetDeviceCaps(hdc, LOGPIXELSY), 72), 0, 0, 0,
		       FW_LIGHT, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		       CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		       FF_MODERN | FIXED_PITCH, "Courier New");

	ReleaseDC(hwndMain, hdc);

	SendMessage(hwndBuffer, WM_SETFONT, (WPARAM) hfBufferFont, 0);

	ShowWindow(hwndMain, SW_SHOW);
	UpdateWindow(hwndMain);
}

//
// I_ShowSysConsole
//

void I_ShowSysConsole(dboolean show)
{
	ShowWindow(hwndMain, show ? SW_SHOW : SW_HIDE);
}

#endif

ticcmd_t emptycmd;
static int64 I_GetTime_Scale = 1 << 24;

//
// I_uSleep
//

void I_Sleep(unsigned long usecs)
{
	SDL_Delay(usecs);
}

static int basetime = 0;

//
// I_GetTimeNormal
//

static int I_GetTimeNormal(void)
{
	uint32 ticks;

	ticks = SDL_GetTicks();

	if (basetime == 0)
		basetime = ticks;

	ticks -= basetime;

	return (ticks * TICRATE) / 1000;
}

//
// I_GetTime_Scaled
//

static int I_GetTime_Scaled(void)
{
	return (int)((int64) I_GetTimeNormal() * I_GetTime_Scale >> 24);
}

//
// I_GetTime_Error
//

static int I_GetTime_Error(void)
{
	I_Error("I_GetTime_Error: GetTime() used before initialization");
	return 0;
}

//
// I_InitClockRate
//

void I_InitClockRate(void)
{
	I_GetTime = I_GetTimeNormal;
}

static unsigned int start_displaytime;
static unsigned int displaytime;
static dboolean InDisplay = false;
static int saved_gametic = -1;

dboolean realframe = false;

fixed_t rendertic_frac = 0;
unsigned int rendertic_start;
unsigned int rendertic_step;
unsigned int rendertic_next;
const float rendertic_msec = 100 * TICRATE / 100000.0f;

dboolean I_StartDisplay(void)
{
	rendertic_frac = I_GetTimeFrac();

	if (InDisplay)
		return false;

	start_displaytime = SDL_GetTicks();
	InDisplay = true;

	return true;
}

void I_EndDisplay(void)
{
	displaytime = SDL_GetTicks() - start_displaytime;
	InDisplay = false;
}

fixed_t I_GetTimeFrac(void)
{
	unsigned long now;
	fixed_t frac;

	now = SDL_GetTicks();

	if (rendertic_step == 0)
		return FRACUNIT;
	else {
		frac =
		    (fixed_t) ((now - rendertic_start +
				displaytime) * FRACUNIT / rendertic_step);
		if (frac < 0)
			frac = 0;
		if (frac > FRACUNIT)
			frac = FRACUNIT;
		return frac;
	}
}

void I_GetTime_SaveMS(void)
{
	rendertic_start = SDL_GetTicks();
	rendertic_next =
	    (unsigned int)((rendertic_start * rendertic_msec + 1.0f) /
			   rendertic_msec);
	rendertic_step = rendertic_next - rendertic_start;
}

//
// I_BaseTiccmd
//

ticcmd_t *I_BaseTiccmd(void)
{
	return &emptycmd;
}

//
// I_DoomExeDir
//

char *I_DoomExeDir(void)
{
	static char current_dir_dummy[] = { "./" };
	static char *base;
	if (!base)		// cache multiple requests
	{
		size_t len = dstrlen(*myargv);
		char *p = (base = malloc(len + 1)) + len - 1;

		dstrcpy(base, *myargv);

		while (p > base && *p != '/' && *p != '\\')
			*p-- = 0;

		if (*p == '/' || *p == '\\')
			*p-- = 0;

		if (dstrlen(base) < 2) {
			free(base);
			base = malloc(1024);
			if (!getcwd(base, 1024))
				dstrcpy(base, current_dir_dummy);
		}
	}

	return base;
}

//
// I_GetTime
// returns time in 1/70th second tics
// now 1/35th?
//

int (*I_GetTime) (void) = I_GetTime_Error;

//
// I_GetTimeMS
//
// Same as I_GetTime, but returns time in milliseconds
//

int I_GetTimeMS(void)
{
	uint32 ticks;

	ticks = SDL_GetTicks();

	if (basetime == 0)
		basetime = ticks;

	return ticks - basetime;
}

//
// I_GetRandomTimeSeed
//

unsigned long I_GetRandomTimeSeed(void)
{
	// not exactly random....
	return SDL_GetTicks();
}

//
// I_StartTic
//

void I_StartTic(void)
{
	SDL_Event Event;

	while (SDL_PollEvent(&Event)) {
		if (Event.type == SDL_QUIT)
			I_Quit();

		if ((init_systems & I_KEYBOARD) &&
				I_KeyboardEvent(&Event))
			continue;

		if ((init_systems & I_MOUSE) &&
				I_MouseEvent(&Event))
			continue;

		if ((init_systems & I_VIDEO) &&
				I_VideoEvent(&Event))
			continue;

		if ((init_systems & I_JOYSTICK) &&
				I_JoystickEvent(&Event))
			continue;
	}

#ifdef _USE_XINPUT
	I_XInputPollEvent();
#endif

	if (init_systems & I_MOUSE)
		I_ReadMouse();

	if (init_systems & I_JOYSTICK)
		I_ReadJoystick();
}

//
// I_Init
//

void I_Init(void)
{
#ifdef USESYSCONSOLE
	//I_SpawnLauncher(hwndMain);
#endif

	int sdl_flags = SDL_INIT_VIDEO;
	SDL_version compiled;
#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_version linked;
#endif

	init_systems = I_KEYBOARD | I_VIDEO ;

	if (!M_CheckParm("-nomouse"))
		init_systems |= I_MOUSE;

	if (!M_CheckParm("-noxinput"))
		init_systems |= I_XINPUT;

	if (!M_CheckParm("-nojoy")) { // only sadness
		init_systems |= I_JOYSTICK;
		sdl_flags |= SDL_INIT_JOYSTICK;
	}

	if (SDL_Init(sdl_flags) < 0)
		I_Error("Couldn't initialize SDL");

#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_GetVersion(&linked);
	I_Printf("Linked against SDL v%d.%d.%d\n", linked.major, linked.minor,
		 linked.patch);
#endif

	SDL_VERSION(&compiled);
	I_Printf("Compiled against SDL v%d.%d.%d\n", compiled.major,
		 compiled.minor, compiled.patch);

	// Init Video
	if (init_systems & I_VIDEO)
		I_InitVideo();

	// Init Keyboard
	if (init_systems & I_KEYBOARD)
		I_InitKeyboard();

	// Init Mouse
	if (init_systems & I_MOUSE)
		I_InitMouse();

#ifdef _USE_XINPUT
	// Init Xinput
	if (init_systems & I_XINPUT)
		I_XInputInit();
#endif

	// Init Joystick
	if (init_systems & I_JOYSTICK)
		I_InitJoystick();

	I_InitClockRate();

	SDL_PumpEvents();
}

//
// I_Error
//

void I_Error(char *string, ...)
{
	char buff[1024];
	va_list va;

	I_ShutdownSound();

	va_start(va, string);
	vsprintf(buff, string, va);
	va_end(va);

	fprintf(stderr, "Error - %s\n", buff);
	fflush(stderr);

	I_Printf("\n********* ERROR *********\n");
	I_Printf(buff);

	if (usingGL) {
		while (1) {
			GL_ClearView(0xFF000000);
			Draw_Text(0, 0, WHITE, 1, 1, "Error - %s\n", buff);
			GL_SwapBuffers();

	//		if (I_ShutdownWait())
				break;

			I_Sleep(1);
		}
	} else
		I_ShutdownVideo();

#ifdef USESYSCONSOLE
	{
		MSG msg;

		I_ShowSysConsole(true);

		while (1) {
			while (GetMessage(&msg, NULL, 0, 0)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			I_Sleep(100);
		}
	}
#endif
	exit(0);		// just in case...
}

//
// I_Quit
//

void I_Quit(void)
{
	if (demorecording) {
		endDemo = true;
		G_CheckDemoStatus();
	}

	M_SaveDefaults();

#ifdef USESYSCONSOLE
	I_DestroySysConsole();
#endif

	exit(0);
}

//
// I_Printf
//

void I_Printf(char *string, ...)
{
	char buff[1024];
	va_list va;

	dmemset(buff, 0, 1024);

	va_start(va, string);
	vsprintf(buff, string, va);
	va_end(va);

#ifdef USESYSCONSOLE
	{
		char winBuff[1024];
		char *c = buff;
		char *b = winBuff;

		dmemset(winBuff, 0, 1024);

		do {
			if (!*c)
				break;

			if (*c == '\n') {
				*b = '\r';
				b++;
			}
			*b = *c;
			b++;

		} while (c++);

		SendMessage(hwndBuffer, EM_LINESCROLL, 0, 0xffff);
		SendMessage(hwndBuffer, EM_SCROLLCARET, 0, 0);
		SendMessage(hwndBuffer, EM_REPLACESEL, 0, (LPARAM) winBuff);
	}
#endif

	printf("%s", buff);
	if (console_initialized)
		CON_AddText(buff);
}

//
// I_BeginRead
//

dboolean inshowbusy = false;

void I_BeginRead(void)
{
	if (!devparm)
		return;

	if (inshowbusy)
		return;
	inshowbusy = true;
	inshowbusy = false;
	BusyDisk = true;
}

//
// I_RegisterCvars
//

#ifdef _USE_XINPUT
CVAR_EXTERNAL(i_rsticksensitivity);
CVAR_EXTERNAL(i_rstickthreshold);
CVAR_EXTERNAL(i_xinputscheme);
#endif

CVAR_EXTERNAL(i_gamma);
CVAR_EXTERNAL(i_brightness);

void I_RegisterCvars(void)
{
#ifdef _USE_XINPUT
	CON_CvarRegister(&i_rsticksensitivity);
	CON_CvarRegister(&i_rstickthreshold);
	CON_CvarRegister(&i_xinputscheme);
#endif

	CON_CvarRegister(&i_gamma);
	CON_CvarRegister(&i_brightness);
	CON_CvarRegister(&i_interpolateframes);

	I_RegisterVideoCvars();
	I_RegisterMouseCvars();
	I_RegisterJoystickCvars();
}
