#pragma once

#include "CredentialField.h"
#include "../Dump/MifareClassic.h"

#include <vector>
#include <cstdint>
#include <string>



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


    std::string decodeValue(
        std::vector<uint8_t> data,
        CredentialType type
    );


    std::vector<uint8_t> encodeValue(
        std::string value,
        CredentialType type,
        int size
    );

};
