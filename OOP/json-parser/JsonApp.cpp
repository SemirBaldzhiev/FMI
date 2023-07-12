#include "JsonApp.h"
#include <string>

#include <iostream>
#include "JsonValidator.h"
#include "./exceptions/CustomJsonExceptions.h"

#include "JsonParser.h"
#include "JsonFactory.h"
#include <exception>


void JsonApp::run() {

    std::string line;

    while (true) {
        std::cout << "> ";

        getline(std::cin, line);

        if (line.empty()) {
            continue;
        }

        std::vector<std::string> commands = JsonParser::split(line, " ");

        if (commands[0] == "exit") {
            break;
        }


        if (commands[0] == "open") {
            if (commands.size() > 2) {
                std::cout << "Invalid command fromat!\n";
                continue;
            }
            filePath = commands[1];
            std::ifstream ifs(filePath);
        
            if (!ifs.is_open()) {
                std::cout << "Cannot open file " << filePath << " for reading!\n";
                continue;
            }
            try {
                JsonValidator::validate(ifs);
                ifs.clear();
                ifs.seekg(0);
                json.parse(ifs);
                ifs.close();
            }
            catch (...) {
                ifs.close();
                throw;
            }
            isFileOpened = true;
            std::cout << "Successfuly opened " << commands[1] << "\n";
            
            continue;
        }

        if(isFileOpened) {

            if (commands[0] == "validate") {
                if (commands.size() != 1) {
                    std::cout << "Invalid command fromat!\n";
                    continue;
                }

                std::ifstream ifs(filePath);
                if (!ifs.is_open()) {
                    std::cout << "Cannot open file for validation!\n";
                    continue;
                }

                try{
                    JsonValidator::validate(ifs);
                    std::cout << "Valid!\n";
                    ifs.close();
                }
                catch (JsonVailidationException& e) {
                    ifs.close();
                    std::cout << e.what() << "\n";
                }
            }
            else if (commands[0] == "print") {
                json.print(std::cout);
                std::cout << "\n";
            }
            else if (commands[0] == "search") {
                
                if (commands.size() > 2) {
                    std::cout << "Invalid command fromat!\n";
                    continue;
                }
                try {
                json.search(commands[1]).print(std::cout, 1);
                std::cout << "\n";

                }
                catch(std::exception& e) {
                    std::cout << e.what() << '\n';
                }
            }
            else if (commands[0] == "contains") {
                if (commands.size() > 2) {
                    std::cout << "Invalid command fromat!\n";
                    continue;
                }
                std::cout << std::boolalpha << json.contains(commands[1]);
                std::cout << "\n";
            }
            else if (commands[0] == "set") {

                if (commands.size() > 3) {
                    for (size_t i = 3; i < commands.size(); ++i) {
                        commands[2] += commands[i];
                    }
                }

                std::vector<std::string> jsonPath = JsonParser::split(commands[1], ".[]");
                try{
                    JsonType* type = createTypeFromString(commands[2]);

                    json.set(jsonPath, type);

                }
                catch (std::exception& e) {
                    std::cout << e.what() <<'\n';
                }
            }
            else if (commands[0] == "create") {
                if (commands.size() > 3) {
                    for (size_t i = 3; i < commands.size(); ++i) {
                        commands[2] += commands[i];
                    }
                }

                std::vector<std::string> jsonPath = JsonParser::split(commands[1], ".[]");
                try{

                json.create(jsonPath, createTypeFromString(commands[2]));
                }
                catch(std::exception& e) {
                    std::cout <<e.what()<< '\n';
                }
            }
            else if (commands[0] == "delete") {
                if (commands.size() > 2) {
                    std::cout << "Invalid command fromat!\n";
                    continue;
                }

                std::vector<std::string> jsonPath = JsonParser::split(commands[1], ".[]");
                try {
                json.deleteElement(jsonPath);

                }
                catch(std::exception& e) {
                    std::cout << e.what();
                }
            }
            else if (commands[0] == "move") {
                if (commands.size() != 3) {
                    std::cout << "Invalid command fromat!\n";
                    continue;
                }

                std::vector<std::string> jsonPathFrom = JsonParser::split(commands[1], ".[]");
                std::vector<std::string> jsonPathTo = JsonParser::split(commands[2], ".[]");

                for (std::string& s : jsonPathFrom) {
                    std::cout << s << "\n";
                }

                for (std::string& s : jsonPathTo) {
                    std::cout << s << "\n";
                }
                json.move(jsonPathFrom, jsonPathTo);
            }
            else if (commands[0] == "save") {
                
                std::ofstream ofs(filePath);

                if (!ofs.is_open()) {
                    std::cout << "Cannot open file for saving!\n";
                    continue;
                }

                if (commands.size() == 1) {
                    json.print(ofs);
                    ofs.close();
                }
                else if (commands.size() == 2) {
                    std::vector<std::string> jsonPath = JsonParser::split(commands[1], ".[]");
                    json.find(jsonPath)->print(ofs, 1);
                    ofs.close();
                }
                else {
                    std::cout << "Invalid command fromat!\n";
                    continue;
                }
            }
            else if (commands[0] == "saveas") {
                std::ofstream newFile(commands[1]);

                if (!newFile.is_open()) {
                    std::cout << "Cannot open file for saving!\n";
                    continue;
                }
                
                if (commands.size() == 2) {
                    json.print(newFile);
                }
                else if (commands.size() == 3) {
                    std::vector<std::string> jsonPath = JsonParser::split(commands[2], ".[]");

                    const JsonType* const  elemToSave = json.find(jsonPath);
                    if (elemToSave){
                        elemToSave->print(newFile, 1);
                    }
                    else {
                        throw JsonElementNotFound(jsonPath.back());
                    }
                }
            }
            else {
                std::cout << "Unsuported command!\n";
            }
        }
        else {
            std::cout << "First open file!\n";
        }
    }
}

JsonType* JsonApp::createTypeFromString(const std::string& jsonElement) {
    std::fstream stream;

    stream.open("dummy.json", std::ios::in | std::ios::out | std::ios::trunc);

    if (!stream.is_open()) {
        std::cout << "Cannot open file!\n";
        return nullptr;
    }

    stream << jsonElement << std::flush;
    stream.clear();
    stream.seekg(0);


    try{
    JsonValidator::validate(stream);

    }
    catch(JsonVailidationException& e){
        stream.close();
        throw;
    }

    try{
        stream.clear();
        stream.seekg(0);
        JsonType* element = JsonFactory::getFactory().createJsonType(stream);
        
        return element;
    }
    catch(...) {
        stream.close();
        throw;
    }
}


