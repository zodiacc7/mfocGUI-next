#include "DumpViewer.h"

#include <iostream>
#include <iomanip>



void DumpViewer::showCard(
    MifareClassic& card
)
{

    for(int block = 0; block < 64; block++)
    {

        auto info =
            card.getBlockInfo(block);


        std::cout
            << "Sector "
            << info.sector
            << " Block "
            << info.block;


        if(info.trailer)
        {

            std::cout
                << " [SECTOR TRAILER]";

        }


        std::cout
            << std::endl;


        auto data =
            card.getBlock(block);


        printHex(data);


        if(info.trailer)
        {

            auto trailer =
                card.getSectorTrailer(block);


            std::cout
                << " Key A: ";

            printHex(
                trailer.keyA
            );


            std::cout
                << " Access Bits: ";

            printHex(
                trailer.accessBits
            );


            std::cout
                << " Key B: ";

            printHex(
                trailer.keyB
            );

        }


        std::cout
            << std::endl;

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
