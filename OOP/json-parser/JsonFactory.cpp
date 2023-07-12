#include "JsonFactory.h"
#include <string.h>
#include <iostream>

JsonFactory::JsonFactory() : countCreators(0) {}
JsonFactory::~JsonFactory() {}

const JsonTypeCreator* JsonFactory::getCreator(char symbol) const {

    for (int i = 0; i < countCreators; ++i) {
        if (strchr(creators[i]->getTypeCommand(), symbol) != nullptr) {
            return creators[i];
        }
    }

    return nullptr;
}

JsonType* JsonFactory::createJsonType(std::istream& input) {
    char symbol;
    input >> symbol;
    input.unget();
    const JsonTypeCreator* creator = getCreator(symbol);
    

    if (creator) {
        return creator->createJsonType(input);
    }

    return nullptr;
}

JsonFactory& JsonFactory::getFactory() {
    static JsonFactory factory;
    return factory;
}

void JsonFactory::registerJsonType(const JsonTypeCreator* creator) {
    creators[countCreators] = creator;
    countCreators++;
}