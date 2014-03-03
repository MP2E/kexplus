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

#include "SDL.h"

#include "doomdef.h"
#include "doomstat.h"
#include "d_main.h"
#include "i_mouse.h"
#include "i_system.h"

CVAR(v_msensitivityx, 5);
CVAR(v_msensitivityy, 5);
CVAR(v_macceleration, 0);
CVAR(v_mlook, 0);
CVAR(v_mlookinvert, 0);
CVAR(v_yaxismove, 0);

CVAR_EXTERNAL(m_menumouse);

float mouse_accelfactor;
int mouse_x = 0;
int mouse_y = 0;

//
// I_SDLtoDoomMouseState
//

static int I_SDLtoDoomMouseState(Uint8 buttonstate)
{
	return 0 | (buttonstate & SDL_BUTTON(SDL_BUTTON_LEFT) ? 1 : 0)
		| (buttonstate & SDL_BUTTON(SDL_BUTTON_MIDDLE) ? 2 : 0)
		| (buttonstate & SDL_BUTTON(SDL_BUTTON_RIGHT) ? 4 : 0);
}

//
// I_MouseAccelChange
//

void I_MouseAccelChange(void)
{
	mouse_accelfactor = v_macceleration.value / 200.0f + 1.0f;
}

//
// I_MouseAccel
//

int I_MouseAccel(int val)
{
	if (!v_macceleration.value)
		return val;

	if (val < 0)
		return -I_MouseAccel(-val);

	return (int)(pow((double)val, (double)mouse_accelfactor));
}

//
// I_CenterMouse
//

void I_CenterMouse(void)
{
	// Warp the the screen center
#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_WarpMouseInWindow(window,
				  (unsigned short)(video_width / 2),
				  (unsigned short)(video_height / 2));
#else
	SDL_WarpMouse((unsigned short)(video_width / 2),
			  (unsigned short)(video_height / 2));
#endif

	// Clear any relative movement caused by warping
	SDL_PumpEvents();
	SDL_GetRelativeMouseState(NULL, NULL);
}

//
// I_ReadMouse
//

void I_ReadMouse(void)
{
	int x, y;
	Uint8 btn;
	event_t ev;
	static Uint8 lastmbtn = 0;

	SDL_GetRelativeMouseState(&x, &y);
	btn = SDL_GetMouseState(&mouse_x, &mouse_y);

	if (x != 0 || y != 0 || btn || (lastmbtn != btn)) {
		ev.type = ev_mouse;
		ev.data1 = I_SDLtoDoomMouseState(btn);
		ev.data2 = x << 5;
		ev.data3 = (-y) << 5;
		ev.data4 = 0;
		D_PostEvent(&ev);
	}

	lastmbtn = btn;
}

//
// I_UpdateGrab
//

void I_UpdateGrab(void)
{
	static dboolean currently_grabbed = false;
	dboolean grab;

	grab = false;
	if (grab && !currently_grabbed) {
#if SDL_VERSION_ATLEAST(2, 0, 0)
		SDL_SetRelativeMouseMode(1);
#else
		SDL_WM_GrabInput(SDL_GRAB_ON);
#endif
	SDL_ShowCursor(1);
	}

	if (!grab && currently_grabbed) {
#if SDL_VERSION_ATLEAST(2, 0, 0)
		SDL_SetRelativeMouseMode(0);
#else
		SDL_WM_GrabInput(SDL_GRAB_OFF);
#endif
	SDL_ShowCursor(m_menumouse.value < 1);
	}

	currently_grabbed = grab;
}

//
// I_MouseEvent
//

dboolean I_MouseEvent(const SDL_Event * Event)
{
	event_t event;
	uint32 mwheeluptic = 0, mwheeldowntic = 0;
	uint32 tic = gametic;

	switch (Event->type) {
#if SDL_VERSION_ATLEAST(2, 0, 0)
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		if (!window_focused)
			break;

		event.type =
			Event->type ==
			SDL_MOUSEBUTTONUP ? ev_mouseup : ev_mousedown;
		event.data1 =
			I_SDLtoDoomMouseState(SDL_GetMouseState(NULL, NULL));
		event.data2 = event.data3 = 0;

		D_PostEvent(&event);
		break;

	case SDL_MOUSEWHEEL:
		if (Event->wheel.y > 0) {
			event.type = ev_keydown;
			event.data1 = KEY_MWHEELUP;
			mwheeluptic = tic;
		} else if (Event->wheel.y < 0) {
			event.type = ev_keydown;
			event.data1 = KEY_MWHEELDOWN;
			mwheeldowntic = tic;
		} else
			break;

		event.data2 = event.data3 = 0;
		D_PostEvent(&event);
		break;
#else
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		if (!window_focused)
			break;

		if (Event->button.button == SDL_BUTTON_WHEELUP) {
			event.type = ev_keydown;
			event.data1 = KEY_MWHEELUP;
			mwheeluptic = tic;
		} else if (Event->button.button == SDL_BUTTON_WHEELDOWN) {
			event.type = ev_keydown;
			event.data1 = KEY_MWHEELDOWN;
			mwheeldowntic = tic;
		} else {
			event.type = Event->type ==
				SDL_MOUSEBUTTONUP ? ev_mouseup : ev_mousedown;
			event.data1 =
				I_SDLtoDoomMouseState(SDL_GetMouseState
						  (NULL, NULL));
		}

		event.data2 = event.data3 = 0;
		D_PostEvent(&event);
		break;
#endif
		default:
			return false;
			break;
	}

	if (mwheeluptic && mwheeluptic + 1 < tic) {
		event.type = ev_keyup;
		event.data1 = KEY_MWHEELUP;
		D_PostEvent(&event);
		mwheeluptic = 0;
	}

	if (mwheeldowntic && mwheeldowntic + 1 < tic) {
		event.type = ev_keyup;
		event.data1 = KEY_MWHEELDOWN;
		D_PostEvent(&event);
		mwheeldowntic = 0;
	}

	return true;
}

//
// I_InitMouse
//

void I_InitMouse(void)
{
	I_MouseAccelChange();
}

//
// I_ShutdownMouse
//

void I_ShutdownMouse(void)
{
}

//
// I_RegisterMouseCvars
//

void I_RegisterMouseCvars(void)
{
	CON_CvarRegister(&v_msensitivityx);
	CON_CvarRegister(&v_msensitivityy);
	CON_CvarRegister(&v_macceleration);
	CON_CvarRegister(&v_mlook);
	CON_CvarRegister(&v_mlookinvert);
	CON_CvarRegister(&v_yaxismove);
}
