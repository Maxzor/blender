/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2012 Blender Foundation.
 * All rights reserved.
 */

/** \file
 * \ingroup pybmesh
 */

#pragma once

struct BPy_BMesh;

extern PyTypeObject BPy_BMEditSelSeq_Type;
extern PyTypeObject BPy_BMEditSelIter_Type;

#define BPy_BMSelectHistory_Check(v) (Py_TYPE(v) == &BPy_BMEditSelSeq_Type)
#define BPy_BMSelectHistoryIter_Check(v) (Py_TYPE(v) == &BPy_BMEditSelIter_Type)

typedef struct BPy_BMEditSelSeq {
  PyObject_VAR_HEAD
  struct BMesh *bm; /* keep first */
} BPy_BMEditSelSeq;

typedef struct BPy_BMEditSelIter {
  PyObject_VAR_HEAD
  struct BMesh *bm; /* keep first */
  struct BMEditSelection *ese;
} BPy_BMEditSelIter;

void BPy_BM_init_types_select(void);

PyObject *BPy_BMEditSel_CreatePyObject(BMesh *bm);
PyObject *BPy_BMEditSelIter_CreatePyObject(BMesh *bm);
/**
 * \note doesn't actually check selection.
 */
int BPy_BMEditSel_Assign(struct BPy_BMesh *self, PyObject *value);
