#pragma once

#include <string>


enum class CredentialType
{
    Integer,
    String,
    Hex
};



struct CredentialField
{

    std::string name;

    int sector;

    int block;

    int offset;

    int size;

    CredentialType type;

};
