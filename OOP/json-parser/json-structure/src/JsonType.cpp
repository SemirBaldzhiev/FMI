#include "../headers/JsonType.h"
#include "../../JsonFactory.h"
#include <vector>
#include <iostream>

void JsonType::search(const std::string& searchKey, std::vector<JsonType*>& result) const { }

void JsonType::deleteElement(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag) { 
}

void JsonType::set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) {
}

void JsonType::create(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) {
}

const JsonType* const JsonType::find(std::vector<std::string> &jsonPathElements, size_t jsonPathIndex) const {
    return nullptr;
}

JsonTypeCreator::JsonTypeCreator(const char* typeCmd) : typeCmd(typeCmd) {
    JsonFactory::getFactory().registerJsonType(this);
}

const char* JsonTypeCreator::getTypeCommand() const {
    return typeCmd;
}
