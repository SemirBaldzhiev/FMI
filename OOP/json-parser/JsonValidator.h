#ifndef JSON_VALIDATOR_H
#define JSON_VALIDATOR_H

#include <fstream>

#define QUOTES_COUNT   2
#define NULL_VALUE_LEN 4

class JsonValidator {

    public:
        static void validate(std::istream& input);
    private:
        static const char ARR_SYMBOL_OPEN =  '[';
        static const char ARR_SYMBOL_CLOSE = ']';
        static const char BOOL_SYMBOL_T =    't';
        static const char BOOL_SYMBOL_F =    'f';
        static const char OBJ_SYMBOL_OPEN =  '{';
        static const char OBJ_SYMBOL_CLOSE = '}';
        static const char NULL_SYMBOL =      'n';
        static const char NUMBER_MIN =       '0';
        static const char NUMBER_MAX =       '9';
        static const char NUMBER_SIGN =      '-';
        static const char STR_SYMBOL =       '"';
    private:
        static void validateNumber(std::istream& input);
        static void validateBool(std::istream& input);
        static void validateNull(std::istream& input);
        static void validateString(std::istream& input);
        static void validateArray(std::istream& input);
        static void validateObject(std::istream& input);
        static void validateValue(std::istream& input);
        static void validateKey(std::istream& input);
};

#endif