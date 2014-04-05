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

#include "doomdef.h"
#include "gl_pixmap.h"
#include "m_fixed.h"
#include "z_zone.h"

#define PADWIDTH(x) (((x+3)>>2)<<2)
#define PADWIDTH2(x,a) (((x+a-1)/a)*a)

typedef struct {
	int pitch; // bytes per pixel
	GLenum gl;
	byte order[4];
} pixfmt_t;

pixfmt_t formats[DPM_PF_LAST] = {
	{ 0 },

	{ 3, GL_RGB, { 0, 1, 2 } },
	{ 3, GL_BGR, { 2, 1, 0 } },
	{ 4, GL_RGBA, { 0, 1, 2, 3 } },
	{ 4, GL_BGRA, { 2, 1, 0, 3 } }
};

static byte *PixmapByte(const dpixmap *pm, short x, short y)
{
	int pitch = formats[pm->fmt].pitch;
	size_t offset = pm->w * pitch;
	return pm->map + y * PADWIDTH(offset) + x * pitch;
}

//
// FilterNearest
//

#if 1
void FilterNearest(dpixmap *dst, const dpixmap *src)
{
	int i;
	int pitch;

	byte *src_ptr, *dst_ptr;
	int src_x, src_y;
	int dst_x, dst_y;

	fixed_t ratio_x, ratio_y;

	ratio_x = INT2F(src->w) / dst->w;
	ratio_y = INT2F(src->h) / dst->h;

	pitch = formats[src->fmt].pitch;

	for (dst_y = 0; dst_y < dst->h; dst_y++) {
		dst_ptr = GL_PixmapScanline(dst, dst_y);
		for (dst_x = 0; dst_x < dst->w; dst_x++) {
			src_x = F2INT(ratio_x * dst_x);
			src_y = F2INT(ratio_y * dst_y);

			src_ptr = PixmapByte(src, src_x, src_y);

			for (i = 0; i < pitch; i++)
				dst_ptr[i] = src_ptr[i];

			dst_ptr += pitch;
		}
	}
}
#endif

//
// FilterBox
//

void FilterBox(dpixmap *dst, const dpixmap *src)
{
	int i, j;
	int pitch;

	byte *src_ptr, *dst_ptr;
	int src_x, src_y;
	int dst_x, dst_y;
	int x, y;

	fixed_t ratio_x, ratio_y;

	ratio_x = INT2F(src->w) / dst->w;
	ratio_y = INT2F(src->h) / dst->h;

	if (!ratio_x || !ratio_y)
		return;

	pitch = formats[src->fmt].pitch;

	uint32 clr[pitch];

	for (dst_y = 0; dst_y < dst->h; dst_y++) {
		dst_ptr = GL_PixmapScanline(dst, dst_y);
		for (dst_x = 0; dst_x < dst->w; dst_x++) {

			dmemset(clr, 0, sizeof(clr));

			src_y = F2INT(ratio_y * dst_y);
			for (y = 0; y < F2INT(ratio_y); y++) {
				src_x = F2INT(ratio_x * dst_x);
				for (x = 0; x < F2INT(ratio_x); x++) {
					src_ptr = PixmapByte(src, src_x, src_y);
					for (i = 0; i < pitch; i++)
						clr[i] += src_ptr[i];
					src_x++;
				}
				src_y++;
			}

			for (i = 0; i < pitch; i++)
				dst_ptr[i] = clr[i] / (F2INT(ratio_x) * F2INT(ratio_y));

			dst_ptr += pitch;
		}
	}
}

//
// FilterLinear
//

// TODO: Implement linear filter.
#define FilterLinear FilterNearest

//
// PixmapResize
//

void PixmapResize(dpixmap *pm, short width, short height)
{
	size_t len;
	len = width * formats[pm->fmt].pitch;

	if (pm->w == width && pm->h == height) {
		return;
	}

	if (pm->map) {
		Z_Free(pm->map);
	}

	if (width && height) {
		pm->map = Z_Malloc(PADWIDTH(len) * height, PU_STATIC, NULL);
		pm->w = width;
		pm->h = height;
	} else {
		pm->map = NULL;
		pm->w = NULL;
		pm->h = NULL;
	}
}

//
// GL_PixmapCreate
//

dpixmap *GL_PixmapCreate(short width, short height, dpixfmt fmt, byte *data)
{
	size_t len;
	dpixmap *pm;

	if (fmt < 0 || fmt >= DPM_PF_LAST)
		return NULL;

	len = PADWIDTH(width * formats[fmt].pitch);

	pm = Z_Malloc(sizeof(*pm), PU_STATIC, NULL);
	pm->map = Z_Malloc(len * height, PU_STATIC, NULL);
	pm->fmt = fmt;
	pm->w = width;
	pm->h = height;

	if (data) {
		dmemcpy(pm->map, data, len * height);
	} else {
		dmemset(pm->map, 0, len * height);
	}

	return pm;
}

//
// GL_PixmapNull
//

dpixmap *GL_PixmapNull(dpixfmt fmt)
{
	dpixmap *pm;

	if (fmt < 0 || fmt >= DPM_PF_LAST)
		return NULL;

	pm = Z_Calloc(sizeof(*pm), PU_STATIC, NULL);
	pm->fmt = fmt;

	return pm;
}

//
// GL_PixmapCopy
//

dpixmap *GL_PixmapCopy(const dpixmap *pm)
{
	return GL_PixmapCreate(pm->w, pm->h, pm->fmt, pm->map);
}

//
// GL_PixmapConvert
//

