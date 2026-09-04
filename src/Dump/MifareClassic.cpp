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


    while(file)
    {

        std::vector<uint8_t> block(
            BLOCK_SIZE
        );


        file.read(
            reinterpret_cast<char*>(
                block.data()
            ),
            BLOCK_SIZE
        );


        if(file.gcount() != BLOCK_SIZE)
            break;


        blocks.push_back(block);

    }


    return !blocks.empty();

}



bool MifareClassic::saveDump(
    std::string filename
)
{

    std::ofstream file(
        filename,
        std::ios::binary
    );


    if(!file)
        return false;


    for(auto& block : blocks)
    {

        file.write(
            reinterpret_cast<char*>(
                block.data()
            ),
            BLOCK_SIZE
        );

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



bool MifareClassic::writeBlock(
    int block,
    std::vector<uint8_t> data
)
{

    if(
        block < 0 ||
        block >= blocks.size()
    )
    {
        return false;
    }


    if(
        data.size() != BLOCK_SIZE
    )
    {
        return false;
    }


    blocks[block] = data;


    return true;

}



BlockInfo MifareClassic::getBlockInfo(
    int block
)
{

    BlockInfo info;


    if(block < 128)
    {
        info.sector = block / 4;
        info.block = block % 4;
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



SectorTrailer MifareClassic::getSectorTrailer(
    int block
)
{

    SectorTrailer trailer;


    auto data =
        getBlock(block);


    if(data.size() != 16)
        return trailer;


    trailer.keyA.assign(
        data.begin(),
        data.begin()+6
    );


    trailer.accessBits.assign(
        data.begin()+6,
        data.begin()+10
    );


    trailer.keyB.assign(
        data.begin()+10,
        data.end()
    );


    return trailer;

}
