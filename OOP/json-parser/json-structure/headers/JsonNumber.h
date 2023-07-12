#ifndef JSON_NUMBER_H
#define JSON_NUMBER_H

#include "JsonType.h"

class JsonNumber : public JsonType {
    public:
        JsonNumber(double number);

        void print(std::ostream& output, size_t offset) const override;
        bool contains(const std::string& searchValue) const override;

        bool isNumber(const std::string& str) const;
        JsonType* clone() const override;

    private:
        double numberValue;
};

class JsonNumberCreator : public JsonTypeCreator {
    public:
        JsonNumberCreator();
        JsonType* createJsonType(std::istream& input) const override;
};

#endif