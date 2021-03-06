/*
 * Copyright (c) 2017 Red Hat, Inc.
 *
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA. 
 *
 * $Id: //eng/uds-releases/flanders/src/uds/regionIndexComponentInternal.h#2 $
 */

#ifndef REGION_INDEX_COMPONENT_INTERNAL_H
#define REGION_INDEX_COMPONENT_INTERNAL_H

#include "regionIndexComponent.h"
#include "indexComponentInternal.h"

#include "compiler.h"
#include "permassert.h"

typedef struct regionIndexComponent {
  IndexComponent    common;
  RegionIndexState *ris;
} RegionIndexComponent;

/*****************************************************************************/
static INLINE RegionIndexComponent *asRegionIndexComponent(IndexComponent *comp)
{
  return container_of(comp, RegionIndexComponent, common);
}

#endif // REGION_INDEX_COMPONENT_INTERNAL_H
