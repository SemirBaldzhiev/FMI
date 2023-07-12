#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "JsonType.h"

#include <vector>
#include <iostream>

class JsonArray : public JsonType {
    public:
        JsonArray() = default;
        JsonArray(const JsonArray& other);
        JsonArray& operator=(const JsonArray& other);
        ~JsonArray() override;

        void print(std::ostream& output, size_t offset) const override;
        void search(const std::string& searchKey, std::vector<JsonType*>& result) const override; 
        void deleteElement(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag) override;
        void set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) override;
        void create(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) override;
        bool contains(const std::string& searchValue) const override;
        const JsonType* const find(std::vector<std::string>& jsonPathElements, size_t pathElemIndex) const override;

        JsonType* clone() const override;
        void addValue(const JsonType* value);
        std::vector<JsonType*>& getValues();
    private:
        std::vector<JsonType*> values;

        void free();
        void copy(const JsonArray& other);
};

class JsonArrayCreator : public JsonTypeCreator {
    public:
        JsonArrayCreator();
        JsonType* createJsonType(std::istream& input) const override; 
};

#endif