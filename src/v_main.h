// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright(C) 2005 Simon Howard
// Copyright(C) 2007-2012 Samuel Villarreal
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

#if SDL_VERSION_ATLEAST(2, 0, 0)
struct SDL_Window;
struct SDL_GLContext;

extern SDL_Window * window;
extern SDL_GLContext * glcontext;
#else
struct SDL_Surface;

extern SDL_Surface * screen;
#endif

enum {
	V_WINDOWED_OFF		= 0x00,
	V_WINDOWED_ON		= 0x01,
	V_WINDOWED_NOBORDER	= 0x02,
	V_WINDOWED_MASK		= 0x03,
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
	char * disp_name;

	vidmode_t * modes;
	int num_modes;
} viddisp_t;

typedef struct {
	viddisp_t * displays;
	int num_displays;
} vidinfo_t;

extern const vidmode_t * vidmode;
extern vidinfo_t vidinfo;

void V_Init(void);
dboolean V_SetMode(const vidmode_t * vm);
dboolean V_RevertMode(void);
vidmode_t * V_Mode(int display, int width, int height, int x, int h, int flags);

void V_UpdateVidInfo(void);
void V_ClearVidInfo(void);

void V_RegisterCvars(void);

inline int V_NumDisplays(void)
{
	return vidinfo.num_displays;
}

inline int V_NumModes(int display)
{
	if(display < 0 || display >= vidinfo.num_displays)
		return 0;
	return vidinfo.displays[display].num_modes;
}

inline const viddisp_t * V_GetDisplay(int display)
{
	if(display < 0 || display >= vidinfo.num_displays)
		return NULL;
	return &vidinfo.displays[display];
}

inline const vidmode_t * V_GetMode(int display, int mode)
{
	if(display < 0 || display >= vidinfo.num_displays)
		return NULL;

	const viddisp_t * disp = &vidinfo.displays[display];
	if(mode < 0 || mode >= disp->num_modes)
		return NULL;
	return &disp->modes[mode];
}
