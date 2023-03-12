#include "XmlDocument.h"

std::vector<std::string> XmlDocument::parseAttributes(std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string word = "";
    for (char x : str)
    {
        if (x == delimiter)
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

void XmlDocument::addAttributes(std::string &rawAttributes, std::map<std::string, std::string> &attributes) {
    std::vector<std::string> tokens = parseAttributes(rawAttributes, ' ');
    for (std::string token : tokens) {
        size_t equalIndex = token.find("=");
        std::string key = token.substr(0, equalIndex);
        std::string value = token.substr(equalIndex + 2, token.length() - equalIndex - 3);
        attributes.insert({ key, value });
    }
}


void XmlDocument::buildDocumentTree(std::istream &is) {
    std::string currTag = "";
    std::string attributes = "";
    std::string text = "";
    root = new XmlNode("", nullptr);
    XmlNode* current = root;
    char c;
    while (!is.eof()) {

        c = is.get();

        if (c == '<') {
            c = is.get();
            if (c == '/') {
                c = is.get();
                while (c != '>' && c != ' ') {
                    c = is.get();  
                }
                current = current->parent;
            }
            else {
                //c = is.get();
                while (c != ' ' && c != '>') {
                    currTag += c;
                    c = is.get();
                }
                
                while (c == ' ') {
                    c = is.get();
                }

                while (c != '>' && c != '/') {
                    attributes += c;
                    c = is.get();
                }

                if (c == '>' || c == '/') {
                    XmlNode* node = new XmlNode(currTag, current);
                    if (attributes != "")
                        addAttributes(attributes, node->attributes);
                    current->children.push_back(node);
                    current = node;
                }
                if (c == '/'){
                    current = current->parent;
                    is.get();
                }

                
            }

            currTag = "";
            attributes = "";                    
        }
        else {
            if (c != '\n')
                current->text += c;
        }
    }
    // return root;
    
}  

XmlNode *XmlDocument::getDocumentRoot() const {
    return this->root;
}

bool XmlDocument::isNumber(std::string &str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }  

    return true;  
}

std::vector<XmlNode*> XmlDocument::parseXPathQuery(std::string &query) {
   
    std::vector<std::string> parts = {};
    std::string part = "";    
    bool inPredicate = false;
    for (char c : query) {
        if (c == '[') inPredicate = true;
        if (c == ']') inPredicate = false;
        if (c == '/' && !inPredicate) {
        parts.push_back(part);
        part.clear();
        } else {
        part += c;
        }
    }
    parts.push_back(part);

    std::vector<XmlNode*> nodes = {root};

    int idx = -1;
    int count = 0;
    std::string attributeName = "";
    std::string name = "";
    std::string predValue = "";
    std::string predKey = "";
    for (std::string &part : parts) {

        std::vector<XmlNode*> nextNodes;
        for (XmlNode *node : nodes) {
            
            if (part == node->tagName) {
                nextNodes.push_back(node);
            }
            else if (part.find('[') != std::string::npos) {

                size_t predicateStart = part.find('[');
                name = part.substr(0, predicateStart);
                size_t predicateEnd = part.find(']');
                std::string predicate = part.substr(predicateStart + 1, predicateEnd - predicateStart - 1);
                if (isNumber(predicate)) {
                    idx = stoi(predicate);
                }
                else if (predicate[0] == '@') {
                    attributeName = predicate.substr(1, predicateEnd);
                }
                else if (predicate.find('=') != std::string::npos) {
                    size_t equalForCalc = part.find('=');
                    size_t equalPos = predicate.find('=');

                    predKey = predicate.substr(0, equalPos);
                    predValue = predicate.substr(equalPos+2, predicateEnd - equalForCalc -3);

                }

            }

            for (int i = 0; i < node->children.size(); i++) {
                
                
                
                if (node->children[i]->tagName == name || node->children[i]->tagName == part) {
                    if (predKey != "" && predValue != "") {

                        if (node->children[i]->attributes.find(predKey) != node->children[i]->attributes.end() 
                                && node->children[i]->attributes[predKey] == predValue) {
                            nextNodes.push_back(node->children[i]);
                            continue;            
                        }
                        else {
                            for (XmlNode *n : node->children[i]->children) {
                                if (n->tagName == predKey && n->text == predValue) {
                                    nextNodes.push_back(node->children[i]);
                                }
                            }
                        }
                    }
                    if (attributeName != ""){
                        if(node->children[i]->attributes.find(attributeName) != node->children[i]->attributes.end()) {
                            nextNodes.push_back(node->children[i]);
                            continue;
                        }
                    }

                    if (idx == -1 && attributeName == "" && predKey == "" && predValue == "") {
                        nextNodes.push_back(node->children[i]);
                    }
                    else {
                        if (count == idx) {
                            nextNodes.push_back(node->children[i]);
                            break;
                        }
                    }

                    count++;
                    
                }
            }
            count = 0;
            idx = -1;
            attributeName = "";
            predKey = "";
            predValue = "";

        }

        nodes = nextNodes;
    }


    return nodes;
}

std::vector<std::string> XmlDocument::evaluateXPath(std::string &xpath) {
    std::vector<std::string> res;
    std::vector<XmlNode*> nodes = parseXPathQuery(xpath);
    if (xpath.find('@')!= std::string::npos) {
        for (XmlNode *n : nodes) {
            for (std::map<std::string, std::string>::const_iterator it = n->attributes.begin();
                it != n->attributes.end(); ++it) {

                res.push_back(it->second);    
            }
        }
    }
    else {
        for (XmlNode *n : nodes) {
            res.push_back(n->text);
        } 
    }

    return res;
}

void XmlDocument::deleteTree(XmlNode *node) {

    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < node->children.size(); i++) {
        deleteTree(node->children[i]);
    }

    delete node;
}

XmlDocument::~XmlDocument() {
    deleteTree(this->root);
}
