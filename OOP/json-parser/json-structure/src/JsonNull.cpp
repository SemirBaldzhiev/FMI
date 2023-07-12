#include "../headers/JsonNull.h"
#include "../../JsonParser.h"

JsonNull::JsonNull() : nullValue("null") {}

void JsonNull::print(std::ostream& output, size_t offset) const {
    output << nullValue;
}

bool JsonNull::contains(const std::string& searchValue) const {
    return searchValue == "null";
}

JsonType* JsonNull::clone() const {
    return new JsonNull(*this);
}

JsonNullCreator::JsonNullCreator() : JsonTypeCreator("n") {}

JsonType* JsonNullCreator::createJsonType(std::istream& input) const {
    JsonParser::readNull(input);
    return new JsonNull();
}

static JsonNullCreator __;