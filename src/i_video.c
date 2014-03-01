// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
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
//
// DESCRIPTION:
//    SDL Stuff
//
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "SDL.h"
#include "SDL_opengl.h"

#include "doomdef.h"
#include "doomstat.h"
#include "d_main.h"
#include "gl_main.h"
#include "i_system.h"
#include "i_video.h"
#include "m_misc.h"
#include "v_main.h"

#ifdef _WIN32
#include "i_xinput.h"
#endif

#if SDL_VERSION_ATLEAST(2, 0, 0)
#define SDL_keysym	SDL_Keysym
#define SDLK_KP0	SDLK_KP_0
#define SDLK_KP1	SDLK_KP_1
#define SDLK_KP2	SDLK_KP_2
#define SDLK_KP3	SDLK_KP_3
#define SDLK_KP4	SDLK_KP_4
#define SDLK_KP5	SDLK_KP_5
#define SDLK_KP6	SDLK_KP_6
#define SDLK_KP7	SDLK_KP_7
#define SDLK_KP8	SDLK_KP_8
#define SDLK_KP9	SDLK_KP_9
#define SDLK_
#endif

CVAR_EXTERNAL(m_menumouse);
CVAR_EXTERNAL(v_msensitivityx);
CVAR_EXTERNAL(v_msensitivityy);
CVAR_EXTERNAL(v_macceleration);
CVAR_EXTERNAL(v_mlook);
CVAR_EXTERNAL(v_mlookinvert);
CVAR_EXTERNAL(v_yaxismove);
CVAR_EXTERNAL(v_vsync);
CVAR_EXTERNAL(v_depthsize);
CVAR_EXTERNAL(v_buffersize);
CVAR_EXTERNAL(v_width);
CVAR_EXTERNAL(v_height);
CVAR_EXTERNAL(v_windowed);

static void I_GetEvent(SDL_Event * Event);
static void I_ReadMouse(void);
static void I_InitInputs(void);
void I_UpdateGrab(void);

//================================================================================
// Video
//================================================================================

dboolean window_focused;

int mouse_x = 0;
int mouse_y = 0;

//
// I_ShutdownWait
//

int I_ShutdownWait(void)
{
	static SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT ||
		    (event.type == SDL_KEYDOWN
		     && event.key.keysym.sym == SDLK_ESCAPE)) {
#ifndef USESYSCONSOLE
			exit(0);
#else
			return 1;
#endif
		}
	}

	return 0;
}

//
// I_NetWaitScreen
// Blank screen display while waiting for players to join
//

void I_NetWaitScreen(void)
{
	I_Printf("STUB: I_NetWaitScreen\n");
}

//
// I_InitVideo
//

void I_InitVideo(void)
{
	uint32 f = SDL_INIT_VIDEO;

#ifdef _DEBUG
	f |= SDL_INIT_NOPARACHUTE;
#endif

#if !SDL_VERSION_ATLEAST(2, 0, 0)
	putenv("SDL_VIDEO_CENTERED=1");
#endif

	if (SDL_Init(f) < 0) {
		printf("ERROR - Failed to initialize SDL");
		exit(1);
	}

	I_InitInputs();
}

//
// I_StartTic
//

void I_StartTic(void)
{
	SDL_Event Event;

	while (SDL_PollEvent(&Event))
		I_GetEvent(&Event);

#ifdef _USE_XINPUT
	I_XInputPollEvent();
#endif

	I_ReadMouse();
}

//
// I_FinishUpdate
//

void I_FinishUpdate(void)
{
	I_UpdateGrab();
	GL_SwapBuffers();

	BusyDisk = false;
}

//================================================================================
// Input
//================================================================================

static SDL_Cursor *cursors[2] = { NULL, NULL };

float mouse_accelfactor;

int UseJoystick;
int UseMouse[2];
dboolean DigiJoy;
int DualMouse;

dboolean MouseMode;		//false=microsoft, true=mouse systems

//
// I_TranslateKey
//

