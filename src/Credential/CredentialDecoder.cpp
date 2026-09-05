#include "CredentialDecoder.h"

#include <cstddef>
#include <cstdint>
#include <sstream>
#include <iomanip>



std::vector<uint8_t>
CredentialDecoder::decode(
    MifareClassic& card,
    CredentialField field
)
{

    auto block =
        card.getBlock(
            field.block
        );


    if(block.empty())
        return {};


    std::vector<uint8_t> result;


    for(
        int i = 0;
        i < field.size;
        i++
    )
    {

        result.push_back(
            block[field.offset+i]
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

    auto block =
        card.getBlock(
            field.block
        );


    if(block.empty())
        return false;


    if(value.size() != field.size)
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



std::string CredentialDecoder::decodeValue(
    std::vector<uint8_t> data,
    CredentialType type
)
{

    std::stringstream ss;


    if(type == CredentialType::Integer)
    {

        int value = 0;


        for(auto b : data)
        {
            value =
                (value << 8) | b;
        }


        ss << value;


        return ss.str();

    }



    if(type == CredentialType::String)
    {

        for(auto b : data)
        {
            ss << (char)b;
        }


        return ss.str();

    }



    for(auto b : data)
    {

        ss
        << std::hex
        << std::setw(2)
        << std::setfill('0')
        << (int)b
        << " ";

    }


    return ss.str();

}



std::vector<uint8_t>
CredentialDecoder::encodeValue(
    std::string value,
    CredentialType type,
    int size
)
{

    std::vector<uint8_t> result;


    if(type == CredentialType::Integer)
    {

        int number =
            std::stoi(value);


        for(
            int i = size-1;
            i >= 0;
            i--
        )
        {

            result.push_back(
                (number >> (i*8)) & 0xff
            );

        }


        return result;

    }



    if(type == CredentialType::String)
    {

        for(char c : value)
        {
            result.push_back(
                (uint8_t)c
            );
        }

    }



    if(type == CredentialType::Hex)
    {

        for(
            size_t i = 0;
            i < value.length();
            i += 2
        )
        {

            result.push_back(
                std::stoi(
                    value.substr(i,2),
                    nullptr,
                    16
                )
            );

        }

    }


    while(result.size() < size)
    {
        result.push_back(0);
    }


    return result;

}
