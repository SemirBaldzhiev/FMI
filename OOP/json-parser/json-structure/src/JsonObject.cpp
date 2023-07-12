#include "../headers/JsonObject.h"
#include "../../JsonParser.h"
#include <iostream>
#include "../../exceptions/CustomJsonExceptions.h"


JsonObject::JsonObject(const JsonObject& other) { 
    copy(other);
}

JsonObject& JsonObject::operator=(const JsonObject& other) {
    if (this != &other) {
        free();
        pairs = std::vector<KVPair*>();
        copy(other);
    }

    return *this;
}

JsonObject::~JsonObject() {
    free();
}

JsonType* JsonObject::clone() const {
    return new JsonObject(*this);
}

void JsonObject::print(std::ostream& output, size_t offset) const {
    output << "{";
    for (size_t i = 0; i < pairs.size(); ++i) {

        output << '\n' << std::string(offset, '\t');
        pairs[i]->print(output, offset + 1);
        if (i == pairs.size() - 1) {
            output << '\n';
        }
        else {
            output << ",";
        }
    }
    output << std::string(offset - 1, '\t') << "}";
}

void JsonObject::free() {
    for (size_t i = 0; i < pairs.size(); ++i) {
        delete pairs[i];
    }
}

void JsonObject::copy(const JsonObject& other) {

    pairs.reserve(other.pairs.size());
    for (size_t i = 0; i < other.pairs.size(); ++i) {
        pairs.push_back(other.pairs[i]->clone());
    }
} 

const std::vector<KVPair*>& JsonObject::getPairs() const {
    return pairs;
}

void JsonObject::addKVPair(const KVPair* pair) {
    pairs.push_back(const_cast<KVPair*>(pair));
}

void JsonObject::search(const std::string& searchKey, std::vector<JsonType*>& result) const {

    for (KVPair*const& pair : pairs) {
        if (pair->getKey() == searchKey) {
            result.push_back(pair->getValue()->clone());
        }

        pair->getValue()->search(searchKey, result);
    }
}

KVPair* JsonObject::getPairByKey(std::string& key) const {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i]->getKey() == key) {
            return pairs[i];
        }
    }

    return nullptr;
}

bool JsonObject::conatainsKey(std::string& key) const {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i]->getKey() == key) {
            return true;
        }
    }

    return false;
}

void JsonObject::create(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) {


    if (pathElemIndex == jsonPathElements.size() - 1) {
        if (!conatainsKey(jsonPathElements[pathElemIndex])) {
            pairs.push_back(new KVPair(jsonPathElements[pathElemIndex], element));
        }
        else {
            throw JsonElementAlreadyExist(jsonPathElements[pathElemIndex]);
        }
    }
    else {
        KVPair* pair = getPairByKey(jsonPathElements[pathElemIndex]);
        if (pair) {
            pair->getValue()->create(jsonPathElements, pathElemIndex + 1, element);
        }
        else {
            throw JsonElementNotFound(jsonPathElements[pathElemIndex]);
        }
    }
}

void JsonObject::deleteElement(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag) {

    if (jsonPathElements.size() - 1 == pathElemIndex) {
        for (size_t i = 0; i < pairs.size(); ++i) {
            if (pairs[i]->getKey() == jsonPathElements[pathElemIndex]) {
                if (delFlag) {
                    std::cout << "dsadsadsadsadhere================\n";
                    delete pairs[i];
                } 
                pairs.erase(pairs.begin() + i);
                break;
            }
        }
    }
    else {
        KVPair* pair = getPairByKey(jsonPathElements[pathElemIndex]);
        if (pair != nullptr) {
            pair->deletePairValue(jsonPathElements, pathElemIndex + 1, delFlag);
        }
        else {
            throw JsonElementNotFound(jsonPathElements[pathElemIndex]);
        }
    }
}


const JsonType* const JsonObject::find(std::vector<std::string> &jsonPathElements, size_t jsonPathIndex) const {
    const KVPair* pair = getPairByKey(jsonPathElements[jsonPathIndex]);

    if (pair != nullptr)
    {
        if (jsonPathElements.size() - 1 == jsonPathIndex)
        {   
            pair->getValue()->print(std::cout, 2);
            return pair->getValue();
        }
        return pair->getValue()->find(jsonPathElements, jsonPathIndex + 1);
    }


    return nullptr;
}


bool JsonObject::contains(const std::string& searchValue) const {

    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i]->getValue()->contains(searchValue)) {
            return true;
        }
    }

    return false;
}

void JsonObject::set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) {
    KVPair* pair = getPairByKey(jsonPathElements[pathElemIndex]);

    if (pair != nullptr) {
        pair->set(jsonPathElements, pathElemIndex, element);
    } 
    else {
        throw JsonElementNotFound(jsonPathElements[pathElemIndex]);
    }
}

JsonObjectCreator::JsonObjectCreator() : JsonTypeCreator("{") {}

JsonType* JsonObjectCreator::createJsonType(std::istream& input) const {
    JsonObject* obj = new JsonObject();
    JsonParser::readObject(input, obj);
    return obj;
}

static JsonObjectCreator __;