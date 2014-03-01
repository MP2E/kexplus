// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright(C) 2014 Zohar Malamant
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
// DESCRIPTION: Window routines
//
//-----------------------------------------------------------------------------

#include "SDL.h"

#include "doomdef.h"
#include "con_cvar.h"
#include "g_actions.h"
#include "gl_main.h"
#include "m_misc.h"
#include "i_system.h"
#include "v_main.h"
#include "z_zone.h"

CVAR(v_msensitivityx, 5);
CVAR(v_msensitivityy, 5);
CVAR(v_macceleration, 0);
CVAR(v_mlook, 0);
CVAR(v_mlookinvert, 0);
CVAR(v_yaxismove, 0);
CVAR(v_vsync, 1);
CVAR(v_depthsize, 24);
CVAR(v_buffersize, 32);
CVAR(v_width, 640);
CVAR(v_height, 480);
CVAR(v_windowed, 1);
CVAR(v_display, 0);

#if SDL_VERSION_ATLEAST(2, 0, 0)
SDL_Window *window = NULL;
SDL_GLContext *glcontext = NULL;
#else
SDL_Surface *screen = NULL;
#endif

#define SDL_BPP        0

static vidmode_t vidmodes[2] = { {0} };	// vidmodes[0]: current, vidmodes[1]: previous

static int num_vidmodes = 0;

const vidmode_t *vidmode = &vidmodes[0];
vidinfo_t vidinfo = { 0 };

static char title[256];

//
// CMD_ListVideoModes
//

static CMD(ListVidModes)
{
	int i, j;

	for (i = 0; i < vidinfo.num_displays; i++) {
		viddisp_t *disp = &vidinfo.displays[i];

		if (disp->disp_name)
			I_Printf("Display %d (%s):\n", disp->disp_id,
				 disp->disp_name);
		else
			I_Printf("Display %d:\n", disp->disp_id);

		for (j = 0; j < disp->num_modes; j++) {
			vidmode_t *vm = &disp->modes[j];

			I_Printf("  %d: %dx%d\n", vm->id, vm->w, vm->h);
		}
	}
}

//
// CMD_VidSet
//

static CMD(VidSet)
{
	if (V_SetMode(NULL)) {
		I_Printf("Video mode set successfully.\n");
	} else {
		I_Printf("Video mode wasn't set.\n");
	}
}

//
// CMD_VidRevert
//

static CMD(VidRevert)
{
	if (V_RevertMode()) {
		I_Printf("Video mode reverted successfully.\n");
	} else {
		I_Printf("Video mode wasn't reverted.\n");
	}
}

//
// V_Init
//

void V_Init(void)
{
	int p, newwidth, newheight;
	SDL_version compiled;
#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_version linked;
#endif

	newwidth = newheight = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		I_Error("Couldn't initialize SDL");
	}

	V_UpdateVidInfo();

	if (M_CheckParm("-fullscreen"))
		CON_CvarSetValue(v_windowed.name, 0.f);
	if (M_CheckParm("-window"))
		CON_CvarSetValue(v_windowed.name, 1.f);
	if (M_CheckParm("-noborder"))
		CON_CvarSetValue(v_windowed.name, 2.f);

	p = M_CheckParm("-width");
	if (p && p < myargc - 1)
		newwidth = datoi(myargv[p + 1]);

	p = M_CheckParm("-height");
	if (p && p < myargc - 1)
		newheight = datoi(myargv[p + 1]);

	p = M_CheckParm("-display");
	if (p && p < myargc - 1)
		CON_CvarSetValue(v_display.name, (float)datoi(myargv[p + 1]));

	if (newwidth && newheight) {
		CON_CvarSetValue(v_width.name, (float)newwidth);
		CON_CvarSetValue(v_height.name, (float)newheight);
	}

	if (v_depthsize.value != 8 &&
	    v_depthsize.value != 16 && v_depthsize.value != 24) {
		CON_CvarSetValue(v_depthsize.name, 24);
	}

	if (v_buffersize.value != 8 &&
	    v_buffersize.value != 16 &&
	    v_buffersize.value != 24 && v_buffersize.value != 32) {
		CON_CvarSetValue(v_buffersize.name, 32);
	}
#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_GetVersion(&linked);
	I_Printf("Linked against SDL v%d.%d.%d\n", linked.major, linked.minor,
		 linked.patch);
#endif

	SDL_VERSION(&compiled);
	I_Printf("Compiled against SDL v%d.%d.%d\n", compiled.major,
		 compiled.minor, compiled.patch);

#if SDL_VERSION_ATLEAST(2, 0, 0)
	sprintf(title, "Doom64 - Version Date %s - SDL2", version_date);
#else
	sprintf(title, "Doom64 - Version Date %s", version_date);
	SDL_WM_SetCaption(title, "Doom64");
#endif

	G_AddCommand("listvidmodes", CMD_ListVidModes, 0);
	G_AddCommand("v_set", CMD_VidSet, 0);
	G_AddCommand("v_revert", CMD_VidRevert, 0);
}