dpixmap *GL_PixmapConvert(const dpixmap *src, dpixfmt fmt)
{
	if (src->fmt == fmt)
		return GL_PixmapCopy(src);

	int x, y, i;
	dpixmap *dst;
	byte *src_ptr, *dst_ptr;
	int src_pitch, dst_pitch;
	int src_order, dst_order;

	src_pitch = formats[src->fmt].pitch;
	dst_pitch = formats[fmt].pitch;

	dst = GL_PixmapNull(fmt);
	PixmapResize(dst, src->w, src->h);

	for (y = 0; y < src->h; y++) {
		src_ptr = GL_PixmapScanline(src, y);
		dst_ptr = GL_PixmapScanline(dst, y);
		for (x = 0; x < src->w; x++) {
			for (i = 0; i < src_pitch; i++) {
				src_order = formats[src->fmt].order[i];

				if (src_order > dst_pitch)
					continue;

				dst_order = formats[fmt].order[src_order];
				dst_ptr[dst_order] = src_ptr[src_order];
			}

			src_ptr += src_pitch;
			dst_ptr += dst_pitch;
		}
	}

	return dst;
}

//
// GL_PixmapFree
//

void GL_PixmapFree(dpixmap *pm)
{
	if (pm->map)
		Z_Free(pm->map);
	Z_Free(pm);
}

//
// GL_PixmapSetData
//

void GL_PixmapSetData(dpixmap *dst, int align, byte *data)
{
	int x, y;
	int pitch;
	byte *src_ptr, *dst_ptr;

	pitch = formats[dst->fmt].pitch;

	for (y = 0; y < dst->h; y++) {
		src_ptr = data + y * PADWIDTH2(dst->w * pitch, align);
		dst_ptr = GL_PixmapScanline(dst, y);
		for (x = 0; x < dst->w * pitch; x++) {
			*(dst_ptr++) = *(src_ptr++);
		}
	}
}

//
// GL_PixmapScanline
//

byte *GL_PixmapScanline(const dpixmap *pm, short y)
{
	size_t offset = pm->w * formats[pm->fmt].pitch;
	return pm->map + y * PADWIDTH(offset);
}

//
// _GL_PixmapFlipRotate
//

void _GL_PixmapFlipRotate(dpixmap **dst, const dpixmap *src, int flag)
{
	int i;

	int src_x, src_y;
	int dst_x, dst_y;
	int newwidth, newheight;

	int pitch;
	byte *src_ptr, *dst_ptr;

	dboolean free_src = false;

	if (!*dst) {
		*dst = GL_PixmapNull(src->fmt);
	} else if (!src || dst == src) {
		src = *dst;
		*dst = GL_PixmapNull(src->fmt);
		free_src = true;
	}

	pitch = formats[(*dst)->fmt].pitch;

	if (flag == DPM_ROT90 || flag == DPM_ROT270) {
		newwidth = src->h;
		newheight = src->w;
	} else {
		newwidth = src->w;
		newheight = src->h;
	}

	PixmapResize(dst, newwidth, newheight);

	for (dst_y = 0; dst_y < (*dst)->h; dst_y++) {
		dst_ptr = GL_PixmapScanline(dst, dst_y);
		for (dst_x = 0; dst_x < (*dst)->w; dst_x++) {
			if (flag == DPM_ROT90) {
				src_x = dst_y;
				src_y = (*dst)->w - dst_x - 1;
			} else if (flag == DPM_ROT270) {
				src_x = (*dst)->h - dst_y - 1;
				src_y = dst_x;
			} else if (flag == DPM_FLIPX) {
				src_x = (*dst)->w - dst_x - 1;
				src_y = dst_y;
			} else if (flag == DPM_FLIPY) {
				src_x = dst_x;
				src_y = (*dst)->h - dst_y - 1;
			} else if (flag == DPM_FLIPXY) {
				src_x = (*dst)->w - dst_x - 1;
				src_y = (*dst)->h - dst_y - 1;
			}

			src_ptr = PixmapByte(src, src_x, src_y);

			for (i = 0; i < pitch; i++)
				dst_ptr[i] = src_ptr[i];

			dst_ptr += pitch;
		}
	}

	if (free_src) {
		GL_PixmapFree(src);
	}
}

//
// GL_PixmapScale
//

void GL_PixmapScale(dpixmap **dst, const dpixmap *src, fixed_t scalex, fixed_t scaley)
{
	short newwidth, newheight;

	if (!src)
		src = *dst;

	newwidth = F2INT(src->w * scalex);
	newheight = F2INT(src->h * scaley);

	GL_PixmapScaleTo(dst, src, newwidth, newheight);
}

//
// GL_PixmapScaleTo
//

void GL_PixmapScaleTo(dpixmap **dst, const dpixmap *src, short width, short height)
{
	if (src && (src->w == width && src->h == height) ||
		(*dst && (*dst)->w == width && (*dst)->h == height)) {
		return;
	}

	dboolean free_src = false;
	if (!*dst) {
		*dst = GL_PixmapNull(src->fmt);
	} else if (!src || *dst == src) {
		src = *dst;
		*dst = GL_PixmapNull(src->fmt);

		free_src = true;
	}

	PixmapResize(*dst, width, height);
	if (!width || !height)
		return;

	if (src->w > (*dst)->w && src->h > (*dst)->h) {
		FilterBox(*dst, src);
	} else {
		FilterLinear(*dst, src);
	}

	if (free_src) {
		GL_PixmapFree(src);
	}
}

//
// GL_PixmapUpload
//

GLuint GL_PixmapUpload(const dpixmap *pm)
{
	GLuint tex;

	dglGenTextures(1, &tex);
	dglBindTexture(GL_TEXTURE_2D, tex);
	dglTexImage2D(GL_TEXTURE_2D, 0, formats[pm->fmt].gl,
				  pm->w, pm->h, 0, formats[pm->fmt].gl,
				  GL_UNSIGNED_BYTE, pm->map);

	return tex;
}
