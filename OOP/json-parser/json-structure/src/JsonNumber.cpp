#include "../headers/JsonNumber.h"
#include "../../JsonParser.h"
#include <iostream>

JsonNumber::JsonNumber(double number) : numberValue(number) {}

void JsonNumber::print(std::ostream& output, size_t offset) const {
    output << numberValue;
}

bool JsonNumber::isNumber(const std::string& str) const {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        ++it;
    }

    return it == str.end() && !str.empty();
}

bool JsonNumber::contains(const std::string& searchValue) const {
    
    if (isNumber(searchValue)) {
        double num = stoll(searchValue);

        if (num == numberValue) {
            return true;
        }
    }

    return false;
}

JsonType* JsonNumber::clone() const {
    return new JsonNumber(*this);
}

JsonNumberCreator::JsonNumberCreator() : JsonTypeCreator("-0123456789") {}

JsonType* JsonNumberCreator::createJsonType(std::istream& input) const {
    return new JsonNumber(JsonParser::readNumber(input));
}

static JsonNumberCreator __;