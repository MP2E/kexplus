// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright(C) 1993-1997 Id Software, Inc.
// Copyright(C) 2007-2013 Samuel Villarreal
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
// DESCRIPTION: Demo System
//
//-----------------------------------------------------------------------------

#include "doomdef.h"
#include "doomstat.h"
#include "z_zone.h"
#include "p_tick.h"
#include "g_local.h"
#include "g_demo.h"
#include "m_misc.h"
#include "con_console.h"

void G_DoLoadLevel(void);
dboolean G_CheckDemoStatus(void);
void G_ReadDemoTiccmd(ticcmd_t * cmd);
void G_WriteDemoTiccmd(ticcmd_t * cmd);

dboolean timingdemo = false;	// if true, exit with report on completion
char demoname[32];
dboolean demorecording = false;
dboolean demoplayback = false;
dboolean netdemo = false;
byte *demobuffer;
byte *demo_p;
byte *demoend;
dboolean singledemo = false;	// quit after playing a demo from cmdline

extern int starttime;

//
// DEMO RECORDING
//

//
// G_ReadDemoTiccmd
//

void G_ReadDemoTiccmd(ticcmd_t * cmd)
{
	if (*demo_p == DEMOMARKER) {
		// end of demo data stream
		G_CheckDemoStatus();
		return;
	}

	cmd->forwardmove = ((signed char)*demo_p++);
	cmd->sidemove = ((signed char)*demo_p++);
	cmd->angleturn = ((unsigned char)*demo_p++) << 8;
	cmd->pitch = ((unsigned char)*demo_p++) << 8;
	cmd->buttons = (unsigned char)*demo_p++;
	cmd->buttons2 = (unsigned char)*demo_p++;
}

//
// G_WriteDemoTiccmd
//

void G_WriteDemoTiccmd(ticcmd_t * cmd)
{
	*demo_p++ = cmd->forwardmove;
	*demo_p++ = cmd->sidemove;
	*demo_p++ = (cmd->angleturn + 128) >> 8;
	*demo_p++ = (cmd->pitch + 128) >> 8;
	*demo_p++ = cmd->buttons;
	*demo_p++ = cmd->buttons2;

	demo_p -= 6;

	if (demo_p > demoend - 24) {
		// no more space
		G_CheckDemoStatus();
		return;
	}

	G_ReadDemoTiccmd(cmd);	// make SURE it is exactly the same
}

//
// G_RecordDemo
//

void G_RecordDemo(const char *name)
{
	int i;
	int maxsize;

	dstrcpy(demoname, name);
	dstrcat(demoname, ".lmp");

	CON_DPrintf("--------Recording %s--------\n", demoname);

	maxsize = 0x20000;
	i = M_CheckParm("-maxdemo");

	if (i && i < myargc - 1)
		maxsize = datoi(myargv[i + 1]) * 1024;

	demobuffer = Z_Malloc(maxsize, PU_STATIC, NULL);
	demoend = demobuffer + maxsize;
	demo_p = demobuffer;

	G_InitNew(startskill, startmap);

	*demo_p++ = 1;
	*demo_p++ = gameskill;
	*demo_p++ = gamemap;
	*demo_p++ = deathmatch;
	*demo_p++ = respawnparm;
	*demo_p++ = respawnitem;
	*demo_p++ = fastparm;
	*demo_p++ = nomonsters;
	*demo_p++ = consoleplayer;

	for (i = 0; i < MAXPLAYERS; i++)
		*demo_p++ = playeringame[i];

	demorecording = true;
	usergame = false;

	G_DoLoadLevel();
	D_MiniLoop(P_Start, P_Stop, P_Drawer, P_Ticker);

	G_CheckDemoStatus();
}

//
// G_PlayDemo
//

void G_PlayDemo(const char *name)
{
	int i;
	int p;
	char filename[256];

	gameaction = ga_nothing;

	p = M_CheckParm("-playdemo");
	if (p && p < myargc - 1) {
		// 20120107 bkw: add .lmp extension if missing.
		if (dstrrchr(myargv[p + 1], '.'))
			dstrcpy(filename, myargv[p + 1]);
		else
			dsprintf(filename, "%s.lmp", myargv[p + 1]);

		CON_DPrintf("--------Reading demo %s--------\n", filename);
		if (M_ReadFile(filename, &demobuffer) == -1) {
			gameaction = ga_exitdemo;
			return;
		}

		demo_p = demobuffer;
	} else {
		if (W_CheckNumForName(name) == -1) {
			gameaction = ga_exitdemo;
			return;
		}

		CON_DPrintf("--------Playing demo %s--------\n", name);
		demobuffer = demo_p = W_CacheLumpName(name, PU_STATIC);
	}

	demo_p++;

	startskill = *demo_p++;
	startmap = *demo_p++;
	deathmatch = *demo_p++;
	respawnparm = *demo_p++;
	respawnitem = *demo_p++;
	fastparm = *demo_p++;
	nomonsters = *demo_p++;
	consoleplayer = *demo_p++;

	for (i = 0; i < MAXPLAYERS; i++)
		playeringame[i] = *demo_p++;

	G_InitNew(startskill, startmap);

	if (playeringame[1]) {
		netgame = true;
		netdemo = true;
	}

	precache = true;
	usergame = false;
	demoplayback = true;

	G_DoLoadLevel();
	D_MiniLoop(P_Start, P_Stop, P_Drawer, P_Ticker);
}

//
// G_CheckDemoStatus
// Called after a death or level completion to allow demos to be cleaned up
// Returns true if a new demo loop action will take place
//

dboolean G_CheckDemoStatus(void)
{
	int endtime;

	if (timingdemo) {
		endtime = I_GetTime();
		I_Error
		    ("G_CheckDemoStatus: timed %i gametics in %i realtics (%d FPS)",
		     gametic, endtime - starttime,
		     (gametic * TICRATE) / (endtime - starttime));
	}

	if (demoplayback) {
		if (singledemo)
			I_Quit();

		Z_Free(demobuffer);

		netdemo = false;
		netgame = false;
		deathmatch = false;
		playeringame[1] = playeringame[2] = playeringame[3] = 0;
		respawnparm = false;
		respawnitem = false;
		fastparm = false;
		nomonsters = false;
		consoleplayer = 0;
		gameaction = ga_exitdemo;

		G_ReloadDefaults();
		return true;
	}

	if (demorecording) {
		*demo_p++ = DEMOMARKER;
		M_WriteFile(demoname, demobuffer, demo_p - demobuffer);
		Z_Free(demobuffer);
		demorecording = false;
		I_Error("Demo %s recorded", demoname);
	}

	return false;
}
