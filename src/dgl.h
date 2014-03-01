// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
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

#ifndef __DGL_H__
#define __DGL_H__

#include <math.h>

#ifdef HAVE_GLES
#include <stddef.h>
#include "SDL_opengles.h"
// specific definitions for GLES
typedef  unsigned int GLhandleARB;
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;

#define GL_TEXTURE0_ARB	GL_TEXTURE0
#define GL_TEXTURE1_ARB	GL_TEXTURE1
#define GL_TEXTURE2_ARB	GL_TEXTURE2
#define GL_TEXTURE3_ARB	GL_TEXTURE3
#define GL_MAX_TEXTURE_UNITS_ARB	GL_MAX_TEXTURE_UNITS

#define GL_SOURCE0_RGB		GL_SRC0_RGB
#define GL_SOURCE1_RGB		GL_SRC1_RGB
#define GL_SOURCE2_RGB		GL_SRC2_RGB
#define GL_SOURCE3_RGB		GL_SRC3_RGB
#define GL_SOURCE0_ALPHA	GL_SRC0_ALPHA
#define GL_SOURCE1_ALPHA	GL_SRC1_ALPHA
#define GL_SOURCE2_ALPHA	GL_SRC2_ALPHA
#define GL_SOURCE3_ALPHA	GL_SRC3_ALPHA

#define GL_COMBINE_ARB	GL_COMBINE

#define GL_MIRRORED_REPEAT	GL_MIRRORED_REPEAT_OES

#define GL_RGBA8	GL_RGBA
#define GL_RGB8		GL_RGB

#define GL_CLAMP	GL_CLAMP_TO_EDGE

#define APIENTRYP	GL_APIENTRYP
#define GLdouble	double

typedef void (APIENTRYP PFNGLACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DARBPROC) (GLenum target, GLdouble s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FARBPROC) (GLenum target, GLfloat s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IARBPROC) (GLenum target, GLint s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVARBPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SARBPROC) (GLenum target, GLshort s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVARBPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DARBPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FARBPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IARBPROC) (GLenum target, GLint s, GLint t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVARBPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SARBPROC) (GLenum target, GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVARBPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IARBPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVARBPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVARBPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IARBPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVARBPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVARBPROC) (GLenum target, const GLshort *v);

typedef void (APIENTRYP PFNGLLOCKARRAYSEXTPROC) (GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLUNLOCKARRAYSEXTPROC) (void);

typedef void (APIENTRYP PFNGLFOGCOORDFEXTPROC) (GLfloat coord);
typedef void (APIENTRYP PFNGLFOGCOORDFVEXTPROC) (const GLfloat *coord);
typedef void (APIENTRYP PFNGLFOGCOORDDEXTPROC) (GLdouble coord);
typedef void (APIENTRYP PFNGLFOGCOORDDVEXTPROC) (const GLdouble *coord);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid *pointer);

typedef void (APIENTRYP PFNGLBINDBUFFERARBPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSARBPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSARBPROC) (GLsizei n, GLuint *buffers);
typedef GLboolean (APIENTRYP PFNGLISBUFFERARBPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAARBPROC) (GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
typedef GLvoid* (APIENTRYP PFNGLMAPBUFFERARBPROC) (GLenum target, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERARBPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVARBPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVARBPROC) (GLenum target, GLenum pname, GLvoid* *params);

#else
#include "SDL_opengl.h"
#endif
#include "gl_main.h"
#include "i_system.h"

//#define LOG_GLFUNC_CALLS
//#define USE_DEBUG_GLFUNCS

#ifdef USE_DEBUG_GLFUNCS
void dglLogError(const char *message, const char *file, int line);
#endif

#define dglGetString(name)  glGetString(name)

//
// CUSTOM ROUTINES
//

extern void dglSetVertex(vtx_t * vtx);
extern void dglTriangle(int v0, int v1, int v2);
extern void dglDrawGeometry(dword count, vtx_t * vtx);
extern void dglViewFrustum(int width, int height, rfloat fovy, rfloat znear);
extern void dglSetVertexColor(vtx_t * v, rcolor c, word count);
extern void dglGetColorf(rcolor color, float *argb);
extern void dglTexCombReplace(void);
extern void dglTexCombColor(int t, rcolor c, int func);
extern void dglTexCombColorf(int t, float *f, int func);
extern void dglTexCombModulate(int t, int s);
extern void dglTexCombAdd(int t, int s);
extern void dglTexCombInterpolate(int t, float a);
extern void dglTexCombReplaceAlpha(int t);

//
// Generated by dglmake
//
#ifndef USE_DEBUG_GLFUNCS

#define dglAccum(op, value) glAccum(op, value)
#define dglAlphaFunc(func, ref) glAlphaFunc(func, ref)
#define dglAreTexturesResident(n, textures, residences) glAreTexturesResident(n, textures, residences)
#define dglArrayElement(i) glArrayElement(i)
#define dglBegin(mode) glBegin(mode)
#define dglBindTexture(target, texture) glBindTexture(target, texture)
#define dglBitmap(width, height, xorig, yorig, xmove, ymove, bitmap) glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap)
#define dglBlendFunc(sfactor, dfactor) glBlendFunc(sfactor, dfactor)
#define dglCallList(list) glCallList(list)
#define dglCallLists(n, type, lists) glCallLists(n, type, lists)
#define dglClear(mask) glClear(mask)
#define dglClearAccum(red, green, blue, alpha) glClearAccum(red, green, blue, alpha)
#define dglClearColor(red, green, blue, alpha) glClearColor(red, green, blue, alpha)
#ifdef HAVE_GLES
#define dglClearDepth(depth) glClearDepthf(depth)
#else
#define dglClearDepth(depth) glClearDepth(depth)
#endif
#define dglClearIndex(c) glClearIndex(c)
#define dglClearStencil(s) glClearStencil(s)
#define dglClipPlane(plane, equation) glClipPlane(plane, equation)
#define dglColor3b(red, green, blue) glColor3b(red, green, blue)
#define dglColor3bv(v) glColor3bv(v)
#define dglColor3d(red, green, blue) glColor3d(red, green, blue)
#define dglColor3dv(v) glColor3dv(v)
#define dglColor3f(red, green, blue) glColor3f(red, green, blue)
#define dglColor3fv(v) glColor3fv(v)
#define dglColor3i(red, green, blue) glColor3i(red, green, blue)
#define dglColor3iv(v) glColor3iv(v)
#define dglColor3s(red, green, blue) glColor3s(red, green, blue)
#define dglColor3sv(v) glColor3sv(v)
#define dglColor3ub(red, green, blue) glColor3ub(red, green, blue)
#define dglColor3ubv(v) glColor3ubv(v)
#define dglColor3ui(red, green, blue) glColor3ui(red, green, blue)
#define dglColor3uiv(v) glColor3uiv(v)
#define dglColor3us(red, green, blue) glColor3us(red, green, blue)
#define dglColor3usv(v) glColor3usv(v)
#define dglColor4b(red, green, blue, alpha) glColor4b(red, green, blue, alpha)
#define dglColor4bv(v) glColor4bv(v)
#define dglColor4d(red, green, blue, alpha) glColor4d(red, green, blue, alpha)
#define dglColor4dv(v) glColor4dv(v)
#define dglColor4f(red, green, blue, alpha) glColor4f(red, green, blue, alpha)
#define dglColor4fv(v) glColor4fv(v)
#define dglColor4i(red, green, blue, alpha) glColor4i(red, green, blue, alpha)
#define dglColor4iv(v) glColor4iv(v)
#define dglColor4s(red, green, blue, alpha) glColor4s(red, green, blue, alpha)
#define dglColor4sv(v) glColor4sv(v)
#define dglColor4ub(red, green, blue, alpha) glColor4ub(red, green, blue, alpha)
#ifdef HAVE_GLES
#define dglColor4ubv(v) glColor4ub((v)[0], (v)[1], (v)[2], (v)[3])
#else
#define dglColor4ubv(v) glColor4ubv(v)
#endif
#define dglColor4ui(red, green, blue, alpha) glColor4ui(red, green, blue, alpha)
#define dglColor4uiv(v) glColor4uiv(v)
#define dglColor4us(red, green, blue, alpha) glColor4us(red, green, blue, alpha)
#define dglColor4usv(v) glColor4usv(v)
#define dglColorMask(red, green, blue, alpha) glColorMask(red, green, blue, alpha)
#define dglColorMaterial(face, mode) glColorMaterial(face, mode)
#define dglColorPointer(size, type, stride, pointer) glColorPointer(size, type, stride, pointer)
#define dglCopyPixels(x, y, width, height, type) glCopyPixels(x, y, width, height, type)
#define dglCopyTexImage1D(target, level, internalFormat, x, y, width, border) glCopyTexImage1D(target, level, internalFormat, x, y, width, border)
#define dglCopyTexImage2D(target, level, internalFormat, x, y, width, height, border) glCopyTexImage2D(target, level, internalFormat, x, y, width, height, border)
#define dglCopyTexSubImage1D(target, level, xoffset, x, y, width) glCopyTexSubImage1D(target, level, xoffset, x, y, width)
#define dglCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height) glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height)
#define dglCullFace(mode) glCullFace(mode)
#define dglDeleteLists(list, range) glDeleteLists(list, range)
#define dglDeleteTextures(n, textures) glDeleteTextures(n, textures)
#define dglDepthFunc(func) glDepthFunc(func)
#define dglDepthMask(flag) glDepthMask(flag)
#ifdef HAVE_GLES
#define dglDepthRange(zNear, zFar) glDepthRangef(zNear, zFar)
#else
#define dglDepthRange(zNear, zFar) glDepthRange(zNear, zFar)
#endif
#define dglDisable(cap) glDisable(cap)
#define dglDisableClientState(array) glDisableClientState(array)
#define dglDrawArrays(mode, first, count) glDrawArrays(mode, first, count)
#define dglDrawBuffer(mode) glDrawBuffer(mode)
#define dglDrawElements(mode, count, type, indices) glDrawElements(mode, count, type, indices)
#define dglDrawPixels(width, height, format, type, pixels) glDrawPixels(width, height, format, type, pixels)
#define dglEdgeFlag(flag) glEdgeFlag(flag)
#define dglEdgeFlagPointer(stride, pointer) glEdgeFlagPointer(stride, pointer)
#define dglEdgeFlagv(flag) glEdgeFlagv(flag)
#define dglEnable(cap) glEnable(cap)
#define dglEnableClientState(array) glEnableClientState(array)
#define dglEnd() glEnd()
#define dglEndList() glEndList()
#define dglEvalCoord1d(u) glEvalCoord1d(u)
#define dglEvalCoord1dv(u) glEvalCoord1dv(u)
#define dglEvalCoord1f(u) glEvalCoord1f(u)
#define dglEvalCoord1fv(u) glEvalCoord1fv(u)
#define dglEvalCoord2d(u, v) glEvalCoord2d(u, v)
#define dglEvalCoord2dv(u) glEvalCoord2dv(u)
#define dglEvalCoord2f(u, v) glEvalCoord2f(u, v)
#define dglEvalCoord2fv(u) glEvalCoord2fv(u)
#define dglEvalMesh1(mode, i1, i2) glEvalMesh1(mode, i1, i2)
#define dglEvalMesh2(mode, i1, i2, j1, j2) glEvalMesh2(mode, i1, i2, j1, j2)
#define dglEvalPoint1(i) glEvalPoint1(i)
#define dglEvalPoint2(i, j) glEvalPoint2(i, j)
#define dglFeedbackBuffer(size, type, buffer) glFeedbackBuffer(size, type, buffer)
#define dglFinish() glFinish()
#define dglFlush() glFlush()
#define dglFogf(pname, param) glFogf(pname, param)
#define dglFogfv(pname, params) glFogfv(pname, params)
#ifdef HAVE_GLES
#define dglFogi(pname, param) glFogf(pname, param)
#else
#define dglFogi(pname, param) glFogi(pname, param)
#endif
#define dglFogiv(pname, params) glFogiv(pname, params)
#define dglFrontFace(mode) glFrontFace(mode)
#define dglFrustum(left, right, bottom, top, zNear, zFar) glFrustum(left, right, bottom, top, zNear, zFar)
#define dglGenLists(range) glGenLists(range)
#define dglGenTextures(n, textures) glGenTextures(n, textures)
#define dglGetBooleanv(pname, params) glGetBooleanv(pname, params)
#define dglGetClipPlane(plane, equation) glGetClipPlane(plane, equation)
#define dglGetDoublev(pname, params) glGetDoublev(pname, params)
#define dglGetError() glGetError()
#define dglGetFloatv(pname, params) glGetFloatv(pname, params)
#define dglGetIntegerv(pname, params) glGetIntegerv(pname, params)
#define dglGetLightfv(light, pname, params) glGetLightfv(light, pname, params)
#define dglGetLightiv(light, pname, params) glGetLightiv(light, pname, params)
#define dglGetMapdv(target, query, v) glGetMapdv(target, query, v)
#define dglGetMapfv(target, query, v) glGetMapfv(target, query, v)
#define dglGetMapiv(target, query, v) glGetMapiv(target, query, v)
#define dglGetMaterialfv(face, pname, params) glGetMaterialfv(face, pname, params)
#define dglGetMaterialiv(face, pname, params) glGetMaterialiv(face, pname, params)
#define dglGetPixelMapfv(map, values) glGetPixelMapfv(map, values)
#define dglGetPixelMapuiv(map, values) glGetPixelMapuiv(map, values)
#define dglGetPixelMapusv(map, values) glGetPixelMapusv(map, values)
#define dglGetPointerv(pname, params) glGetPointerv(pname, params)
#define dglGetPolygonStipple(mask) glGetPolygonStipple(mask)
#define dglGetTexEnvfv(target, pname, params) glGetTexEnvfv(target, pname, params)
#define dglGetTexEnviv(target, pname, params) glGetTexEnviv(target, pname, params)
#define dglGetTexGendv(coord, pname, params) glGetTexGendv(coord, pname, params)
#define dglGetTexGenfv(coord, pname, params) glGetTexGenfv(coord, pname, params)
#define dglGetTexGeniv(coord, pname, params) glGetTexGeniv(coord, pname, params)
#define dglGetTexImage(target, level, format, type, pixels) glGetTexImage(target, level, format, type, pixels)
#define dglGetTexLevelParameterfv(target, level, pname, params) glGetTexLevelParameterfv(target, level, pname, params)
#define dglGetTexLevelParameteriv(target, level, pname, params) glGetTexLevelParameteriv(target, level, pname, params)
#define dglGetTexParameterfv(target, pname, params) glGetTexParameterfv(target, pname, params)
#define dglGetTexParameteriv(target, pname, params) glGetTexParameteriv(target, pname, params)
#define dglHint(target, mode) glHint(target, mode)
#define dglIndexMask(mask) glIndexMask(mask)
#define dglIndexPointer(type, stride, pointer) glIndexPointer(type, stride, pointer)
#define dglIndexd(c) glIndexd(c)
#define dglIndexdv(c) glIndexdv(c)
#define dglIndexf(c) glIndexf(c)
#define dglIndexfv(c) glIndexfv(c)
#define dglIndexi(c) glIndexi(c)
#define dglIndexiv(c) glIndexiv(c)
#define dglIndexs(c) glIndexs(c)
#define dglIndexsv(c) glIndexsv(c)
#define dglIndexub(c) glIndexub(c)
#define dglIndexubv(c) glIndexubv(c)
#define dglInitNames() glInitNames()
#define dglInterleavedArrays(format, stride, pointer) glInterleavedArrays(format, stride, pointer)
#define dglIsEnabled(cap) glIsEnabled(cap)
#define dglIsList(list) glIsList(list)
#define dglIsTexture(texture) glIsTexture(texture)
#define dglLightModelf(pname, param) glLightModelf(pname, param)
#define dglLightModelfv(pname, params) glLightModelfv(pname, params)
#define dglLightModeli(pname, param) glLightModeli(pname, param)
#define dglLightModeliv(pname, params) glLightModeliv(pname, params)
#define dglLightf(light, pname, param) glLightf(light, pname, param)
#define dglLightfv(light, pname, params) glLightfv(light, pname, params)
#define dglLighti(light, pname, param) glLighti(light, pname, param)
#define dglLightiv(light, pname, params) glLightiv(light, pname, params)
#define dglLineStipple(factor, pattern) glLineStipple(factor, pattern)
#define dglLineWidth(width) glLineWidth(width)
#define dglListBase(base) glListBase(base)
#define dglLoadIdentity() glLoadIdentity()
#define dglLoadMatrixd(m) glLoadMatrixd(m)
#define dglLoadMatrixf(m) glLoadMatrixf(m)
#define dglLoadName(name) glLoadName(name)
#define dglLogicOp(opcode) glLogicOp(opcode)
#define dglMap1d(target, u1, u2, stride, order, points) glMap1d(target, u1, u2, stride, order, points)
#define dglMap1f(target, u1, u2, stride, order, points) glMap1f(target, u1, u2, stride, order, points)
#define dglMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points)
#define dglMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points)
#define dglMapGrid1d(un, u1, u2) glMapGrid1d(un, u1, u2)
#define dglMapGrid1f(un, u1, u2) glMapGrid1f(un, u1, u2)
#define dglMapGrid2d(un, u1, u2, vn, v1, v2) glMapGrid2d(un, u1, u2, vn, v1, v2)
#define dglMapGrid2f(un, u1, u2, vn, v1, v2) glMapGrid2f(un, u1, u2, vn, v1, v2)
#define dglMaterialf(face, pname, param) glMaterialf(face, pname, param)
#define dglMaterialfv(face, pname, params) glMaterialfv(face, pname, params)
#define dglMateriali(face, pname, param) glMateriali(face, pname, param)
#define dglMaterialiv(face, pname, params) glMaterialiv(face, pname, params)
#define dglMatrixMode(mode) glMatrixMode(mode)
#define dglMultMatrixd(m) glMultMatrixd(m)
#define dglMultMatrixf(m) glMultMatrixf(m)
#define dglNewList(list, mode) glNewList(list, mode)
#define dglNormal3b(nx, ny, nz) glNormal3b(nx, ny, nz)
#define dglNormal3bv(v) glNormal3bv(v)
#define dglNormal3d(nx, ny, nz) glNormal3d(nx, ny, nz)
#define dglNormal3dv(v) glNormal3dv(v)
#define dglNormal3f(nx, ny, nz) glNormal3f(nx, ny, nz)
#define dglNormal3fv(v) glNormal3fv(v)
#define dglNormal3i(nx, ny, nz) glNormal3i(nx, ny, nz)
#define dglNormal3iv(v) glNormal3iv(v)
#define dglNormal3s(nx, ny, nz) glNormal3s(nx, ny, nz)
#define dglNormal3sv(v) glNormal3sv(v)
#define dglNormalPointer(type, stride, pointer) glNormalPointer(type, stride, pointer)
#ifdef HAVE_GLES
#define dglOrtho(left, right, bottom, top, zNear, zFar) glOrthof(left, right, bottom, top, zNear, zFar)
#else
#define dglOrtho(left, right, bottom, top, zNear, zFar) glOrtho(left, right, bottom, top, zNear, zFar)
#endif
#define dglPassThrough(token) glPassThrough(token)
#define dglPixelMapfv(map, mapsize, values) glPixelMapfv(map, mapsize, values)
#define dglPixelMapuiv(map, mapsize, values) glPixelMapuiv(map, mapsize, values)
#define dglPixelMapusv(map, mapsize, values) glPixelMapusv(map, mapsize, values)
#define dglPixelStoref(pname, param) glPixelStoref(pname, param)
#define dglPixelStorei(pname, param) glPixelStorei(pname, param)
#define dglPixelTransferf(pname, param) glPixelTransferf(pname, param)
#define dglPixelTransferi(pname, param) glPixelTransferi(pname, param)
#define dglPixelZoom(xfactor, yfactor) glPixelZoom(xfactor, yfactor)
#define dglPointSize(size) glPointSize(size)
#define dglPolygonMode(face, mode) glPolygonMode(face, mode)
#define dglPolygonOffset(factor, units) glPolygonOffset(factor, units)
#define dglPolygonStipple(mask) glPolygonStipple(mask)
#define dglPopAttrib() glPopAttrib()
#define dglPopClientAttrib() glPopClientAttrib()
#define dglPopMatrix() glPopMatrix()
#define dglPopName() glPopName()
#define dglPrioritizeTextures(n, textures, priorities) glPrioritizeTextures(n, textures, priorities)
#define dglPushAttrib(mask) glPushAttrib(mask)
#define dglPushClientAttrib(mask) glPushClientAttrib(mask)
#define dglPushMatrix() glPushMatrix()
#define dglPushName(name) glPushName(name)
#define dglRasterPos2d(x, y) glRasterPos2d(x, y)
#define dglRasterPos2dv(v) glRasterPos2dv(v)
#define dglRasterPos2f(x, y) glRasterPos2f(x, y)
#define dglRasterPos2fv(v) glRasterPos2fv(v)
#define dglRasterPos2i(x, y) glRasterPos2i(x, y)
#define dglRasterPos2iv(v) glRasterPos2iv(v)
#define dglRasterPos2s(x, y) glRasterPos2s(x, y)
#define dglRasterPos2sv(v) glRasterPos2sv(v)
#define dglRasterPos3d(x, y, z) glRasterPos3d(x, y, z)
#define dglRasterPos3dv(v) glRasterPos3dv(v)
#define dglRasterPos3f(x, y, z) glRasterPos3f(x, y, z)
#define dglRasterPos3fv(v) glRasterPos3fv(v)
#define dglRasterPos3i(x, y, z) glRasterPos3i(x, y, z)
#define dglRasterPos3iv(v) glRasterPos3iv(v)
#define dglRasterPos3s(x, y, z) glRasterPos3s(x, y, z)
#define dglRasterPos3sv(v) glRasterPos3sv(v)
#define dglRasterPos4d(x, y, z, w) glRasterPos4d(x, y, z, w)
#define dglRasterPos4dv(v) glRasterPos4dv(v)
#define dglRasterPos4f(x, y, z, w) glRasterPos4f(x, y, z, w)
#define dglRasterPos4fv(v) glRasterPos4fv(v)
#define dglRasterPos4i(x, y, z, w) glRasterPos4i(x, y, z, w)
#define dglRasterPos4iv(v) glRasterPos4iv(v)
#define dglRasterPos4s(x, y, z, w) glRasterPos4s(x, y, z, w)
#define dglRasterPos4sv(v) glRasterPos4sv(v)
#define dglReadBuffer(mode) glReadBuffer(mode)
#define dglReadPixels(x, y, width, height, format, type, pixels) glReadPixels(x, y, width, height, format, type, pixels)
#define dglRectd(x1, y1, x2, y2) glRectd(x1, y1, x2, y2)
#define dglRectdv(v1, v2) glRectdv(v1, v2)
#define dglRectf(x1, y1, x2, y2) glRectf(x1, y1, x2, y2)
#define dglRectfv(v1, v2) glRectfv(v1, v2)
#ifndef HAVE_GLES
#define dglRecti(x1, y1, x2, y2) glRecti(x1, y1, x2, y2)
#endif
#define dglRectiv(v1, v2) glRectiv(v1, v2)
#define dglRects(x1, y1, x2, y2) glRects(x1, y1, x2, y2)
#define dglRectsv(v1, v2) glRectsv(v1, v2)
#define dglRenderMode(mode) glRenderMode(mode)
#define dglRotated(angle, x, y, z) glRotated(angle, x, y, z)
#define dglRotatef(angle, x, y, z) glRotatef(angle, x, y, z)
#define dglScaled(x, y, z) glScaled(x, y, z)
#define dglScalef(x, y, z) glScalef(x, y, z)
#define dglScissor(x, y, width, height) glScissor(x, y, width, height)
#define dglSelectBuffer(size, buffer) glSelectBuffer(size, buffer)
#define dglShadeModel(mode) glShadeModel(mode)
#define dglStencilFunc(func, ref, mask) glStencilFunc(func, ref, mask)
#define dglStencilMask(mask) glStencilMask(mask)
#define dglStencilOp(fail, zfail, zpass) glStencilOp(fail, zfail, zpass)
#define dglTexCoord1d(s) glTexCoord1d(s)
#define dglTexCoord1dv(v) glTexCoord1dv(v)
#define dglTexCoord1f(s) glTexCoord1f(s)
#define dglTexCoord1fv(v) glTexCoord1fv(v)
#define dglTexCoord1i(s) glTexCoord1i(s)
#define dglTexCoord1iv(v) glTexCoord1iv(v)
#define dglTexCoord1s(s) glTexCoord1s(s)
#define dglTexCoord1sv(v) glTexCoord1sv(v)
#define dglTexCoord2d(s, t) glTexCoord2d(s, t)
#define dglTexCoord2dv(v) glTexCoord2dv(v)
#define dglTexCoord2f(s, t) glTexCoord2f(s, t)
#define dglTexCoord2fv(v) glTexCoord2fv(v)
#define dglTexCoord2i(s, t) glTexCoord2i(s, t)
#define dglTexCoord2iv(v) glTexCoord2iv(v)
#define dglTexCoord2s(s, t) glTexCoord2s(s, t)
#define dglTexCoord2sv(v) glTexCoord2sv(v)
#define dglTexCoord3d(s, t, r) glTexCoord3d(s, t, r)
#define dglTexCoord3dv(v) glTexCoord3dv(v)
#define dglTexCoord3f(s, t, r) glTexCoord3f(s, t, r)
#define dglTexCoord3fv(v) glTexCoord3fv(v)
#define dglTexCoord3i(s, t, r) glTexCoord3i(s, t, r)
#define dglTexCoord3iv(v) glTexCoord3iv(v)
#define dglTexCoord3s(s, t, r) glTexCoord3s(s, t, r)
#define dglTexCoord3sv(v) glTexCoord3sv(v)
#define dglTexCoord4d(s, t, r, q) glTexCoord4d(s, t, r, q)
#define dglTexCoord4dv(v) glTexCoord4dv(v)
#define dglTexCoord4f(s, t, r, q) glTexCoord4f(s, t, r, q)
#define dglTexCoord4fv(v) glTexCoord4fv(v)
#define dglTexCoord4i(s, t, r, q) glTexCoord4i(s, t, r, q)
#define dglTexCoord4iv(v) glTexCoord4iv(v)
#define dglTexCoord4s(s, t, r, q) glTexCoord4s(s, t, r, q)
#define dglTexCoord4sv(v) glTexCoord4sv(v)
#define dglTexCoordPointer(size, type, stride, pointer) glTexCoordPointer(size, type, stride, pointer)
#define dglTexEnvf(target, pname, param) glTexEnvf(target, pname, param)
#define dglTexEnvfv(target, pname, params) glTexEnvfv(target, pname, params)
#define dglTexEnvi(target, pname, param) glTexEnvi(target, pname, param)
#define dglTexEnviv(target, pname, params) glTexEnviv(target, pname, params)
#define dglTexGend(coord, pname, param) glTexGend(coord, pname, param)
#define dglTexGendv(coord, pname, params) glTexGendv(coord, pname, params)
#define dglTexGenf(coord, pname, param) glTexGenf(coord, pname, param)
#define dglTexGenfv(coord, pname, params) glTexGenfv(coord, pname, params)
#define dglTexGeni(coord, pname, param) glTexGeni(coord, pname, param)
#define dglTexGeniv(coord, pname, params) glTexGeniv(coord, pname, params)
#define dglTexImage1D(target, level, internalformat, width, border, format, type, pixels) glTexImage1D(target, level, internalformat, width, border, format, type, pixels)
#define dglTexImage2D(target, level, internalformat, width, height, border, format, type, pixels) glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels)
#define dglTexParameterf(target, pname, param) glTexParameterf(target, pname, param)
#define dglTexParameterfv(target, pname, params) glTexParameterfv(target, pname, params)
#define dglTexParameteri(target, pname, param) glTexParameteri(target, pname, param)
#define dglTexParameteriv(target, pname, params) glTexParameteriv(target, pname, params)
#define dglTexSubImage1D(target, level, xoffset, width, format, type, pixels) glTexSubImage1D(target, level, xoffset, width, format, type, pixels)
#define dglTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels) glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels)
#ifdef HAVE_GLES
#define dglTranslated(x, y, z) glTranslatef(x, y, z)
#else
#define dglTranslated(x, y, z) glTranslated(x, y, z)
#endif
#define dglTranslatef(x, y, z) glTranslatef(x, y, z)
#define dglVertex2d(x, y) glVertex2d(x, y)
#define dglVertex2dv(v) glVertex2dv(v)
#define dglVertex2f(x, y) glVertex2f(x, y)
#define dglVertex2fv(v) glVertex2fv(v)
#define dglVertex2i(x, y) glVertex2i(x, y)
#define dglVertex2iv(v) glVertex2iv(v)
#define dglVertex2s(x, y) glVertex2s(x, y)
#define dglVertex2sv(v) glVertex2sv(v)
#define dglVertex3d(x, y, z) glVertex3d(x, y, z)
#define dglVertex3dv(v) glVertex3dv(v)
#define dglVertex3f(x, y, z) glVertex3f(x, y, z)
#define dglVertex3fv(v) glVertex3fv(v)
#define dglVertex3i(x, y, z) glVertex3i(x, y, z)
#define dglVertex3iv(v) glVertex3iv(v)
#define dglVertex3s(x, y, z) glVertex3s(x, y, z)
#define dglVertex3sv(v) glVertex3sv(v)
#define dglVertex4d(x, y, z, w) glVertex4d(x, y, z, w)
#define dglVertex4dv(v) glVertex4dv(v)
#define dglVertex4f(x, y, z, w) glVertex4f(x, y, z, w)
#define dglVertex4fv(v) glVertex4fv(v)
#define dglVertex4i(x, y, z, w) glVertex4i(x, y, z, w)
#define dglVertex4iv(v) glVertex4iv(v)
#define dglVertex4s(x, y, z, w) glVertex4s(x, y, z, w)
#define dglVertex4sv(v) glVertex4sv(v)
#define dglVertexPointer(size, type, stride, pointer) glVertexPointer(size, type, stride, pointer)
#define dglViewport(x, y, width, height) glViewport(x, y, width, height)

#else

d_inline static void glAccum_DEBUG(GLenum op, GLfloat value, const char *file,
				   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glAccum(op=0x%x, value=%f)\n", file,
		 line, op, value);
#endif
	glAccum(op, value);
	dglLogError("glAccum", file, line);
}

