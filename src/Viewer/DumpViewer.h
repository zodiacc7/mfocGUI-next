#pragma once

#include "../Dump/DumpParser.h"


class DumpViewer
{
public:

    void showDump(DumpParser& dump);

private:

    void printHex(
        const std::vector<uint8_t>& data
    );

};
