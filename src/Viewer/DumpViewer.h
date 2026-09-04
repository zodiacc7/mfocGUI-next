#pragma once

#include "../Dump/MifareClassic.h"


class DumpViewer
{

public:

    void showCard(
        MifareClassic& card
    );


private:

    void printHex(
        const std::vector<uint8_t>& data
    );

};
