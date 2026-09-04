#include "DumpViewer.h"
#include <iostream>


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
                << std::endl;
        }

    }

}
