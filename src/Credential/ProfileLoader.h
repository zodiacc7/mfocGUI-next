#pragma once

#include "CredentialField.h"
#include "JsonParser.h"
#include "CredentialDecoder.h"

#include "../Dump/MifareClassic.h"

#include <vector>
#include <string>
#include <cstdint>


class ProfileLoader
{

private:

    std::vector<CredentialField> fields;


public:

    bool load(
        std::string filename
    );


    std::vector<CredentialField> getFields();


    std::vector<uint8_t> decodeField(
        MifareClassic& card,
        int index
    );


    bool updateField(
        MifareClassic& card,
        int index,
        std::string value
    );

};
