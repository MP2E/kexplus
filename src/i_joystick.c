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
#include "con_cvar.h"
#include "d_main.h"
#include "i_joystick.h"
#include "z_zone.h"

CVAR(i_joysensx, 3.0f);
CVAR(i_joysensy, 3.0f);
CVAR(i_joytwinstick, 0);

typedef int (*keyconv_t)(int);

typedef struct {
	int16 device_id;
	SDL_Joystick *device;

	char *name;

	keyconv_t keyconv;

	int num_axes;
	int num_hats;
} joy_t;

static joy_t *joy = NULL;
static int num_joy = 0;

//
// keyconv_Playstation3
//

static int keyconv_Playstation3(int key) {
	int ch = -1;

	if (key == 4)
		ch = KEY_UPARROW;
	else if (key == 5)
		ch = KEY_RIGHTARROW;
	else if (key == 6)
		ch = KEY_DOWNARROW;
	else if (key == 7)
		ch = KEY_LEFTARROW;
	else if (key == 3)
		ch = KEY_ESCAPE;
	else if (key == 13)
		ch = KEY_BACKSPACE;
	else if (key == 14)
		ch = KEY_ENTER;

	return ch;
}

typedef struct {
	const char *name;
	keyconv_t func;
} keyconvstruct_t;

static keyconvstruct_t keyconv[] = {
	{ "Sony PLAYSTATION(R)3 Controller", keyconv_Playstation3 },
};

static int num_keyconv = sizeof(keyconv) / sizeof(keyconv[0]);

//
// JoystickCloseAll
//

static void JoystickCloseAll()
{
	int i;

	for (i = 0; i < num_joy; i++) {
		SDL_JoystickClose(joy[i].device);
		if (joy[i].name)
			Z_Free(joy[i].name);
	}
	if (joy) {
		Z_Free(joy);
		joy = 0;
	}
}

//
// JoystickClose
//

static void JoystickClose(int device_id)
{
	int i;

	for (i = 0; i < num_joy; i++) {
		if (joy[i].device_id == device_id) {
			I_Printf("Controller %d \"%s\" disconnected...\n", joy[i].device_id, joy[i].name);

			SDL_JoystickClose(joy[i].device);
			Z_Free(joy[i].name);
			break;
		}
	}

	// Joystick not found.
	if (i == num_joy)
		return;

	num_joy--;
	for (; i < num_joy; i++) {
		joy[i] = joy[i+1];
	}

	Z_ReallocV(joy, num_joy, PU_STATIC, NULL);
}

//
// JoystickOpen
//

static void JoystickOpen(int device_id)
{
	int i;
	joy_t j;
	const char *name;

	j.device = SDL_JoystickOpen(device_id);

	if (!j.device)
		return;

	j.device_id = device_id;
	j.keyconv = NULL;
	j.num_axes = SDL_JoystickNumAxes(j.device);
	j.num_hats = SDL_JoystickNumHats(j.device);

#if SDL_VERSION_ATLEAST(2, 0, 0)
	name = SDL_JoystickName(j.device);
#else
	name = SDL_JoystickName(j.device_id);
#endif

	if (name) {
		j.name = Z_Malloc(dstrlen(name) + 1, PU_STATIC, NULL);
		dstrcpy(j.name, name);

		for (i = 0; i < num_keyconv; i++) {
			if (dstrcmp(j.name, keyconv[i].name) == 0) {
				j.keyconv = keyconv[i].func;
				break;
			}
		}
	} else {
		j.name = NULL;
	}

	num_joy++;
	Z_ReallocV(joy, num_joy, PU_STATIC, NULL);

	joy[num_joy - 1] = j;

	if (j.keyconv) {
		I_Printf("Supported controller %d \"%s\" connected...\n", j.device_id, j.name);
	} else {
		I_Printf("Controller %d \"%s\" connected...\n", j.device_id, j.name);
	}
}

//
// I_InitJoystick
//

void I_InitJoystick(void)
{
#if !SDL_VERSION_ATLEAST(2, 0, 0)
	int i, num;

	num = SDL_NumJoysticks();

	for (i = 0; i < num; i++) {
		JoystickOpen(i);
	}
#endif
}

//
// I_ShutdownJoystick
//

void I_ShutdownJoystick(void)
{
	JoystickCloseAll();
}

//
// I_ReadJoystick
//

void I_ReadJoystick(void)
{
	int16 lx, ly, rx, ry;
	event_t event;

	if (!num_joy)
		return;

	lx = SDL_JoystickGetAxis(joy[0].device, 0);
	ly = SDL_JoystickGetAxis(joy[0].device, 1);
	rx = SDL_JoystickGetAxis(joy[0].device, 2);
	ry = SDL_JoystickGetAxis(joy[0].device, 3);

	event.type = ev_gamepad;
	event.data1 = lx;
	event.data2 = ly;
	event.data3 = rx;
	event.data4 = ry;
	D_PostEvent(&event);
}

//
// I_JoystickName
//

const char *I_JoystickName(void)
{
	if (!num_joy || !joy[0].name)
		return "None";

	return joy[0].name;
}

//
// I_JoystickToKey
//

int I_JoystickToKey(int key)
{
	if (!num_joy || !joy[0].keyconv)
		return -1;

	return joy[0].keyconv(key);
}

//
// I_JoystickEvent
//

dboolean I_JoystickEvent(const SDL_Event *Event)
{
	event_t event;
	switch (Event->type) {
#if SDL_VERSION_ATLEAST(2, 0, 0)
	case SDL_JOYDEVICEREMOVED:
		JoystickClose(Event->jdevice.which);
		break;

	case SDL_JOYDEVICEADDED:
		JoystickOpen(Event->jdevice.which);
		break;
#endif

	case SDL_JOYBUTTONDOWN:
		I_Printf("joy%d pressed\n", Event->jbutton.button);
		event.type = ev_gamepaddown;
		event.data1 = Event->jbutton.button;
		D_PostEvent(&event);
		break;

	case SDL_JOYBUTTONUP:
		event.type = ev_gamepadup;
		event.data1 = Event->jbutton.button;
		D_PostEvent(&event);
		break;

	default:
		return false;
		break;
	}

	return true;
}

//
// I_RegisterJoystickCvars
//

void I_RegisterJoystickCvars(void)
{
	CON_CvarRegister(&i_joytwinstick);
	CON_CvarRegister(&i_joysensx);
	CON_CvarRegister(&i_joysensy);
}