//
// V_Shutdown
//

void V_Shutdown(void)
{
	V_ClearVidInfo();
#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
#endif
	SDL_Quit();
}

//
// V_TrySetMode
//

const vidmode_t *V_TrySetMode(const vidmode_t * vm)
{
	int flags;

	if (!vm)
		vm = V_Mode((int)v_display.value,
			    (int)v_width.value, (int)v_height.value,
			    -1, -1, ((int)v_windowed.value) & V_WINDOWED_MASK);

#if SDL_VERSION_ATLEAST(2, 0, 0)
	int16 x, y;
	SDL_Rect display_bounds;

	SDL_GetDisplayBounds(vm->disp_id, &display_bounds);

	if (vm->x < 0)
		x = display_bounds.x + (display_bounds.w - vm->w) / 2;
	else
		x = display_bounds.x + vm->x;

	if (vm->y < 0)
		y = display_bounds.y + (display_bounds.h - vm->h) / 2;
	else
		y = display_bounds.y + vm->y;

	if (window) {		// resize and move window
		assert(glcontext);

		SDL_SetWindowSize(window, vm->w, vm->h);
		SDL_SetWindowPosition(window, x, y);
		SDL_SetWindowFullscreen(window,
					(vm->flags & V_WINDOWED_MASK) ==
					V_WINDOWED_OFF);
		SDL_SetWindowBordered(window,
				      !((vm->flags & V_WINDOWED_MASK) ==
					V_WINDOWED_NOBORDER));

		GL_SetLogicalResolution(vm->w, vm->h);
		return vm;
	}

	flags = SDL_WINDOW_OPENGL;
	if ((vm->flags & V_WINDOWED_MASK) == V_WINDOWED_OFF)
		flags |= SDL_WINDOW_FULLSCREEN;
	if ((vm->flags & V_WINDOWED_MASK) == V_WINDOWED_NOBORDER)
		flags |= SDL_WINDOW_BORDERLESS;

	window = SDL_CreateWindow(title, x, y, vm->w, vm->h, flags);

	if (window) {
		glcontext = SDL_GL_CreateContext(window);
		if (!glcontext) {
			I_Printf
			    ("Couldn't create OpenGL context for window.\n");
			SDL_DestroyWindow(window);
		}
	}

	if (window && glcontext) {
		GL_SetLogicalResolution(vm->w, vm->h);
		return vm;
	}
#else
	flags = SDL_OPENGL;

	if ((vm->flags & V_WINDOWED_MASK) == V_WINDOWED_OFF)
		flags |= SDL_FULLSCREEN;
//      if((vm->flags & V_WINDOWED_MASK) == V_WINDOWED_NOBORDER) flags |= SDL_NOFRAME;

	screen = SDL_SetVideoMode(vm->w, vm->h, SDL_BPP, flags);

	if (screen) {
		GL_SetLogicalResolution(vm->w, vm->h);
		return vm;
	}
#endif
	return NULL;
}

//
// V_SetMode
//

dboolean V_SetMode(const vidmode_t * vm)
{
	if ((vm = V_TrySetMode(vm))) {
		// Don't add the new vidmode to history if it equals the
		// previous one, but try to set it anyway in case
		// it failed last time.
		if (!V_ModeEquals(vm, &vidmodes[0])) {
			v_width.value = (float)vm->w;
			v_height.value = (float)vm->h;
			v_display.value = (float)vm->disp_id;
			v_windowed.value = (float)(vm->flags & V_WINDOWED_MASK);

			if (num_vidmodes++) {
				dmemcpy(&vidmodes[1], &vidmodes[0], sizeof(vidmode_t));
			}
			dmemcpy(&vidmodes[0], vm, sizeof(vidmode_t));
		}
	}

	return (vm ? true : false);
}

//
// V_RevertMode
//

dboolean V_RevertMode(void)
{
	const vidmode_t *vm;
	if (num_vidmodes < 2)
		return false;	// no mode to revert to

	if ((vm = V_TrySetMode(&vidmodes[1]))) {
		v_width.value = (float)vm->w;
		v_height.value = (float)vm->h;
		v_display.value = (float)vm->disp_id;
		v_windowed.value = (float)(vm->flags & V_WINDOWED_MASK);

		dmemcpy(&vidmodes[0], vm, sizeof(vidmode_t));
		num_vidmodes--;

		return true;
	}

	return false;
}

//
// V_Mode
//

vidmode_t *V_Mode(int display, int w, int h, int x, int y, int flags)
{
	static vidmode_t vm = { 0 };

	vm.disp_id = display;
	vm.id = -1;
	vm.flags = flags;
	vm.w = w;
	vm.h = h;
	vm.x = x;
	vm.y = y;

	return &vm;
}

//
// __compar_vidmode
//