d_inline static void glAlphaFunc_DEBUG(GLenum func, GLclampf ref,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glAlphaFunc(func=0x%x, ref=%f)\n", file,
		 line, func, ref);
#endif
	glAlphaFunc(func, ref);
	dglLogError("glAlphaFunc", file, line);
}

d_inline static GLboolean glAreTexturesResident_DEBUG(GLsizei n,
						      GLuint * textures,
						      GLboolean * residences,
						      const char *file,
						      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glAreTexturesResident(n=0x%x, textures=%p, residences=%p)\n",
	     file, line, n, textures, residences);
#endif
	glAreTexturesResident(n, textures, residences);
	dglLogError("glAreTexturesResident", file, line);
}

d_inline static void glArrayElement_DEBUG(GLint i, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glArrayElement(i=%i)\n", file, line, i);
#endif
	glArrayElement(i);
	dglLogError("glArrayElement", file, line);
}

d_inline static void glBegin_DEBUG(GLenum mode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glBegin(mode=0x%x)\n", file, line,
		 mode);
#endif
	glBegin(mode);
}

d_inline static void glBindTexture_DEBUG(GLenum target, GLuint texture,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glBindTexture(target=0x%x, texture=%i)\n",
	     file, line, target, texture);
#endif
	glBindTexture(target, texture);
	dglLogError("glBindTexture", file, line);
}

d_inline static void glBitmap_DEBUG(GLsizei width, GLsizei height,
				    GLfloat xorig, GLfloat yorig, GLfloat xmove,
				    GLfloat ymove, GLubyte * bitmap,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glBitmap(width=0x%x, height=0x%x, xorig=%f, yorig=%f, xmove=%f, ymove=%f, bitmap=%p)\n",
	     file, line, width, height, xorig, yorig, xmove, ymove, bitmap);
#endif
	glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
	dglLogError("glBitmap", file, line);
}

d_inline static void glBlendFunc_DEBUG(GLenum sfactor, GLenum dfactor,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glBlendFunc(sfactor=0x%x, dfactor=0x%x)\n",
	     file, line, sfactor, dfactor);
#endif
	glBlendFunc(sfactor, dfactor);
	dglLogError("glBlendFunc", file, line);
}

d_inline static void glCallList_DEBUG(GLuint list, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glCallList(list=%i)\n", file, line,
		 list);
#endif
	glCallList(list);
	dglLogError("glCallList", file, line);
}

d_inline static void glCallLists_DEBUG(GLsizei n, GLenum type, GLvoid * lists,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glCallLists(n=0x%x, type=0x%x, lists=%p)\n",
	     file, line, n, type, lists);
#endif
	glCallLists(n, type, lists);
	dglLogError("glCallLists", file, line);
}

d_inline static void glClear_DEBUG(GLbitfield mask, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glClear(mask=0x%x)\n", file, line,
		 mask);
#endif
	glClear(mask);
	dglLogError("glClear", file, line);
}

d_inline static void glClearAccum_DEBUG(GLfloat red, GLfloat green,
					GLfloat blue, GLfloat alpha,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glClearAccum(red=%f, green=%f, blue=%f, alpha=%f)\n",
	     file, line, red, green, blue, alpha);
#endif
	glClearAccum(red, green, blue, alpha);
	dglLogError("glClearAccum", file, line);
}

d_inline static void glClearColor_DEBUG(GLclampf red, GLclampf green,
					GLclampf blue, GLclampf alpha,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glClearColor(red=%f, green=%f, blue=%f, alpha=%f)\n",
	     file, line, red, green, blue, alpha);
#endif
	glClearColor(red, green, blue, alpha);
	dglLogError("glClearColor", file, line);
}

d_inline static void glClearDepth_DEBUG(GLclampd depth, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glClearDepth(depth=%f)\n", file, line,
		 depth);
#endif
#ifdef HAVE_GLES
	glClearDepthf(depth);
#else
	glClearDepth(depth);
#endif
	dglLogError("glClearDepth", file, line);
}

d_inline static void glClearIndex_DEBUG(GLfloat c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glClearIndex(c=%f)\n", file, line, c);
#endif
	glClearIndex(c);
	dglLogError("glClearIndex", file, line);
}

d_inline static void glClearStencil_DEBUG(GLint s, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glClearStencil(s=%i)\n", file, line, s);
#endif
	glClearStencil(s);
	dglLogError("glClearStencil", file, line);
}

d_inline static void glClipPlane_DEBUG(GLenum plane, GLdouble * equation,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glClipPlane(plane=0x%x, equation=%p)\n",
		 file, line, plane, equation);
#endif
	glClipPlane(plane, equation);
	dglLogError("glClipPlane", file, line);
}

d_inline static void glColor3b_DEBUG(GLbyte red, GLbyte green, GLbyte blue,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3b(red=%i, green=%i, blue=%i)\n",
		 file, line, red, green, blue);
#endif
	glColor3b(red, green, blue);
	dglLogError("glColor3b", file, line);
}

d_inline static void glColor3bv_DEBUG(GLbyte * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3bv(v=%p)\n", file, line, v);
#endif
	glColor3bv(v);
	dglLogError("glColor3bv", file, line);
}

d_inline static void glColor3d_DEBUG(GLdouble red, GLdouble green,
				     GLdouble blue, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3d(red=%f, green=%f, blue=%f)\n",
		 file, line, red, green, blue);
#endif
	glColor3d(red, green, blue);
	dglLogError("glColor3d", file, line);
}

d_inline static void glColor3dv_DEBUG(GLdouble * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3dv(v=%p)\n", file, line, v);
#endif
	glColor3dv(v);
	dglLogError("glColor3dv", file, line);
}

d_inline static void glColor3f_DEBUG(GLfloat red, GLfloat green, GLfloat blue,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3f(red=%f, green=%f, blue=%f)\n",
		 file, line, red, green, blue);
#endif
	glColor3f(red, green, blue);
	dglLogError("glColor3f", file, line);
}

d_inline static void glColor3fv_DEBUG(GLfloat * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3fv(v=%p)\n", file, line, v);
#endif
	glColor3fv(v);
	dglLogError("glColor3fv", file, line);
}

d_inline static void glColor3i_DEBUG(GLint red, GLint green, GLint blue,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3i(red=%i, green=%i, blue=%i)\n",
		 file, line, red, green, blue);
#endif
	glColor3i(red, green, blue);
	dglLogError("glColor3i", file, line);
}

d_inline static void glColor3iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3iv(v=%p)\n", file, line, v);
#endif
	glColor3iv(v);
	dglLogError("glColor3iv", file, line);
}

d_inline static void glColor3s_DEBUG(GLshort red, GLshort green, GLshort blue,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3s(red=%i, green=%i, blue=%i)\n",
		 file, line, red, green, blue);
#endif
	glColor3s(red, green, blue);
	dglLogError("glColor3s", file, line);
}

d_inline static void glColor3sv_DEBUG(GLshort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3sv(v=%p)\n", file, line, v);
#endif
	glColor3sv(v);
	dglLogError("glColor3sv", file, line);
}

d_inline static void glColor3ub_DEBUG(GLubyte red, GLubyte green, GLubyte blue,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor3ub(red=%i, green=%i, blue=%i)\n",
	     file, line, red, green, blue);
#endif
	glColor3ub(red, green, blue);
	dglLogError("glColor3ub", file, line);
}

d_inline static void glColor3ubv_DEBUG(GLubyte * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3ubv(v=%p)\n", file, line, v);
#endif
	glColor3ubv(v);
	dglLogError("glColor3ubv", file, line);
}

d_inline static void glColor3ui_DEBUG(GLuint red, GLuint green, GLuint blue,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor3ui(red=%i, green=%i, blue=%i)\n",
	     file, line, red, green, blue);
#endif
	glColor3ui(red, green, blue);
	dglLogError("glColor3ui", file, line);
}

d_inline static void glColor3uiv_DEBUG(GLuint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3uiv(v=%p)\n", file, line, v);
#endif
	glColor3uiv(v);
	dglLogError("glColor3uiv", file, line);
}

d_inline static void glColor3us_DEBUG(GLushort red, GLushort green,
				      GLushort blue, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor3us(red=%i, green=%i, blue=%i)\n",
	     file, line, red, green, blue);
#endif
	glColor3us(red, green, blue);
	dglLogError("glColor3us", file, line);
}

d_inline static void glColor3usv_DEBUG(GLushort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor3usv(v=%p)\n", file, line, v);
#endif
	glColor3usv(v);
	dglLogError("glColor3usv", file, line);
}

d_inline static void glColor4b_DEBUG(GLbyte red, GLbyte green, GLbyte blue,
				     GLbyte alpha, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4b(red=%i, green=%i, blue=%i, alpha=%i)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4b(red, green, blue, alpha);
	dglLogError("glColor4b", file, line);
}

d_inline static void glColor4bv_DEBUG(GLbyte * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4bv(v=%p)\n", file, line, v);
#endif
	glColor4bv(v);
	dglLogError("glColor4bv", file, line);
}

d_inline static void glColor4d_DEBUG(GLdouble red, GLdouble green,
				     GLdouble blue, GLdouble alpha,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4d(red=%f, green=%f, blue=%f, alpha=%f)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4d(red, green, blue, alpha);
	dglLogError("glColor4d", file, line);
}

d_inline static void glColor4dv_DEBUG(GLdouble * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4dv(v=%p)\n", file, line, v);
#endif
	glColor4dv(v);
	dglLogError("glColor4dv", file, line);
}

d_inline static void glColor4f_DEBUG(GLfloat red, GLfloat green, GLfloat blue,
				     GLfloat alpha, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4f(red=%f, green=%f, blue=%f, alpha=%f)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4f(red, green, blue, alpha);
	dglLogError("glColor4f", file, line);
}

d_inline static void glColor4fv_DEBUG(GLfloat * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4fv(v=%p)\n", file, line, v);
#endif
	glColor4fv(v);
	dglLogError("glColor4fv", file, line);
}

d_inline static void glColor4i_DEBUG(GLint red, GLint green, GLint blue,
				     GLint alpha, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4i(red=%i, green=%i, blue=%i, alpha=%i)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4i(red, green, blue, alpha);
	dglLogError("glColor4i", file, line);
}

d_inline static void glColor4iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4iv(v=%p)\n", file, line, v);
#endif
	glColor4iv(v);
	dglLogError("glColor4iv", file, line);
}

d_inline static void glColor4s_DEBUG(GLshort red, GLshort green, GLshort blue,
				     GLshort alpha, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4s(red=%i, green=%i, blue=%i, alpha=%i)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4s(red, green, blue, alpha);
	dglLogError("glColor4s", file, line);
}

d_inline static void glColor4sv_DEBUG(GLshort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4sv(v=%p)\n", file, line, v);
#endif
	glColor4sv(v);
	dglLogError("glColor4sv", file, line);
}

d_inline static void glColor4ub_DEBUG(GLubyte red, GLubyte green, GLubyte blue,
				      GLubyte alpha, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4ub(red=%i, green=%i, blue=%i, alpha=%i)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4ub(red, green, blue, alpha);
	dglLogError("glColor4ub", file, line);
}

d_inline static void glColor4ubv_DEBUG(GLubyte * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4ubv(v=%p)\n", file, line, v);
#endif
#ifdef HAVE_GLES
	glColor4ub(v[0], v[1], v[2], v[3]);
#else
	glColor4ubv(v);
#endif
	dglLogError("glColor4ubv", file, line);
}

d_inline static void glColor4ui_DEBUG(GLuint red, GLuint green, GLuint blue,
				      GLuint alpha, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4ui(red=%i, green=%i, blue=%i, alpha=%i)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4ui(red, green, blue, alpha);
	dglLogError("glColor4ui", file, line);
}

d_inline static void glColor4uiv_DEBUG(GLuint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4uiv(v=%p)\n", file, line, v);
#endif
	glColor4uiv(v);
	dglLogError("glColor4uiv", file, line);
}

d_inline static void glColor4us_DEBUG(GLushort red, GLushort green,
				      GLushort blue, GLushort alpha,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColor4us(red=%i, green=%i, blue=%i, alpha=%i)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColor4us(red, green, blue, alpha);
	dglLogError("glColor4us", file, line);
}

d_inline static void glColor4usv_DEBUG(GLushort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glColor4usv(v=%p)\n", file, line, v);
#endif
	glColor4usv(v);
	dglLogError("glColor4usv", file, line);
}

d_inline static void glColorMask_DEBUG(GLboolean red, GLboolean green,
				       GLboolean blue, GLboolean alpha,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColorMask(red=%i, green=%i, blue=%i, alpha=%i)\n",
	     file, line, red, green, blue, alpha);
#endif
	glColorMask(red, green, blue, alpha);
	dglLogError("glColorMask", file, line);
}

d_inline static void glColorMaterial_DEBUG(GLenum face, GLenum mode,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColorMaterial(face=0x%x, mode=0x%x)\n",
	     file, line, face, mode);
#endif
	glColorMaterial(face, mode);
	dglLogError("glColorMaterial", file, line);
}

d_inline static void glColorPointer_DEBUG(GLint size, GLenum type,
					  GLsizei stride, GLvoid * pointer,
					  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glColorPointer(size=%i, type=0x%x, stride=0x%x, pointer=%p)\n",
	     file, line, size, type, stride, pointer);
#endif
	glColorPointer(size, type, stride, pointer);
	dglLogError("glColorPointer", file, line);
}

d_inline static void glCopyPixels_DEBUG(GLint x, GLint y, GLsizei width,
					GLsizei height, GLenum type,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glCopyPixels(x=%i, y=%i, width=0x%x, height=0x%x, type=0x%x)\n",
	     file, line, x, y, width, height, type);
#endif
	glCopyPixels(x, y, width, height, type);
	dglLogError("glCopyPixels", file, line);
}

d_inline static void glCopyTexImage1D_DEBUG(GLenum target, GLint level,
					    GLenum internalFormat, GLint x,
					    GLint y, GLsizei width,
					    GLint border, const char *file,
					    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glCopyTexImage1D(target=0x%x, level=%i, internalFormat=0x%x, x=%i, y=%i, width=0x%x, border=%i)\n",
	     file, line, target, level, internalFormat, x, y, width, border);
#endif
	glCopyTexImage1D(target, level, internalFormat, x, y, width, border);
	dglLogError("glCopyTexImage1D", file, line);
}

d_inline static void glCopyTexImage2D_DEBUG(GLenum target, GLint level,
					    GLenum internalFormat, GLint x,
					    GLint y, GLsizei width,
					    GLsizei height, GLint border,
					    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glCopyTexImage2D(target=0x%x, level=%i, internalFormat=0x%x, x=%i, y=%i, width=0x%x, height=0x%x, border=%i)\n",
	     file, line, target, level, internalFormat, x, y, width, height,
	     border);
#endif
	glCopyTexImage2D(target, level, internalFormat, x, y, width, height,
			 border);
	dglLogError("glCopyTexImage2D", file, line);
}

d_inline static void glCopyTexSubImage1D_DEBUG(GLenum target, GLint level,
					       GLint xoffset, GLint x, GLint y,
					       GLsizei width, const char *file,
					       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glCopyTexSubImage1D(target=0x%x, level=%i, xoffset=%i, x=%i, y=%i, width=0x%x)\n",
	     file, line, target, level, xoffset, x, y, width);
#endif
	glCopyTexSubImage1D(target, level, xoffset, x, y, width);
	dglLogError("glCopyTexSubImage1D", file, line);
}

d_inline static void glCopyTexSubImage2D_DEBUG(GLenum target, GLint level,
					       GLint xoffset, GLint yoffset,
					       GLint x, GLint y, GLsizei width,
					       GLsizei height, const char *file,
					       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glCopyTexSubImage2D(target=0x%x, level=%i, xoffset=%i, yoffset=%i, x=%i, y=%i, width=0x%x, height=0x%x)\n",
	     file, line, target, level, xoffset, yoffset, x, y, width, height);
#endif
	glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width,
			    height);
	dglLogError("glCopyTexSubImage2D", file, line);
}

d_inline static void glCullFace_DEBUG(GLenum mode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glCullFace(mode=0x%x)\n", file, line,
		 mode);
#endif
	glCullFace(mode);
	dglLogError("glCullFace", file, line);
}

d_inline static void glDeleteLists_DEBUG(GLuint list, GLsizei range,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glDeleteLists(list=%i, range=0x%x)\n",
		 file, line, list, range);
#endif
	glDeleteLists(list, range);
	dglLogError("glDeleteLists", file, line);
}

d_inline static void glDeleteTextures_DEBUG(GLsizei n, GLuint * textures,
					    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glDeleteTextures(n=0x%x, textures=%p)\n",
	     file, line, n, textures);
#endif
	glDeleteTextures(n, textures);
	dglLogError("glDeleteTextures", file, line);
}

d_inline static void glDepthFunc_DEBUG(GLenum func, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glDepthFunc(func=0x%x)\n", file, line,
		 func);
#endif
	glDepthFunc(func);
	dglLogError("glDepthFunc", file, line);
}

d_inline static void glDepthMask_DEBUG(GLboolean flag, const char *file,
				       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glDepthMask(flag=%i)\n", file, line,
		 flag);
#endif
	glDepthMask(flag);
	dglLogError("glDepthMask", file, line);
}

d_inline static void glDepthRange_DEBUG(GLclampd zNear, GLclampd zFar,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glDepthRange(zNear=%f, zFar=%f)\n",
		 file, line, zNear, zFar);
#endif
#ifdef HAVE_GLES
	glDepthRangef(zNear, zFar);
#else
	glDepthRange(zNear, zFar);
#endif
	dglLogError("glDepthRange", file, line);
}

d_inline static void glDisable_DEBUG(GLenum cap, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glDisable(cap=0x%x)\n", file, line,
		 cap);
#endif
	glDisable(cap);
	dglLogError("glDisable", file, line);
}

d_inline static void glDisableClientState_DEBUG(GLenum array, const char *file,
						int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glDisableClientState(array=0x%x)\n",
		 file, line, array);
#endif
	glDisableClientState(array);
	dglLogError("glDisableClientState", file, line);
}

d_inline static void glDrawArrays_DEBUG(GLenum mode, GLint first, GLsizei count,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glDrawArrays(mode=0x%x, first=%i, count=0x%x)\n",
	     file, line, mode, first, count);
#endif
	glDrawArrays(mode, first, count);
	dglLogError("glDrawArrays", file, line);
}

d_inline static void glDrawBuffer_DEBUG(GLenum mode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glDrawBuffer(mode=0x%x)\n", file, line,
		 mode);
#endif
	glDrawBuffer(mode);
	dglLogError("glDrawBuffer", file, line);
}

d_inline static void glDrawElements_DEBUG(GLenum mode, GLsizei count,
					  GLenum type, GLvoid * indices,
					  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glDrawElements(mode=0x%x, count=0x%x, type=0x%x, indices=%p)\n",
	     file, line, mode, count, type, indices);
#endif
	glDrawElements(mode, count, type, indices);
	dglLogError("glDrawElements", file, line);
}

d_inline static void glDrawPixels_DEBUG(GLsizei width, GLsizei height,
					GLenum format, GLenum type,
					GLvoid * pixels, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glDrawPixels(width=0x%x, height=0x%x, format=0x%x, type=0x%x, pixels=%p)\n",
	     file, line, width, height, format, type, pixels);
#endif
	glDrawPixels(width, height, format, type, pixels);
	dglLogError("glDrawPixels", file, line);
}

d_inline static void glEdgeFlag_DEBUG(GLboolean flag, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEdgeFlag(flag=%i)\n", file, line,
		 flag);
#endif
	glEdgeFlag(flag);
	dglLogError("glEdgeFlag", file, line);
}

d_inline static void glEdgeFlagPointer_DEBUG(GLsizei stride, GLvoid * pointer,
					     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glEdgeFlagPointer(stride=0x%x, pointer=%p)\n",
	     file, line, stride, pointer);
#endif
	glEdgeFlagPointer(stride, pointer);
	dglLogError("glEdgeFlagPointer", file, line);
}

d_inline static void glEdgeFlagv_DEBUG(GLboolean * flag, const char *file,
				       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEdgeFlagv(flag=%p)\n", file, line,
		 flag);
#endif
	glEdgeFlagv(flag);
	dglLogError("glEdgeFlagv", file, line);
}

d_inline static void glEnable_DEBUG(GLenum cap, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEnable(cap=0x%x)\n", file, line, cap);
#endif
	glEnable(cap);
	dglLogError("glEnable", file, line);
}

d_inline static void glEnableClientState_DEBUG(GLenum array, const char *file,
					       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEnableClientState(array=0x%x)\n",
		 file, line, array);
#endif
	glEnableClientState(array);
	dglLogError("glEnableClientState", file, line);
}

d_inline static void glEnd_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEnd()\n", file, line);
#endif
	glEnd();
}

d_inline static void glEndList_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEndList()\n", file, line);
#endif
	glEndList();
	dglLogError("glEndList", file, line);
}

d_inline static void glEvalCoord1d_DEBUG(GLdouble u, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord1d(u=%f)\n", file, line, u);
#endif
	glEvalCoord1d(u);
	dglLogError("glEvalCoord1d", file, line);
}

