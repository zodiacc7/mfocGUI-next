#include "CredentialDecoder.h"



std::vector<uint8_t>
CredentialDecoder::decode(
    MifareClassic& card,
    CredentialField field
)
{

    std::vector<uint8_t> result;


    auto block =
        card.getBlock(
            field.block
        );


    if(block.empty())
        return result;


    int end =
        field.offset + field.size;


    if(end > block.size())
        return result;


    for(
        int i = field.offset;
        i < end;
        i++
    )
    {
        result.push_back(
            block[i]
        );
    }


    return result;

}



bool CredentialDecoder::encode(
    MifareClassic& card,
    CredentialField field,
    std::vector<uint8_t> value
)
{

    if(
        value.size() != field.size
    )
    {
        return false;
    }


    auto block =
        card.getBlock(
            field.block
        );


    if(block.empty())
        return false;


    for(
        int i = 0;
        i < field.size;
        i++
    )
    {

        block[field.offset+i] =
            value[i];

    }


    return card.writeBlock(
        field.block,
        block
    );

}
