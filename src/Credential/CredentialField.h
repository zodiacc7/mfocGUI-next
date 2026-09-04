#ifndef CREDENTIALFIELD_H
#define CREDENTIALFIELD_H

#include <string>

struct CredentialField
{
    std::string name;

    int sector;
    int block;

    int offset;
    int size;

    std::string type;
};

#endif
