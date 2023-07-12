#include "../headers/KVPair.h"
#include "../../JsonParser.h"
#include "../../JsonFactory.h"
#include <iostream>

KVPair::KVPair(const std::string& key, JsonType* value) {
    setKey(key);
    setValue(value);
}

KVPair::KVPair(const KVPair& other) {
    copy(other);
}

KVPair& KVPair::operator=(const KVPair& other) {
    if (this != &other) {
        free();
        copy(other);
    }

    return *this;
}   

KVPair::~KVPair() {
    free();
}

void KVPair::setKey(const std::string& key){
    this->key = key;
}

void KVPair::setValue(JsonType* value){
    this->value = value;
}

const std::string& KVPair::getKey() const {
    return key;
}

const JsonType* const KVPair::getValue() const {
    return value;
}

JsonType* KVPair::getValue() {
    return value;
}

KVPair* KVPair::clone() const {
    return new KVPair(*this);
}

void KVPair::print(std::ostream& output, size_t offset) const {
    output << "\"" << key << "\"" << ": ";
    value->print(output, offset);
}


void KVPair::deletePairValue(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag) {
    value->deleteElement(jsonPathElements, pathElemIndex, delFlag);
}

void KVPair::set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) {
    
    if (jsonPathElements.size() - 1 == pathElemIndex) {
        delete value;
        value = element;
    }
    else {
        value->set(jsonPathElements, pathElemIndex + 1, element);
    }
}

void KVPair::free() {
    delete value;
}

void KVPair::copy(const KVPair& other){
    key = other.key;
    value = other.value->clone();
}


KVPair* KVPairCreator::createKVPair(std::istream& input) {
    std::string key = JsonParser::readKey(input);
    input.get();
    JsonType* value = JsonFactory::getFactory().createJsonType(input);
    return new KVPair(key, value);
}