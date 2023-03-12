#ifndef APP_H_
#define APP_H_

#include <string>
#include <vector>
#include <fstream>
#include "XmlDocument.h"
#include "XmlValidator.h"
class App {
    public:
        App();
        ~App() { }

        /**
         * Main function which combine all funtions and it is starting point of the program
         * 
        */
        void run();
    private:
        XmlDocument doc;
        XmlValidator validator;
        std::ifstream is;
        bool fileIsLoaded;

        /**
         * Execute commands entered from terminal
         * 
         * @param command entered command from terminal as string
         * 
        */
        void executeCommand(std::string &command);

        /**
         * Load input file by path
         * 
         * @param path path to file which you want to load
         * 
         * @return true if file is loaded successful otherwise false
        */
        bool loadFile(std::string &path);

        /**
         * Split commands by space to separete each other
         * 
         * @param str entered command by user
         * 
         * @return vector from strings which are all parts from command separated in single strings
        */
        std::vector<std::string> splitBySpace(std::string &str);

        /**
         * Function to print result from XPath query
         * 
         * @param res vector from strings which is results which should be printed
         * 
        */
        void printXPathResult(std::vector<std::string> &res);
        
        /**
         * Close currently oppened file
         * 
        */
        void closeFile();

        /**
         * Print which command to use and make program userfriendly
         * 
        */
        void menu();
};

#endif