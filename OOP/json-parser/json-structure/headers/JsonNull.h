#ifndef JSON_NULL_H
#define JSON_NULL_H

#include "JsonType.h"

class JsonNull : public JsonType {
    public:
        JsonNull();

        void print(std::ostream& output, size_t offset) const override;
        bool contains(const std::string& searchValue) const override;
        JsonType* clone() const override;

    private:
        const std::string nullValue;
};

class JsonNullCreator : public JsonTypeCreator {
    public:
        JsonNullCreator();
        JsonType* createJsonType(std::istream& input) const override;
};

#endif