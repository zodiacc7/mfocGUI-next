#include "MifareClassic.h"

#include <fstream>


std::vector<uint8_t> blocks;



bool MifareClassic::loadDump(std::string filename)
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
MifareClassic::getBlock(int block)
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
