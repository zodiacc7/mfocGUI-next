#ifndef DUMPPARSER_H
#define DUMPPARSER_H

#include <string>
#include <vector>

class DumpParser
{
public:

    bool load(const std::string& filename);

    std::vector<unsigned char> data;

};

#endif