static int I_TranslateKey(SDL_keysym * key)
{
	int rc = 0;

	switch (key->sym) {
	case SDLK_LEFT:
		rc = KEY_LEFTARROW;
		break;
	case SDLK_RIGHT:
		rc = KEY_RIGHTARROW;
		break;
	case SDLK_DOWN:
		rc = KEY_DOWNARROW;
		break;
	case SDLK_UP:
		rc = KEY_UPARROW;
		break;
	case SDLK_ESCAPE:
		rc = KEY_ESCAPE;
		break;
	case SDLK_RETURN:
		rc = KEY_ENTER;
		break;
	case SDLK_TAB:
		rc = KEY_TAB;
		break;
	case SDLK_F1:
		rc = KEY_F1;
		break;
	case SDLK_F2:
		rc = KEY_F2;
		break;
	case SDLK_F3:
		rc = KEY_F3;
		break;
	case SDLK_F4:
		rc = KEY_F4;
		break;
	case SDLK_F5:
		rc = KEY_F5;
		break;
	case SDLK_F6:
		rc = KEY_F6;
		break;
	case SDLK_F7:
		rc = KEY_F7;
		break;
	case SDLK_F8:
		rc = KEY_F8;
		break;
	case SDLK_F9:
		rc = KEY_F9;
		break;
	case SDLK_F10:
		rc = KEY_F10;
		break;
	case SDLK_F11:
		rc = KEY_F11;
		break;
	case SDLK_F12:
		rc = KEY_F12;
		break;
	case SDLK_BACKSPACE:
		rc = KEY_BACKSPACE;
		break;
	case SDLK_DELETE:
		rc = KEY_DEL;
		break;
	case SDLK_INSERT:
		rc = KEY_INSERT;
		break;
	case SDLK_PAGEUP:
		rc = KEY_PAGEUP;
		break;
	case SDLK_PAGEDOWN:
		rc = KEY_PAGEDOWN;
		break;
	case SDLK_HOME:
		rc = KEY_HOME;
		break;
	case SDLK_END:
		rc = KEY_END;
		break;
	case SDLK_PAUSE:
		rc = KEY_PAUSE;
		break;
	case SDLK_EQUALS:
		rc = KEY_EQUALS;
		break;
	case SDLK_MINUS:
		rc = KEY_MINUS;
		break;
	case SDLK_KP0:
		rc = KEY_KEYPAD0;
		break;
	case SDLK_KP1:
		rc = KEY_KEYPAD1;
		break;
	case SDLK_KP2:
		rc = KEY_KEYPAD2;
		break;
	case SDLK_KP3:
		rc = KEY_KEYPAD3;
		break;
	case SDLK_KP4:
		rc = KEY_KEYPAD4;
		break;
	case SDLK_KP5:
		rc = KEY_KEYPAD5;
		break;
	case SDLK_KP6:
		rc = KEY_KEYPAD6;
		break;
	case SDLK_KP7:
		rc = KEY_KEYPAD7;
		break;
	case SDLK_KP8:
		rc = KEY_KEYPAD8;
		break;
	case SDLK_KP9:
		rc = KEY_KEYPAD9;
		break;
	case SDLK_KP_PLUS:
		rc = KEY_KEYPADPLUS;
		break;
	case SDLK_KP_MINUS:
		rc = KEY_KEYPADMINUS;
		break;
	case SDLK_KP_DIVIDE:
		rc = KEY_KEYPADDIVIDE;
		break;
	case SDLK_KP_MULTIPLY:
		rc = KEY_KEYPADMULTIPLY;
		break;
	case SDLK_KP_ENTER:
		rc = KEY_KEYPADENTER;
		break;
	case SDLK_KP_PERIOD:
		rc = KEY_KEYPADPERIOD;
		break;
	case SDLK_LSHIFT:
	case SDLK_RSHIFT:
		rc = KEY_RSHIFT;
		break;
	case SDLK_LCTRL:
	case SDLK_RCTRL:
		rc = KEY_RCTRL;
		break;
#if !SDL_VERSION_ATLEAST(2, 0, 0)
	case SDLK_LMETA:
	case SDLK_RMETA:
#endif
	case SDLK_LALT:
	case SDLK_RALT:
		rc = KEY_RALT;
		break;
	case SDLK_CAPSLOCK:
		rc = KEY_CAPS;
		break;
	default:
		rc = key->sym;
		break;
	}

	return rc;

}

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
// I_UpdateFocus
//

