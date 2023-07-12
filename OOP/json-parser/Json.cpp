#include "Json.h"
#include "JsonFactory.h"
#include <iostream>
#include "./exceptions/CustomJsonExceptions.h"

Json::Json() : root(nullptr) {}

Json::Json(const Json& other) {
    copy(other);
}
Json& Json::operator=(const Json& other) {
    if (this != &other) {
        free();
        copy(other);
    }

    return *this;
}

Json::~Json() {
    free();
}

void Json::parse(std::istream& input) {
    root = JsonFactory::getFactory().createJsonType(input);
}

void Json::print(std::ostream& stream) const {
    root->print(stream, 1);
}

JsonArray Json::search(const std::string& searchKey) const {
    JsonArray searchResult;
    root->search(searchKey, searchResult.getValues());
    if (searchResult.getValues().size() == 0) {
        throw JsonElementNotFound(searchKey);
    }

    return searchResult;
}

void Json::create(std::vector<std::string>& jsonPathElements, JsonType* element) {
    root->create(jsonPathElements, 0, element);
}

void Json::deleteElement(std::vector<std::string>& jsonPathElements) {
    root->deleteElement(jsonPathElements, 0, true);
}

void Json::set(std::vector<std::string>& jsonPathElements, JsonType* element) {
    root->set(jsonPathElements, 0, element);
}

void Json::move(std::vector<std::string>& jsonPathFrom, std::vector<std::string>& jsonPathTo) {
    
    JsonType* elementFrom = const_cast<JsonType*>(root->find(jsonPathFrom, 0));
    JsonType* elementTo = const_cast<JsonType*>(root->find(jsonPathTo, 0));
 
    if (elementFrom == nullptr)
    {
        throw JsonElementNotFound(jsonPathFrom.back());
    }

    if (elementTo) {
        root->set(jsonPathTo, 0, elementFrom);
        root->deleteElement(jsonPathFrom, 0, false);  
    }
    else {
        root->create(jsonPathTo, 0, elementFrom);
        root->deleteElement(jsonPathFrom, 0, false);
    }
}

bool Json::contains(std::string& value) {
    return root->contains(value);
}

const JsonType* const Json::find(std::vector<std::string>& jsonPath) const {
    return root->find(jsonPath, 0);
}


void Json::copy(const Json& other) {
    root = other.root->clone();
}

void Json::free() {
    delete root;
}