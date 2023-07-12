#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "JsonType.h"
#include "KVPair.h"
#include <vector>

class JsonObject : public JsonType {
    
    public:
        JsonObject() = default;
        JsonObject(const JsonObject& other);
        JsonObject& operator=(const JsonObject& other);
        ~JsonObject() override;

        JsonType* clone() const override;
        const std::vector<KVPair*>& getPairs() const;
        void addKVPair(const KVPair* pair);  
        KVPair* getPairByKey(std::string& key) const;

        void print(std::ostream& output, size_t offset) const override;
        void search(const std::string& searchKey, std::vector<JsonType*>& result) const override; 
        void deleteElement(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag) override;
        void set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) override;
        void create(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element) override;
        bool contains(const std::string& searchValue) const override;
        const JsonType* const find(std::vector<std::string> &jsonPathElements, size_t jsonPathIndex) const override;

    private:
        std::vector<KVPair*> pairs;

        void free();
        void copy(const JsonObject& other);

        bool conatainsKey(std::string& key) const;

};

class JsonObjectCreator : public JsonTypeCreator {
    public:
        JsonObjectCreator();
        JsonType* createJsonType(std::istream& input) const override;
};


#endif