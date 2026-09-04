#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "CredentialField.h"
#include <vector>
#include <string>


class JsonParser
{

public:

    static std::vector<CredentialField>
    loadFields(std::string filename);

};

#endif