d_inline static void glEvalCoord1dv_DEBUG(GLdouble * u, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord1dv(u=%p)\n", file, line, u);
#endif
	glEvalCoord1dv(u);
	dglLogError("glEvalCoord1dv", file, line);
}

d_inline static void glEvalCoord1f_DEBUG(GLfloat u, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord1f(u=%f)\n", file, line, u);
#endif
	glEvalCoord1f(u);
	dglLogError("glEvalCoord1f", file, line);
}

d_inline static void glEvalCoord1fv_DEBUG(GLfloat * u, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord1fv(u=%p)\n", file, line, u);
#endif
	glEvalCoord1fv(u);
	dglLogError("glEvalCoord1fv", file, line);
}

d_inline static void glEvalCoord2d_DEBUG(GLdouble u, GLdouble v,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord2d(u=%f, v=%f)\n", file,
		 line, u, v);
#endif
	glEvalCoord2d(u, v);
	dglLogError("glEvalCoord2d", file, line);
}

d_inline static void glEvalCoord2dv_DEBUG(GLdouble * u, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord2dv(u=%p)\n", file, line, u);
#endif
	glEvalCoord2dv(u);
	dglLogError("glEvalCoord2dv", file, line);
}

d_inline static void glEvalCoord2f_DEBUG(GLfloat u, GLfloat v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord2f(u=%f, v=%f)\n", file,
		 line, u, v);
#endif
	glEvalCoord2f(u, v);
	dglLogError("glEvalCoord2f", file, line);
}

d_inline static void glEvalCoord2fv_DEBUG(GLfloat * u, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalCoord2fv(u=%p)\n", file, line, u);
#endif
	glEvalCoord2fv(u);
	dglLogError("glEvalCoord2fv", file, line);
}

d_inline static void glEvalMesh1_DEBUG(GLenum mode, GLint i1, GLint i2,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalMesh1(mode=0x%x, i1=%i, i2=%i)\n",
		 file, line, mode, i1, i2);
#endif
	glEvalMesh1(mode, i1, i2);
	dglLogError("glEvalMesh1", file, line);
}

d_inline static void glEvalMesh2_DEBUG(GLenum mode, GLint i1, GLint i2,
				       GLint j1, GLint j2, const char *file,
				       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glEvalMesh2(mode=0x%x, i1=%i, i2=%i, j1=%i, j2=%i)\n",
	     file, line, mode, i1, i2, j1, j2);
#endif
	glEvalMesh2(mode, i1, i2, j1, j2);
	dglLogError("glEvalMesh2", file, line);
}

d_inline static void glEvalPoint1_DEBUG(GLint i, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalPoint1(i=%i)\n", file, line, i);
#endif
	glEvalPoint1(i);
	dglLogError("glEvalPoint1", file, line);
}

d_inline static void glEvalPoint2_DEBUG(GLint i, GLint j, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glEvalPoint2(i=%i, j=%i)\n", file, line,
		 i, j);
#endif
	glEvalPoint2(i, j);
	dglLogError("glEvalPoint2", file, line);
}

d_inline static void glFeedbackBuffer_DEBUG(GLsizei size, GLenum type,
					    GLfloat * buffer, const char *file,
					    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glFeedbackBuffer(size=0x%x, type=0x%x, buffer=%p)\n",
	     file, line, size, type, buffer);
#endif
	glFeedbackBuffer(size, type, buffer);
	dglLogError("glFeedbackBuffer", file, line);
}

d_inline static void glFinish_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFinish()\n", file, line);
#endif
	glFinish();
	dglLogError("glFinish", file, line);
}

d_inline static void glFlush_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFlush()\n", file, line);
#endif
	glFlush();
	dglLogError("glFlush", file, line);
}

d_inline static void glFogf_DEBUG(GLenum pname, GLfloat param, const char *file,
				  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogf(pname=0x%x, param=%f)\n", file,
		 line, pname, param);
#endif
	glFogf(pname, param);
	dglLogError("glFogf", file, line);
}

d_inline static void glFogfv_DEBUG(GLenum pname, GLfloat * params,
				   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogfv(pname=0x%x, params=%p)\n", file,
		 line, pname, params);
#endif
	glFogfv(pname, params);
	dglLogError("glFogfv", file, line);
}

d_inline static void glFogi_DEBUG(GLenum pname, GLint param, const char *file,
				  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogi(pname=0x%x, param=%i)\n", file,
		 line, pname, param);
#endif
#ifdef HAVE_GLES
	glFogf(pname, param);
#else
	glFogi(pname, param);
#endif
	dglLogError("glFogi", file, line);
}

d_inline static void glFogiv_DEBUG(GLenum pname, GLint * params,
				   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogiv(pname=0x%x, params=%p)\n", file,
		 line, pname, params);
#endif
	glFogiv(pname, params);
	dglLogError("glFogiv", file, line);
}

d_inline static void glFrontFace_DEBUG(GLenum mode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFrontFace(mode=0x%x)\n", file, line,
		 mode);
#endif
	glFrontFace(mode);
	dglLogError("glFrontFace", file, line);
}

d_inline static void glFrustum_DEBUG(GLdouble left, GLdouble right,
				     GLdouble bottom, GLdouble top,
				     GLdouble zNear, GLdouble zFar,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glFrustum(left=%f, right=%f, bottom=%f, top=%f, zNear=%f, zFar=%f)\n",
	     file, line, left, right, bottom, top, zNear, zFar);
#endif
	glFrustum(left, right, bottom, top, zNear, zFar);
	dglLogError("glFrustum", file, line);
}

d_inline static GLuint glGenLists_DEBUG(GLsizei range, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGenLists(range=0x%x)\n", file, line,
		 range);
#endif
	glGenLists(range);
	dglLogError("glGenLists", file, line);
}

d_inline static void glGenTextures_DEBUG(GLsizei n, GLuint * textures,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGenTextures(n=0x%x, textures=%p)\n",
		 file, line, n, textures);
#endif
	glGenTextures(n, textures);
	dglLogError("glGenTextures", file, line);
}

d_inline static void glGetBooleanv_DEBUG(GLenum pname, GLboolean * params,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetBooleanv(pname=0x%x, params=%p)\n",
		 file, line, pname, params);
#endif
	glGetBooleanv(pname, params);
	dglLogError("glGetBooleanv", file, line);
}

d_inline static void glGetClipPlane_DEBUG(GLenum plane, GLdouble * equation,
					  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetClipPlane(plane=0x%x, equation=%p)\n",
	     file, line, plane, equation);
#endif
	glGetClipPlane(plane, equation);
	dglLogError("glGetClipPlane", file, line);
}

d_inline static void glGetDoublev_DEBUG(GLenum pname, GLdouble * params,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetDoublev(pname=0x%x, params=%p)\n",
		 file, line, pname, params);
#endif
	glGetDoublev(pname, params);
	dglLogError("glGetDoublev", file, line);
}

d_inline static GLenum glGetError_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetError()\n", file, line);
#endif
	glGetError();
	dglLogError("glGetError", file, line);
}

d_inline static void glGetFloatv_DEBUG(GLenum pname, GLfloat * params,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetFloatv(pname=0x%x, params=%p)\n",
		 file, line, pname, params);
#endif
	glGetFloatv(pname, params);
	dglLogError("glGetFloatv", file, line);
}

d_inline static void glGetIntegerv_DEBUG(GLenum pname, GLint * params,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetIntegerv(pname=0x%x, params=%p)\n",
		 file, line, pname, params);
#endif
	glGetIntegerv(pname, params);
	dglLogError("glGetIntegerv", file, line);
}

d_inline static void glGetLightfv_DEBUG(GLenum light, GLenum pname,
					GLfloat * params, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetLightfv(light=0x%x, pname=0x%x, params=%p)\n",
	     file, line, light, pname, params);
#endif
	glGetLightfv(light, pname, params);
	dglLogError("glGetLightfv", file, line);
}

d_inline static void glGetLightiv_DEBUG(GLenum light, GLenum pname,
					GLint * params, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetLightiv(light=0x%x, pname=0x%x, params=%p)\n",
	     file, line, light, pname, params);
#endif
	glGetLightiv(light, pname, params);
	dglLogError("glGetLightiv", file, line);
}

d_inline static void glGetMapdv_DEBUG(GLenum target, GLenum query, GLdouble * v,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetMapdv(target=0x%x, query=0x%x, v=%p)\n",
	     file, line, target, query, v);
#endif
	glGetMapdv(target, query, v);
	dglLogError("glGetMapdv", file, line);
}

d_inline static void glGetMapfv_DEBUG(GLenum target, GLenum query, GLfloat * v,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetMapfv(target=0x%x, query=0x%x, v=%p)\n",
	     file, line, target, query, v);
#endif
	glGetMapfv(target, query, v);
	dglLogError("glGetMapfv", file, line);
}

d_inline static void glGetMapiv_DEBUG(GLenum target, GLenum query, GLint * v,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetMapiv(target=0x%x, query=0x%x, v=%p)\n",
	     file, line, target, query, v);
#endif
	glGetMapiv(target, query, v);
	dglLogError("glGetMapiv", file, line);
}

d_inline static void glGetMaterialfv_DEBUG(GLenum face, GLenum pname,
					   GLfloat * params, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetMaterialfv(face=0x%x, pname=0x%x, params=%p)\n",
	     file, line, face, pname, params);
#endif
	glGetMaterialfv(face, pname, params);
	dglLogError("glGetMaterialfv", file, line);
}

d_inline static void glGetMaterialiv_DEBUG(GLenum face, GLenum pname,
					   GLint * params, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetMaterialiv(face=0x%x, pname=0x%x, params=%p)\n",
	     file, line, face, pname, params);
#endif
	glGetMaterialiv(face, pname, params);
	dglLogError("glGetMaterialiv", file, line);
}

d_inline static void glGetPixelMapfv_DEBUG(GLenum map, GLfloat * values,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetPixelMapfv(map=0x%x, values=%p)\n",
		 file, line, map, values);
#endif
	glGetPixelMapfv(map, values);
	dglLogError("glGetPixelMapfv", file, line);
}

d_inline static void glGetPixelMapuiv_DEBUG(GLenum map, GLuint * values,
					    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetPixelMapuiv(map=0x%x, values=%p)\n",
	     file, line, map, values);
#endif
	glGetPixelMapuiv(map, values);
	dglLogError("glGetPixelMapuiv", file, line);
}

d_inline static void glGetPixelMapusv_DEBUG(GLenum map, GLushort * values,
					    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetPixelMapusv(map=0x%x, values=%p)\n",
	     file, line, map, values);
#endif
	glGetPixelMapusv(map, values);
	dglLogError("glGetPixelMapusv", file, line);
}

d_inline static void glGetPointerv_DEBUG(GLenum pname, void *params,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetPointerv(pname=0x%x, params=%p)\n",
		 file, line, pname, params);
#endif
	glGetPointerv(pname, params);
	dglLogError("glGetPointerv", file, line);
}

d_inline static void glGetPolygonStipple_DEBUG(GLubyte * mask, const char *file,
					       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGetPolygonStipple(mask=%p)\n", file,
		 line, mask);
#endif
	glGetPolygonStipple(mask);
	dglLogError("glGetPolygonStipple", file, line);
}

d_inline static void glGetTexEnvfv_DEBUG(GLenum target, GLenum pname,
					 GLfloat * params, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexEnvfv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glGetTexEnvfv(target, pname, params);
	dglLogError("glGetTexEnvfv", file, line);
}

d_inline static void glGetTexEnviv_DEBUG(GLenum target, GLenum pname,
					 GLint * params, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexEnviv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glGetTexEnviv(target, pname, params);
	dglLogError("glGetTexEnviv", file, line);
}

d_inline static void glGetTexGendv_DEBUG(GLenum coord, GLenum pname,
					 GLdouble * params, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexGendv(coord=0x%x, pname=0x%x, params=%p)\n",
	     file, line, coord, pname, params);
#endif
	glGetTexGendv(coord, pname, params);
	dglLogError("glGetTexGendv", file, line);
}

d_inline static void glGetTexGenfv_DEBUG(GLenum coord, GLenum pname,
					 GLfloat * params, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexGenfv(coord=0x%x, pname=0x%x, params=%p)\n",
	     file, line, coord, pname, params);
#endif
	glGetTexGenfv(coord, pname, params);
	dglLogError("glGetTexGenfv", file, line);
}

d_inline static void glGetTexGeniv_DEBUG(GLenum coord, GLenum pname,
					 GLint * params, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexGeniv(coord=0x%x, pname=0x%x, params=%p)\n",
	     file, line, coord, pname, params);
#endif
	glGetTexGeniv(coord, pname, params);
	dglLogError("glGetTexGeniv", file, line);
}

d_inline static void glGetTexImage_DEBUG(GLenum target, GLint level,
					 GLenum format, GLenum type,
					 GLvoid * pixels, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexImage(target=0x%x, level=%i, format=0x%x, type=0x%x, pixels=%p)\n",
	     file, line, target, level, format, type, pixels);
#endif
	glGetTexImage(target, level, format, type, pixels);
	dglLogError("glGetTexImage", file, line);
}

d_inline static void glGetTexLevelParameterfv_DEBUG(GLenum target, GLint level,
						    GLenum pname,
						    GLfloat * params,
						    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexLevelParameterfv(target=0x%x, level=%i, pname=0x%x, params=%p)\n",
	     file, line, target, level, pname, params);
#endif
	glGetTexLevelParameterfv(target, level, pname, params);
	dglLogError("glGetTexLevelParameterfv", file, line);
}

d_inline static void glGetTexLevelParameteriv_DEBUG(GLenum target, GLint level,
						    GLenum pname,
						    GLint * params,
						    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexLevelParameteriv(target=0x%x, level=%i, pname=0x%x, params=%p)\n",
	     file, line, target, level, pname, params);
#endif
	glGetTexLevelParameteriv(target, level, pname, params);
	dglLogError("glGetTexLevelParameteriv", file, line);
}

d_inline static void glGetTexParameterfv_DEBUG(GLenum target, GLenum pname,
					       GLfloat * params,
					       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexParameterfv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glGetTexParameterfv(target, pname, params);
	dglLogError("glGetTexParameterfv", file, line);
}

d_inline static void glGetTexParameteriv_DEBUG(GLenum target, GLenum pname,
					       GLint * params, const char *file,
					       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetTexParameteriv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glGetTexParameteriv(target, pname, params);
	dglLogError("glGetTexParameteriv", file, line);
}

d_inline static void glHint_DEBUG(GLenum target, GLenum mode, const char *file,
				  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glHint(target=0x%x, mode=0x%x)\n", file,
		 line, target, mode);
#endif
	glHint(target, mode);
	dglLogError("glHint", file, line);
}

d_inline static void glIndexMask_DEBUG(GLuint mask, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexMask(mask=%i)\n", file, line,
		 mask);
#endif
	glIndexMask(mask);
	dglLogError("glIndexMask", file, line);
}

d_inline static void glIndexPointer_DEBUG(GLenum type, GLsizei stride,
					  GLvoid * pointer, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glIndexPointer(type=0x%x, stride=0x%x, pointer=%p)\n",
	     file, line, type, stride, pointer);
#endif
	glIndexPointer(type, stride, pointer);
	dglLogError("glIndexPointer", file, line);
}

d_inline static void glIndexd_DEBUG(GLdouble c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexd(c=%f)\n", file, line, c);
#endif
	glIndexd(c);
	dglLogError("glIndexd", file, line);
}

d_inline static void glIndexdv_DEBUG(GLdouble * c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexdv(c=%p)\n", file, line, c);
#endif
	glIndexdv(c);
	dglLogError("glIndexdv", file, line);
}

d_inline static void glIndexf_DEBUG(GLfloat c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexf(c=%f)\n", file, line, c);
#endif
	glIndexf(c);
	dglLogError("glIndexf", file, line);
}

d_inline static void glIndexfv_DEBUG(GLfloat * c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexfv(c=%p)\n", file, line, c);
#endif
	glIndexfv(c);
	dglLogError("glIndexfv", file, line);
}

d_inline static void glIndexi_DEBUG(GLint c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexi(c=%i)\n", file, line, c);
#endif
	glIndexi(c);
	dglLogError("glIndexi", file, line);
}

d_inline static void glIndexiv_DEBUG(GLint * c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexiv(c=%p)\n", file, line, c);
#endif
	glIndexiv(c);
	dglLogError("glIndexiv", file, line);
}

d_inline static void glIndexs_DEBUG(GLshort c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexs(c=%i)\n", file, line, c);
#endif
	glIndexs(c);
	dglLogError("glIndexs", file, line);
}

d_inline static void glIndexsv_DEBUG(GLshort * c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexsv(c=%p)\n", file, line, c);
#endif
	glIndexsv(c);
	dglLogError("glIndexsv", file, line);
}

d_inline static void glIndexub_DEBUG(GLubyte c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexub(c=%i)\n", file, line, c);
#endif
	glIndexub(c);
	dglLogError("glIndexub", file, line);
}

d_inline static void glIndexubv_DEBUG(GLubyte * c, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIndexubv(c=%p)\n", file, line, c);
#endif
	glIndexubv(c);
	dglLogError("glIndexubv", file, line);
}

d_inline static void glInitNames_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glInitNames()\n", file, line);
#endif
	glInitNames();
	dglLogError("glInitNames", file, line);
}

d_inline static void glInterleavedArrays_DEBUG(GLenum format, GLsizei stride,
					       GLvoid * pointer,
					       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glInterleavedArrays(format=0x%x, stride=0x%x, pointer=%p)\n",
	     file, line, format, stride, pointer);
#endif
	glInterleavedArrays(format, stride, pointer);
	dglLogError("glInterleavedArrays", file, line);
}

d_inline static GLboolean glIsEnabled_DEBUG(GLenum cap, const char *file,
					    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIsEnabled(cap=0x%x)\n", file, line,
		 cap);
#endif
	glIsEnabled(cap);
	dglLogError("glIsEnabled", file, line);
}

d_inline static GLboolean glIsList_DEBUG(GLuint list, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIsList(list=%i)\n", file, line, list);
#endif
	glIsList(list);
	dglLogError("glIsList", file, line);
}

d_inline static GLboolean glIsTexture_DEBUG(GLuint texture, const char *file,
					    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIsTexture(texture=%i)\n", file, line,
		 texture);
#endif
	glIsTexture(texture);
	dglLogError("glIsTexture", file, line);
}

d_inline static void glLightModelf_DEBUG(GLenum pname, GLfloat param,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLightModelf(pname=0x%x, param=%f)\n",
		 file, line, pname, param);
#endif
	glLightModelf(pname, param);
	dglLogError("glLightModelf", file, line);
}

d_inline static void glLightModelfv_DEBUG(GLenum pname, GLfloat * params,
					  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glLightModelfv(pname=0x%x, params=%p)\n",
	     file, line, pname, params);
#endif
	glLightModelfv(pname, params);
	dglLogError("glLightModelfv", file, line);
}

d_inline static void glLightModeli_DEBUG(GLenum pname, GLint param,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLightModeli(pname=0x%x, param=%i)\n",
		 file, line, pname, param);
#endif
	glLightModeli(pname, param);
	dglLogError("glLightModeli", file, line);
}

d_inline static void glLightModeliv_DEBUG(GLenum pname, GLint * params,
					  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glLightModeliv(pname=0x%x, params=%p)\n",
	     file, line, pname, params);
#endif
	glLightModeliv(pname, params);
	dglLogError("glLightModeliv", file, line);
}

d_inline static void glLightf_DEBUG(GLenum light, GLenum pname, GLfloat param,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glLightf(light=0x%x, pname=0x%x, param=%f)\n",
	     file, line, light, pname, param);
#endif
	glLightf(light, pname, param);
	dglLogError("glLightf", file, line);
}

d_inline static void glLightfv_DEBUG(GLenum light, GLenum pname,
				     GLfloat * params, const char *file,
				     int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glLightfv(light=0x%x, pname=0x%x, params=%p)\n",
	     file, line, light, pname, params);
#endif
	glLightfv(light, pname, params);
	dglLogError("glLightfv", file, line);
}

d_inline static void glLighti_DEBUG(GLenum light, GLenum pname, GLint param,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glLighti(light=0x%x, pname=0x%x, param=%i)\n",
	     file, line, light, pname, param);
#endif
	glLighti(light, pname, param);
	dglLogError("glLighti", file, line);
}

d_inline static void glLightiv_DEBUG(GLenum light, GLenum pname, GLint * params,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glLightiv(light=0x%x, pname=0x%x, params=%p)\n",
	     file, line, light, pname, params);
#endif
	glLightiv(light, pname, params);
	dglLogError("glLightiv", file, line);
}

d_inline static void glLineStipple_DEBUG(GLint factor, GLushort pattern,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLineStipple(factor=%i, pattern=%i)\n",
		 file, line, factor, pattern);
#endif
	glLineStipple(factor, pattern);
	dglLogError("glLineStipple", file, line);
}

d_inline static void glLineWidth_DEBUG(GLfloat width, const char *file,
				       int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLineWidth(width=%f)\n", file, line,
		 width);
#endif
	glLineWidth(width);
	dglLogError("glLineWidth", file, line);
}

d_inline static void glListBase_DEBUG(GLuint base, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glListBase(base=%i)\n", file, line,
		 base);
#endif
	glListBase(base);
	dglLogError("glListBase", file, line);
}

d_inline static void glLoadIdentity_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLoadIdentity()\n", file, line);
#endif
	glLoadIdentity();
	dglLogError("glLoadIdentity", file, line);
}

d_inline static void glLoadMatrixd_DEBUG(GLdouble * m, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLoadMatrixd(m=%p)\n", file, line, m);
#endif
	glLoadMatrixd(m);
	dglLogError("glLoadMatrixd", file, line);
}

d_inline static void glLoadMatrixf_DEBUG(GLfloat * m, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLoadMatrixf(m=%p)\n", file, line, m);
#endif
	glLoadMatrixf(m);
	dglLogError("glLoadMatrixf", file, line);
}

d_inline static void glLoadName_DEBUG(GLuint name, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLoadName(name=%i)\n", file, line,
		 name);
#endif
	glLoadName(name);
	dglLogError("glLoadName", file, line);
}

d_inline static void glLogicOp_DEBUG(GLenum opcode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glLogicOp(opcode=0x%x)\n", file, line,
		 opcode);
#endif
	glLogicOp(opcode);
	dglLogError("glLogicOp", file, line);
}

d_inline static void glMap1d_DEBUG(GLenum target, GLdouble u1, GLdouble u2,
				   GLint stride, GLint order, GLdouble * points,
				   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMap1d(target=0x%x, u1=%f, u2=%f, stride=%i, order=%i, points=%p)\n",
	     file, line, target, u1, u2, stride, order, points);
#endif
	glMap1d(target, u1, u2, stride, order, points);
	dglLogError("glMap1d", file, line);
}

d_inline static void glMap1f_DEBUG(GLenum target, GLfloat u1, GLfloat u2,
				   GLint stride, GLint order, GLfloat * points,
				   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMap1f(target=0x%x, u1=%f, u2=%f, stride=%i, order=%i, points=%p)\n",
	     file, line, target, u1, u2, stride, order, points);
#endif
	glMap1f(target, u1, u2, stride, order, points);
	dglLogError("glMap1f", file, line);
}

d_inline static void glMap2d_DEBUG(GLenum target, GLdouble u1, GLdouble u2,
				   GLint ustride, GLint uorder, GLdouble v1,
				   GLdouble v2, GLint vstride, GLint vorder,
				   GLdouble * points, const char *file,
				   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMap2d(target=0x%x, u1=%f, u2=%f, ustride=%i, uorder=%i, v1=%f, v2=%f, vstride=%i, vorder=%i, points=%p)\n",
	     file, line, target, u1, u2, ustride, uorder, v1, v2, vstride,
	     vorder, points);
#endif
	glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder,
		points);
	dglLogError("glMap2d", file, line);
}

d_inline static void glMap2f_DEBUG(GLenum target, GLfloat u1, GLfloat u2,
				   GLint ustride, GLint uorder, GLfloat v1,
				   GLfloat v2, GLint vstride, GLint vorder,
				   GLfloat * points, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMap2f(target=0x%x, u1=%f, u2=%f, ustride=%i, uorder=%i, v1=%f, v2=%f, vstride=%i, vorder=%i, points=%p)\n",
	     file, line, target, u1, u2, ustride, uorder, v1, v2, vstride,
	     vorder, points);
#endif
	glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder,
		points);
	dglLogError("glMap2f", file, line);
}

d_inline static void glMapGrid1d_DEBUG(GLint un, GLdouble u1, GLdouble u2,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glMapGrid1d(un=%i, u1=%f, u2=%f)\n",
		 file, line, un, u1, u2);
#endif
	glMapGrid1d(un, u1, u2);
	dglLogError("glMapGrid1d", file, line);
}

d_inline static void glMapGrid1f_DEBUG(GLint un, GLfloat u1, GLfloat u2,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glMapGrid1f(un=%i, u1=%f, u2=%f)\n",
		 file, line, un, u1, u2);
#endif
	glMapGrid1f(un, u1, u2);
	dglLogError("glMapGrid1f", file, line);
}

d_inline static void glMapGrid2d_DEBUG(GLint un, GLdouble u1, GLdouble u2,
				       GLint vn, GLdouble v1, GLdouble v2,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMapGrid2d(un=%i, u1=%f, u2=%f, vn=%i, v1=%f, v2=%f)\n",
	     file, line, un, u1, u2, vn, v1, v2);
#endif
	glMapGrid2d(un, u1, u2, vn, v1, v2);
	dglLogError("glMapGrid2d", file, line);
}

d_inline static void glMapGrid2f_DEBUG(GLint un, GLfloat u1, GLfloat u2,
				       GLint vn, GLfloat v1, GLfloat v2,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMapGrid2f(un=%i, u1=%f, u2=%f, vn=%i, v1=%f, v2=%f)\n",
	     file, line, un, u1, u2, vn, v1, v2);
