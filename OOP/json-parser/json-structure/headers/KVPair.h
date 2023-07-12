#ifndef PAIR_H
#define PAIR_H

#include <string>
#include "JsonType.h"

class KVPair {

    public:
        KVPair(const std::string& key, JsonType* value);
        KVPair(const KVPair& other);
        KVPair& operator=(const KVPair& other);
        ~KVPair();

        void setKey(const std::string& key);
        void setValue(JsonType* value);

        const std::string& getKey() const;
        const JsonType* const  getValue() const;
        JsonType* getValue();

        KVPair* clone() const;

        void print(std::ostream& output, size_t offset) const;
        void deletePairValue(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, bool delFlag);
        void set(std::vector<std::string>& jsonPathElements, size_t pathElemIndex, JsonType* element);

    private:
        std::string key;
        JsonType* value;

        void free();
        void copy(const KVPair& other);
};


class KVPairCreator {
    public:
        static KVPair* createKVPair(std::istream& input); 
};


#endif