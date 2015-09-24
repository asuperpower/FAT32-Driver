/*+===================================================================
  File:

  Summary:

  Author:

  Rev History:

----------------------------------------------------------------------
  Copyright 2015-2016 Radial Technologies, Pty Ltd
===================================================================+*/

#pragma once
#include "fatstruc.h"

//Handy FAT32 macro functions!
#define SECTOR2OFFSET(sectnum, bps)         (sectnum * bps)
#define CLUST2OFFSET(clustnum, bps, spc)    (clustnum * bps * spc)

uint32_t    fat_rootdir(); //Offset into the disk our root directory lies
uint8_t     fat_initvolume32(FAT32_MBR* mbr);


