#include "DumpParser.h"
#include <fstream>

bool DumpParser::load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);

    if(!file)
        return false;

    data.assign(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );

    return true;
}
