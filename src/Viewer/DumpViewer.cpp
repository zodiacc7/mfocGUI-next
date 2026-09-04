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


    CredentialDecoder decoder;


    for(auto& field : fields)
    {

        auto data =
            decoder.decode(
                card,
                field
            );


        std::cout
            << field.name
            << ": ";


        std::cout
            << decoder.decodeValue(
                data,
                field.type
            )
            << std::endl;

    }

}



void DumpViewer::showCredit(
    MifareClassic& card,
    ProfileLoader& profile
)
{

    auto fields =
        profile.getFields();


    if(fields.empty())
        return;


    CredentialDecoder decoder;


    auto data =
        decoder.decode(
            card,
            fields[0]
        );


    std::cout
        << "Credit: ";


    std::cout
        << decoder.decodeValue(
            data,
            fields[0].type
        )
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
