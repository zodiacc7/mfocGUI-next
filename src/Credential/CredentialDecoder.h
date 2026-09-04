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


};
