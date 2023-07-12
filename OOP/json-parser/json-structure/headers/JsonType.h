#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include <fstream>
#include <vector>

class JsonType {

    public:
        virtual ~JsonType() = default;

        virtual void print(std::ostream& output, size_t offset) const = 0;
        virtual void search(const std::string& searchKey, std::vector<JsonType*>& result) const;
        virtual void deleteElement(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag);
        virtual void set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element);
        virtual void create(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element);
        virtual bool contains(const std::string& searchValue) const = 0;
        virtual const JsonType* const find(std::vector<std::string> &jsonPathElements, size_t jsonPathIndex) const;
        virtual JsonType* clone() const = 0;
};


class JsonTypeCreator {
    public:
        JsonTypeCreator(const char* typeCmd);
        virtual ~JsonTypeCreator() = default;

        const char* getTypeCommand() const;

        virtual JsonType* createJsonType(std::istream& input) const = 0;

    protected:
        JsonTypeCreator(const JsonTypeCreator& other) = delete;
        JsonTypeCreator& operator=(const JsonTypeCreator& other) = delete;

        const char* const typeCmd;
};

#endif