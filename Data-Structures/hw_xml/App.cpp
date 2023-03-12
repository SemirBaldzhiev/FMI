#include "App.h"
#include <iostream>

App::App() {
    fileIsLoaded = false;
}

std::vector<std::string> App::splitBySpace(std::string &str)
{
    std::vector<std::string> tokens;
    std::string word = "";
    for (char x : str)
    {
        if (x == ' ')
        {
            if (word == "") {
                continue;
            }
            tokens.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }

    tokens.push_back(word);

    return tokens;
}

bool App::loadFile(std::string &path) {

    is.open(path);

    if (!is.is_open()) {
        return false;
    }

    return true;
}

void App::printXPathResult(std::vector<std::string> &res) {

    std::cout << "["; 
    for (int i = 0; i < res.size(); i++) {
        if (i == res.size() - 1) {
            std::cout << res[i];
        }
        else {
            std::cout << res[i] << " | ";
        }
    }
    std::cout << "]";
    std::cout << '\n';
}

void App::executeCommand(std::string &command) {

    std::vector<std::string> tokens = splitBySpace(command);

    if (tokens.size() > 1 && tokens[0] == "load" && !fileIsLoaded) {
        bool isLoaded = loadFile(tokens[1]);

        if (!isLoaded) {
            throw std::invalid_argument("Cannot open file for reading!");
        }

        if (!validator.isValidXml(is)) {
            throw std::invalid_argument("Invalid xml document");
        }

        std::cout << "Sucessfuly load document " << tokens[1] << "\n";

        is.clear();
        is.seekg(0, std::ios::beg);

        doc.buildDocumentTree(is);
        fileIsLoaded = true;
    }
    else {
        if (!fileIsLoaded) {
            throw std::invalid_argument("Cannot execute XPath query whitout loaded file");
        }
        std::vector<std::string> res = doc.evaluateXPath(tokens[0]);
        printXPathResult(res);
    }

}

void App::closeFile() {
    is.close();
}

void App::menu() {
    std::cout << "____________________________________________________________\n";
    std::cout << "|                                                          |\n";
    std::cout << "|-----------------------Xml Parser-------------------------|\n";
    std::cout << "|__________________________________________________________|\n";
    std::cout << "| Commands:                                                |\n";
    std::cout << "|   > load <file_paths>                                    |\n";
    std::cout << "|   > <XPath query>                                        |\n";
    std::cout << "|   > exit                                                 |\n";
    std::cout << "|__________________________________________________________|\n";
}

void App::run() {

    menu();
    std::string inputCommand;

    std::getline(std::cin, inputCommand);

    while (inputCommand != "exit") {
        try
        {
            executeCommand(inputCommand);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            closeFile();
        }
        
        inputCommand.clear();
        std::getline(std::cin, inputCommand);
    }

    closeFile();
}
