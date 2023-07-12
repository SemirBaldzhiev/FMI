#include "JsonParser.h"
#include "JsonFactory.h"
#include "./json-structure/headers/KVPair.h"
#include <iostream>
#include <cstring>

double JsonParser::readNumber(std::istream& input) {
    double numberValue;
    input >> numberValue;
    return numberValue;
}

std::string JsonParser::readString(std::istream& input) {
    
    unsigned quotesCount = 0;
    std::string stringValue;
    removeWhiteSpaces(input);
    char c;
    while(input.get(c)) {
        if (c == '\"') {
            ++quotesCount;
        }
        else {
            // if (!isspace(c))
            stringValue += c;
        }

        if (quotesCount == 2) {
            break;
        }
    }

    return stringValue;
}

void JsonParser::removeWhiteSpaces(std::istream& input) {
    char c;
    input.get(c);
    while (isspace(c)) {
        input.get(c);
    }

    input.unget();
}

bool JsonParser::readBool(std::istream& input) {
    bool boolValue;
    input >> std::boolalpha >> boolValue;
    return boolValue;
}

void JsonParser::readArray(std::istream& input, JsonArray* arrayToReturn) {

    char c;
    input >> c;
    input >> c;

    if (c == ']') {
        return;
    }

    input.unget();

    while (input.good()) {
        JsonType* arrayValue = JsonFactory::getFactory().createJsonType(input);
        arrayToReturn->addValue(arrayValue);
        input >> c;
        if (c == ']') {
            // input.unget();
            break;
        }
    }
}

void JsonParser::readNull(std::istream& input) {
    char c;
    for (int i = 0; i < 4; ++i){
        input.get(c);
    }
}

void JsonParser::readObject(std::istream& input, JsonObject* objectToReturn) {
    char c;
    bool foundDuplictate = false;
    input >> c;
    input >> c;

    if (c == '}') {
        return;
    } 

    input.unget();

    while (input.good()) {
        KVPair* createPair = KVPairCreator::createKVPair(input); 

        for (KVPair* pair : objectToReturn->getPairs()) {
            if (pair->getKey() == createPair->getKey()) {
                std::cout << "Duplicate keys found! - key: " << pair->getKey() << " Please correct your json file!\n";
                delete createPair;
                foundDuplictate = true;
            }
        }

        if (!foundDuplictate) {
            objectToReturn->addKVPair(createPair);
        }

        input >> c;

        if (c == '}') {
            // input.unget();
            break;
        }
    }
}

std::string JsonParser::readKey(std::istream& input) {
    return readString(input);
}


std::vector<std::string> JsonParser::split(const std::string& str, const char* delimiters)
{
    std::vector<std::string> tokens;
    std::string word = "";
    for (char c : str)
    {
        if (strchr(delimiters, c) != nullptr)
        {
            if (word == "") {
                continue;
            }
            tokens.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    if (!word.empty())
        tokens.push_back(word);

    return tokens;
}