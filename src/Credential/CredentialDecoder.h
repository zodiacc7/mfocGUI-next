#ifndef CREDENTIALDECODER_H
#define CREDENTIALDECODER_H

#include "CredentialField.h"
#include <vector>
#include <string>


class CredentialDecoder
{

public:

    void addField(CredentialField field);


    std::string decode(
        std::vector<unsigned char>& dump,
        CredentialField field
    );


private:

    std::vector<CredentialField> fields;

};

#endif
