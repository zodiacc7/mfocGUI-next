#include "DumpViewer.h"

#include <iostream>
#include <iomanip>


void DumpViewer::showDump(DumpParser& dump)
{

    for(int s = 0; s < dump.getSectorCount(); s++)
    {

        std::cout
            << "Sector "
            << s
            << std::endl;


        auto blocks =
            dump.getBlocks(s);


        for(auto& block : blocks)
        {

            std::cout
                << " Block "
                << block.index
                << ": ";


            printHex(block.data);

        }

    }

}



void DumpViewer::printHex(
    const std::vector<uint8_t>& data
)
{

    for(auto byte : data)
    {

        std::cout
            << std::hex
            << std::setw(2)
            << std::setfill('0')
            << (int)byte
            << " ";

    }


    std::cout
        << std::dec
        << std::endl;

}