static int __compar_vidmode(const void * _a, const void * _b)
{
	const vidmode_t * a = (const void *) _a;
	const vidmode_t * b = (const void *) _b;

	if (a->w < b->w)
		return -1;
	if (a->w > b->w)
		return 1;
	// a->w == b->w
	if (a->h < b->h)
		return -1;
	if (a->h > b->h)
		return 1;
	// a->h == b->h
	return 0;
}

//
// V_UpdateVidInfo
//

void V_UpdateVidInfo(void)
{
	V_ClearVidInfo();

#if SDL_VERSION_ATLEAST(2, 0, 0)
	int i, j, cm;		// cm: current mode
	SDL_DisplayMode mode;

	vidinfo.num_displays = SDL_GetNumVideoDisplays();
	vidinfo.displays =
	    Z_Malloc(sizeof(viddisp_t) * vidinfo.num_displays, PU_STATIC, NULL);

	for (i = 0; i < vidinfo.num_displays; i++) {
		viddisp_t *disp = &vidinfo.displays[i];
		const char *disp_name;
		size_t disp_name_size;

		disp_name = SDL_GetDisplayName(i);
		if (!disp_name) {
			disp->disp_name = NULL;
		} else {
			disp_name_size = dstrlen(disp_name) + 1;
			disp->disp_name =
			    Z_Malloc(disp_name_size, PU_STATIC, NULL);
			dstrncpy(disp->disp_name, disp_name, disp_name_size);
		}

		disp->disp_id = i;
		disp->num_modes = SDL_GetNumDisplayModes(i);
		disp->modes =
		    Z_Calloc(sizeof(vidmode_t) * disp->num_modes, PU_STATIC,
			     NULL);

		for (j = cm = 0; j < disp->num_modes; j++) {
			vidmode_t *vm = &disp->modes[j];

			SDL_GetDisplayMode(i, j, &mode);

			if (vm->w == mode.w && vm->h == mode.h)
				continue;

			vm->disp_id = i;
			vm->flags = 0;
			vm->w = mode.w;
			vm->h = mode.h;
			vm->x = -1;
			vm->y = -1;

			cm++;
		}
		disp->num_modes = cm;

		qsort(disp->modes, disp->num_modes, sizeof(vidmode_t),
		      __compar_vidmode);
		for (j = 0; j < disp->num_modes; j++)
			disp->modes[j].id = j;
	}
#else
	int i;

	SDL_Rect **modes;

	// All SDLs prior to v2 assume there is only 1 display.
	vidinfo.num_displays = 1;
	vidinfo.displays = Z_Malloc(sizeof(viddisp_t), PU_STATIC, NULL);

	viddisp_t *disp = vidinfo.displays;

	disp->disp_id = 0;
	disp->disp_name = NULL;

	modes = SDL_ListModes(NULL, SDL_FULLSCREEN | SDL_HWSURFACE);
	if (modes == (SDL_Rect **) -1 || modes == (SDL_Rect **) 0) {
		disp->num_modes = 0;
		disp->modes = NULL;
		return;
	}

	for (i = 0; modes[i]; i++) ;	// count number of modes
	disp->num_modes = i;
	disp->modes =
	    Z_Malloc(sizeof(vidmode_t) * disp->num_modes, PU_STATIC, NULL);

	for (i = 0; modes[i]; i++) {
		vidmode_t *vm = &disp->modes[i];

		vm->disp_id = 0;
		vm->flags = 0;
		vm->w = modes[i]->w;
		vm->h = modes[i]->h;
		vm->x = -1;
		vm->y = -1;
	}

	qsort(disp->modes, disp->num_modes, sizeof(vidmode_t),
	      __compar_vidmode);
	for (i = 0; i < disp->num_modes; i++)
		disp->modes[i].id = i;
#endif
}

//
// V_ClearVidInfo
//

void V_ClearVidInfo(void)
{
	int i;
	if (vidinfo.displays) {
		for (i = 0; i < vidinfo.num_displays; i++) {
			viddisp_t *disp = vidinfo.displays + i;

			if (disp->disp_name)
				Z_Free(disp->disp_name);
			if (disp->modes)
				Z_Free(disp->modes);
		}
		Z_Free(vidinfo.displays);
		dmemset(&vidinfo, 0, sizeof(vidinfo));
	}
}

//
// V_RegisterCvars
//

void V_RegisterCvars(void)
{
	CON_CvarRegister(&v_msensitivityx);
	CON_CvarRegister(&v_msensitivityy);
	CON_CvarRegister(&v_macceleration);
	CON_CvarRegister(&v_mlook);
	CON_CvarRegister(&v_mlookinvert);
	CON_CvarRegister(&v_yaxismove);
	CON_CvarRegister(&v_width);
	CON_CvarRegister(&v_height);
	CON_CvarRegister(&v_windowed);
	CON_CvarRegister(&v_vsync);
	CON_CvarRegister(&v_depthsize);
	CON_CvarRegister(&v_buffersize);
}
