#ifndef CUSTOM_JSON_EXCEPTIONS_H
#define CUSTOM_JSON_EXCEPTIONS_H

#include <exception>
#include <string>

class JsonElementNotFound : public std::exception {

    public:
        JsonElementNotFound(const std::string& exceptionMsg) {
            notFoundMsg += exceptionMsg;
        }

        const char * what() const noexcept override
        {
            return notFoundMsg.c_str();
        }

    private:
        std::string notFoundMsg = "Json element not found - ";
};

class JsonElementAlreadyExist : public std::exception {
    public:
        JsonElementAlreadyExist(const std::string& exceptionMsg) {
            existMsg += exceptionMsg;
        }

        const char * what() const noexcept override
        {
            return existMsg.c_str();
        }
    private:
        std::string existMsg = "Json element already exist - ";
};

class JsonVailidationException : public std::exception {
    public:
        JsonVailidationException(const std::string& exceptionMsg, long long int errorPosition) {
            validationMsg += exceptionMsg;
            validationMsg += " Error at position - ";
            validationMsg += std::to_string(errorPosition);
        }

        const char * what() const noexcept override
        {
            return validationMsg.c_str();
        }

    private:
        std::string validationMsg = "Invalid json type! ";
};

#endif