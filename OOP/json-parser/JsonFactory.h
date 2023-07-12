#ifndef JSON_FACTORY_H
#define JSON_FACTORY_H

#include "./json-structure/headers/JsonType.h"

class JsonFactory {
    public:
        static JsonFactory& getFactory();
        void registerJsonType(const JsonTypeCreator* creator);
        JsonType* createJsonType(std::istream& input);

    private:
        JsonFactory();
        ~JsonFactory();
        JsonFactory(const JsonFactory& other) = delete;
        JsonFactory& operator=(const JsonFactory& other) = delete;
        
        const JsonTypeCreator* getCreator(char symbol) const;
    private:
        const JsonTypeCreator* creators[10];
        int countCreators;
};

#endif