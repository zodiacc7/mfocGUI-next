#include "JsonParser.h"
#include "../../external/json/json.hpp"

#include <fstream>


using json = nlohmann::json;



std::vector<CredentialField>
JsonParser::loadFields(std::string filename)
{

    std::vector<CredentialField> fields;


    std::ifstream file(
        filename
    );


    if(!file)
        return fields;


    json j;

    file >> j;



    for(auto& item : j["fields"])
    {

        CredentialField field;


        field.name =
            item["name"];


        field.sector =
            item["sector"];


        field.block =
            item["block"];


        field.offset =
            item["offset"];


        field.size =
            item["size"];



        std::string type =
            item["type"];



        if(type == "uint32")
        {
            field.type =
                CredentialType::Integer;
        }
        else if(type == "inverse")
        {
            field.type =
                CredentialType::Hex;
        }
        else
        {
            field.type =
                CredentialType::Hex;
        }



        fields.push_back(
            field
        );

    }


    return fields;

}
