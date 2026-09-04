#include "MifareClassic.h"

#include <fstream>



bool MifareClassic::loadDump(
    std::string filename
)
{

    std::ifstream file(
        filename,
        std::ios::binary
    );


    if(!file)
        return false;


    blocks.clear();


    for(int i = 0; i < 64; i++)
    {

        std::vector<uint8_t> block;

        block.resize(
            BLOCK_SIZE
        );


        file.read(
            reinterpret_cast<char*>(
                block.data()
            ),
            BLOCK_SIZE
        );


        if(!file)
            return false;


        blocks.push_back(block);

    }


    return true;

}



std::vector<uint8_t>
MifareClassic::getBlock(
    int block
)
{

    if(
        block < 0 ||
        block >= blocks.size()
    )
    {
        return {};
    }


    return blocks[block];

}



BlockInfo MifareClassic::getBlockInfo(
    int block
)
{

    BlockInfo info;


    if(block < 128)
    {

        info.sector =
            block / 4;

        info.block =
            block % 4;

    }
    else
    {

        info.sector =
            32 + ((block - 128) / 16);

        info.block =
            (block - 128) % 16;

    }


    int blocksPerSector =
        (info.sector < 32)
        ? 4
        : 16;


    info.trailer =
        (
            info.block ==
            blocksPerSector - 1
        );


    return info;

}
