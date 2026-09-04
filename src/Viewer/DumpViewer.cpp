#include "DumpViewer.h"

#include <iostream>
#include <iomanip>


void DumpViewer::showCard(
    MifareClassic& card
)
{

    for(int block = 0; block < 64; block++)
    {

        std::cout
            << "Block "
            << block
            << ": ";


        auto data =
            card.getBlock(block);


        printHex(data);

    }

}



void DumpViewer::printHex(
    const std::vector<uint8_t>& data
)
{

    for(auto b : data)
    {

        std::cout
            << std::hex
            << std::setw(2)
            << std::setfill('0')
            << (int)b
            << " ";

    }


    std::cout
        << std::dec
        << std::endl;

}
