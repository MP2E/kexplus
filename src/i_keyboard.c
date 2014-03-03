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
#include "i_keyboard.h"
#include "i_system.h"

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
#endif

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
// I_InitKeyboard
//

void I_InitKeyboard()
{

}

//
// I_KeyboardEvent
//

dboolean I_KeyboardEvent(const SDL_Event * Event)
{
	event_t event;
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

		default:
			return false;
			break;
	}

	return true;
}
