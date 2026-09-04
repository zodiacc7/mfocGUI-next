#pragma once

#include "CredentialField.h"
#include "../Dump/MifareClassic.h"

#include <vector>
#include <cstdint>


class CredentialDecoder
{

public:

    std::vector<uint8_t> decode(
        MifareClassic& card,
        CredentialField field
    );


    bool encode(
        MifareClassic& card,
        CredentialField field,
        std::vector<uint8_t> value
    );

};
