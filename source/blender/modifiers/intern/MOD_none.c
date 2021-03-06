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
 * The Original Code is Copyright (C) 2005 Blender Foundation.
 * All rights reserved.
 */

/** \file
 * \ingroup modifiers
 */

#include <stdio.h>

#include "BLI_utildefines.h"

#include "MOD_modifiertypes.h"

#include "UI_resources.h"

#include "RNA_access.h"

/* We only need to define isDisabled; because it always returns 1,
 * no other functions will be called
 */

static bool isDisabled(const struct Scene *UNUSED(scene),
                       ModifierData *UNUSED(md),
                       bool UNUSED(userRenderParams))
{
  return true;
}

ModifierTypeInfo modifierType_None = {
    /* name */ "None",
    /* structName */ "ModifierData",
    /* structSize */ sizeof(ModifierData),
    /* srna */ &RNA_Modifier,
    /* type */ eModifierTypeType_None,
    /* flags */ eModifierTypeFlag_AcceptsMesh | eModifierTypeFlag_AcceptsCVs,
    /* icon */ ICON_NONE,

    /* copyData */ NULL,

    /* deformVerts */ NULL,
    /* deformMatrices */ NULL,
    /* deformVertsEM */ NULL,
    /* deformMatricesEM */ NULL,
    /* modifyMesh */ NULL,
    /* modifyGeometrySet */ NULL,

    /* initData */ NULL,
    /* requiredDataMask */ NULL,
    /* freeData */ NULL,
    /* isDisabled */ isDisabled,
    /* updateDepsgraph */ NULL,
    /* dependsOnTime */ NULL,
    /* dependsOnNormals */ NULL,
    /* foreachIDLink */ NULL,
    /* foreachTexLink */ NULL,
    /* freeRuntimeData */ NULL,
    /* panelRegister */ NULL,
    /* blendWrite */ NULL,
    /* blendRead */ NULL,
};
