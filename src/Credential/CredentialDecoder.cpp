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
    {
        return result;
    }


    int start =
        field.offset;


    int end =
        start + field.size;


    if(end > block.size())
    {
        return result;
    }


    for(
        int i = start;
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
