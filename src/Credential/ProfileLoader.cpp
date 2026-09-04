#include "ProfileLoader.h"
#include "JsonParser.h"


bool ProfileLoader::load(std::string filename)
{

    fields =
        JsonParser::loadFields(filename);


    return !fields.empty();
}