#endif
	glMapGrid2f(un, u1, u2, vn, v1, v2);
	dglLogError("glMapGrid2f", file, line);
}

d_inline static void glMaterialf_DEBUG(GLenum face, GLenum pname, GLfloat param,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMaterialf(face=0x%x, pname=0x%x, param=%f)\n",
	     file, line, face, pname, param);
#endif
	glMaterialf(face, pname, param);
	dglLogError("glMaterialf", file, line);
}

d_inline static void glMaterialfv_DEBUG(GLenum face, GLenum pname,
					GLfloat * params, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMaterialfv(face=0x%x, pname=0x%x, params=%p)\n",
	     file, line, face, pname, params);
#endif
	glMaterialfv(face, pname, params);
	dglLogError("glMaterialfv", file, line);
}

d_inline static void glMateriali_DEBUG(GLenum face, GLenum pname, GLint param,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMateriali(face=0x%x, pname=0x%x, param=%i)\n",
	     file, line, face, pname, param);
#endif
	glMateriali(face, pname, param);
	dglLogError("glMateriali", file, line);
}

d_inline static void glMaterialiv_DEBUG(GLenum face, GLenum pname,
					GLint * params, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMaterialiv(face=0x%x, pname=0x%x, params=%p)\n",
	     file, line, face, pname, params);
#endif
	glMaterialiv(face, pname, params);
	dglLogError("glMaterialiv", file, line);
}

d_inline static void glMatrixMode_DEBUG(GLenum mode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glMatrixMode(mode=0x%x)\n", file, line,
		 mode);
#endif
	glMatrixMode(mode);
	dglLogError("glMatrixMode", file, line);
}

d_inline static void glMultMatrixd_DEBUG(GLdouble * m, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glMultMatrixd(m=%p)\n", file, line, m);
#endif
	glMultMatrixd(m);
	dglLogError("glMultMatrixd", file, line);
}

d_inline static void glMultMatrixf_DEBUG(GLfloat * m, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glMultMatrixf(m=%p)\n", file, line, m);
#endif
	glMultMatrixf(m);
	dglLogError("glMultMatrixf", file, line);
}

d_inline static void glNewList_DEBUG(GLuint list, GLenum mode, const char *file,
				     int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNewList(list=%i, mode=0x%x)\n", file,
		 line, list, mode);
#endif
	glNewList(list, mode);
	dglLogError("glNewList", file, line);
}

d_inline static void glNormal3b_DEBUG(GLbyte nx, GLbyte ny, GLbyte nz,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3b(nx=%i, ny=%i, nz=%i)\n",
		 file, line, nx, ny, nz);
#endif
	glNormal3b(nx, ny, nz);
	dglLogError("glNormal3b", file, line);
}

d_inline static void glNormal3bv_DEBUG(GLbyte * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3bv(v=%p)\n", file, line, v);
#endif
	glNormal3bv(v);
	dglLogError("glNormal3bv", file, line);
}

d_inline static void glNormal3d_DEBUG(GLdouble nx, GLdouble ny, GLdouble nz,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3d(nx=%f, ny=%f, nz=%f)\n",
		 file, line, nx, ny, nz);
#endif
	glNormal3d(nx, ny, nz);
	dglLogError("glNormal3d", file, line);
}

d_inline static void glNormal3dv_DEBUG(GLdouble * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3dv(v=%p)\n", file, line, v);
#endif
	glNormal3dv(v);
	dglLogError("glNormal3dv", file, line);
}

d_inline static void glNormal3f_DEBUG(GLfloat nx, GLfloat ny, GLfloat nz,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3f(nx=%f, ny=%f, nz=%f)\n",
		 file, line, nx, ny, nz);
#endif
	glNormal3f(nx, ny, nz);
	dglLogError("glNormal3f", file, line);
}

d_inline static void glNormal3fv_DEBUG(GLfloat * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3fv(v=%p)\n", file, line, v);
#endif
	glNormal3fv(v);
	dglLogError("glNormal3fv", file, line);
}

d_inline static void glNormal3i_DEBUG(GLint nx, GLint ny, GLint nz,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3i(nx=%i, ny=%i, nz=%i)\n",
		 file, line, nx, ny, nz);
#endif
	glNormal3i(nx, ny, nz);
	dglLogError("glNormal3i", file, line);
}

d_inline static void glNormal3iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3iv(v=%p)\n", file, line, v);
#endif
	glNormal3iv(v);
	dglLogError("glNormal3iv", file, line);
}

d_inline static void glNormal3s_DEBUG(GLshort nx, GLshort ny, GLshort nz,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3s(nx=%i, ny=%i, nz=%i)\n",
		 file, line, nx, ny, nz);
#endif
	glNormal3s(nx, ny, nz);
	dglLogError("glNormal3s", file, line);
}

d_inline static void glNormal3sv_DEBUG(GLshort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glNormal3sv(v=%p)\n", file, line, v);
#endif
	glNormal3sv(v);
	dglLogError("glNormal3sv", file, line);
}

d_inline static void glNormalPointer_DEBUG(GLenum type, GLsizei stride,
					   GLvoid * pointer, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glNormalPointer(type=0x%x, stride=0x%x, pointer=%p)\n",
	     file, line, type, stride, pointer);
#endif
	glNormalPointer(type, stride, pointer);
	dglLogError("glNormalPointer", file, line);
}

d_inline static void glOrtho_DEBUG(GLdouble left, GLdouble right,
				   GLdouble bottom, GLdouble top,
				   GLdouble zNear, GLdouble zFar,
				   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glOrtho(left=%f, right=%f, bottom=%f, top=%f, zNear=%f, zFar=%f)\n",
	     file, line, left, right, bottom, top, zNear, zFar);
#endif
#ifdef HAVE_GLES
	glOrthof(left, right, bottom, top, zNear, zFar);
#else
	glOrtho(left, right, bottom, top, zNear, zFar);
#endif
	dglLogError("glOrtho", file, line);
}

d_inline static void glPassThrough_DEBUG(GLfloat token, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPassThrough(token=%f)\n", file, line,
		 token);
#endif
	glPassThrough(token);
	dglLogError("glPassThrough", file, line);
}

d_inline static void glPixelMapfv_DEBUG(GLenum map, GLsizei mapsize,
					GLfloat * values, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glPixelMapfv(map=0x%x, mapsize=0x%x, values=%p)\n",
	     file, line, map, mapsize, values);
#endif
	glPixelMapfv(map, mapsize, values);
	dglLogError("glPixelMapfv", file, line);
}

d_inline static void glPixelMapuiv_DEBUG(GLenum map, GLsizei mapsize,
					 GLuint * values, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glPixelMapuiv(map=0x%x, mapsize=0x%x, values=%p)\n",
	     file, line, map, mapsize, values);
#endif
	glPixelMapuiv(map, mapsize, values);
	dglLogError("glPixelMapuiv", file, line);
}

d_inline static void glPixelMapusv_DEBUG(GLenum map, GLsizei mapsize,
					 GLushort * values, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glPixelMapusv(map=0x%x, mapsize=0x%x, values=%p)\n",
	     file, line, map, mapsize, values);
#endif
	glPixelMapusv(map, mapsize, values);
	dglLogError("glPixelMapusv", file, line);
}

d_inline static void glPixelStoref_DEBUG(GLenum pname, GLfloat param,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPixelStoref(pname=0x%x, param=%f)\n",
		 file, line, pname, param);
#endif
	glPixelStoref(pname, param);
	dglLogError("glPixelStoref", file, line);
}

d_inline static void glPixelStorei_DEBUG(GLenum pname, GLint param,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPixelStorei(pname=0x%x, param=%i)\n",
		 file, line, pname, param);
#endif
	glPixelStorei(pname, param);
	dglLogError("glPixelStorei", file, line);
}

d_inline static void glPixelTransferf_DEBUG(GLenum pname, GLfloat param,
					    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glPixelTransferf(pname=0x%x, param=%f)\n",
	     file, line, pname, param);
#endif
	glPixelTransferf(pname, param);
	dglLogError("glPixelTransferf", file, line);
}

d_inline static void glPixelTransferi_DEBUG(GLenum pname, GLint param,
					    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glPixelTransferi(pname=0x%x, param=%i)\n",
	     file, line, pname, param);
#endif
	glPixelTransferi(pname, param);
	dglLogError("glPixelTransferi", file, line);
}

d_inline static void glPixelZoom_DEBUG(GLfloat xfactor, GLfloat yfactor,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPixelZoom(xfactor=%f, yfactor=%f)\n",
		 file, line, xfactor, yfactor);
#endif
	glPixelZoom(xfactor, yfactor);
	dglLogError("glPixelZoom", file, line);
}

d_inline static void glPointSize_DEBUG(GLfloat size, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPointSize(size=%f)\n", file, line,
		 size);
#endif
	glPointSize(size);
	dglLogError("glPointSize", file, line);
}

d_inline static void glPolygonMode_DEBUG(GLenum face, GLenum mode,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPolygonMode(face=0x%x, mode=0x%x)\n",
		 file, line, face, mode);
#endif
	glPolygonMode(face, mode);
	dglLogError("glPolygonMode", file, line);
}

d_inline static void glPolygonOffset_DEBUG(GLfloat factor, GLfloat units,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPolygonOffset(factor=%f, units=%f)\n",
		 file, line, factor, units);
#endif
	glPolygonOffset(factor, units);
	dglLogError("glPolygonOffset", file, line);
}

d_inline static void glPolygonStipple_DEBUG(GLubyte * mask, const char *file,
					    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPolygonStipple(mask=%p)\n", file,
		 line, mask);
#endif
	glPolygonStipple(mask);
	dglLogError("glPolygonStipple", file, line);
}

d_inline static void glPopAttrib_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPopAttrib()\n", file, line);
#endif
	glPopAttrib();
	dglLogError("glPopAttrib", file, line);
}

d_inline static void glPopClientAttrib_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPopClientAttrib()\n", file, line);
#endif
	glPopClientAttrib();
	dglLogError("glPopClientAttrib", file, line);
}

d_inline static void glPopMatrix_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPopMatrix()\n", file, line);
#endif
	glPopMatrix();
	dglLogError("glPopMatrix", file, line);
}

d_inline static void glPopName_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPopName()\n", file, line);
#endif
	glPopName();
	dglLogError("glPopName", file, line);
}

d_inline static void glPrioritizeTextures_DEBUG(GLsizei n, GLuint * textures,
						GLclampf * priorities,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glPrioritizeTextures(n=0x%x, textures=%p, priorities=%p)\n",
	     file, line, n, textures, priorities);
#endif
	glPrioritizeTextures(n, textures, priorities);
	dglLogError("glPrioritizeTextures", file, line);
}

d_inline static void glPushAttrib_DEBUG(GLbitfield mask, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPushAttrib(mask=0x%x)\n", file, line,
		 mask);
#endif
	glPushAttrib(mask);
	dglLogError("glPushAttrib", file, line);
}

d_inline static void glPushClientAttrib_DEBUG(GLbitfield mask, const char *file,
					      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPushClientAttrib(mask=0x%x)\n", file,
		 line, mask);
#endif
	glPushClientAttrib(mask);
	dglLogError("glPushClientAttrib", file, line);
}

d_inline static void glPushMatrix_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPushMatrix()\n", file, line);
#endif
	glPushMatrix();
	dglLogError("glPushMatrix", file, line);
}

d_inline static void glPushName_DEBUG(GLuint name, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glPushName(name=%i)\n", file, line,
		 name);
#endif
	glPushName(name);
	dglLogError("glPushName", file, line);
}

d_inline static void glRasterPos2d_DEBUG(GLdouble x, GLdouble y,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2d(x=%f, y=%f)\n", file,
		 line, x, y);
#endif
	glRasterPos2d(x, y);
	dglLogError("glRasterPos2d", file, line);
}

d_inline static void glRasterPos2dv_DEBUG(GLdouble * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2dv(v=%p)\n", file, line, v);
#endif
	glRasterPos2dv(v);
	dglLogError("glRasterPos2dv", file, line);
}

d_inline static void glRasterPos2f_DEBUG(GLfloat x, GLfloat y, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2f(x=%f, y=%f)\n", file,
		 line, x, y);
#endif
	glRasterPos2f(x, y);
	dglLogError("glRasterPos2f", file, line);
}

d_inline static void glRasterPos2fv_DEBUG(GLfloat * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2fv(v=%p)\n", file, line, v);
#endif
	glRasterPos2fv(v);
	dglLogError("glRasterPos2fv", file, line);
}

d_inline static void glRasterPos2i_DEBUG(GLint x, GLint y, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2i(x=%i, y=%i)\n", file,
		 line, x, y);
#endif
	glRasterPos2i(x, y);
	dglLogError("glRasterPos2i", file, line);
}

d_inline static void glRasterPos2iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2iv(v=%p)\n", file, line, v);
#endif
	glRasterPos2iv(v);
	dglLogError("glRasterPos2iv", file, line);
}

d_inline static void glRasterPos2s_DEBUG(GLshort x, GLshort y, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2s(x=%i, y=%i)\n", file,
		 line, x, y);
#endif
	glRasterPos2s(x, y);
	dglLogError("glRasterPos2s", file, line);
}

d_inline static void glRasterPos2sv_DEBUG(GLshort * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos2sv(v=%p)\n", file, line, v);
#endif
	glRasterPos2sv(v);
	dglLogError("glRasterPos2sv", file, line);
}

d_inline static void glRasterPos3d_DEBUG(GLdouble x, GLdouble y, GLdouble z,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3d(x=%f, y=%f, z=%f)\n",
		 file, line, x, y, z);
#endif
	glRasterPos3d(x, y, z);
	dglLogError("glRasterPos3d", file, line);
}

d_inline static void glRasterPos3dv_DEBUG(GLdouble * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3dv(v=%p)\n", file, line, v);
#endif
	glRasterPos3dv(v);
	dglLogError("glRasterPos3dv", file, line);
}

d_inline static void glRasterPos3f_DEBUG(GLfloat x, GLfloat y, GLfloat z,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3f(x=%f, y=%f, z=%f)\n",
		 file, line, x, y, z);
#endif
	glRasterPos3f(x, y, z);
	dglLogError("glRasterPos3f", file, line);
}

d_inline static void glRasterPos3fv_DEBUG(GLfloat * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3fv(v=%p)\n", file, line, v);
#endif
	glRasterPos3fv(v);
	dglLogError("glRasterPos3fv", file, line);
}

d_inline static void glRasterPos3i_DEBUG(GLint x, GLint y, GLint z,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3i(x=%i, y=%i, z=%i)\n",
		 file, line, x, y, z);
#endif
	glRasterPos3i(x, y, z);
	dglLogError("glRasterPos3i", file, line);
}

d_inline static void glRasterPos3iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3iv(v=%p)\n", file, line, v);
#endif
	glRasterPos3iv(v);
	dglLogError("glRasterPos3iv", file, line);
}

d_inline static void glRasterPos3s_DEBUG(GLshort x, GLshort y, GLshort z,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3s(x=%i, y=%i, z=%i)\n",
		 file, line, x, y, z);
#endif
	glRasterPos3s(x, y, z);
	dglLogError("glRasterPos3s", file, line);
}

d_inline static void glRasterPos3sv_DEBUG(GLshort * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos3sv(v=%p)\n", file, line, v);
#endif
	glRasterPos3sv(v);
	dglLogError("glRasterPos3sv", file, line);
}

d_inline static void glRasterPos4d_DEBUG(GLdouble x, GLdouble y, GLdouble z,
					 GLdouble w, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glRasterPos4d(x=%f, y=%f, z=%f, w=%f)\n",
	     file, line, x, y, z, w);
#endif
	glRasterPos4d(x, y, z, w);
	dglLogError("glRasterPos4d", file, line);
}

d_inline static void glRasterPos4dv_DEBUG(GLdouble * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos4dv(v=%p)\n", file, line, v);
#endif
	glRasterPos4dv(v);
	dglLogError("glRasterPos4dv", file, line);
}

d_inline static void glRasterPos4f_DEBUG(GLfloat x, GLfloat y, GLfloat z,
					 GLfloat w, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glRasterPos4f(x=%f, y=%f, z=%f, w=%f)\n",
	     file, line, x, y, z, w);
#endif
	glRasterPos4f(x, y, z, w);
	dglLogError("glRasterPos4f", file, line);
}

d_inline static void glRasterPos4fv_DEBUG(GLfloat * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos4fv(v=%p)\n", file, line, v);
#endif
	glRasterPos4fv(v);
	dglLogError("glRasterPos4fv", file, line);
}

d_inline static void glRasterPos4i_DEBUG(GLint x, GLint y, GLint z, GLint w,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glRasterPos4i(x=%i, y=%i, z=%i, w=%i)\n",
	     file, line, x, y, z, w);
#endif
	glRasterPos4i(x, y, z, w);
	dglLogError("glRasterPos4i", file, line);
}

d_inline static void glRasterPos4iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos4iv(v=%p)\n", file, line, v);
#endif
	glRasterPos4iv(v);
	dglLogError("glRasterPos4iv", file, line);
}

d_inline static void glRasterPos4s_DEBUG(GLshort x, GLshort y, GLshort z,
					 GLshort w, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glRasterPos4s(x=%i, y=%i, z=%i, w=%i)\n",
	     file, line, x, y, z, w);
#endif
	glRasterPos4s(x, y, z, w);
	dglLogError("glRasterPos4s", file, line);
}

d_inline static void glRasterPos4sv_DEBUG(GLshort * v, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRasterPos4sv(v=%p)\n", file, line, v);
#endif
	glRasterPos4sv(v);
	dglLogError("glRasterPos4sv", file, line);
}

d_inline static void glReadBuffer_DEBUG(GLenum mode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glReadBuffer(mode=0x%x)\n", file, line,
		 mode);
#endif
	glReadBuffer(mode);
	dglLogError("glReadBuffer", file, line);
}

d_inline static void glReadPixels_DEBUG(GLint x, GLint y, GLsizei width,
					GLsizei height, GLenum format,
					GLenum type, GLvoid * pixels,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glReadPixels(x=%i, y=%i, width=0x%x, height=0x%x, format=0x%x, type=0x%x, pixels=%p)\n",
	     file, line, x, y, width, height, format, type, pixels);
#endif
	glReadPixels(x, y, width, height, format, type, pixels);
	dglLogError("glReadPixels", file, line);
}

d_inline static void glRectd_DEBUG(GLdouble x1, GLdouble y1, GLdouble x2,
				   GLdouble y2, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRectd(x1=%f, y1=%f, x2=%f, y2=%f)\n",
		 file, line, x1, y1, x2, y2);
#endif
	glRectd(x1, y1, x2, y2);
	dglLogError("glRectd", file, line);
}

d_inline static void glRectdv_DEBUG(GLdouble * v1, GLdouble * v2,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRectdv(v1=%p, v2=%p)\n", file, line,
		 v1, v2);
#endif
	glRectdv(v1, v2);
	dglLogError("glRectdv", file, line);
}

d_inline static void glRectf_DEBUG(GLfloat x1, GLfloat y1, GLfloat x2,
				   GLfloat y2, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRectf(x1=%f, y1=%f, x2=%f, y2=%f)\n",
		 file, line, x1, y1, x2, y2);
#endif
	glRectf(x1, y1, x2, y2);
	dglLogError("glRectf", file, line);
}

d_inline static void glRectfv_DEBUG(GLfloat * v1, GLfloat * v2,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRectfv(v1=%p, v2=%p)\n", file, line,
		 v1, v2);
#endif
	glRectfv(v1, v2);
	dglLogError("glRectfv", file, line);
}

d_inline static void glRecti_DEBUG(GLint x1, GLint y1, GLint x2, GLint y2,
				   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRecti(x1=%i, y1=%i, x2=%i, y2=%i)\n",
		 file, line, x1, y1, x2, y2);
#endif
	glRecti(x1, y1, x2, y2);
	dglLogError("glRecti", file, line);
}

d_inline static void glRectiv_DEBUG(GLint * v1, GLint * v2, const char *file,
				    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRectiv(v1=%p, v2=%p)\n", file, line,
		 v1, v2);
#endif
	glRectiv(v1, v2);
	dglLogError("glRectiv", file, line);
}

d_inline static void glRects_DEBUG(GLshort x1, GLshort y1, GLshort x2,
				   GLshort y2, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRects(x1=%i, y1=%i, x2=%i, y2=%i)\n",
		 file, line, x1, y1, x2, y2);
#endif
	glRects(x1, y1, x2, y2);
	dglLogError("glRects", file, line);
}

d_inline static void glRectsv_DEBUG(GLshort * v1, GLshort * v2,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRectsv(v1=%p, v2=%p)\n", file, line,
		 v1, v2);
#endif
	glRectsv(v1, v2);
	dglLogError("glRectsv", file, line);
}

d_inline static GLint glRenderMode_DEBUG(GLenum mode, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glRenderMode(mode=0x%x)\n", file, line,
		 mode);
#endif
	glRenderMode(mode);
	dglLogError("glRenderMode", file, line);
}

d_inline static void glRotated_DEBUG(GLdouble angle, GLdouble x, GLdouble y,
				     GLdouble z, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glRotated(angle=%f, x=%f, y=%f, z=%f)\n",
	     file, line, angle, x, y, z);
#endif
	glRotated(angle, x, y, z);
	dglLogError("glRotated", file, line);
}

d_inline static void glRotatef_DEBUG(GLfloat angle, GLfloat x, GLfloat y,
				     GLfloat z, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glRotatef(angle=%f, x=%f, y=%f, z=%f)\n",
	     file, line, angle, x, y, z);
#endif
	glRotatef(angle, x, y, z);
	dglLogError("glRotatef", file, line);
}

d_inline static void glScaled_DEBUG(GLdouble x, GLdouble y, GLdouble z,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glScaled(x=%f, y=%f, z=%f)\n", file,
		 line, x, y, z);
#endif
	glScaled(x, y, z);
	dglLogError("glScaled", file, line);
}

d_inline static void glScalef_DEBUG(GLfloat x, GLfloat y, GLfloat z,
				    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glScalef(x=%f, y=%f, z=%f)\n", file,
		 line, x, y, z);
#endif
	glScalef(x, y, z);
	dglLogError("glScalef", file, line);
}

d_inline static void glScissor_DEBUG(GLint x, GLint y, GLsizei width,
				     GLsizei height, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glScissor(x=%i, y=%i, width=0x%x, height=0x%x)\n",
	     file, line, x, y, width, height);
#endif
	glScissor(x, y, width, height);
	dglLogError("glScissor", file, line);
}

d_inline static void glSelectBuffer_DEBUG(GLsizei size, GLuint * buffer,
					  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glSelectBuffer(size=0x%x, buffer=%p)\n",
		 file, line, size, buffer);
#endif
	glSelectBuffer(size, buffer);
	dglLogError("glSelectBuffer", file, line);
}

d_inline static void glShadeModel_DEBUG(GLenum mode, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glShadeModel(mode=0x%x)\n", file, line,
		 mode);
#endif
	glShadeModel(mode);
	dglLogError("glShadeModel", file, line);
}

d_inline static void glStencilFunc_DEBUG(GLenum func, GLint ref, GLuint mask,
					 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glStencilFunc(func=0x%x, ref=%i, mask=%i)\n",
	     file, line, func, ref, mask);
#endif
	glStencilFunc(func, ref, mask);
	dglLogError("glStencilFunc", file, line);
}

d_inline static void glStencilMask_DEBUG(GLuint mask, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glStencilMask(mask=%i)\n", file, line,
		 mask);
#endif
	glStencilMask(mask);
	dglLogError("glStencilMask", file, line);
}

d_inline static void glStencilOp_DEBUG(GLenum fail, GLenum zfail, GLenum zpass,
				       const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glStencilOp(fail=0x%x, zfail=0x%x, zpass=0x%x)\n",
	     file, line, fail, zfail, zpass);
#endif
	glStencilOp(fail, zfail, zpass);
	dglLogError("glStencilOp", file, line);
}

d_inline static void glTexCoord1d_DEBUG(GLdouble s, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1d(s=%f)\n", file, line, s);
#endif
	glTexCoord1d(s);
	dglLogError("glTexCoord1d", file, line);
}

d_inline static void glTexCoord1dv_DEBUG(GLdouble * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1dv(v=%p)\n", file, line, v);
#endif
	glTexCoord1dv(v);
	dglLogError("glTexCoord1dv", file, line);
}

d_inline static void glTexCoord1f_DEBUG(GLfloat s, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1f(s=%f)\n", file, line, s);
#endif
	glTexCoord1f(s);
	dglLogError("glTexCoord1f", file, line);
}

d_inline static void glTexCoord1fv_DEBUG(GLfloat * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1fv(v=%p)\n", file, line, v);
#endif
	glTexCoord1fv(v);
	dglLogError("glTexCoord1fv", file, line);
}

d_inline static void glTexCoord1i_DEBUG(GLint s, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1i(s=%i)\n", file, line, s);
#endif
	glTexCoord1i(s);
	dglLogError("glTexCoord1i", file, line);
}

d_inline static void glTexCoord1iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1iv(v=%p)\n", file, line, v);
#endif
	glTexCoord1iv(v);
	dglLogError("glTexCoord1iv", file, line);
}

d_inline static void glTexCoord1s_DEBUG(GLshort s, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1s(s=%i)\n", file, line, s);
#endif
	glTexCoord1s(s);
	dglLogError("glTexCoord1s", file, line);
}

d_inline static void glTexCoord1sv_DEBUG(GLshort * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord1sv(v=%p)\n", file, line, v);
#endif
	glTexCoord1sv(v);
	dglLogError("glTexCoord1sv", file, line);
}

d_inline static void glTexCoord2d_DEBUG(GLdouble s, GLdouble t,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2d(s=%f, t=%f)\n", file, line,
		 s, t);
