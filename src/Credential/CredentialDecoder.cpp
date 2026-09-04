#include "CredentialDecoder.h"
#include <sstream>
#include <iomanip>


void CredentialDecoder::addField(CredentialField field)
{
    fields.push_back(field);
}



std::string CredentialDecoder::decode(
    std::vector<unsigned char>& dump,
    CredentialField field
)
{

    int blockOffset =
        (field.sector * 4 + field.block) * 16;


    int pos =
        blockOffset + field.offset;


    unsigned int value = 0;


    for(int i=0;i<field.size;i++)
    {
        value |= 
        dump[pos+i] << (8*i);
    }


    std::stringstream ss;

    ss << value;


    return ss.str();
}
