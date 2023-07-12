#ifndef JSON_H
#define JSON_H

#include <string>
#include <fstream>
#include "./json-structure/headers/JsonType.h"
#include "./json-structure/headers/JsonArray.h"
#include <iostream>
class Json {

    public:
        Json();
        Json(const Json& other);
        Json& operator=(const Json& other);
        ~Json();

        void parse(std::istream& input);
        void print(std::ostream& stream) const;
        JsonArray search(const std::string& searchKey) const;
        void create(std::vector<std::string>& jsonPathElements, JsonType* element);
        void deleteElement(std::vector<std::string>& jsonPathElements);
        void set(std::vector<std::string>& jsonPathElements, JsonType* element);
        void move(std::vector<std::string>& jsonPathFrom, std::vector<std::string>& jsonPathTo);
        bool contains(std::string& value);
        const JsonType* const find(std::vector<std::string>& jsonPath) const;  

    private:
        JsonType* root;

        void copy(const Json& other);
        void free();
};


#endif