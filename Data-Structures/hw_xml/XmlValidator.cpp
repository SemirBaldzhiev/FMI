#include "XmlValidator.h"
#include <stack>
#include <iostream>

XmlValidator::XmlValidator() {
}

bool XmlValidator::isValidXml(std::istream &is) {
    
    std::string currTag = "";
    std::string attributes = "";
    std::stack<std::string> tags;
    char c;
    while (!is.eof()) {

        c = is.get();
        if (c == '<') {

            c = is.get();
            if (c == '/') {
                c = is.get();
                while (c != '>' && c != ' ') {
                    currTag += c;
                    c = is.get();  
                }
                if (currTag != tags.top()) {
                    return false;
                }

                tags.pop();
            }
            else {
                while (c != ' ' && c != '>') {
                    currTag += c;
                    c = is.get();
                }
                
                if (!isValidName(currTag)) {
                    return false;
                }

                while (c == ' ') {
                    c = is.get();
                }

                while (c != '>' && c != '/') {
                    attributes += c;
                    c = is.get();
                }   

                if (!isValidAttribute(attributes)) {
                    return false;
                }  

                if (c == '>') {
                    tags.push(currTag);
                }
                else if (c == '/'){
                    c = is.get();
                    if (c != '>'){
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            currTag = "";
            attributes = "";
        }
    }

    if (tags.empty()) {
        return true;
    }
    else {
        return false;
    }
}

bool XmlValidator::isValidName(std::string &tagName) {
    if (!isalpha(tagName[0]) && (tagName[0] != '_')){
        return false;
    }

    for (int i = 1; i < tagName.length(); i++){
        if (!isalpha(tagName[i]) && !isdigit(tagName[i]) && tagName[i] != '-' && tagName[i] != '_'){
            return false;
        }    
    }

    return true;
}

bool XmlValidator::isValidAttribute(std::string &attributes) {

    if (attributes == "") {
        return true;
    }
    size_t eqPos= attributes.find('=');
    if (eqPos == std::string::npos) {
        return false;
    }

    std::string key = attributes.substr(0, eqPos);
    std::string value = attributes.substr(eqPos+1, attributes.length() - eqPos - 1);

    
    if (!isValidName(key)) {
        return false;
    }

    if(value[0] != '\"' && value[0] != '\'') {
        return false;
    }

    if (value[value.length()-1] != '\"' && value[value.length() - 1] != '\'') {
        return false;
    }

    std::string valText = value.substr(1, value.length() - 2);

    for (int i = 0; i < valText.length(); i++) {
        if (!isalpha(valText[i]) && !isdigit(valText[i]) && valText[i] != '-' && valText[i] != '_'){
            return false;
        }  
    }

    return true;
}

XmlValidator::~XmlValidator() {
}