#include "DumpViewer.h"
#include <iostream>


void DumpViewer::showStructure(int sectors)
{

    for(int s = 0; s < sectors; s++)
    {

        std::cout
            << "Sector "
            << s
            << std::endl;


        for(int b = 0; b < 4; b++)
        {

            if(b == 3)
            {
                std::cout
                    << " Block "
                    << b
                    << " (Trailer)"
                    << std::endl;
            }
            else
            {
                std::cout
                    << " Block "
                    << b
                    << std::endl;
            }

        }

    }

}
