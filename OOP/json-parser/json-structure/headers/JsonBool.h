#ifndef JSON_BOOL_H
#define JSON_BOOL_H

#include "JsonType.h"

class JsonBool : public JsonType {
    public:
        JsonBool(bool boolValue);

        void print(std::ostream& output, size_t offset = 0) const override;
        bool contains(const std::string& searchValue) const override; 
        JsonType* clone() const override;

    private:
        bool boolValue;

        const std::string boolToStr(bool value) const;
};

class JsonBoolCreator : public JsonTypeCreator {
    public:
        JsonBoolCreator();
        JsonType* createJsonType(std::istream& input) const override;
};

#endif