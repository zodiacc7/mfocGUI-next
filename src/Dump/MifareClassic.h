#ifndef MIFARECLASSIC_H
#define MIFARECLASSIC_H

struct BlockInfo
{
    int sector;
    int block;
    bool trailer;
};


class MifareClassic
{
public:

    static BlockInfo getBlockInfo(int block);

};

#endif
