#include "../headers/JsonString.h"
#include "../../JsonParser.h"

JsonString::JsonString(const std::string& str) : strValue(str) {}

void JsonString::print(std::ostream& output, size_t offset) const {
    output << "\"" << strValue << "\"";
}

bool JsonString::contains(const std::string& searchValue) const {

    if (strValue.find(searchValue) != std::string::npos) {
        return true;
    }

    return false;
}

JsonType* JsonString::clone() const { 
    return new JsonString(*this);
}

JsonStringCreator::JsonStringCreator() : JsonTypeCreator("\"") {}

JsonType* JsonStringCreator::createJsonType(std::istream& input) const {
    return new JsonString(JsonParser::readString(input));
}

static JsonStringCreator __;