/*+===================================================================
  File:

  Summary:

  Author:

  Rev History:

----------------------------------------------------------------------
  Copyright 2015-2016 Radial Technologies, Pty Ltd
===================================================================+*/

#pragma once

#include <stdint.h>

struct MBR
{
    uint8_t     fat_jmp[3]; //3 Bytes of x86 Jump code
    char        fat_oem[8]; //8 Byte OEM name
    uint16_t    fat_bps; //Number of bytes per sector on the disk.
    uint8_t     fat_spc; //Number of sectors per cluster
    uint16_t    fat_rsvdsectscnt; //Number of reserved sectors on disk.
    uint8_t     fat_numfats; //Number of fat-data structures on disk
    uint16_t    fat_numrootents; //Should be zero for FAT32. Number of 32-byte dir entries in the root dir
    uint16_t    fat_sectors16; //Should be zero for FAT32.
    uint8_t     fat_mediatype; //Type of media we are dealing with.
    uint16_t    fat_fatsz16; //FAT12/16 FAT size in sectors. Zero in FAT32.
    uint16_t    fat_spt; //Number of sectors per track. Only relevant for drives with actual geometry (I'm looking at you, floppy disks...)
    uint16_t    fat_numheads; //Number of heads. For disks with real geometry
    uint32_t    fat_hiddsecs; //Number of hidden sectors preceding the partition with FAT volume
    uint32_t    fat_sectors32; //Number of 32-bit sectors on the volume.
    uint32_t    fat_fatsz32; //32-bit FAT size
    /**
        Bits 0-3: Zero-based number of active FAT. Only valid if mirroring is disabled
        Bits 4-6: Reserved
        Bit  7:   0 Means FAT is mirrored at runtime into all FATS
                  1 means only one FAT is active
        Bits 8-15: Reserved
    **/
    uint16_t    fat_extflags;
    uint16_t    fat_fsver; //HIgh byte is major revision of the FAT32 file system, Low Byte is lower rev number
    uint32_t    fat_rootclus; //Cluster number of first cluster of the root directory. Usually 2
    uint16_t    fat_fsinfo; //Cluster number where the FSINFO structure is located
    uint16_t    fat_bkbootsec; //If Non-Zero, this is the sector number in the resvd area our copy boot sector
    uint8_t     fat_resvd[12]; //Reserved for future expansion
    uint8_t     fat_drvnum; //Drive Number (?)
    uint8_t     fat_resvd1; //Don't know what this is, bet you feel stupid reading this comment now :)
    uint8_t     fat_bootsig; //Same here!
    uint32_t    fat_volid;
    uint8_t     fat_vollab[11];
    char        fat_fstype; //Should ALWAYS be the string "FAT32   "
}__attribute((packed));

//Directory and file entry
struct fentry
{
    char        fat_fname[11]; //Our 8.3 short file name
    uint8_t     fat_fattrib;    //File attributes
    uint8_t     fat_resvd[10];  //Reserved..
    uint16_t    fat_ctime;  //File creation time
    uint16_t    fat_cdate;   //File creation date
    uint16_t    fat_laccess;
    uint16_t    fat_clusthi; //High 16-bits of cluster number
    uint32_t    UNUSED; //Unused for us
    uint16_t    fat_clustlo; //Low 16-bits of cluster
    uint32_t    fat_fsize;
}__attribute((packed));


typedef struct MBR      FAT32_MBR;
typedef struct fentry   FAT32_FILE;

