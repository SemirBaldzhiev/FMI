#include "../headers/JsonArray.h"
#include "../../JsonParser.h"
#include <iostream>

JsonArray::JsonArray(const JsonArray& other) {
    copy(other);
}

JsonArray& JsonArray::operator=(const JsonArray& other) {
    if (this != &other) {
        free();
        this->values = std::vector<JsonType*>();
        copy(other);
    }

    return *this;
}

std::vector<JsonType*>& JsonArray::getValues() {
    return values;
}

bool JsonArray::contains(const std::string& searchValue) const {
    
    for (size_t i = 0; i < values.size(); ++i) {
        if(values[i]->contains(searchValue)) {
            return true;
        }
    }

    return false;
}

void JsonArray::print(std::ostream& output, size_t offset) const {

    output << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        output << '\n' << std::string(offset, '\t');
        values[i]->print(output, offset + 1);
        if (i == values.size() - 1) {
            output << '\n';
        }
        else {
            output << ",";
        }
    }
    output << std::string(offset - 1, '\t') << "]";
}

void JsonArray::deleteElement(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag) {
    
    size_t indexToDelete = stoll(jsonPathElements[pathElemIndex]);
    
    if ((indexToDelete >= 0 && indexToDelete < jsonPathElements.size()) 
        && pathElemIndex == jsonPathElements.size() - 1) {
        if (delFlag) {
            delete values[indexToDelete];
        }
        values.erase(values.begin() + indexToDelete);
    }
    else if (indexToDelete >= 0 && indexToDelete < jsonPathElements.size()) {
        values[indexToDelete]->deleteElement(jsonPathElements, pathElemIndex + 1, delFlag);
    }
    else {
        // throw exception;
    }
}

const JsonType* const JsonArray::find(std::vector<std::string>& jsonPathElements, size_t pathElemIndex) const {
    size_t findIndex = std::stoll(jsonPathElements[pathElemIndex]);

    if (findIndex >= 0 
        && findIndex < values.size() 
        && jsonPathElements.size() - 1 == pathElemIndex)
    {
        return values[findIndex];
    }
    else if (findIndex >= 0 
            && findIndex < values.size()
            && jsonPathElements.size() - 1 != pathElemIndex)
    {
        return values[findIndex]->find(jsonPathElements, pathElemIndex + 1);
    }

    std::cout << "nullptr032193921381239=======================================---------------\n";

    return nullptr;
}


void JsonArray::set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) {
    size_t setIndex = stoll(jsonPathElements[pathElemIndex]);

    if (setIndex >= 0 && setIndex < values.size() - 1 && jsonPathElements.size() - 1 == pathElemIndex) {
        delete values[setIndex];
        values[setIndex] = element;
    }
    else if (setIndex >= 0 && setIndex < values.size() - 1){
        values[setIndex]->set(jsonPathElements, pathElemIndex + 1, element);
    }
    else {
        //throw exception
    }
}

void JsonArray::search(const std::string& searchKey, std::vector<JsonType*>& result) const {
    for (size_t i = 0; i < values.size(); ++i) {
        values[i]->search(searchKey, result);
    }
}

void JsonArray::create(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) {

    size_t createIndex = stoll(jsonPathElements[pathElemIndex]);

    if (createIndex == values.size() && jsonPathElements.size() - 1 == pathElemIndex) {
        values.push_back(element);
    }
    else if (createIndex >= 0 && createIndex < values.size()) {
        values[createIndex]->create(jsonPathElements, pathElemIndex + 1, element);
    }
    else {
        // throw exception
    }
}


JsonType* JsonArray::clone() const {
    return new JsonArray(*this);
}

void JsonArray::copy(const JsonArray& other) {

    values.reserve(other.values.size());
    for (size_t i = 0; i < other.values.size(); ++i) {
        values.push_back(other.values[i]->clone());
    }
}

void JsonArray::free() {
    for (size_t i = 0; i < values.size(); ++i) {
        delete values[i];
    }
}


void JsonArray::addValue(const JsonType* value) {
    values.push_back(const_cast<JsonType*>(value));
}

JsonArray::~JsonArray() {
    free();
}

JsonArrayCreator::JsonArrayCreator() : JsonTypeCreator("[") {}

JsonType* JsonArrayCreator::createJsonType(std::istream& input) const {
    JsonArray* arr = new JsonArray();
    JsonParser::readArray(input, arr);
    return arr;
}

static JsonArrayCreator __;


