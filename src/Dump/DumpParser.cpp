#include "DumpParser.h"

#include <fstream>


bool DumpParser::load(std::string filename)
{

    std::ifstream file(
        filename,
        std::ios::binary
    );


    if(!file)
        return false;


    sectors.clear();


    /*
        MIFARE Classic:
        
        1K:
        16 sectors
        each sector:
        4 blocks

        block size:
        16 bytes
    */


    for(int s = 0; s < 16; s++)
    {

        std::vector<DumpBlock> sector;


        for(int b = 0; b < 4; b++)
        {

            DumpBlock block;


            block.index =
                b;


            block.data.resize(16);


            file.read(
                reinterpret_cast<char*>(
                    block.data.data()
                ),
                16
            );


            if(!file)
                return false;


            sector.push_back(block);

        }


        sectors.push_back(sector);

    }


    return true;

}



int DumpParser::getSectorCount()
{

    return sectors.size();

}



std::vector<DumpBlock>
DumpParser::getBlocks(int sector)
{

    if(
        sector < 0 ||
        sector >= sectors.size()
    )
    {
        return {};
    }


    return sectors[sector];

}
