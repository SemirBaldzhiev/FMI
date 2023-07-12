#ifndef JSON_APP_H
#define JSON_APP_H

#include "Json.h"
#include <fstream>

class JsonApp {

    public:
        JsonApp()  = default; 
        void run();

    private:
        Json json;
        std::string filePath;
        bool isFileOpened = false;

        JsonType* createTypeFromString(const std::string& jsonElement);

};

#endif