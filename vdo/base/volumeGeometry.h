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
 * $Id: //eng/vdo-releases/magnesium/src/c++/vdo/base/volumeGeometry.h#1 $
 */

#ifndef VOLUME_GEOMETRY_H
#define VOLUME_GEOMETRY_H

#include "types.h"

typedef enum {
  INDEX_REGION = 0,
  DATA_REGION  = 1,
  VOLUME_REGION_COUNT,
} VolumePartitionID;

typedef struct {
  /** The ID of the partition */
  VolumePartitionID   id;
  /**
   * The absolute starting offset on the device. The partition continues until
   * the next partition begins.
   */
  PhysicalBlockNumber startBlock;
} __attribute__((packed)) VolumePartition;

typedef struct {
  /** The nonce of this volume */
  Nonce           nonce;
  /** The partitions in ID order */
  VolumePartition partitions[VOLUME_REGION_COUNT];
} __attribute__((packed)) VolumeGeometry;

/**
 * Read a geometry block.
 *
 * @param [in]  layer        The layer to read and parse the geometry from
 * @param [out] geometryPtr  A pointer to return the geometry in
 **/
int loadVolumeGeometry(PhysicalLayer *layer, VolumeGeometry **geometryPtr)
__attribute__((warn_unused_result));

/**
 * Write a geometry block for a VDO.
 *
 * @param layer      The layer for the VDO
 * @param nonce      The nonce for the VDO
 * @param indexSize  The size, in blocks, for the index
 *
 * @return VDO_SUCCESS or an error
 **/
int writeVolumeGeometry(PhysicalLayer *layer,
                        Nonce          nonce,
                        BlockCount     indexSize)
__attribute__((warn_unused_result));

#endif // VOLUME_GEOMETRY_H
