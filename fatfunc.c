/*+===================================================================
  File:

  Summary:

  Author:

  Rev History:

----------------------------------------------------------------------
  Copyright 2015-2016 Radial Technologies, Pty Ltd
===================================================================+*/
#include "fatfunc.h"

/**
    Initialise the volume by doing some sanity checks on the boot record. Kick and scream if something is wrong.
    On the Teensy, this will (probably) not take a paramater, as we'll just read the 512-byte block into a local struct and check it from there.
**/
uint8_t fat_initvolume32(FAT32_MBR* mbr)
{
    //Our boot signature is not 0xAA55, something could be wrong here...
    if(mbr->fat_bootsig != 0xAA55)
    {
        return 0;
    }
}
