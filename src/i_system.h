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

#ifndef __I_SYSTEM__
#define __I_SYSTEM__

#include <stdio.h>

#include "d_ticcmd.h"
#include "d_event.h"
#include "m_fixed.h"

#ifdef __GNUG__
#pragma interface
#define attr_printf(a,b) __attribute__((format (printf, a, b)))
#else
#define attr_printf(a,b)
#endif

enum {
	I_VIDEO = 0x01,
	I_KEYBOARD = 0x02,
	I_MOUSE = 0x04,
	I_XINPUT = 0x08,
	I_JOYSTICK = 0x10
};

extern int init_systems;

// Called by DoomMain.
void I_Init(void);

#ifdef _WIN32

#define USESYSCONSOLE

void I_SpawnSysConsole(void);
void I_ShowSysConsole(dboolean show);

#endif

// Called by D_DoomLoop,
// returns current time in tics.

extern fixed_t rendertic_frac;

extern int (*I_GetTime) (void);
void I_InitClockRate(void);
int I_GetTimeMS(void);
void I_Sleep(unsigned long usecs);
dboolean I_StartDisplay(void);
void I_EndDisplay(void);
fixed_t I_GetTimeFrac(void);
void I_GetTime_SaveMS(void);
unsigned long I_GetRandomTimeSeed(void);

// Timers for debugging
void I_StartTimer(void);
unsigned int I_StopTimer(void);
unsigned int I_PeekTimer(void);
void I_PrintTimer(const char *fmt, ...) attr_printf(1, 2);

// Asynchronous interrupt functions should maintain private queues
// that are read by the synchronous functions
// to be converted into events.

// Either returns a null ticcmd,
// or calls a loadable driver to build it.
// This ticcmd will then be modified by the gameloop
// for normal input.
ticcmd_t *I_BaseTiccmd(void);

// Called by M_Responder when quit is selected.
// Clean exit, displays sell blurb.
void I_Quit(void);

void I_BeginRead(void);
void I_Error(char *error, ...) attr_printf(1, 2);
void I_Printf(char *msg, ...) attr_printf(1, 2);
char *I_DoomExeDir(void);

void I_RegisterCvars(void);

extern FILE *DebugFile;
extern dboolean DigiJoy;

#endif
