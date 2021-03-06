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
 * The Original Code is Copyright (C) 2008 Blender Foundation.
 * All rights reserved.
 */

/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ARegion;
struct Object;
struct UndoType;
struct ViewContext;
struct bContext;
struct rcti;

/* sculpt.c */

void ED_operatortypes_sculpt(void);
void ED_sculpt_redraw_planes_get(float planes[4][4], struct ARegion *region, struct Object *ob);
bool ED_sculpt_mask_box_select(struct bContext *C,
                               struct ViewContext *vc,
                               const struct rcti *rect,
                               bool select);

/* sculpt_transform.c */

void ED_sculpt_update_modal_transform(struct bContext *C, struct Object *ob);
void ED_sculpt_init_transform(struct bContext *C, struct Object *ob);
void ED_sculpt_end_transform(struct bContext *C, struct Object *ob);

/* sculpt_undo.c */

/** Export for ED_undo_sys. */
void ED_sculpt_undosys_type(struct UndoType *ut);

void ED_sculpt_undo_geometry_begin(struct Object *ob, const char *name);
void ED_sculpt_undo_geometry_end(struct Object *ob);

/* Face sets. */

int ED_sculpt_face_sets_find_next_available_id(struct Mesh *mesh);
void ED_sculpt_face_sets_initialize_none_to_id(struct Mesh *mesh, int new_id);

int ED_sculpt_face_sets_active_update_and_get(struct bContext *C,
                                              struct Object *ob,
                                              const float mval[2]);

/* Undo for changes happening on a base mesh for multires sculpting.
 * if there is no multi-res sculpt active regular undo is used. */
void ED_sculpt_undo_push_multires_mesh_begin(struct bContext *C, const char *str);
void ED_sculpt_undo_push_multires_mesh_end(struct bContext *C, const char *str);

#ifdef __cplusplus
}
#endif
