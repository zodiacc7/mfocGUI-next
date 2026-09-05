#include "HexViewer.h"

#include <iostream>
#include <iomanip>

void HexViewer::show(const std::vector<uint8_t>& data)
{
    for(auto b : data)
    {
        std::cout
            << std::hex
            << std::setw(2)
            << std::setfill('0')
            << static_cast<int>(b)
            << " ";
    }

    std::cout << std::dec << std::endl;
}
