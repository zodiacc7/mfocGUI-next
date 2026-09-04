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


        printHex(
            card.getBlock(block)
        );


        std::cout
            << std::endl;

    }

}



void DumpViewer::showCredentials(
    MifareClassic& card,
    ProfileLoader& profile
)
{

    auto fields =
        profile.getFields();


    for(int i = 0; i < fields.size(); i++)
    {

        auto value =
            profile.decodeField(
                card,
                i
            );


        std::cout
            << "Field "
            << fields[i].name
            << ": ";


        printHex(value);

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
