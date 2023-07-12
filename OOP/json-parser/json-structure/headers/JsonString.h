#ifndef JSON_STRING_H
#define JSON_STRING_H

#include "JsonType.h"

class JsonString : public JsonType {
    public:
        JsonString(const std::string& str);

        void print(std::ostream& output, size_t offset) const override;
        bool contains(const std::string& searchValue) const override;
        JsonType* clone() const override;

    private:
        std::string strValue;
};

class JsonStringCreator : public JsonTypeCreator {
    public:
        JsonStringCreator();
        JsonType* createJsonType(std::istream& input) const override;
};


#endif