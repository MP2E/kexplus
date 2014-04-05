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

#ifndef __GL_PIXMAP_H__
#define __GL_PIXMAP_H__

typedef enum {
	DPM_PFINVALID,

	DPM_PFRGB,
	DPM_PFBGR,
	DPM_PFRGBA,
	DPM_PFBGRA,

	DPM_PF_LAST
} dpixfmt;

enum {
	DPM_FLIPX = 0x1,
	DPM_FLIPY = 0x2,
	DPM_FLIPXY = 0x3,

	DPM_ROT90 = 0x4,
	DPM_ROT180 = DPM_FLIPXY,
	DPM_ROT270 = 0x5,
};

dpixmap *GL_PixmapCreate(short width, short height, dpixfmt fmt, byte *data);
dpixmap *GL_PixmapNull(dpixfmt fmt);
dpixmap *GL_PixmapCopy(const dpixmap *src);
dpixmap *GL_PixmapConvert(const dpixmap *src, dpixfmt fmt);
void GL_PixmapFree(dpixmap *pm);

void GL_PixmapSetData(dpixmap *dst, int align, byte *data);

byte *GL_PixmapScanline(const dpixmap *pm, short y);

//
// Transformations
//

void _GL_PixmapFlipRotate(dpixmap *dst, const dpixmap *src, int flag);

#define GL_PixmapFlip(dst, src, flag) _GL_PixmapFlipRotate(dst, src, flag)
#define GL_PixmapRotate(dst, src, flag) _GL_PixmapFlipRotate(dst, src, flag)

void GL_PixmapScale(dpixmap *dst, const dpixmap *src, fixed_t scalex, fixed_t scaley);
#define GL_PixmapScalef(dst, src, scalex, scaley) GL_PixmapScale(dst, src, FLOATTOFIXED(scalex), FLOATTOFIXED(scaley))
void GL_PixmapScaleTo(dpixmap *dst, const dpixmap *src, short width, short height);

GLuint GL_PixmapUpload(const dpixmap *pm);

#endif /* __GL_PIXMAP_H__ */
