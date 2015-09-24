#include <stdio.h>
#include <stdlib.h>

#include "fatstruc.h"
#include "fatfunc.h"

int main()
{
    FILE* img = fopen("bpb.img", "r");
    FAT32_MBR mbr;

    //Read our bios-block into our FAT32_MBR struct
    fread(&mbr, sizeof(uint8_t), sizeof(FAT32_MBR), img);

    printf("DRIVE DATA:\n");
    printf("Bytes per sector: %d\n", mbr.fat_bps);
    printf("Sectors per Cluster: %d\n", mbr.fat_spc);
    printf("Num. Resvd sectors: %d\n", mbr.fat_rsvdsectscnt);
    printf("Fat Size: %d\n", mbr.fat_fatsz32);
    printf("Number of FATS: %d\n", mbr.fat_numfats);
    printf("ROOT Dir cluster num.: %d\n", mbr.fat_rootclus);


    return 0;
}
