#include "../headers/JsonBool.h"
#include "../../JsonParser.h"

JsonBool::JsonBool(bool boolValue) : boolValue(boolValue) {}

void JsonBool::print(std::ostream& output, size_t offset) const {
    output << std::boolalpha << boolValue;
}

bool JsonBool::contains(const std::string& searchValue) const {
    if (boolToStr(boolValue) == searchValue) {
        return true;
    }

    return false;
}

const std::string JsonBool::boolToStr(bool value) const {
    return boolValue ? "true" : "false"; 
}

JsonType* JsonBool::clone() const {
    return new JsonBool(*this);
}

JsonBoolCreator::JsonBoolCreator() : JsonTypeCreator("tf") {}

JsonType* JsonBoolCreator::createJsonType(std::istream& input) const {
    return new JsonBool(JsonParser::readBool(input));
}


static JsonBoolCreator __;