#endif
	glTexCoord2d(s, t);
	dglLogError("glTexCoord2d", file, line);
}

d_inline static void glTexCoord2dv_DEBUG(GLdouble * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2dv(v=%p)\n", file, line, v);
#endif
	glTexCoord2dv(v);
	dglLogError("glTexCoord2dv", file, line);
}

d_inline static void glTexCoord2f_DEBUG(GLfloat s, GLfloat t, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2f(s=%f, t=%f)\n", file, line,
		 s, t);
#endif
	glTexCoord2f(s, t);
	dglLogError("glTexCoord2f", file, line);
}

d_inline static void glTexCoord2fv_DEBUG(GLfloat * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2fv(v=%p)\n", file, line, v);
#endif
	glTexCoord2fv(v);
	dglLogError("glTexCoord2fv", file, line);
}

d_inline static void glTexCoord2i_DEBUG(GLint s, GLint t, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2i(s=%i, t=%i)\n", file, line,
		 s, t);
#endif
	glTexCoord2i(s, t);
	dglLogError("glTexCoord2i", file, line);
}

d_inline static void glTexCoord2iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2iv(v=%p)\n", file, line, v);
#endif
	glTexCoord2iv(v);
	dglLogError("glTexCoord2iv", file, line);
}

d_inline static void glTexCoord2s_DEBUG(GLshort s, GLshort t, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2s(s=%i, t=%i)\n", file, line,
		 s, t);
#endif
	glTexCoord2s(s, t);
	dglLogError("glTexCoord2s", file, line);
}

d_inline static void glTexCoord2sv_DEBUG(GLshort * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord2sv(v=%p)\n", file, line, v);
#endif
	glTexCoord2sv(v);
	dglLogError("glTexCoord2sv", file, line);
}

d_inline static void glTexCoord3d_DEBUG(GLdouble s, GLdouble t, GLdouble r,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3d(s=%f, t=%f, r=%f)\n", file,
		 line, s, t, r);
#endif
	glTexCoord3d(s, t, r);
	dglLogError("glTexCoord3d", file, line);
}

d_inline static void glTexCoord3dv_DEBUG(GLdouble * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3dv(v=%p)\n", file, line, v);
#endif
	glTexCoord3dv(v);
	dglLogError("glTexCoord3dv", file, line);
}

d_inline static void glTexCoord3f_DEBUG(GLfloat s, GLfloat t, GLfloat r,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3f(s=%f, t=%f, r=%f)\n", file,
		 line, s, t, r);
#endif
	glTexCoord3f(s, t, r);
	dglLogError("glTexCoord3f", file, line);
}

d_inline static void glTexCoord3fv_DEBUG(GLfloat * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3fv(v=%p)\n", file, line, v);
#endif
	glTexCoord3fv(v);
	dglLogError("glTexCoord3fv", file, line);
}

d_inline static void glTexCoord3i_DEBUG(GLint s, GLint t, GLint r,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3i(s=%i, t=%i, r=%i)\n", file,
		 line, s, t, r);
#endif
	glTexCoord3i(s, t, r);
	dglLogError("glTexCoord3i", file, line);
}

d_inline static void glTexCoord3iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3iv(v=%p)\n", file, line, v);
#endif
	glTexCoord3iv(v);
	dglLogError("glTexCoord3iv", file, line);
}

d_inline static void glTexCoord3s_DEBUG(GLshort s, GLshort t, GLshort r,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3s(s=%i, t=%i, r=%i)\n", file,
		 line, s, t, r);
#endif
	glTexCoord3s(s, t, r);
	dglLogError("glTexCoord3s", file, line);
}

d_inline static void glTexCoord3sv_DEBUG(GLshort * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord3sv(v=%p)\n", file, line, v);
#endif
	glTexCoord3sv(v);
	dglLogError("glTexCoord3sv", file, line);
}

d_inline static void glTexCoord4d_DEBUG(GLdouble s, GLdouble t, GLdouble r,
					GLdouble q, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4d(s=%f, t=%f, r=%f, q=%f)\n",
		 file, line, s, t, r, q);
#endif
	glTexCoord4d(s, t, r, q);
	dglLogError("glTexCoord4d", file, line);
}

d_inline static void glTexCoord4dv_DEBUG(GLdouble * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4dv(v=%p)\n", file, line, v);
#endif
	glTexCoord4dv(v);
	dglLogError("glTexCoord4dv", file, line);
}

d_inline static void glTexCoord4f_DEBUG(GLfloat s, GLfloat t, GLfloat r,
					GLfloat q, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4f(s=%f, t=%f, r=%f, q=%f)\n",
		 file, line, s, t, r, q);
#endif
	glTexCoord4f(s, t, r, q);
	dglLogError("glTexCoord4f", file, line);
}

d_inline static void glTexCoord4fv_DEBUG(GLfloat * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4fv(v=%p)\n", file, line, v);
#endif
	glTexCoord4fv(v);
	dglLogError("glTexCoord4fv", file, line);
}

d_inline static void glTexCoord4i_DEBUG(GLint s, GLint t, GLint r, GLint q,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4i(s=%i, t=%i, r=%i, q=%i)\n",
		 file, line, s, t, r, q);
#endif
	glTexCoord4i(s, t, r, q);
	dglLogError("glTexCoord4i", file, line);
}

d_inline static void glTexCoord4iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4iv(v=%p)\n", file, line, v);
#endif
	glTexCoord4iv(v);
	dglLogError("glTexCoord4iv", file, line);
}

d_inline static void glTexCoord4s_DEBUG(GLshort s, GLshort t, GLshort r,
					GLshort q, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4s(s=%i, t=%i, r=%i, q=%i)\n",
		 file, line, s, t, r, q);
#endif
	glTexCoord4s(s, t, r, q);
	dglLogError("glTexCoord4s", file, line);
}

d_inline static void glTexCoord4sv_DEBUG(GLshort * v, const char *file,
					 int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTexCoord4sv(v=%p)\n", file, line, v);
#endif
	glTexCoord4sv(v);
	dglLogError("glTexCoord4sv", file, line);
}

d_inline static void glTexCoordPointer_DEBUG(GLint size, GLenum type,
					     GLsizei stride, GLvoid * pointer,
					     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexCoordPointer(size=%i, type=0x%x, stride=0x%x, pointer=%p)\n",
	     file, line, size, type, stride, pointer);
#endif
	glTexCoordPointer(size, type, stride, pointer);
	dglLogError("glTexCoordPointer", file, line);
}

d_inline static void glTexEnvf_DEBUG(GLenum target, GLenum pname, GLfloat param,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexEnvf(target=0x%x, pname=0x%x, param=%f)\n",
	     file, line, target, pname, param);
#endif
	glTexEnvf(target, pname, param);
	dglLogError("glTexEnvf", file, line);
}

d_inline static void glTexEnvfv_DEBUG(GLenum target, GLenum pname,
				      GLfloat * params, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexEnvfv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glTexEnvfv(target, pname, params);
	dglLogError("glTexEnvfv", file, line);
}

d_inline static void glTexEnvi_DEBUG(GLenum target, GLenum pname, GLint param,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexEnvi(target=0x%x, pname=0x%x, param=%i)\n",
	     file, line, target, pname, param);
#endif
	glTexEnvi(target, pname, param);
	dglLogError("glTexEnvi", file, line);
}

d_inline static void glTexEnviv_DEBUG(GLenum target, GLenum pname,
				      GLint * params, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexEnviv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glTexEnviv(target, pname, params);
	dglLogError("glTexEnviv", file, line);
}

d_inline static void glTexGend_DEBUG(GLenum coord, GLenum pname, GLdouble param,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexGend(coord=0x%x, pname=0x%x, param=%f)\n",
	     file, line, coord, pname, param);
#endif
	glTexGend(coord, pname, param);
	dglLogError("glTexGend", file, line);
}

d_inline static void glTexGendv_DEBUG(GLenum coord, GLenum pname,
				      GLdouble * params, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexGendv(coord=0x%x, pname=0x%x, params=%p)\n",
	     file, line, coord, pname, params);
#endif
	glTexGendv(coord, pname, params);
	dglLogError("glTexGendv", file, line);
}

d_inline static void glTexGenf_DEBUG(GLenum coord, GLenum pname, GLfloat param,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexGenf(coord=0x%x, pname=0x%x, param=%f)\n",
	     file, line, coord, pname, param);
#endif
	glTexGenf(coord, pname, param);
	dglLogError("glTexGenf", file, line);
}

d_inline static void glTexGenfv_DEBUG(GLenum coord, GLenum pname,
				      GLfloat * params, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexGenfv(coord=0x%x, pname=0x%x, params=%p)\n",
	     file, line, coord, pname, params);
#endif
	glTexGenfv(coord, pname, params);
	dglLogError("glTexGenfv", file, line);
}

d_inline static void glTexGeni_DEBUG(GLenum coord, GLenum pname, GLint param,
				     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexGeni(coord=0x%x, pname=0x%x, param=%i)\n",
	     file, line, coord, pname, param);
#endif
	glTexGeni(coord, pname, param);
	dglLogError("glTexGeni", file, line);
}

d_inline static void glTexGeniv_DEBUG(GLenum coord, GLenum pname,
				      GLint * params, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexGeniv(coord=0x%x, pname=0x%x, params=%p)\n",
	     file, line, coord, pname, params);
#endif
	glTexGeniv(coord, pname, params);
	dglLogError("glTexGeniv", file, line);
}

d_inline static void glTexImage1D_DEBUG(GLenum target, GLint level,
					GLint internalformat, GLsizei width,
					GLint border, GLenum format,
					GLenum type, GLvoid * pixels,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexImage1D(target=0x%x, level=%i, internalformat=%i, width=0x%x, border=%i, format=0x%x, type=0x%x, pixels=%p)\n",
	     file, line, target, level, internalformat, width, border, format,
	     type, pixels);
#endif
	glTexImage1D(target, level, internalformat, width, border, format, type,
		     pixels);
	dglLogError("glTexImage1D", file, line);
}

d_inline static void glTexImage2D_DEBUG(GLenum target, GLint level,
					GLint internalformat, GLsizei width,
					GLsizei height, GLint border,
					GLenum format, GLenum type,
					GLvoid * pixels, const char *file,
					int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexImage2D(target=0x%x, level=%i, internalformat=%i, width=0x%x, height=0x%x, border=%i, format=0x%x, type=0x%x, pixels=%p)\n",
	     file, line, target, level, internalformat, width, height, border,
	     format, type, pixels);
#endif
	glTexImage2D(target, level, internalformat, width, height, border,
		     format, type, pixels);
	dglLogError("glTexImage2D", file, line);
}

d_inline static void glTexParameterf_DEBUG(GLenum target, GLenum pname,
					   GLfloat param, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexParameterf(target=0x%x, pname=0x%x, param=%f)\n",
	     file, line, target, pname, param);
#endif
	glTexParameterf(target, pname, param);
	dglLogError("glTexParameterf", file, line);
}

d_inline static void glTexParameterfv_DEBUG(GLenum target, GLenum pname,
					    GLfloat * params, const char *file,
					    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexParameterfv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glTexParameterfv(target, pname, params);
	dglLogError("glTexParameterfv", file, line);
}

d_inline static void glTexParameteri_DEBUG(GLenum target, GLenum pname,
					   GLint param, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexParameteri(target=0x%x, pname=0x%x, param=%i)\n",
	     file, line, target, pname, param);
#endif
	glTexParameteri(target, pname, param);
	dglLogError("glTexParameteri", file, line);
}

d_inline static void glTexParameteriv_DEBUG(GLenum target, GLenum pname,
					    GLint * params, const char *file,
					    int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexParameteriv(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	glTexParameteriv(target, pname, params);
	dglLogError("glTexParameteriv", file, line);
}

d_inline static void glTexSubImage1D_DEBUG(GLenum target, GLint level,
					   GLint xoffset, GLsizei width,
					   GLenum format, GLenum type,
					   GLvoid * pixels, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexSubImage1D(target=0x%x, level=%i, xoffset=%i, width=0x%x, format=0x%x, type=0x%x, pixels=%p)\n",
	     file, line, target, level, xoffset, width, format, type, pixels);
#endif
	glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
	dglLogError("glTexSubImage1D", file, line);
}

d_inline static void glTexSubImage2D_DEBUG(GLenum target, GLint level,
					   GLint xoffset, GLint yoffset,
					   GLsizei width, GLsizei height,
					   GLenum format, GLenum type,
					   GLvoid * pixels, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glTexSubImage2D(target=0x%x, level=%i, xoffset=%i, yoffset=%i, width=0x%x, height=0x%x, format=0x%x, type=0x%x, pixels=%p)\n",
	     file, line, target, level, xoffset, yoffset, width, height, format,
	     type, pixels);
#endif
	glTexSubImage2D(target, level, xoffset, yoffset, width, height, format,
			type, pixels);
	dglLogError("glTexSubImage2D", file, line);
}

d_inline static void glTranslated_DEBUG(GLdouble x, GLdouble y, GLdouble z,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTranslated(x=%f, y=%f, z=%f)\n", file,
		 line, x, y, z);
#endif
#ifdef HAVE_GLES
	glTranslatef(x, y, z);
#else
	glTranslated(x, y, z);
#endif
	dglLogError("glTranslated", file, line);
}

d_inline static void glTranslatef_DEBUG(GLfloat x, GLfloat y, GLfloat z,
					const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glTranslatef(x=%f, y=%f, z=%f)\n", file,
		 line, x, y, z);
#endif
	glTranslatef(x, y, z);
	dglLogError("glTranslatef", file, line);
}

d_inline static void glVertex2d_DEBUG(GLdouble x, GLdouble y, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2d(x=%f, y=%f)\n", file, line,
		 x, y);
#endif
	glVertex2d(x, y);
	dglLogError("glVertex2d", file, line);
}

d_inline static void glVertex2dv_DEBUG(GLdouble * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2dv(v=%p)\n", file, line, v);
#endif
	glVertex2dv(v);
	dglLogError("glVertex2dv", file, line);
}

d_inline static void glVertex2f_DEBUG(GLfloat x, GLfloat y, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2f(x=%f, y=%f)\n", file, line,
		 x, y);
#endif
	glVertex2f(x, y);
	dglLogError("glVertex2f", file, line);
}

d_inline static void glVertex2fv_DEBUG(GLfloat * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2fv(v=%p)\n", file, line, v);
#endif
	glVertex2fv(v);
	dglLogError("glVertex2fv", file, line);
}

d_inline static void glVertex2i_DEBUG(GLint x, GLint y, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2i(x=%i, y=%i)\n", file, line,
		 x, y);
#endif
	glVertex2i(x, y);
	dglLogError("glVertex2i", file, line);
}

d_inline static void glVertex2iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2iv(v=%p)\n", file, line, v);
#endif
	glVertex2iv(v);
	dglLogError("glVertex2iv", file, line);
}

d_inline static void glVertex2s_DEBUG(GLshort x, GLshort y, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2s(x=%i, y=%i)\n", file, line,
		 x, y);
#endif
	glVertex2s(x, y);
	dglLogError("glVertex2s", file, line);
}

d_inline static void glVertex2sv_DEBUG(GLshort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex2sv(v=%p)\n", file, line, v);
#endif
	glVertex2sv(v);
	dglLogError("glVertex2sv", file, line);
}

d_inline static void glVertex3d_DEBUG(GLdouble x, GLdouble y, GLdouble z,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3d(x=%f, y=%f, z=%f)\n", file,
		 line, x, y, z);
#endif
	glVertex3d(x, y, z);
	dglLogError("glVertex3d", file, line);
}

d_inline static void glVertex3dv_DEBUG(GLdouble * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3dv(v=%p)\n", file, line, v);
#endif
	glVertex3dv(v);
	dglLogError("glVertex3dv", file, line);
}

d_inline static void glVertex3f_DEBUG(GLfloat x, GLfloat y, GLfloat z,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3f(x=%f, y=%f, z=%f)\n", file,
		 line, x, y, z);
#endif
	glVertex3f(x, y, z);
	dglLogError("glVertex3f", file, line);
}

d_inline static void glVertex3fv_DEBUG(GLfloat * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3fv(v=%p)\n", file, line, v);
#endif
	glVertex3fv(v);
	dglLogError("glVertex3fv", file, line);
}

d_inline static void glVertex3i_DEBUG(GLint x, GLint y, GLint z,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3i(x=%i, y=%i, z=%i)\n", file,
		 line, x, y, z);
#endif
	glVertex3i(x, y, z);
	dglLogError("glVertex3i", file, line);
}

d_inline static void glVertex3iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3iv(v=%p)\n", file, line, v);
#endif
	glVertex3iv(v);
	dglLogError("glVertex3iv", file, line);
}

d_inline static void glVertex3s_DEBUG(GLshort x, GLshort y, GLshort z,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3s(x=%i, y=%i, z=%i)\n", file,
		 line, x, y, z);
#endif
	glVertex3s(x, y, z);
	dglLogError("glVertex3s", file, line);
}

d_inline static void glVertex3sv_DEBUG(GLshort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex3sv(v=%p)\n", file, line, v);
#endif
	glVertex3sv(v);
	dglLogError("glVertex3sv", file, line);
}

d_inline static void glVertex4d_DEBUG(GLdouble x, GLdouble y, GLdouble z,
				      GLdouble w, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4d(x=%f, y=%f, z=%f, w=%f)\n",
		 file, line, x, y, z, w);
#endif
	glVertex4d(x, y, z, w);
	dglLogError("glVertex4d", file, line);
}

d_inline static void glVertex4dv_DEBUG(GLdouble * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4dv(v=%p)\n", file, line, v);
#endif
	glVertex4dv(v);
	dglLogError("glVertex4dv", file, line);
}

d_inline static void glVertex4f_DEBUG(GLfloat x, GLfloat y, GLfloat z,
				      GLfloat w, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4f(x=%f, y=%f, z=%f, w=%f)\n",
		 file, line, x, y, z, w);
#endif
	glVertex4f(x, y, z, w);
	dglLogError("glVertex4f", file, line);
}

d_inline static void glVertex4fv_DEBUG(GLfloat * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4fv(v=%p)\n", file, line, v);
#endif
	glVertex4fv(v);
	dglLogError("glVertex4fv", file, line);
}

d_inline static void glVertex4i_DEBUG(GLint x, GLint y, GLint z, GLint w,
				      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4i(x=%i, y=%i, z=%i, w=%i)\n",
		 file, line, x, y, z, w);
#endif
	glVertex4i(x, y, z, w);
	dglLogError("glVertex4i", file, line);
}

d_inline static void glVertex4iv_DEBUG(GLint * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4iv(v=%p)\n", file, line, v);
#endif
	glVertex4iv(v);
	dglLogError("glVertex4iv", file, line);
}

d_inline static void glVertex4s_DEBUG(GLshort x, GLshort y, GLshort z,
				      GLshort w, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4s(x=%i, y=%i, z=%i, w=%i)\n",
		 file, line, x, y, z, w);
#endif
	glVertex4s(x, y, z, w);
	dglLogError("glVertex4s", file, line);
}

d_inline static void glVertex4sv_DEBUG(GLshort * v, const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glVertex4sv(v=%p)\n", file, line, v);
#endif
	glVertex4sv(v);
	dglLogError("glVertex4sv", file, line);
}

d_inline static void glVertexPointer_DEBUG(GLint size, GLenum type,
					   GLsizei stride, GLvoid * pointer,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glVertexPointer(size=%i, type=0x%x, stride=0x%x, pointer=%p)\n",
	     file, line, size, type, stride, pointer);
#endif
	glVertexPointer(size, type, stride, pointer);
	dglLogError("glVertexPointer", file, line);
}

d_inline static void glViewport_DEBUG(GLint x, GLint y, GLsizei width,
				      GLsizei height, const char *file,
				      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glViewport(x=%i, y=%i, width=0x%x, height=0x%x)\n",
	     file, line, x, y, width, height);
#endif
	glViewport(x, y, width, height);
	dglLogError("glViewport", file, line);
}

