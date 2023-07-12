#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <fstream>
#include "./json-structure/headers/JsonArray.h"
#include "./json-structure/headers/JsonObject.h"

class JsonParser {
    public:
        static double readNumber(std::istream& input);
        static std::string readString(std::istream& input);
        static bool readBool(std::istream& input);
        static void readArray(std::istream& input, JsonArray* arrayToReturn);
        static void readObject(std::istream& input, JsonObject* objectToReturn);
        static std::string readKey(std::istream& input);
        static void readNull(std::istream& input);
        static std::vector<std::string> split(const std::string& str, const char* delimiters);
    private:
        static void removeWhiteSpaces(std::istream& input);
};

#endif