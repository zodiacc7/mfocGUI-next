#pragma once

#include <vector>
#include <string>
#include <cstdint>


class MifareClassic
{

public:

    static constexpr int BLOCK_SIZE = 16;


    bool loadDump(
        std::string filename
    );


    std::vector<uint8_t> getBlock(
        int block
    );

};