#if !SDL_VERSION_ATLEAST(2, 0 ,0)
static void I_UpdateFocus(void)
{
	Uint8 state;
	state = SDL_GetAppState();

	// We should have input (keyboard) focus and be visible
	// (not minimised)
	window_focused = (state & SDL_APPINPUTFOCUS) && (state & SDL_APPACTIVE);
}
#endif

// I_CenterMouse
// Warp the mouse back to the middle of the screen
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
// I_MouseShouldBeGrabbed
//

static dboolean I_MouseShouldBeGrabbed()
{
#ifndef _WIN32
	// 20140105 bkw: Always grab the mouse in fullscreen mode
	if (!InWindow)
		return true;
#endif

	// if the window doesnt have focus, never grab it
	if (!window_focused)
		return false;

#ifdef _WIN32
	if (!InWindow && m_menumouse.value <= 0)
		return true;
#endif

	// when menu is active or game is paused, release the mouse
	if (menuactive || paused)
		return false;

	// only grab mouse when playing levels (but not demos)
	return (gamestate == GS_LEVEL) && !demoplayback;
}

//
// I_ReadMouse
//

static void I_ReadMouse(void)
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

	if (I_MouseShouldBeGrabbed())
		I_CenterMouse();
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
// I_ActivateMouse
//

static void I_ActivateMouse(void)
{
	SDL_SetCursor(cursors[1]);
#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_SetRelativeMouseMode(1);
#else
	SDL_WM_GrabInput(SDL_GRAB_ON);
#endif
	SDL_ShowCursor(1);
}

//
// I_DeactivateMouse
//

static void I_DeactivateMouse(void)
{
	SDL_SetCursor(cursors[0]);
#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_SetRelativeMouseMode(0);
#else
	SDL_WM_GrabInput(SDL_GRAB_OFF);
#endif
	SDL_ShowCursor(m_menumouse.value < 1);
}

//
// I_UpdateGrab
//

void I_UpdateGrab(void)
{
	static dboolean currently_grabbed = false;
	dboolean grab;

	grab = I_MouseShouldBeGrabbed();
	if (grab && !currently_grabbed) {
		I_ActivateMouse();
	}

	if (!grab && currently_grabbed) {
		I_DeactivateMouse();
	}

	currently_grabbed = grab;
}

//
// I_GetEvent
//

static void I_GetEvent(SDL_Event * Event)
{
	event_t event;
	uint32 mwheeluptic = 0, mwheeldowntic = 0;
	uint32 tic = gametic;

	switch (Event->type) {
	case SDL_KEYDOWN:
#if SDL_VERSION_ATLEAST(2, 0, 0)
		// TODO: 'repeat' shouldn't be ignored when console is open.
		if (Event->key.repeat)
			break;
#endif
		event.type = ev_keydown;
		event.data1 = I_TranslateKey(&Event->key.keysym);
		D_PostEvent(&event);
		break;

	case SDL_KEYUP:
		event.type = ev_keyup;
		event.data1 = I_TranslateKey(&Event->key.keysym);
		D_PostEvent(&event);
		break;

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

	case SDL_WINDOWEVENT:
		switch (Event->window.event) {
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			window_focused = 1;
			break;

		case SDL_WINDOWEVENT_FOCUS_LOST:
			window_focused = 0;
			break;

		default:
			break;
		}
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

	case SDL_ACTIVEEVENT:
	case SDL_VIDEOEXPOSE:
		I_UpdateFocus();
		break;
#endif

	case SDL_QUIT:
		I_Quit();
		break;

	default:
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
}

//
// I_InitInputs
//

static void I_InitInputs(void)
{
	Uint8 data[1] = { 0x00 };

	SDL_PumpEvents();
	cursors[0] = SDL_GetCursor();
	cursors[1] = SDL_CreateCursor(data, data, 8, 1, 0, 0);

	SDL_ShowCursor(m_menumouse.value < 1);

	UseMouse[0] = 1;
	UseMouse[1] = 2;

	I_CenterMouse();
	I_MouseAccelChange();

#ifdef _USE_XINPUT
	I_XInputInit();
#endif
}
