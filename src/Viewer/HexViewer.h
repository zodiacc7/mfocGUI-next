#pragma once

#include <vector>
#include <cstdint>

class HexViewer
{
public:
    static void show(const std::vector<uint8_t>& data);
};
