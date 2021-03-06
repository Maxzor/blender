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
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 */
#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct BlendDataReader;
struct BlendWriter;
struct Object;
struct ReportList;
struct Scene;
struct bAnimVizSettings;
struct bMotionPath;
struct bPoseChannel;

/* ---------------------------------------------------- */
/* Animation Visualization */

/**
 * Initialize the default settings for animation visualization.
 */
void animviz_settings_init(struct bAnimVizSettings *avs);

/**
 * Make a copy of motion-path data, so that viewing with copy on write works.
 */
struct bMotionPath *animviz_copy_motionpath(const struct bMotionPath *mpath_src);

/**
 * Free the given motion path's cache.
 */
void animviz_free_motionpath_cache(struct bMotionPath *mpath);
/**
 * Free the given motion path instance and its data.
 * \note this frees the motion path given!
 */
void animviz_free_motionpath(struct bMotionPath *mpath);

/**
 * Setup motion paths for the given data.
 * \note Only used when explicitly calculating paths on bones which may/may not be consider already
 *
 * \param scene: Current scene (for frame ranges, etc.)
 * \param ob: Object to add paths for (must be provided)
 * \param pchan: Posechannel to add paths for (optional; if not provided, object-paths are assumed)
 */
struct bMotionPath *animviz_verify_motionpaths(struct ReportList *reports,
                                               struct Scene *scene,
                                               struct Object *ob,
                                               struct bPoseChannel *pchan);

void animviz_motionpath_blend_write(struct BlendWriter *writer, struct bMotionPath *mpath);
void animviz_motionpath_blend_read_data(struct BlendDataReader *reader, struct bMotionPath *mpath);

#ifdef __cplusplus
}
#endif
