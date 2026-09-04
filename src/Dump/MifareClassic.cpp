#include "MifareClassic.h"


BlockInfo MifareClassic::getBlockInfo(int block)
{
    BlockInfo info;

    if(block < 128)
    {
        info.sector = block / 4;
        info.block = block % 4;
    }
    else
    {
        info.sector = 32 + ((block - 128) / 16);
        info.block = (block - 128) % 16;
    }


    int blocksPerSector = 
        (info.sector < 32) ? 4 : 16;


    info.trailer =
        (info.block == blocksPerSector - 1);


    return info;
}
