#pragma once

#include <vector>
#include <string>
#include <cstdint>


struct DumpBlock
{
    int index;

    std::vector<uint8_t> data;
};


class DumpParser
{

private:

    std::vector<std::vector<DumpBlock>> sectors;


public:

    bool load(std::string filename);


    int getSectorCount();


    std::vector<DumpBlock> getBlocks(int sector);


};
