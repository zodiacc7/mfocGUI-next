#pragma once

#include "../Dump/MifareClassic.h"
#include "../Credential/ProfileLoader.h"
#include "../Credential/CredentialDecoder.h"

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


    void showCredit(
        MifareClassic& card,
        ProfileLoader& profile
    );


private:

    void printHex(
        const std::vector<uint8_t>& data
    );

};
