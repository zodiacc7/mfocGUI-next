#ifndef PROFILELOADER_H
#define PROFILELOADER_H

#include "CredentialField.h"
#include <vector>
#include <string>


class ProfileLoader
{

public:

    bool load(std::string filename);

    std::vector<CredentialField> fields;

};

#endif