#define dglAccum(op, value) glAccum_DEBUG(op, value, __FILE__, __LINE__)
#define dglAlphaFunc(func, ref) glAlphaFunc_DEBUG(func, ref, __FILE__, __LINE__)
#define dglAreTexturesResident(n, textures, residences) glAreTexturesResident_DEBUG(n, textures, residences, __FILE__, __LINE__)
#define dglArrayElement(i) glArrayElement_DEBUG(i, __FILE__, __LINE__)
#define dglBegin(mode) glBegin_DEBUG(mode, __FILE__, __LINE__)
#define dglBindTexture(target, texture) glBindTexture_DEBUG(target, texture, __FILE__, __LINE__)
#define dglBitmap(width, height, xorig, yorig, xmove, ymove, bitmap) glBitmap_DEBUG(width, height, xorig, yorig, xmove, ymove, bitmap, __FILE__, __LINE__)
#define dglBlendFunc(sfactor, dfactor) glBlendFunc_DEBUG(sfactor, dfactor, __FILE__, __LINE__)
#define dglCallList(list) glCallList_DEBUG(list, __FILE__, __LINE__)
#define dglCallLists(n, type, lists) glCallLists_DEBUG(n, type, lists, __FILE__, __LINE__)
#define dglClear(mask) glClear_DEBUG(mask, __FILE__, __LINE__)
#define dglClearAccum(red, green, blue, alpha) glClearAccum_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglClearColor(red, green, blue, alpha) glClearColor_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglClearDepth(depth) glClearDepth_DEBUG(depth, __FILE__, __LINE__)
#define dglClearIndex(c) glClearIndex_DEBUG(c, __FILE__, __LINE__)
#define dglClearStencil(s) glClearStencil_DEBUG(s, __FILE__, __LINE__)
#define dglClipPlane(plane, equation) glClipPlane_DEBUG(plane, equation, __FILE__, __LINE__)
#define dglColor3b(red, green, blue) glColor3b_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3bv(v) glColor3bv_DEBUG(v, __FILE__, __LINE__)
#define dglColor3d(red, green, blue) glColor3d_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3dv(v) glColor3dv_DEBUG(v, __FILE__, __LINE__)
#define dglColor3f(red, green, blue) glColor3f_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3fv(v) glColor3fv_DEBUG(v, __FILE__, __LINE__)
#define dglColor3i(red, green, blue) glColor3i_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3iv(v) glColor3iv_DEBUG(v, __FILE__, __LINE__)
#define dglColor3s(red, green, blue) glColor3s_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3sv(v) glColor3sv_DEBUG(v, __FILE__, __LINE__)
#define dglColor3ub(red, green, blue) glColor3ub_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3ubv(v) glColor3ubv_DEBUG(v, __FILE__, __LINE__)
#define dglColor3ui(red, green, blue) glColor3ui_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3uiv(v) glColor3uiv_DEBUG(v, __FILE__, __LINE__)
#define dglColor3us(red, green, blue) glColor3us_DEBUG(red, green, blue, __FILE__, __LINE__)
#define dglColor3usv(v) glColor3usv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4b(red, green, blue, alpha) glColor4b_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4bv(v) glColor4bv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4d(red, green, blue, alpha) glColor4d_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4dv(v) glColor4dv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4f(red, green, blue, alpha) glColor4f_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4fv(v) glColor4fv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4i(red, green, blue, alpha) glColor4i_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4iv(v) glColor4iv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4s(red, green, blue, alpha) glColor4s_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4sv(v) glColor4sv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4ub(red, green, blue, alpha) glColor4ub_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4ubv(v) glColor4ubv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4ui(red, green, blue, alpha) glColor4ui_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4uiv(v) glColor4uiv_DEBUG(v, __FILE__, __LINE__)
#define dglColor4us(red, green, blue, alpha) glColor4us_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColor4usv(v) glColor4usv_DEBUG(v, __FILE__, __LINE__)
#define dglColorMask(red, green, blue, alpha) glColorMask_DEBUG(red, green, blue, alpha, __FILE__, __LINE__)
#define dglColorMaterial(face, mode) glColorMaterial_DEBUG(face, mode, __FILE__, __LINE__)
#define dglColorPointer(size, type, stride, pointer) glColorPointer_DEBUG(size, type, stride, pointer, __FILE__, __LINE__)
#define dglCopyPixels(x, y, width, height, type) glCopyPixels_DEBUG(x, y, width, height, type, __FILE__, __LINE__)
#define dglCopyTexImage1D(target, level, internalFormat, x, y, width, border) glCopyTexImage1D_DEBUG(target, level, internalFormat, x, y, width, border, __FILE__, __LINE__)
#define dglCopyTexImage2D(target, level, internalFormat, x, y, width, height, border) glCopyTexImage2D_DEBUG(target, level, internalFormat, x, y, width, height, border, __FILE__, __LINE__)
#define dglCopyTexSubImage1D(target, level, xoffset, x, y, width) glCopyTexSubImage1D_DEBUG(target, level, xoffset, x, y, width, __FILE__, __LINE__)
#define dglCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height) glCopyTexSubImage2D_DEBUG(target, level, xoffset, yoffset, x, y, width, height, __FILE__, __LINE__)
#define dglCullFace(mode) glCullFace_DEBUG(mode, __FILE__, __LINE__)
#define dglDeleteLists(list, range) glDeleteLists_DEBUG(list, range, __FILE__, __LINE__)
#define dglDeleteTextures(n, textures) glDeleteTextures_DEBUG(n, textures, __FILE__, __LINE__)
#define dglDepthFunc(func) glDepthFunc_DEBUG(func, __FILE__, __LINE__)
#define dglDepthMask(flag) glDepthMask_DEBUG(flag, __FILE__, __LINE__)
#define dglDepthRange(zNear, zFar) glDepthRange_DEBUG(zNear, zFar, __FILE__, __LINE__)
#define dglDisable(cap) glDisable_DEBUG(cap, __FILE__, __LINE__)
#define dglDisableClientState(array) glDisableClientState_DEBUG(array, __FILE__, __LINE__)
#define dglDrawArrays(mode, first, count) glDrawArrays_DEBUG(mode, first, count, __FILE__, __LINE__)
#define dglDrawBuffer(mode) glDrawBuffer_DEBUG(mode, __FILE__, __LINE__)
#define dglDrawElements(mode, count, type, indices) glDrawElements_DEBUG(mode, count, type, indices, __FILE__, __LINE__)
#define dglDrawPixels(width, height, format, type, pixels) glDrawPixels_DEBUG(width, height, format, type, pixels, __FILE__, __LINE__)
#define dglEdgeFlag(flag) glEdgeFlag_DEBUG(flag, __FILE__, __LINE__)
#define dglEdgeFlagPointer(stride, pointer) glEdgeFlagPointer_DEBUG(stride, pointer, __FILE__, __LINE__)
#define dglEdgeFlagv(flag) glEdgeFlagv_DEBUG(flag, __FILE__, __LINE__)
#define dglEnable(cap) glEnable_DEBUG(cap, __FILE__, __LINE__)
#define dglEnableClientState(array) glEnableClientState_DEBUG(array, __FILE__, __LINE__)
#define dglEnd() glEnd_DEBUG(__FILE__, __LINE__)
#define dglEndList() glEndList_DEBUG(__FILE__, __LINE__)
#define dglEvalCoord1d(u) glEvalCoord1d_DEBUG(u, __FILE__, __LINE__)
#define dglEvalCoord1dv(u) glEvalCoord1dv_DEBUG(u, __FILE__, __LINE__)
#define dglEvalCoord1f(u) glEvalCoord1f_DEBUG(u, __FILE__, __LINE__)
#define dglEvalCoord1fv(u) glEvalCoord1fv_DEBUG(u, __FILE__, __LINE__)
#define dglEvalCoord2d(u, v) glEvalCoord2d_DEBUG(u, v, __FILE__, __LINE__)
#define dglEvalCoord2dv(u) glEvalCoord2dv_DEBUG(u, __FILE__, __LINE__)
#define dglEvalCoord2f(u, v) glEvalCoord2f_DEBUG(u, v, __FILE__, __LINE__)
#define dglEvalCoord2fv(u) glEvalCoord2fv_DEBUG(u, __FILE__, __LINE__)
#define dglEvalMesh1(mode, i1, i2) glEvalMesh1_DEBUG(mode, i1, i2, __FILE__, __LINE__)
#define dglEvalMesh2(mode, i1, i2, j1, j2) glEvalMesh2_DEBUG(mode, i1, i2, j1, j2, __FILE__, __LINE__)
#define dglEvalPoint1(i) glEvalPoint1_DEBUG(i, __FILE__, __LINE__)
#define dglEvalPoint2(i, j) glEvalPoint2_DEBUG(i, j, __FILE__, __LINE__)
#define dglFeedbackBuffer(size, type, buffer) glFeedbackBuffer_DEBUG(size, type, buffer, __FILE__, __LINE__)
#define dglFinish() glFinish_DEBUG(__FILE__, __LINE__)
#define dglFlush() glFlush_DEBUG(__FILE__, __LINE__)
#define dglFogf(pname, param) glFogf_DEBUG(pname, param, __FILE__, __LINE__)
#define dglFogfv(pname, params) glFogfv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglFogi(pname, param) glFogi_DEBUG(pname, param, __FILE__, __LINE__)
#define dglFogiv(pname, params) glFogiv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglFrontFace(mode) glFrontFace_DEBUG(mode, __FILE__, __LINE__)
#define dglFrustum(left, right, bottom, top, zNear, zFar) glFrustum_DEBUG(left, right, bottom, top, zNear, zFar, __FILE__, __LINE__)
#define dglGenLists(range) glGenLists_DEBUG(range, __FILE__, __LINE__)
#define dglGenTextures(n, textures) glGenTextures_DEBUG(n, textures, __FILE__, __LINE__)
#define dglGetBooleanv(pname, params) glGetBooleanv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglGetClipPlane(plane, equation) glGetClipPlane_DEBUG(plane, equation, __FILE__, __LINE__)
#define dglGetDoublev(pname, params) glGetDoublev_DEBUG(pname, params, __FILE__, __LINE__)
#define dglGetError() glGetError_DEBUG(__FILE__, __LINE__)
#define dglGetFloatv(pname, params) glGetFloatv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglGetIntegerv(pname, params) glGetIntegerv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglGetLightfv(light, pname, params) glGetLightfv_DEBUG(light, pname, params, __FILE__, __LINE__)
#define dglGetLightiv(light, pname, params) glGetLightiv_DEBUG(light, pname, params, __FILE__, __LINE__)
#define dglGetMapdv(target, query, v) glGetMapdv_DEBUG(target, query, v, __FILE__, __LINE__)
#define dglGetMapfv(target, query, v) glGetMapfv_DEBUG(target, query, v, __FILE__, __LINE__)
#define dglGetMapiv(target, query, v) glGetMapiv_DEBUG(target, query, v, __FILE__, __LINE__)
#define dglGetMaterialfv(face, pname, params) glGetMaterialfv_DEBUG(face, pname, params, __FILE__, __LINE__)
#define dglGetMaterialiv(face, pname, params) glGetMaterialiv_DEBUG(face, pname, params, __FILE__, __LINE__)
#define dglGetPixelMapfv(map, values) glGetPixelMapfv_DEBUG(map, values, __FILE__, __LINE__)
#define dglGetPixelMapuiv(map, values) glGetPixelMapuiv_DEBUG(map, values, __FILE__, __LINE__)
#define dglGetPixelMapusv(map, values) glGetPixelMapusv_DEBUG(map, values, __FILE__, __LINE__)
#define dglGetPointerv(pname, params) glGetPointerv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglGetPolygonStipple(mask) glGetPolygonStipple_DEBUG(mask, __FILE__, __LINE__)
#define dglGetTexEnvfv(target, pname, params) glGetTexEnvfv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglGetTexEnviv(target, pname, params) glGetTexEnviv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglGetTexGendv(coord, pname, params) glGetTexGendv_DEBUG(coord, pname, params, __FILE__, __LINE__)
#define dglGetTexGenfv(coord, pname, params) glGetTexGenfv_DEBUG(coord, pname, params, __FILE__, __LINE__)
#define dglGetTexGeniv(coord, pname, params) glGetTexGeniv_DEBUG(coord, pname, params, __FILE__, __LINE__)
#define dglGetTexImage(target, level, format, type, pixels) glGetTexImage_DEBUG(target, level, format, type, pixels, __FILE__, __LINE__)
#define dglGetTexLevelParameterfv(target, level, pname, params) glGetTexLevelParameterfv_DEBUG(target, level, pname, params, __FILE__, __LINE__)
#define dglGetTexLevelParameteriv(target, level, pname, params) glGetTexLevelParameteriv_DEBUG(target, level, pname, params, __FILE__, __LINE__)
#define dglGetTexParameterfv(target, pname, params) glGetTexParameterfv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglGetTexParameteriv(target, pname, params) glGetTexParameteriv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglHint(target, mode) glHint_DEBUG(target, mode, __FILE__, __LINE__)
#define dglIndexMask(mask) glIndexMask_DEBUG(mask, __FILE__, __LINE__)
#define dglIndexPointer(type, stride, pointer) glIndexPointer_DEBUG(type, stride, pointer, __FILE__, __LINE__)
#define dglIndexd(c) glIndexd_DEBUG(c, __FILE__, __LINE__)
#define dglIndexdv(c) glIndexdv_DEBUG(c, __FILE__, __LINE__)
#define dglIndexf(c) glIndexf_DEBUG(c, __FILE__, __LINE__)
#define dglIndexfv(c) glIndexfv_DEBUG(c, __FILE__, __LINE__)
#define dglIndexi(c) glIndexi_DEBUG(c, __FILE__, __LINE__)
#define dglIndexiv(c) glIndexiv_DEBUG(c, __FILE__, __LINE__)
#define dglIndexs(c) glIndexs_DEBUG(c, __FILE__, __LINE__)
#define dglIndexsv(c) glIndexsv_DEBUG(c, __FILE__, __LINE__)
#define dglIndexub(c) glIndexub_DEBUG(c, __FILE__, __LINE__)
#define dglIndexubv(c) glIndexubv_DEBUG(c, __FILE__, __LINE__)
#define dglInitNames() glInitNames_DEBUG(__FILE__, __LINE__)
#define dglInterleavedArrays(format, stride, pointer) glInterleavedArrays_DEBUG(format, stride, pointer, __FILE__, __LINE__)
#define dglIsEnabled(cap) glIsEnabled_DEBUG(cap, __FILE__, __LINE__)
#define dglIsList(list) glIsList_DEBUG(list, __FILE__, __LINE__)
#define dglIsTexture(texture) glIsTexture_DEBUG(texture, __FILE__, __LINE__)
#define dglLightModelf(pname, param) glLightModelf_DEBUG(pname, param, __FILE__, __LINE__)
#define dglLightModelfv(pname, params) glLightModelfv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglLightModeli(pname, param) glLightModeli_DEBUG(pname, param, __FILE__, __LINE__)
#define dglLightModeliv(pname, params) glLightModeliv_DEBUG(pname, params, __FILE__, __LINE__)
#define dglLightf(light, pname, param) glLightf_DEBUG(light, pname, param, __FILE__, __LINE__)
#define dglLightfv(light, pname, params) glLightfv_DEBUG(light, pname, params, __FILE__, __LINE__)
#define dglLighti(light, pname, param) glLighti_DEBUG(light, pname, param, __FILE__, __LINE__)
#define dglLightiv(light, pname, params) glLightiv_DEBUG(light, pname, params, __FILE__, __LINE__)
#define dglLineStipple(factor, pattern) glLineStipple_DEBUG(factor, pattern, __FILE__, __LINE__)
#define dglLineWidth(width) glLineWidth_DEBUG(width, __FILE__, __LINE__)
#define dglListBase(base) glListBase_DEBUG(base, __FILE__, __LINE__)
#define dglLoadIdentity() glLoadIdentity_DEBUG(__FILE__, __LINE__)
#define dglLoadMatrixd(m) glLoadMatrixd_DEBUG(m, __FILE__, __LINE__)
#define dglLoadMatrixf(m) glLoadMatrixf_DEBUG(m, __FILE__, __LINE__)
#define dglLoadName(name) glLoadName_DEBUG(name, __FILE__, __LINE__)
#define dglLogicOp(opcode) glLogicOp_DEBUG(opcode, __FILE__, __LINE__)
#define dglMap1d(target, u1, u2, stride, order, points) glMap1d_DEBUG(target, u1, u2, stride, order, points, __FILE__, __LINE__)
#define dglMap1f(target, u1, u2, stride, order, points) glMap1f_DEBUG(target, u1, u2, stride, order, points, __FILE__, __LINE__)
#define dglMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) glMap2d_DEBUG(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points, __FILE__, __LINE__)
#define dglMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) glMap2f_DEBUG(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points, __FILE__, __LINE__)
#define dglMapGrid1d(un, u1, u2) glMapGrid1d_DEBUG(un, u1, u2, __FILE__, __LINE__)
#define dglMapGrid1f(un, u1, u2) glMapGrid1f_DEBUG(un, u1, u2, __FILE__, __LINE__)
#define dglMapGrid2d(un, u1, u2, vn, v1, v2) glMapGrid2d_DEBUG(un, u1, u2, vn, v1, v2, __FILE__, __LINE__)
#define dglMapGrid2f(un, u1, u2, vn, v1, v2) glMapGrid2f_DEBUG(un, u1, u2, vn, v1, v2, __FILE__, __LINE__)
#define dglMaterialf(face, pname, param) glMaterialf_DEBUG(face, pname, param, __FILE__, __LINE__)
#define dglMaterialfv(face, pname, params) glMaterialfv_DEBUG(face, pname, params, __FILE__, __LINE__)
#define dglMateriali(face, pname, param) glMateriali_DEBUG(face, pname, param, __FILE__, __LINE__)
#define dglMaterialiv(face, pname, params) glMaterialiv_DEBUG(face, pname, params, __FILE__, __LINE__)
#define dglMatrixMode(mode) glMatrixMode_DEBUG(mode, __FILE__, __LINE__)
#define dglMultMatrixd(m) glMultMatrixd_DEBUG(m, __FILE__, __LINE__)
#define dglMultMatrixf(m) glMultMatrixf_DEBUG(m, __FILE__, __LINE__)
#define dglNewList(list, mode) glNewList_DEBUG(list, mode, __FILE__, __LINE__)
#define dglNormal3b(nx, ny, nz) glNormal3b_DEBUG(nx, ny, nz, __FILE__, __LINE__)
#define dglNormal3bv(v) glNormal3bv_DEBUG(v, __FILE__, __LINE__)
#define dglNormal3d(nx, ny, nz) glNormal3d_DEBUG(nx, ny, nz, __FILE__, __LINE__)
#define dglNormal3dv(v) glNormal3dv_DEBUG(v, __FILE__, __LINE__)
#define dglNormal3f(nx, ny, nz) glNormal3f_DEBUG(nx, ny, nz, __FILE__, __LINE__)
#define dglNormal3fv(v) glNormal3fv_DEBUG(v, __FILE__, __LINE__)
#define dglNormal3i(nx, ny, nz) glNormal3i_DEBUG(nx, ny, nz, __FILE__, __LINE__)
#define dglNormal3iv(v) glNormal3iv_DEBUG(v, __FILE__, __LINE__)
#define dglNormal3s(nx, ny, nz) glNormal3s_DEBUG(nx, ny, nz, __FILE__, __LINE__)
#define dglNormal3sv(v) glNormal3sv_DEBUG(v, __FILE__, __LINE__)
#define dglNormalPointer(type, stride, pointer) glNormalPointer_DEBUG(type, stride, pointer, __FILE__, __LINE__)
#define dglOrtho(left, right, bottom, top, zNear, zFar) glOrtho_DEBUG(left, right, bottom, top, zNear, zFar, __FILE__, __LINE__)
#define dglPassThrough(token) glPassThrough_DEBUG(token, __FILE__, __LINE__)
#define dglPixelMapfv(map, mapsize, values) glPixelMapfv_DEBUG(map, mapsize, values, __FILE__, __LINE__)
#define dglPixelMapuiv(map, mapsize, values) glPixelMapuiv_DEBUG(map, mapsize, values, __FILE__, __LINE__)
#define dglPixelMapusv(map, mapsize, values) glPixelMapusv_DEBUG(map, mapsize, values, __FILE__, __LINE__)
#define dglPixelStoref(pname, param) glPixelStoref_DEBUG(pname, param, __FILE__, __LINE__)
#define dglPixelStorei(pname, param) glPixelStorei_DEBUG(pname, param, __FILE__, __LINE__)
#define dglPixelTransferf(pname, param) glPixelTransferf_DEBUG(pname, param, __FILE__, __LINE__)
#define dglPixelTransferi(pname, param) glPixelTransferi_DEBUG(pname, param, __FILE__, __LINE__)
#define dglPixelZoom(xfactor, yfactor) glPixelZoom_DEBUG(xfactor, yfactor, __FILE__, __LINE__)
#define dglPointSize(size) glPointSize_DEBUG(size, __FILE__, __LINE__)
#define dglPolygonMode(face, mode) glPolygonMode_DEBUG(face, mode, __FILE__, __LINE__)
#define dglPolygonOffset(factor, units) glPolygonOffset_DEBUG(factor, units, __FILE__, __LINE__)
#define dglPolygonStipple(mask) glPolygonStipple_DEBUG(mask, __FILE__, __LINE__)
#define dglPopAttrib() glPopAttrib_DEBUG(__FILE__, __LINE__)
#define dglPopClientAttrib() glPopClientAttrib_DEBUG(__FILE__, __LINE__)
#define dglPopMatrix() glPopMatrix_DEBUG(__FILE__, __LINE__)
#define dglPopName() glPopName_DEBUG(__FILE__, __LINE__)
#define dglPrioritizeTextures(n, textures, priorities) glPrioritizeTextures_DEBUG(n, textures, priorities, __FILE__, __LINE__)
#define dglPushAttrib(mask) glPushAttrib_DEBUG(mask, __FILE__, __LINE__)
#define dglPushClientAttrib(mask) glPushClientAttrib_DEBUG(mask, __FILE__, __LINE__)
#define dglPushMatrix() glPushMatrix_DEBUG(__FILE__, __LINE__)
#define dglPushName(name) glPushName_DEBUG(name, __FILE__, __LINE__)
#define dglRasterPos2d(x, y) glRasterPos2d_DEBUG(x, y, __FILE__, __LINE__)
#define dglRasterPos2dv(v) glRasterPos2dv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos2f(x, y) glRasterPos2f_DEBUG(x, y, __FILE__, __LINE__)
#define dglRasterPos2fv(v) glRasterPos2fv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos2i(x, y) glRasterPos2i_DEBUG(x, y, __FILE__, __LINE__)
#define dglRasterPos2iv(v) glRasterPos2iv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos2s(x, y) glRasterPos2s_DEBUG(x, y, __FILE__, __LINE__)
#define dglRasterPos2sv(v) glRasterPos2sv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos3d(x, y, z) glRasterPos3d_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglRasterPos3dv(v) glRasterPos3dv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos3f(x, y, z) glRasterPos3f_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglRasterPos3fv(v) glRasterPos3fv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos3i(x, y, z) glRasterPos3i_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglRasterPos3iv(v) glRasterPos3iv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos3s(x, y, z) glRasterPos3s_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglRasterPos3sv(v) glRasterPos3sv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos4d(x, y, z, w) glRasterPos4d_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglRasterPos4dv(v) glRasterPos4dv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos4f(x, y, z, w) glRasterPos4f_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglRasterPos4fv(v) glRasterPos4fv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos4i(x, y, z, w) glRasterPos4i_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglRasterPos4iv(v) glRasterPos4iv_DEBUG(v, __FILE__, __LINE__)
#define dglRasterPos4s(x, y, z, w) glRasterPos4s_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglRasterPos4sv(v) glRasterPos4sv_DEBUG(v, __FILE__, __LINE__)
#define dglReadBuffer(mode) glReadBuffer_DEBUG(mode, __FILE__, __LINE__)
#define dglReadPixels(x, y, width, height, format, type, pixels) glReadPixels_DEBUG(x, y, width, height, format, type, pixels, __FILE__, __LINE__)
#define dglRectd(x1, y1, x2, y2) glRectd_DEBUG(x1, y1, x2, y2, __FILE__, __LINE__)
#define dglRectdv(v1, v2) glRectdv_DEBUG(v1, v2, __FILE__, __LINE__)
#define dglRectf(x1, y1, x2, y2) glRectf_DEBUG(x1, y1, x2, y2, __FILE__, __LINE__)
#define dglRectfv(v1, v2) glRectfv_DEBUG(v1, v2, __FILE__, __LINE__)
#ifdef HAVE_GLES
#define dglRecti(x1, y1, x2, y2) glRecti_DEBUG(x1, y1, x2, y2, __FILE__, __LINE__)
#endif
#define dglRectiv(v1, v2) glRectiv_DEBUG(v1, v2, __FILE__, __LINE__)
#define dglRects(x1, y1, x2, y2) glRects_DEBUG(x1, y1, x2, y2, __FILE__, __LINE__)
#define dglRectsv(v1, v2) glRectsv_DEBUG(v1, v2, __FILE__, __LINE__)
#define dglRenderMode(mode) glRenderMode_DEBUG(mode, __FILE__, __LINE__)
#define dglRotated(angle, x, y, z) glRotated_DEBUG(angle, x, y, z, __FILE__, __LINE__)
#define dglRotatef(angle, x, y, z) glRotatef_DEBUG(angle, x, y, z, __FILE__, __LINE__)
#define dglScaled(x, y, z) glScaled_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglScalef(x, y, z) glScalef_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglScissor(x, y, width, height) glScissor_DEBUG(x, y, width, height, __FILE__, __LINE__)
#define dglSelectBuffer(size, buffer) glSelectBuffer_DEBUG(size, buffer, __FILE__, __LINE__)
#define dglShadeModel(mode) glShadeModel_DEBUG(mode, __FILE__, __LINE__)
#define dglStencilFunc(func, ref, mask) glStencilFunc_DEBUG(func, ref, mask, __FILE__, __LINE__)
#define dglStencilMask(mask) glStencilMask_DEBUG(mask, __FILE__, __LINE__)
#define dglStencilOp(fail, zfail, zpass) glStencilOp_DEBUG(fail, zfail, zpass, __FILE__, __LINE__)
#define dglTexCoord1d(s) glTexCoord1d_DEBUG(s, __FILE__, __LINE__)
#define dglTexCoord1dv(v) glTexCoord1dv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord1f(s) glTexCoord1f_DEBUG(s, __FILE__, __LINE__)
#define dglTexCoord1fv(v) glTexCoord1fv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord1i(s) glTexCoord1i_DEBUG(s, __FILE__, __LINE__)
#define dglTexCoord1iv(v) glTexCoord1iv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord1s(s) glTexCoord1s_DEBUG(s, __FILE__, __LINE__)
#define dglTexCoord1sv(v) glTexCoord1sv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord2d(s, t) glTexCoord2d_DEBUG(s, t, __FILE__, __LINE__)
#define dglTexCoord2dv(v) glTexCoord2dv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord2f(s, t) glTexCoord2f_DEBUG(s, t, __FILE__, __LINE__)
#define dglTexCoord2fv(v) glTexCoord2fv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord2i(s, t) glTexCoord2i_DEBUG(s, t, __FILE__, __LINE__)
#define dglTexCoord2iv(v) glTexCoord2iv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord2s(s, t) glTexCoord2s_DEBUG(s, t, __FILE__, __LINE__)
#define dglTexCoord2sv(v) glTexCoord2sv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord3d(s, t, r) glTexCoord3d_DEBUG(s, t, r, __FILE__, __LINE__)
#define dglTexCoord3dv(v) glTexCoord3dv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord3f(s, t, r) glTexCoord3f_DEBUG(s, t, r, __FILE__, __LINE__)
#define dglTexCoord3fv(v) glTexCoord3fv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord3i(s, t, r) glTexCoord3i_DEBUG(s, t, r, __FILE__, __LINE__)
#define dglTexCoord3iv(v) glTexCoord3iv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord3s(s, t, r) glTexCoord3s_DEBUG(s, t, r, __FILE__, __LINE__)
#define dglTexCoord3sv(v) glTexCoord3sv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord4d(s, t, r, q) glTexCoord4d_DEBUG(s, t, r, q, __FILE__, __LINE__)
#define dglTexCoord4dv(v) glTexCoord4dv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord4f(s, t, r, q) glTexCoord4f_DEBUG(s, t, r, q, __FILE__, __LINE__)
#define dglTexCoord4fv(v) glTexCoord4fv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord4i(s, t, r, q) glTexCoord4i_DEBUG(s, t, r, q, __FILE__, __LINE__)
#define dglTexCoord4iv(v) glTexCoord4iv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoord4s(s, t, r, q) glTexCoord4s_DEBUG(s, t, r, q, __FILE__, __LINE__)
#define dglTexCoord4sv(v) glTexCoord4sv_DEBUG(v, __FILE__, __LINE__)
#define dglTexCoordPointer(size, type, stride, pointer) glTexCoordPointer_DEBUG(size, type, stride, pointer, __FILE__, __LINE__)
#define dglTexEnvf(target, pname, param) glTexEnvf_DEBUG(target, pname, param, __FILE__, __LINE__)
#define dglTexEnvfv(target, pname, params) glTexEnvfv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglTexEnvi(target, pname, param) glTexEnvi_DEBUG(target, pname, param, __FILE__, __LINE__)
#define dglTexEnviv(target, pname, params) glTexEnviv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglTexGend(coord, pname, param) glTexGend_DEBUG(coord, pname, param, __FILE__, __LINE__)
#define dglTexGendv(coord, pname, params) glTexGendv_DEBUG(coord, pname, params, __FILE__, __LINE__)
#define dglTexGenf(coord, pname, param) glTexGenf_DEBUG(coord, pname, param, __FILE__, __LINE__)
#define dglTexGenfv(coord, pname, params) glTexGenfv_DEBUG(coord, pname, params, __FILE__, __LINE__)
#define dglTexGeni(coord, pname, param) glTexGeni_DEBUG(coord, pname, param, __FILE__, __LINE__)
#define dglTexGeniv(coord, pname, params) glTexGeniv_DEBUG(coord, pname, params, __FILE__, __LINE__)
#define dglTexImage1D(target, level, internalformat, width, border, format, type, pixels) glTexImage1D_DEBUG(target, level, internalformat, width, border, format, type, pixels, __FILE__, __LINE__)
#define dglTexImage2D(target, level, internalformat, width, height, border, format, type, pixels) glTexImage2D_DEBUG(target, level, internalformat, width, height, border, format, type, pixels, __FILE__, __LINE__)
#define dglTexParameterf(target, pname, param) glTexParameterf_DEBUG(target, pname, param, __FILE__, __LINE__)
#define dglTexParameterfv(target, pname, params) glTexParameterfv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglTexParameteri(target, pname, param) glTexParameteri_DEBUG(target, pname, param, __FILE__, __LINE__)
#define dglTexParameteriv(target, pname, params) glTexParameteriv_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglTexSubImage1D(target, level, xoffset, width, format, type, pixels) glTexSubImage1D_DEBUG(target, level, xoffset, width, format, type, pixels, __FILE__, __LINE__)
#define dglTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels) glTexSubImage2D_DEBUG(target, level, xoffset, yoffset, width, height, format, type, pixels, __FILE__, __LINE__)
#define dglTranslated(x, y, z) glTranslated_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglTranslatef(x, y, z) glTranslatef_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglVertex2d(x, y) glVertex2d_DEBUG(x, y, __FILE__, __LINE__)
#define dglVertex2dv(v) glVertex2dv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex2f(x, y) glVertex2f_DEBUG(x, y, __FILE__, __LINE__)
#define dglVertex2fv(v) glVertex2fv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex2i(x, y) glVertex2i_DEBUG(x, y, __FILE__, __LINE__)
#define dglVertex2iv(v) glVertex2iv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex2s(x, y) glVertex2s_DEBUG(x, y, __FILE__, __LINE__)
#define dglVertex2sv(v) glVertex2sv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex3d(x, y, z) glVertex3d_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglVertex3dv(v) glVertex3dv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex3f(x, y, z) glVertex3f_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglVertex3fv(v) glVertex3fv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex3i(x, y, z) glVertex3i_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglVertex3iv(v) glVertex3iv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex3s(x, y, z) glVertex3s_DEBUG(x, y, z, __FILE__, __LINE__)
#define dglVertex3sv(v) glVertex3sv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex4d(x, y, z, w) glVertex4d_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglVertex4dv(v) glVertex4dv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex4f(x, y, z, w) glVertex4f_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglVertex4fv(v) glVertex4fv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex4i(x, y, z, w) glVertex4i_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglVertex4iv(v) glVertex4iv_DEBUG(v, __FILE__, __LINE__)
#define dglVertex4s(x, y, z, w) glVertex4s_DEBUG(x, y, z, w, __FILE__, __LINE__)
#define dglVertex4sv(v) glVertex4sv_DEBUG(v, __FILE__, __LINE__)
#define dglVertexPointer(size, type, stride, pointer) glVertexPointer_DEBUG(size, type, stride, pointer, __FILE__, __LINE__)
#define dglViewport(x, y, width, height) glViewport_DEBUG(x, y, width, height, __FILE__, __LINE__)

