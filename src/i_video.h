// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright(C) 1993-1997 Id Software, Inc.
// Copyright(C) 2005 Simon Howard
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

#ifndef __I_VIDEO__
#define __I_VIDEO__

#include "SDL.h"
#include "d_event.h"
#include "d_keywds.h"

#if SDL_VERSION_ATLEAST(2, 0, 0)
struct SDL_Window;
struct SDL_GLContext;

extern SDL_Window *window;
extern SDL_GLContext *glcontext;
#else
struct SDL_Surface;

extern SDL_Surface *screen;
#endif

enum {
	I_WINDOWED_OFF = 0x00,
	I_WINDOWED_ON = 0x01,
	I_WINDOWED_NOBORDER = 0x02,
	I_WINDOWED_MASK = 0x03,
};

typedef struct {
	int id;
	int disp_id;

	int flags;

	int16 w;
	int16 h;

	// window pos. (0, 0) is top-left of display. -1 to center.
	int16 x;
	int16 y;
} vidmode_t;

typedef struct {
	int disp_id;
	char *disp_name;

	vidmode_t *modes;
	int num_modes;
} viddisp_t;

typedef struct {
	viddisp_t *displays;
	int num_displays;
} vidinfo_t;

extern const vidmode_t *vidmode;
extern vidinfo_t vidinfo;

void I_InitVideo(void);
void I_ShutdownVideo(void);
void I_RegisterVideoCvars(void);

dboolean I_VideoEvent(const SDL_Event * Event);

dboolean I_SetMode(const vidmode_t * vm);
dboolean I_RevertMode(void);
vidmode_t *I_Mode(int display, int width, int height, int x, int h, int flags);

void I_UpdateVidInfo(void);
void I_ClearVidInfo(void);

void I_NetWaitScreen(void);

//
// Called by D_DoomLoop,
// called before processing each tic in a frame.
// Quick syncronous operations are performed here.
// Can call D_PostEvent.
void I_StartTic(void);
void I_FinishUpdate(void);
int I_ShutdownWait(void);

static d_inline int I_NumDisplays(void)
{
	return vidinfo.num_displays;
}

static d_inline int I_NumModes(int display)
{
	if (display < 0 || display >= vidinfo.num_displays)
		return 0;
	return vidinfo.displays[display].num_modes;
}

static d_inline const viddisp_t *I_GetDisplay(int display)
{
	if (display < 0 || display >= vidinfo.num_displays)
		return NULL;
	return &vidinfo.displays[display];
}

static d_inline const vidmode_t *I_GetMode(int display, int mode)
{
	if (display < 0 || display >= vidinfo.num_displays)
		return NULL;

	const viddisp_t *disp = &vidinfo.displays[display];
	if (mode < 0 || mode >= disp->num_modes)
		return NULL;
	return &disp->modes[mode];
}

static d_inline dboolean I_ModeEquals(const vidmode_t * a, const vidmode_t * b)
{
	return (a->w == b->w) && (a->h == b->h) &&
			(a->disp_id == b->disp_id) &&
			(a->flags == b->flags);
}

static d_inline int I_GetClosestMode(const vidmode_t * vm)
{
	int i, j;
	for (i = 0; i < vidinfo.num_displays; i++) {
		const viddisp_t * disp = &vidinfo.displays[i];
		for (j = 0; j < disp->num_modes; j++) {
			const vidmode_t * mode = &disp->modes[j];
			if(mode->w == vm->w && mode->h == vm->h)
				return mode->id;
		}
	}
	return -1;
}

#endif /* __I_VIDEO__ */
