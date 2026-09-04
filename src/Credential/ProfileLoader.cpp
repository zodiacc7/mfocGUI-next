#include "ProfileLoader.h"



bool ProfileLoader::load(
    std::string filename
)
{

    fields =
        JsonParser::loadFields(
            filename
        );


    return !fields.empty();

}



std::vector<CredentialField>
ProfileLoader::getFields()
{

    return fields;

}



std::vector<uint8_t>
ProfileLoader::decodeField(
    MifareClassic& card,
    int index
)
{

    if(
        index < 0 ||
        index >= fields.size()
    )
    {
        return {};
    }


    CredentialDecoder decoder;


    return decoder.decode(
        card,
        fields[index]
    );

}
