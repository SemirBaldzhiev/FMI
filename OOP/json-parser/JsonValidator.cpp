#include "JsonValidator.h"
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>

#include "./exceptions/CustomJsonExceptions.h"

void JsonValidator::validateNumber(std::istream& input) {
    double number;
    input >> number;

    if (input.fail()) {
        input.clear();
        throw JsonVailidationException("Invalid number! - ", input.tellg());
    }
}

void JsonValidator::validateBool(std::istream& input) {

    bool booleanValue;
    input >> std::boolalpha >> booleanValue;

    if (input.fail()) {
        input.clear();
        throw JsonVailidationException("Invalid bool type! - ", input.tellg());
    }
}

void JsonValidator::validateNull(std::istream& input) {
    std::string nullValue;
    char c;
    for (int i = 0; i < NULL_VALUE_LEN; ++i) {
        input.get(c);
        nullValue += c;
    }

    if (nullValue != "null") {
        input.clear();
        throw JsonVailidationException("Invalid null! - ", input.tellg());
    }
}

void JsonValidator::validateString(std::istream& input) {

    char c;
    int quotesCnt = 0;
    
    while (input.get(c)) {
        if (c == STR_SYMBOL) {
            ++quotesCnt;
        }

        if (quotesCnt == QUOTES_COUNT || c == '\n') {
            break;
        }
    }
    
    if (quotesCnt != QUOTES_COUNT) {
        throw JsonVailidationException("Invalid string! - ", input.tellg());
    }
}

void JsonValidator::validateObject(std::istream& input) {

    char c;
    input >> c;

    if (c != OBJ_SYMBOL_OPEN) {
        throw JsonVailidationException("Object should start with curly bracket!", input.tellg());
    }

    input >> c;

    // Empty object
    if (c == OBJ_SYMBOL_CLOSE) {
        return;
    }
    else {
        input.unget();
    }

    while (input.good()) {

        validateKey(input);
        input >> c;

        if (c != ':') {
            throw JsonVailidationException("Object key value separator should be colon", input.tellg());
        }   

        validateValue(input);
        input >> c;

        if (c == ',') {
            input >> c;
            if (c != STR_SYMBOL) {
                throw JsonVailidationException("Trailing comma", input.tellg());

            }else {
                input.unget();
            }
        }
        else {
            if (c == OBJ_SYMBOL_CLOSE) {
                break;
            }
            else {
                throw JsonVailidationException("Object should end with curly bracket!", input.tellg());
            }
        }
    }
}

void JsonValidator::validateArray(std::istream& input) {
    char c;
    input >> c;

    if (c != ARR_SYMBOL_OPEN) {
        throw JsonVailidationException("Array should start with [!", input.tellg());

    }

    input >> c;

    // Empty array
    if (c == ARR_SYMBOL_CLOSE) {
        return;
    }
    input.unget();
    while (input.good()) {
        validateValue(input);

        input >> c;
        
        if (c != ',' && c != ARR_SYMBOL_CLOSE) {
            throw JsonVailidationException("Array shuld end with ] and have comma between values", input.tellg());
        }

        if (c == ARR_SYMBOL_CLOSE) {
            break;
        }
    }
}

void JsonValidator::validateValue(std::istream& input) {
    
    char c;
    input >> c;
    input.unget();
    if (c == NUMBER_SIGN || (c >= NUMBER_MIN && c <= NUMBER_MAX)) {
        validateNumber(input);
    }
    else if (c == ARR_SYMBOL_OPEN) {
        validateArray(input);
    }
    else if (c == OBJ_SYMBOL_OPEN) {
        validateObject(input);
    }
    else if (c == NULL_SYMBOL) {
        validateNull(input);
    }
    else if (c == BOOL_SYMBOL_T || c == BOOL_SYMBOL_F) {
        validateBool(input);
    }
    else if (c == STR_SYMBOL) {
        validateString(input);
    }
    else {
        throw JsonVailidationException("There is no such a json type!", input.tellg());
    }
}

void JsonValidator::validateKey(std::istream& input) {
    validateString(input);
}

void JsonValidator::validate(std::istream& input) {
    char c;
    validateValue(input);



    while(input.get(c)) {
        if (!isspace(c)) {
            throw JsonVailidationException("Multiple root elements", input.tellg());
        }
    }
}