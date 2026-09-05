#include "DumpViewer.h"

#include <cstddef>
#include <cstdint>
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

    }

}



void DumpViewer::showCredentials(
    MifareClassic& card,
    ProfileLoader& profile
)
{

    auto fields =
        profile.getFields();


    CredentialDecoder decoder;


    for(int i = 0; i < static_cast<int>(fields.size()); i++)
    {

        auto data =
            decoder.decode(
                card,
                fields[i]
            );


        std::cout
            << fields[i].name
            << ": "
            << decoder.decodeValue(
                data,
                fields[i].type
            )
            << std::endl;

    }

}



void DumpViewer::editCredit(
    MifareClassic& card,
    ProfileLoader& profile,
    std::string value
)
{

    profile.updateField(
        card,
        0,
        value
    );


    std::cout
        << "Credit updated: "
        << value
        << std::endl;

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
