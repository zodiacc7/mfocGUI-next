#pragma once

#include <vector>
#include <string>
#include <cstdint>


struct BlockInfo
{
    int sector;
    int block;
    bool trailer;
};


struct SectorTrailer
{
    std::vector<uint8_t> keyA;
    std::vector<uint8_t> accessBits;
    std::vector<uint8_t> keyB;
};



class MifareClassic
{

private:

    std::vector<std::vector<uint8_t>> blocks;


public:

    static constexpr int BLOCK_SIZE = 16;


    bool loadDump(
        std::string filename
    );


    std::vector<uint8_t> getBlock(
        int block
    );


    BlockInfo getBlockInfo(
        int block
    );


    SectorTrailer getSectorTrailer(
        int block
    );

};