#endif				// USE_DEBUG_GLFUNCS

//
// GL_ARB_multitexture
//
extern dboolean has_GL_ARB_multitexture;
#ifdef HAVE_GLES
#define GL_ARB_multitexture_Define() \
dboolean has_GL_ARB_multitexture = true;

#define GL_ARB_multitexture_Init() \
has_GL_ARB_multitexture = true;

#define _glActiveTextureARB	glActiveTexture
#define _glClientActiveTextureARB glClientActiveTexture
//#define _glMultiTexCoord2fARB(a, b)	glMultiTexCoord4f(a, b, 0.0f, 1.0f);
#else

extern PFNGLACTIVETEXTUREARBPROC _glActiveTextureARB;
extern PFNGLCLIENTACTIVETEXTUREARBPROC _glClientActiveTextureARB;
extern PFNGLMULTITEXCOORD1DARBPROC _glMultiTexCoord1dARB;
extern PFNGLMULTITEXCOORD1DVARBPROC _glMultiTexCoord1dvARB;
extern PFNGLMULTITEXCOORD1FARBPROC _glMultiTexCoord1fARB;
extern PFNGLMULTITEXCOORD1FVARBPROC _glMultiTexCoord1fvARB;
extern PFNGLMULTITEXCOORD1IARBPROC _glMultiTexCoord1iARB;
extern PFNGLMULTITEXCOORD1IVARBPROC _glMultiTexCoord1ivARB;
extern PFNGLMULTITEXCOORD1SARBPROC _glMultiTexCoord1sARB;
extern PFNGLMULTITEXCOORD1SVARBPROC _glMultiTexCoord1svARB;
extern PFNGLMULTITEXCOORD2DARBPROC _glMultiTexCoord2dARB;
extern PFNGLMULTITEXCOORD2DVARBPROC _glMultiTexCoord2dvARB;
extern PFNGLMULTITEXCOORD2FARBPROC _glMultiTexCoord2fARB;
extern PFNGLMULTITEXCOORD2FVARBPROC _glMultiTexCoord2fvARB;
extern PFNGLMULTITEXCOORD2IARBPROC _glMultiTexCoord2iARB;
extern PFNGLMULTITEXCOORD2IVARBPROC _glMultiTexCoord2ivARB;
extern PFNGLMULTITEXCOORD2SARBPROC _glMultiTexCoord2sARB;
extern PFNGLMULTITEXCOORD2SVARBPROC _glMultiTexCoord2svARB;
extern PFNGLMULTITEXCOORD3DARBPROC _glMultiTexCoord3dARB;
extern PFNGLMULTITEXCOORD3DVARBPROC _glMultiTexCoord3dvARB;
extern PFNGLMULTITEXCOORD3FARBPROC _glMultiTexCoord3fARB;
extern PFNGLMULTITEXCOORD3FVARBPROC _glMultiTexCoord3fvARB;
extern PFNGLMULTITEXCOORD3IARBPROC _glMultiTexCoord3iARB;
extern PFNGLMULTITEXCOORD3IVARBPROC _glMultiTexCoord3ivARB;
extern PFNGLMULTITEXCOORD3SARBPROC _glMultiTexCoord3sARB;
extern PFNGLMULTITEXCOORD3SVARBPROC _glMultiTexCoord3svARB;
extern PFNGLMULTITEXCOORD4DARBPROC _glMultiTexCoord4dARB;
extern PFNGLMULTITEXCOORD4DVARBPROC _glMultiTexCoord4dvARB;
extern PFNGLMULTITEXCOORD4FARBPROC _glMultiTexCoord4fARB;
extern PFNGLMULTITEXCOORD4FVARBPROC _glMultiTexCoord4fvARB;
extern PFNGLMULTITEXCOORD4IARBPROC _glMultiTexCoord4iARB;
extern PFNGLMULTITEXCOORD4IVARBPROC _glMultiTexCoord4ivARB;
extern PFNGLMULTITEXCOORD4SARBPROC _glMultiTexCoord4sARB;
extern PFNGLMULTITEXCOORD4SVARBPROC _glMultiTexCoord4svARB;

#define GL_ARB_multitexture_Define() \
dboolean has_GL_ARB_multitexture = false; \
PFNGLACTIVETEXTUREARBPROC _glActiveTextureARB = NULL; \
PFNGLCLIENTACTIVETEXTUREARBPROC _glClientActiveTextureARB = NULL; \
PFNGLMULTITEXCOORD1DARBPROC _glMultiTexCoord1dARB = NULL; \
PFNGLMULTITEXCOORD1DVARBPROC _glMultiTexCoord1dvARB = NULL; \
PFNGLMULTITEXCOORD1FARBPROC _glMultiTexCoord1fARB = NULL; \
PFNGLMULTITEXCOORD1FVARBPROC _glMultiTexCoord1fvARB = NULL; \
PFNGLMULTITEXCOORD1IARBPROC _glMultiTexCoord1iARB = NULL; \
PFNGLMULTITEXCOORD1IVARBPROC _glMultiTexCoord1ivARB = NULL; \
PFNGLMULTITEXCOORD1SARBPROC _glMultiTexCoord1sARB = NULL; \
PFNGLMULTITEXCOORD1SVARBPROC _glMultiTexCoord1svARB = NULL; \
PFNGLMULTITEXCOORD2DARBPROC _glMultiTexCoord2dARB = NULL; \
PFNGLMULTITEXCOORD2DVARBPROC _glMultiTexCoord2dvARB = NULL; \
PFNGLMULTITEXCOORD2FARBPROC _glMultiTexCoord2fARB = NULL; \
PFNGLMULTITEXCOORD2FVARBPROC _glMultiTexCoord2fvARB = NULL; \
PFNGLMULTITEXCOORD2IARBPROC _glMultiTexCoord2iARB = NULL; \
PFNGLMULTITEXCOORD2IVARBPROC _glMultiTexCoord2ivARB = NULL; \
PFNGLMULTITEXCOORD2SARBPROC _glMultiTexCoord2sARB = NULL; \
PFNGLMULTITEXCOORD2SVARBPROC _glMultiTexCoord2svARB = NULL; \
PFNGLMULTITEXCOORD3DARBPROC _glMultiTexCoord3dARB = NULL; \
PFNGLMULTITEXCOORD3DVARBPROC _glMultiTexCoord3dvARB = NULL; \
PFNGLMULTITEXCOORD3FARBPROC _glMultiTexCoord3fARB = NULL; \
PFNGLMULTITEXCOORD3FVARBPROC _glMultiTexCoord3fvARB = NULL; \
PFNGLMULTITEXCOORD3IARBPROC _glMultiTexCoord3iARB = NULL; \
PFNGLMULTITEXCOORD3IVARBPROC _glMultiTexCoord3ivARB = NULL; \
PFNGLMULTITEXCOORD3SARBPROC _glMultiTexCoord3sARB = NULL; \
PFNGLMULTITEXCOORD3SVARBPROC _glMultiTexCoord3svARB = NULL; \
PFNGLMULTITEXCOORD4DARBPROC _glMultiTexCoord4dARB = NULL; \
PFNGLMULTITEXCOORD4DVARBPROC _glMultiTexCoord4dvARB = NULL; \
PFNGLMULTITEXCOORD4FARBPROC _glMultiTexCoord4fARB = NULL; \
PFNGLMULTITEXCOORD4FVARBPROC _glMultiTexCoord4fvARB = NULL; \
PFNGLMULTITEXCOORD4IARBPROC _glMultiTexCoord4iARB = NULL; \
PFNGLMULTITEXCOORD4IVARBPROC _glMultiTexCoord4ivARB = NULL; \
PFNGLMULTITEXCOORD4SARBPROC _glMultiTexCoord4sARB = NULL; \
PFNGLMULTITEXCOORD4SVARBPROC _glMultiTexCoord4svARB = NULL

#define GL_ARB_multitexture_Init() \
has_GL_ARB_multitexture = GL_CheckExtension("GL_ARB_multitexture"); \
_glActiveTextureARB = GL_RegisterProc("glActiveTextureARB"); \
_glClientActiveTextureARB = GL_RegisterProc("glClientActiveTextureARB"); \
_glMultiTexCoord1dARB = GL_RegisterProc("glMultiTexCoord1dARB"); \
_glMultiTexCoord1dvARB = GL_RegisterProc("glMultiTexCoord1dvARB"); \
_glMultiTexCoord1fARB = GL_RegisterProc("glMultiTexCoord1fARB"); \
_glMultiTexCoord1fvARB = GL_RegisterProc("glMultiTexCoord1fvARB"); \
_glMultiTexCoord1iARB = GL_RegisterProc("glMultiTexCoord1iARB"); \
_glMultiTexCoord1ivARB = GL_RegisterProc("glMultiTexCoord1ivARB"); \
_glMultiTexCoord1sARB = GL_RegisterProc("glMultiTexCoord1sARB"); \
_glMultiTexCoord1svARB = GL_RegisterProc("glMultiTexCoord1svARB"); \
_glMultiTexCoord2dARB = GL_RegisterProc("glMultiTexCoord2dARB"); \
_glMultiTexCoord2dvARB = GL_RegisterProc("glMultiTexCoord2dvARB"); \
_glMultiTexCoord2fARB = GL_RegisterProc("glMultiTexCoord2fARB"); \
_glMultiTexCoord2fvARB = GL_RegisterProc("glMultiTexCoord2fvARB"); \
_glMultiTexCoord2iARB = GL_RegisterProc("glMultiTexCoord2iARB"); \
_glMultiTexCoord2ivARB = GL_RegisterProc("glMultiTexCoord2ivARB"); \
_glMultiTexCoord2sARB = GL_RegisterProc("glMultiTexCoord2sARB"); \
_glMultiTexCoord2svARB = GL_RegisterProc("glMultiTexCoord2svARB"); \
_glMultiTexCoord3dARB = GL_RegisterProc("glMultiTexCoord3dARB"); \
_glMultiTexCoord3dvARB = GL_RegisterProc("glMultiTexCoord3dvARB"); \
_glMultiTexCoord3fARB = GL_RegisterProc("glMultiTexCoord3fARB"); \
_glMultiTexCoord3fvARB = GL_RegisterProc("glMultiTexCoord3fvARB"); \
_glMultiTexCoord3iARB = GL_RegisterProc("glMultiTexCoord3iARB"); \
_glMultiTexCoord3ivARB = GL_RegisterProc("glMultiTexCoord3ivARB"); \
_glMultiTexCoord3sARB = GL_RegisterProc("glMultiTexCoord3sARB"); \
_glMultiTexCoord3svARB = GL_RegisterProc("glMultiTexCoord3svARB"); \
_glMultiTexCoord4dARB = GL_RegisterProc("glMultiTexCoord4dARB"); \
_glMultiTexCoord4dvARB = GL_RegisterProc("glMultiTexCoord4dvARB"); \
_glMultiTexCoord4fARB = GL_RegisterProc("glMultiTexCoord4fARB"); \
_glMultiTexCoord4fvARB = GL_RegisterProc("glMultiTexCoord4fvARB"); \
_glMultiTexCoord4iARB = GL_RegisterProc("glMultiTexCoord4iARB"); \
_glMultiTexCoord4ivARB = GL_RegisterProc("glMultiTexCoord4ivARB"); \
_glMultiTexCoord4sARB = GL_RegisterProc("glMultiTexCoord4sARB"); \
_glMultiTexCoord4svARB = GL_RegisterProc("glMultiTexCoord4svARB")
#endif
#ifndef USE_DEBUG_GLFUNCS

#define dglActiveTextureARB(texture) _glActiveTextureARB(texture)
#define dglClientActiveTextureARB(texture) _glClientActiveTextureARB(texture)
#define dglMultiTexCoord1dARB(target, s) _glMultiTexCoord1dARB(target, s)
#define dglMultiTexCoord1dvARB(target, v) _glMultiTexCoord1dvARB(target, v)
#define dglMultiTexCoord1fARB(target, s) _glMultiTexCoord1fARB(target, s)
#define dglMultiTexCoord1fvARB(target, v) _glMultiTexCoord1fvARB(target, v)
#define dglMultiTexCoord1iARB(target, s) _glMultiTexCoord1iARB(target, s)
#define dglMultiTexCoord1ivARB(target, v) _glMultiTexCoord1ivARB(target, v)
#define dglMultiTexCoord1sARB(target, s) _glMultiTexCoord1sARB(target, s)
#define dglMultiTexCoord1svARB(target, v) _glMultiTexCoord1svARB(target, v)
#define dglMultiTexCoord2dARB(target, s, t) _glMultiTexCoord2dARB(target, s, t)
#define dglMultiTexCoord2dvARB(target, v) _glMultiTexCoord2dvARB(target, v)
#define dglMultiTexCoord2fARB(target, s, t) _glMultiTexCoord2fARB(target, s, t)
#define dglMultiTexCoord2fvARB(target, v) _glMultiTexCoord2fvARB(target, v)
#define dglMultiTexCoord2iARB(target, s, t) _glMultiTexCoord2iARB(target, s, t)
#define dglMultiTexCoord2ivARB(target, v) _glMultiTexCoord2ivARB(target, v)
#define dglMultiTexCoord2sARB(target, s, t) _glMultiTexCoord2sARB(target, s, t)
#define dglMultiTexCoord2svARB(target, v) _glMultiTexCoord2svARB(target, v)
#define dglMultiTexCoord3dARB(target, s, t, r) _glMultiTexCoord3dARB(target, s, t, r)
#define dglMultiTexCoord3dvARB(target, v) _glMultiTexCoord3dvARB(target, v)
#define dglMultiTexCoord3fARB(target, s, t, r) _glMultiTexCoord3fARB(target, s, t, r)
#define dglMultiTexCoord3fvARB(target, v) _glMultiTexCoord3fvARB(target, v)
#define dglMultiTexCoord3iARB(target, s, t, r) _glMultiTexCoord3iARB(target, s, t, r)
#define dglMultiTexCoord3ivARB(target, v) _glMultiTexCoord3ivARB(target, v)
#define dglMultiTexCoord3sARB(target, s, t, r) _glMultiTexCoord3sARB(target, s, t, r)
#define dglMultiTexCoord3svARB(target, v) _glMultiTexCoord3svARB(target, v)
#define dglMultiTexCoord4dARB(target, s, t, r, q) _glMultiTexCoord4dARB(target, s, t, r, q)
#define dglMultiTexCoord4dvARB(target, v) _glMultiTexCoord4dvARB(target, v)
#define dglMultiTexCoord4fARB(target, s, t, r, q) _glMultiTexCoord4fARB(target, s, t, r, q)
#define dglMultiTexCoord4fvARB(target, v) _glMultiTexCoord4fvARB(target, v)
#define dglMultiTexCoord4iARB(target, s, t, r, q) _glMultiTexCoord4iARB(target, s, t, r, q)
#define dglMultiTexCoord4ivARB(target, v) _glMultiTexCoord4ivARB(target, v)
#define dglMultiTexCoord4sARB(target, s, t, r, q) _glMultiTexCoord4sARB(target, s, t, r, q)
#define dglMultiTexCoord4svARB(target, v) _glMultiTexCoord4svARB(target, v)

#else

d_inline static void glActiveTextureARB_DEBUG(GLenum texture, const char *file,
					      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glActiveTextureARB(texture=0x%x)\n",
		 file, line, texture);
#endif
	_glActiveTextureARB(texture);
	dglLogError("glActiveTextureARB", file, line);
}

d_inline static void glClientActiveTextureARB_DEBUG(GLenum texture,
						    const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glClientActiveTextureARB(texture=0x%x)\n",
	     file, line, texture);
#endif
	_glClientActiveTextureARB(texture);
	dglLogError("glClientActiveTextureARB", file, line);
}

d_inline static void glMultiTexCoord1dARB_DEBUG(GLenum target, GLdouble s,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1dARB(target=0x%x, s=%f)\n",
	     file, line, target, s);
#endif
	_glMultiTexCoord1dARB(target, s);
	dglLogError("glMultiTexCoord1dARB", file, line);
}

d_inline static void glMultiTexCoord1dvARB_DEBUG(GLenum target, GLdouble * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1dvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord1dvARB(target, v);
	dglLogError("glMultiTexCoord1dvARB", file, line);
}

d_inline static void glMultiTexCoord1fARB_DEBUG(GLenum target, GLfloat s,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1fARB(target=0x%x, s=%f)\n",
	     file, line, target, s);
#endif
	_glMultiTexCoord1fARB(target, s);
	dglLogError("glMultiTexCoord1fARB", file, line);
}

d_inline static void glMultiTexCoord1fvARB_DEBUG(GLenum target, GLfloat * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1fvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord1fvARB(target, v);
	dglLogError("glMultiTexCoord1fvARB", file, line);
}

d_inline static void glMultiTexCoord1iARB_DEBUG(GLenum target, GLint s,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1iARB(target=0x%x, s=%i)\n",
	     file, line, target, s);
#endif
	_glMultiTexCoord1iARB(target, s);
	dglLogError("glMultiTexCoord1iARB", file, line);
}

d_inline static void glMultiTexCoord1ivARB_DEBUG(GLenum target, GLint * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1ivARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord1ivARB(target, v);
	dglLogError("glMultiTexCoord1ivARB", file, line);
}

d_inline static void glMultiTexCoord1sARB_DEBUG(GLenum target, GLshort s,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1sARB(target=0x%x, s=%i)\n",
	     file, line, target, s);
#endif
	_glMultiTexCoord1sARB(target, s);
	dglLogError("glMultiTexCoord1sARB", file, line);
}

d_inline static void glMultiTexCoord1svARB_DEBUG(GLenum target, GLshort * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord1svARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord1svARB(target, v);
	dglLogError("glMultiTexCoord1svARB", file, line);
}

d_inline static void glMultiTexCoord2dARB_DEBUG(GLenum target, GLdouble s,
						GLdouble t, const char *file,
						int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2dARB(target=0x%x, s=%f, t=%f)\n",
	     file, line, target, s, t);
#endif
	_glMultiTexCoord2dARB(target, s, t);
	dglLogError("glMultiTexCoord2dARB", file, line);
}

d_inline static void glMultiTexCoord2dvARB_DEBUG(GLenum target, GLdouble * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2dvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord2dvARB(target, v);
	dglLogError("glMultiTexCoord2dvARB", file, line);
}

d_inline static void glMultiTexCoord2fARB_DEBUG(GLenum target, GLfloat s,
						GLfloat t, const char *file,
						int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2fARB(target=0x%x, s=%f, t=%f)\n",
	     file, line, target, s, t);
#endif
	_glMultiTexCoord2fARB(target, s, t);
	dglLogError("glMultiTexCoord2fARB", file, line);
}

d_inline static void glMultiTexCoord2fvARB_DEBUG(GLenum target, GLfloat * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2fvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord2fvARB(target, v);
	dglLogError("glMultiTexCoord2fvARB", file, line);
}

d_inline static void glMultiTexCoord2iARB_DEBUG(GLenum target, GLint s, GLint t,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2iARB(target=0x%x, s=%i, t=%i)\n",
	     file, line, target, s, t);
#endif
	_glMultiTexCoord2iARB(target, s, t);
	dglLogError("glMultiTexCoord2iARB", file, line);
}

d_inline static void glMultiTexCoord2ivARB_DEBUG(GLenum target, GLint * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2ivARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord2ivARB(target, v);
	dglLogError("glMultiTexCoord2ivARB", file, line);
}

d_inline static void glMultiTexCoord2sARB_DEBUG(GLenum target, GLshort s,
						GLshort t, const char *file,
						int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2sARB(target=0x%x, s=%i, t=%i)\n",
	     file, line, target, s, t);
#endif
	_glMultiTexCoord2sARB(target, s, t);
	dglLogError("glMultiTexCoord2sARB", file, line);
}

d_inline static void glMultiTexCoord2svARB_DEBUG(GLenum target, GLshort * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord2svARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord2svARB(target, v);
	dglLogError("glMultiTexCoord2svARB", file, line);
}

d_inline static void glMultiTexCoord3dARB_DEBUG(GLenum target, GLdouble s,
						GLdouble t, GLdouble r,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3dARB(target=0x%x, s=%f, t=%f, r=%f)\n",
	     file, line, target, s, t, r);
#endif
	_glMultiTexCoord3dARB(target, s, t, r);
	dglLogError("glMultiTexCoord3dARB", file, line);
}

d_inline static void glMultiTexCoord3dvARB_DEBUG(GLenum target, GLdouble * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3dvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord3dvARB(target, v);
	dglLogError("glMultiTexCoord3dvARB", file, line);
}

d_inline static void glMultiTexCoord3fARB_DEBUG(GLenum target, GLfloat s,
						GLfloat t, GLfloat r,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3fARB(target=0x%x, s=%f, t=%f, r=%f)\n",
	     file, line, target, s, t, r);
#endif
	_glMultiTexCoord3fARB(target, s, t, r);
	dglLogError("glMultiTexCoord3fARB", file, line);
}

d_inline static void glMultiTexCoord3fvARB_DEBUG(GLenum target, GLfloat * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3fvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord3fvARB(target, v);
	dglLogError("glMultiTexCoord3fvARB", file, line);
}

d_inline static void glMultiTexCoord3iARB_DEBUG(GLenum target, GLint s, GLint t,
						GLint r, const char *file,
						int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3iARB(target=0x%x, s=%i, t=%i, r=%i)\n",
	     file, line, target, s, t, r);
#endif
	_glMultiTexCoord3iARB(target, s, t, r);
	dglLogError("glMultiTexCoord3iARB", file, line);
}

d_inline static void glMultiTexCoord3ivARB_DEBUG(GLenum target, GLint * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3ivARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord3ivARB(target, v);
	dglLogError("glMultiTexCoord3ivARB", file, line);
}

d_inline static void glMultiTexCoord3sARB_DEBUG(GLenum target, GLshort s,
						GLshort t, GLshort r,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3sARB(target=0x%x, s=%i, t=%i, r=%i)\n",
	     file, line, target, s, t, r);
#endif
	_glMultiTexCoord3sARB(target, s, t, r);
	dglLogError("glMultiTexCoord3sARB", file, line);
}

d_inline static void glMultiTexCoord3svARB_DEBUG(GLenum target, GLshort * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord3svARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord3svARB(target, v);
	dglLogError("glMultiTexCoord3svARB", file, line);
}

d_inline static void glMultiTexCoord4dARB_DEBUG(GLenum target, GLdouble s,
						GLdouble t, GLdouble r,
						GLdouble q, const char *file,
						int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4dARB(target=0x%x, s=%f, t=%f, r=%f, q=%f)\n",
	     file, line, target, s, t, r, q);
#endif
	_glMultiTexCoord4dARB(target, s, t, r, q);
	dglLogError("glMultiTexCoord4dARB", file, line);
}

d_inline static void glMultiTexCoord4dvARB_DEBUG(GLenum target, GLdouble * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4dvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord4dvARB(target, v);
	dglLogError("glMultiTexCoord4dvARB", file, line);
}

d_inline static void glMultiTexCoord4fARB_DEBUG(GLenum target, GLfloat s,
						GLfloat t, GLfloat r, GLfloat q,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4fARB(target=0x%x, s=%f, t=%f, r=%f, q=%f)\n",
	     file, line, target, s, t, r, q);
#endif
	_glMultiTexCoord4fARB(target, s, t, r, q);
	dglLogError("glMultiTexCoord4fARB", file, line);
}

d_inline static void glMultiTexCoord4fvARB_DEBUG(GLenum target, GLfloat * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4fvARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord4fvARB(target, v);
	dglLogError("glMultiTexCoord4fvARB", file, line);
}

d_inline static void glMultiTexCoord4iARB_DEBUG(GLenum target, GLint s, GLint t,
						GLint r, GLint q,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4iARB(target=0x%x, s=%i, t=%i, r=%i, q=%i)\n",
	     file, line, target, s, t, r, q);
#endif
	_glMultiTexCoord4iARB(target, s, t, r, q);
	dglLogError("glMultiTexCoord4iARB", file, line);
}

