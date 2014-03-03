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

#ifndef __I_MOUSE__
#define __I_MOUSE__

#include "SDL.h"

extern int mouse_x;
extern int mouse_y;

void I_InitMouse(void);
void I_ShutdownMouse(void);
void I_RegisterMouseCvars(void);

void I_ReadMouse(void);

void I_CenterMouse(void);

int I_MouseAccel(int val);
void I_MouseAccelChange(void);

dboolean I_MouseEvent(const SDL_Event * Event);

#endif /* __I_MOUSE__ */
