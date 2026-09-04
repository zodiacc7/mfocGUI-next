#pragma once

#include "../Dump/MifareClassic.h"
#include "../Credential/ProfileLoader.h"

#include <vector>
#include <cstdint>


class DumpViewer
{

public:

    void showCard(
        MifareClassic& card
    );


    void showCredentials(
        MifareClassic& card,
        ProfileLoader& profile
    );


    void editCredit(
        MifareClassic& card,
        ProfileLoader& profile,
        std::string value
    );


private:

    void printHex(
        const std::vector<uint8_t>& data
    );

};