d_inline static void glMultiTexCoord4ivARB_DEBUG(GLenum target, GLint * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4ivARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord4ivARB(target, v);
	dglLogError("glMultiTexCoord4ivARB", file, line);
}

d_inline static void glMultiTexCoord4sARB_DEBUG(GLenum target, GLshort s,
						GLshort t, GLshort r, GLshort q,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4sARB(target=0x%x, s=%i, t=%i, r=%i, q=%i)\n",
	     file, line, target, s, t, r, q);
#endif
	_glMultiTexCoord4sARB(target, s, t, r, q);
	dglLogError("glMultiTexCoord4sARB", file, line);
}

d_inline static void glMultiTexCoord4svARB_DEBUG(GLenum target, GLshort * v,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiTexCoord4svARB(target=0x%x, v=%p)\n",
	     file, line, target, v);
#endif
	_glMultiTexCoord4svARB(target, v);
	dglLogError("glMultiTexCoord4svARB", file, line);
}

#define dglActiveTextureARB(texture) glActiveTextureARB_DEBUG(texture, __FILE__, __LINE__)
#define dglClientActiveTextureARB(texture) glClientActiveTextureARB_DEBUG(texture, __FILE__, __LINE__)
#define dglMultiTexCoord1dARB(target, s) glMultiTexCoord1dARB_DEBUG(target, s, __FILE__, __LINE__)
#define dglMultiTexCoord1dvARB(target, v) glMultiTexCoord1dvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord1fARB(target, s) glMultiTexCoord1fARB_DEBUG(target, s, __FILE__, __LINE__)
#define dglMultiTexCoord1fvARB(target, v) glMultiTexCoord1fvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord1iARB(target, s) glMultiTexCoord1iARB_DEBUG(target, s, __FILE__, __LINE__)
#define dglMultiTexCoord1ivARB(target, v) glMultiTexCoord1ivARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord1sARB(target, s) glMultiTexCoord1sARB_DEBUG(target, s, __FILE__, __LINE__)
#define dglMultiTexCoord1svARB(target, v) glMultiTexCoord1svARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord2dARB(target, s, t) glMultiTexCoord2dARB_DEBUG(target, s, t, __FILE__, __LINE__)
#define dglMultiTexCoord2dvARB(target, v) glMultiTexCoord2dvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord2fARB(target, s, t) glMultiTexCoord2fARB_DEBUG(target, s, t, __FILE__, __LINE__)
#define dglMultiTexCoord2fvARB(target, v) glMultiTexCoord2fvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord2iARB(target, s, t) glMultiTexCoord2iARB_DEBUG(target, s, t, __FILE__, __LINE__)
#define dglMultiTexCoord2ivARB(target, v) glMultiTexCoord2ivARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord2sARB(target, s, t) glMultiTexCoord2sARB_DEBUG(target, s, t, __FILE__, __LINE__)
#define dglMultiTexCoord2svARB(target, v) glMultiTexCoord2svARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord3dARB(target, s, t, r) glMultiTexCoord3dARB_DEBUG(target, s, t, r, __FILE__, __LINE__)
#define dglMultiTexCoord3dvARB(target, v) glMultiTexCoord3dvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord3fARB(target, s, t, r) glMultiTexCoord3fARB_DEBUG(target, s, t, r, __FILE__, __LINE__)
#define dglMultiTexCoord3fvARB(target, v) glMultiTexCoord3fvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord3iARB(target, s, t, r) glMultiTexCoord3iARB_DEBUG(target, s, t, r, __FILE__, __LINE__)
#define dglMultiTexCoord3ivARB(target, v) glMultiTexCoord3ivARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord3sARB(target, s, t, r) glMultiTexCoord3sARB_DEBUG(target, s, t, r, __FILE__, __LINE__)
#define dglMultiTexCoord3svARB(target, v) glMultiTexCoord3svARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord4dARB(target, s, t, r, q) glMultiTexCoord4dARB_DEBUG(target, s, t, r, q, __FILE__, __LINE__)
#define dglMultiTexCoord4dvARB(target, v) glMultiTexCoord4dvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord4fARB(target, s, t, r, q) glMultiTexCoord4fARB_DEBUG(target, s, t, r, q, __FILE__, __LINE__)
#define dglMultiTexCoord4fvARB(target, v) glMultiTexCoord4fvARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord4iARB(target, s, t, r, q) glMultiTexCoord4iARB_DEBUG(target, s, t, r, q, __FILE__, __LINE__)
#define dglMultiTexCoord4ivARB(target, v) glMultiTexCoord4ivARB_DEBUG(target, v, __FILE__, __LINE__)
#define dglMultiTexCoord4sARB(target, s, t, r, q) glMultiTexCoord4sARB_DEBUG(target, s, t, r, q, __FILE__, __LINE__)
#define dglMultiTexCoord4svARB(target, v) glMultiTexCoord4svARB_DEBUG(target, v, __FILE__, __LINE__)

#endif				// USE_DEBUG_GLFUNCS

//
// GL_EXT_compiled_vertex_array
//
extern dboolean has_GL_EXT_compiled_vertex_array;

extern PFNGLLOCKARRAYSEXTPROC _glLockArraysEXT;
extern PFNGLUNLOCKARRAYSEXTPROC _glUnlockArraysEXT;

#define GL_EXT_compiled_vertex_array_Define() \
dboolean has_GL_EXT_compiled_vertex_array = false; \
PFNGLLOCKARRAYSEXTPROC _glLockArraysEXT = NULL; \
PFNGLUNLOCKARRAYSEXTPROC _glUnlockArraysEXT = NULL

#define GL_EXT_compiled_vertex_array_Init() \
has_GL_EXT_compiled_vertex_array = GL_CheckExtension("GL_EXT_compiled_vertex_array"); \
_glLockArraysEXT = GL_RegisterProc("glLockArraysEXT"); \
_glUnlockArraysEXT = GL_RegisterProc("glUnlockArraysEXT")

#ifndef USE_DEBUG_GLFUNCS

#define dglLockArraysEXT(first, count) _glLockArraysEXT(first, count)
#define dglUnlockArraysEXT() _glUnlockArraysEXT()

#else

d_inline static void glLockArraysEXT_DEBUG(GLint first, GLsizei count,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glLockArraysEXT(first=%i, count=0x%x)\n",
	     file, line, first, count);
#endif
	_glLockArraysEXT(first, count);
	dglLogError("glLockArraysEXT", file, line);
}

d_inline static void glUnlockArraysEXT_DEBUG(const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glUnlockArraysEXT()\n", file, line);
#endif
	_glUnlockArraysEXT();
	dglLogError("glUnlockArraysEXT", file, line);
}

#define dglLockArraysEXT(first, count) glLockArraysEXT_DEBUG(first, count, __FILE__, __LINE__)
#define dglUnlockArraysEXT() glUnlockArraysEXT_DEBUG(__FILE__, __LINE__)

#endif				// USE_DEBUG_GLFUNCS

//
// GL_EXT_multi_draw_arrays
//
extern dboolean has_GL_EXT_multi_draw_arrays;

extern PFNGLMULTIDRAWARRAYSEXTPROC _glMultiDrawArraysEXT;
extern PFNGLMULTIDRAWELEMENTSEXTPROC _glMultiDrawElementsEXT;

#define GL_EXT_multi_draw_arrays_Define() \
dboolean has_GL_EXT_multi_draw_arrays = false; \
PFNGLMULTIDRAWARRAYSEXTPROC _glMultiDrawArraysEXT = NULL; \
PFNGLMULTIDRAWELEMENTSEXTPROC _glMultiDrawElementsEXT = NULL

#define GL_EXT_multi_draw_arrays_Init() \
has_GL_EXT_multi_draw_arrays = GL_CheckExtension("GL_EXT_multi_draw_arrays"); \
_glMultiDrawArraysEXT = GL_RegisterProc("glMultiDrawArraysEXT"); \
_glMultiDrawElementsEXT = GL_RegisterProc("glMultiDrawElementsEXT")

#ifndef USE_DEBUG_GLFUNCS

#define dglMultiDrawArraysEXT(mode, first, count, primcount) _glMultiDrawArraysEXT(mode, first, count, primcount)
#define dglMultiDrawElementsEXT(mode, count, type, indices, primcount) _glMultiDrawElementsEXT(mode, count, type, indices, primcount)

#else

d_inline static void glMultiDrawArraysEXT_DEBUG(GLenum mode, GLint * first,
						GLsizei * count,
						GLsizei primcount,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiDrawArraysEXT(mode=0x%x, first=%p, count=%p, primcount=0x%x)\n",
	     file, line, mode, first, count, primcount);
#endif
	_glMultiDrawArraysEXT(mode, first, count, primcount);
	dglLogError("glMultiDrawArraysEXT", file, line);
}

d_inline static void glMultiDrawElementsEXT_DEBUG(GLenum mode, GLsizei * count,
						  GLenum type, void *indices,
						  GLsizei primcount,
						  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMultiDrawElementsEXT(mode=0x%x, count=%p, type=0x%x, indices=%p, primcount=0x%x)\n",
	     file, line, mode, count, type, indices, primcount);
#endif
	_glMultiDrawElementsEXT(mode, count, type, indices, primcount);
	dglLogError("glMultiDrawElementsEXT", file, line);
}

#define dglMultiDrawArraysEXT(mode, first, count, primcount) glMultiDrawArraysEXT_DEBUG(mode, first, count, primcount, __FILE__, __LINE__)
#define dglMultiDrawElementsEXT(mode, count, type, indices, primcount) glMultiDrawElementsEXT_DEBUG(mode, count, type, indices, primcount, __FILE__, __LINE__)

#endif				// USE_DEBUG_GLFUNCS

//
// GL_EXT_fog_coord
//
extern dboolean has_GL_EXT_fog_coord;

extern PFNGLFOGCOORDFEXTPROC _glFogCoordfEXT;
extern PFNGLFOGCOORDFVEXTPROC _glFogCoordfvEXT;
extern PFNGLFOGCOORDDEXTPROC _glFogCoorddEXT;
extern PFNGLFOGCOORDDVEXTPROC _glFogCoorddvEXT;
extern PFNGLFOGCOORDPOINTEREXTPROC _glFogCoordPointerEXT;

#define GL_EXT_fog_coord_Define() \
dboolean has_GL_EXT_fog_coord = false; \
PFNGLFOGCOORDFEXTPROC _glFogCoordfEXT = NULL; \
PFNGLFOGCOORDFVEXTPROC _glFogCoordfvEXT = NULL; \
PFNGLFOGCOORDDEXTPROC _glFogCoorddEXT = NULL; \
PFNGLFOGCOORDDVEXTPROC _glFogCoorddvEXT = NULL; \
PFNGLFOGCOORDPOINTEREXTPROC _glFogCoordPointerEXT = NULL

#define GL_EXT_fog_coord_Init() \
has_GL_EXT_fog_coord = GL_CheckExtension("GL_EXT_fog_coord"); \
_glFogCoordfEXT = GL_RegisterProc("glFogCoordfEXT"); \
_glFogCoordfvEXT = GL_RegisterProc("glFogCoordfvEXT"); \
_glFogCoorddEXT = GL_RegisterProc("glFogCoorddEXT"); \
_glFogCoorddvEXT = GL_RegisterProc("glFogCoorddvEXT"); \
_glFogCoordPointerEXT = GL_RegisterProc("glFogCoordPointerEXT")

#ifndef USE_DEBUG_GLFUNCS

#define dglFogCoordfEXT(coord) _glFogCoordfEXT(coord)
#define dglFogCoordfvEXT(coord) _glFogCoordfvEXT(coord)
#define dglFogCoorddEXT(coord) _glFogCoorddEXT(coord)
#define dglFogCoorddvEXT(coord) _glFogCoorddvEXT(coord)
#define dglFogCoordPointerEXT(type, stride, pointer) _glFogCoordPointerEXT(type, stride, pointer)

#else

d_inline static void glFogCoordfEXT_DEBUG(GLfloat coord, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogCoordfEXT(coord=%f)\n", file, line,
		 coord);
#endif
	_glFogCoordfEXT(coord);
	dglLogError("glFogCoordfEXT", file, line);
}

d_inline static void glFogCoordfvEXT_DEBUG(GLfloat * coord, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogCoordfvEXT(coord=%p)\n", file,
		 line, coord);
#endif
	_glFogCoordfvEXT(coord);
	dglLogError("glFogCoordfvEXT", file, line);
}

d_inline static void glFogCoorddEXT_DEBUG(GLdouble coord, const char *file,
					  int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogCoorddEXT(coord=%f)\n", file, line,
		 coord);
#endif
	_glFogCoorddEXT(coord);
	dglLogError("glFogCoorddEXT", file, line);
}

d_inline static void glFogCoorddvEXT_DEBUG(GLdouble * coord, const char *file,
					   int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glFogCoorddvEXT(coord=%p)\n", file,
		 line, coord);
#endif
	_glFogCoorddvEXT(coord);
	dglLogError("glFogCoorddvEXT", file, line);
}

d_inline static void glFogCoordPointerEXT_DEBUG(GLenum type, GLsizei stride,
						GLvoid * pointer,
						const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glFogCoordPointerEXT(type=0x%x, stride=0x%x, pointer=%p)\n",
	     file, line, type, stride, pointer);
#endif
	_glFogCoordPointerEXT(type, stride, pointer);
	dglLogError("glFogCoordPointerEXT", file, line);
}

#define dglFogCoordfEXT(coord) glFogCoordfEXT_DEBUG(coord, __FILE__, __LINE__)
#define dglFogCoordfvEXT(coord) glFogCoordfvEXT_DEBUG(coord, __FILE__, __LINE__)
#define dglFogCoorddEXT(coord) glFogCoorddEXT_DEBUG(coord, __FILE__, __LINE__)
#define dglFogCoorddvEXT(coord) glFogCoorddvEXT_DEBUG(coord, __FILE__, __LINE__)
#define dglFogCoordPointerEXT(type, stride, pointer) glFogCoordPointerEXT_DEBUG(type, stride, pointer, __FILE__, __LINE__)

#endif				// USE_DEBUG_GLFUNCS

//
// GL_ARB_vertex_buffer_object
//
extern dboolean has_GL_ARB_vertex_buffer_object;

extern PFNGLBINDBUFFERARBPROC _glBindBufferARB;
extern PFNGLDELETEBUFFERSARBPROC _glDeleteBuffersARB;
extern PFNGLGENBUFFERSARBPROC _glGenBuffersARB;
extern PFNGLISBUFFERARBPROC _glIsBufferARB;
extern PFNGLBUFFERDATAARBPROC _glBufferDataARB;
extern PFNGLBUFFERSUBDATAARBPROC _glBufferSubDataARB;
extern PFNGLGETBUFFERSUBDATAARBPROC _glGetBufferSubDataARB;
extern PFNGLMAPBUFFERARBPROC _glMapBufferARB;
extern PFNGLUNMAPBUFFERARBPROC _glUnmapBufferARB;
extern PFNGLGETBUFFERPARAMETERIVARBPROC _glGetBufferParameterivARB;
extern PFNGLGETBUFFERPOINTERVARBPROC _glGetBufferPointervARB;

#define GL_ARB_vertex_buffer_object_Define() \
dboolean has_GL_ARB_vertex_buffer_object = false; \
PFNGLBINDBUFFERARBPROC _glBindBufferARB = NULL; \
PFNGLDELETEBUFFERSARBPROC _glDeleteBuffersARB = NULL; \
PFNGLGENBUFFERSARBPROC _glGenBuffersARB = NULL; \
PFNGLISBUFFERARBPROC _glIsBufferARB = NULL; \
PFNGLBUFFERDATAARBPROC _glBufferDataARB = NULL; \
PFNGLBUFFERSUBDATAARBPROC _glBufferSubDataARB = NULL; \
PFNGLGETBUFFERSUBDATAARBPROC _glGetBufferSubDataARB = NULL; \
PFNGLMAPBUFFERARBPROC _glMapBufferARB = NULL; \
PFNGLUNMAPBUFFERARBPROC _glUnmapBufferARB = NULL; \
PFNGLGETBUFFERPARAMETERIVARBPROC _glGetBufferParameterivARB = NULL; \
PFNGLGETBUFFERPOINTERVARBPROC _glGetBufferPointervARB = NULL

#define GL_ARB_vertex_buffer_object_Init() \
has_GL_ARB_vertex_buffer_object = GL_CheckExtension("GL_ARB_vertex_buffer_object"); \
_glBindBufferARB = GL_RegisterProc("glBindBufferARB"); \
_glDeleteBuffersARB = GL_RegisterProc("glDeleteBuffersARB"); \
_glGenBuffersARB = GL_RegisterProc("glGenBuffersARB"); \
_glIsBufferARB = GL_RegisterProc("glIsBufferARB"); \
_glBufferDataARB = GL_RegisterProc("glBufferDataARB"); \
_glBufferSubDataARB = GL_RegisterProc("glBufferSubDataARB"); \
_glGetBufferSubDataARB = GL_RegisterProc("glGetBufferSubDataARB"); \
_glMapBufferARB = GL_RegisterProc("glMapBufferARB"); \
_glUnmapBufferARB = GL_RegisterProc("glUnmapBufferARB"); \
_glGetBufferParameterivARB = GL_RegisterProc("glGetBufferParameterivARB"); \
_glGetBufferPointervARB = GL_RegisterProc("glGetBufferPointervARB")

#ifndef USE_DEBUG_GLFUNCS

#define dglBindBufferARB(target, buffer) _glBindBufferARB(target, buffer)
#define dglDeleteBuffersARB(n, buffers) _glDeleteBuffersARB(n, buffers)
#define dglGenBuffersARB(n, buffers) _glGenBuffersARB(n, buffers)
#define dglIsBufferARB(buffer) _glIsBufferARB(buffer)
#define dglBufferDataARB(target, size, data, usage) _glBufferDataARB(target, size, data, usage)
#define dglBufferSubDataARB(target, offset, size, data) _glBufferSubDataARB(target, offset, size, data)
#define dglGetBufferSubDataARB(target, offset, size, data) _glGetBufferSubDataARB(target, offset, size, data)
#define dglMapBufferARB(target, access) _glMapBufferARB(target, access)
#define dglUnmapBufferARB(target) _glUnmapBufferARB(target)
#define dglGetBufferParameterivARB(target, pname, params) _glGetBufferParameterivARB(target, pname, params)
#define dglGetBufferPointervARB(target, pname, params) _glGetBufferPointervARB(target, pname, params)

#else

d_inline static void glBindBufferARB_DEBUG(GLenum target, GLuint buffer,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glBindBufferARB(target=0x%x, buffer=%i)\n",
	     file, line, target, buffer);
#endif
	_glBindBufferARB(target, buffer);
	dglLogError("glBindBufferARB", file, line);
}

d_inline static void glDeleteBuffersARB_DEBUG(GLsizei n, GLuint * buffers,
					      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glDeleteBuffersARB(n=0x%x, buffers=%p)\n",
	     file, line, n, buffers);
#endif
	_glDeleteBuffersARB(n, buffers);
	dglLogError("glDeleteBuffersARB", file, line);
}

d_inline static void glGenBuffersARB_DEBUG(GLsizei n, GLuint * buffers,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glGenBuffersARB(n=0x%x, buffers=%p)\n",
		 file, line, n, buffers);
#endif
	_glGenBuffersARB(n, buffers);
	dglLogError("glGenBuffersARB", file, line);
}

d_inline static GLboolean glIsBufferARB_DEBUG(GLuint buffer, const char *file,
					      int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glIsBufferARB(buffer=%i)\n", file, line,
		 buffer);
#endif
	_glIsBufferARB(buffer);
	dglLogError("glIsBufferARB", file, line);
}

d_inline static void glBufferDataARB_DEBUG(GLenum target, GLsizeiptrARB size,
					   GLvoid * data, GLenum usage,
					   const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glBufferDataARB(target=0x%x, size=, data=%p, usage=0x%x)\n",
	     file, line, target, size, data, usage);
#endif
	_glBufferDataARB(target, size, data, usage);
	dglLogError("glBufferDataARB", file, line);
}

d_inline static void glBufferSubDataARB_DEBUG(GLenum target, GLintptrARB offset,
					      GLsizeiptrARB size, GLvoid * data,
					      const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glBufferSubDataARB(target=0x%x, offset=, size=, data=%p)\n",
	     file, line, target, offset, size, data);
#endif
	_glBufferSubDataARB(target, offset, size, data);
	dglLogError("glBufferSubDataARB", file, line);
}

d_inline static void glGetBufferSubDataARB_DEBUG(GLenum target,
						 GLintptrARB offset,
						 GLsizeiptrARB size,
						 GLvoid * data,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetBufferSubDataARB(target=0x%x, offset=, size=, data=%p)\n",
	     file, line, target, offset, size, data);
#endif
	_glGetBufferSubDataARB(target, offset, size, data);
	dglLogError("glGetBufferSubDataARB", file, line);
}

d_inline static void glMapBufferARB_DEBUG(GLenum target, GLenum access,
					  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glMapBufferARB(target=0x%x, access=0x%x)\n",
	     file, line, target, access);
#endif
	_glMapBufferARB(target, access);
	dglLogError("glMapBufferARB", file, line);
}

d_inline static GLboolean glUnmapBufferARB_DEBUG(GLenum target,
						 const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf("file = %s, line = %i, glUnmapBufferARB(target=0x%x)\n", file,
		 line, target);
#endif
	_glUnmapBufferARB(target);
	dglLogError("glUnmapBufferARB", file, line);
}

d_inline static void glGetBufferParameterivARB_DEBUG(GLenum target,
						     GLenum pname,
						     GLint * params,
						     const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetBufferParameterivARB(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	_glGetBufferParameterivARB(target, pname, params);
	dglLogError("glGetBufferParameterivARB", file, line);
}

d_inline static void glGetBufferPointervARB_DEBUG(GLenum target, GLenum pname,
						  void *params,
						  const char *file, int line)
{
#ifdef LOG_GLFUNC_CALLS
	I_Printf
	    ("file = %s, line = %i, glGetBufferPointervARB(target=0x%x, pname=0x%x, params=%p)\n",
	     file, line, target, pname, params);
#endif
	_glGetBufferPointervARB(target, pname, params);
	dglLogError("glGetBufferPointervARB", file, line);
}

#define dglBindBufferARB(target, buffer) glBindBufferARB_DEBUG(target, buffer, __FILE__, __LINE__)
#define dglDeleteBuffersARB(n, buffers) glDeleteBuffersARB_DEBUG(n, buffers, __FILE__, __LINE__)
#define dglGenBuffersARB(n, buffers) glGenBuffersARB_DEBUG(n, buffers, __FILE__, __LINE__)
#define dglIsBufferARB(buffer) glIsBufferARB_DEBUG(buffer, __FILE__, __LINE__)
#define dglBufferDataARB(target, size, data, usage) glBufferDataARB_DEBUG(target, size, data, usage, __FILE__, __LINE__)
#define dglBufferSubDataARB(target, offset, size, data) glBufferSubDataARB_DEBUG(target, offset, size, data, __FILE__, __LINE__)
#define dglGetBufferSubDataARB(target, offset, size, data) glGetBufferSubDataARB_DEBUG(target, offset, size, data, __FILE__, __LINE__)
#define dglMapBufferARB(target, access) glMapBufferARB_DEBUG(target, access, __FILE__, __LINE__)
#define dglUnmapBufferARB(target) glUnmapBufferARB_DEBUG(target, __FILE__, __LINE__)
#define dglGetBufferParameterivARB(target, pname, params) glGetBufferParameterivARB_DEBUG(target, pname, params, __FILE__, __LINE__)
#define dglGetBufferPointervARB(target, pname, params) glGetBufferPointervARB_DEBUG(target, pname, params, __FILE__, __LINE__)

#endif				// USE_DEBUG_GLFUNCS

//
// GL_ARB_texture_non_power_of_two
//
extern dboolean has_GL_ARB_texture_non_power_of_two;

#define GL_ARB_texture_non_power_of_two_Define() \
dboolean has_GL_ARB_texture_non_power_of_two = false;

#define GL_ARB_texture_non_power_of_two_Init() \
has_GL_ARB_texture_non_power_of_two = GL_CheckExtension("GL_ARB_texture_non_power_of_two");

//
// GL_ARB_texture_env_combine
//
extern dboolean has_GL_ARB_texture_env_combine;

#ifdef HAVE_GLES
#define GL_ARB_texture_env_combine_Define() \
dboolean has_GL_ARB_texture_env_combine = true;

#define GL_ARB_texture_env_combine_Init() \
has_GL_ARB_texture_env_combine = true;
#else
#define GL_ARB_texture_env_combine_Define() \
dboolean has_GL_ARB_texture_env_combine = false;

#define GL_ARB_texture_env_combine_Init() \
has_GL_ARB_texture_env_combine = GL_CheckExtension("GL_ARB_texture_env_combine");
#endif

//
// GL_EXT_texture_env_combine
//
extern dboolean has_GL_EXT_texture_env_combine;
#define GL_EXT_texture_env_combine_Define() \
dboolean has_GL_EXT_texture_env_combine = false;

#define GL_EXT_texture_env_combine_Init() \
has_GL_EXT_texture_env_combine = GL_CheckExtension("GL_EXT_texture_env_combine");
//
// GL_EXT_texture_filter_anisotropic
//
extern dboolean has_GL_EXT_texture_filter_anisotropic;

#define GL_EXT_texture_filter_anisotropic_Define() \
dboolean has_GL_EXT_texture_filter_anisotropic = false;

#define GL_EXT_texture_filter_anisotropic_Init() \
has_GL_EXT_texture_filter_anisotropic = GL_CheckExtension("GL_EXT_texture_filter_anisotropic");

#endif				// __DGL_H__
