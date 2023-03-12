#ifndef XML_DOCUMENT_H_
#define XML_DOCUMENT_H_

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>

struct XmlNode {
    std::string tagName;
    std::string text;
    std::map<std::string, std::string> attributes{};
    std::vector<XmlNode*> children;
    XmlNode *parent;

    XmlNode(const std::string &tagName, XmlNode *parent)
        :tagName(tagName),
         parent(parent) { }
};


class XmlDocument {
    private:
        XmlNode *root = nullptr;
        std::vector<std::string> parseAttributes(std::string &str, char delimiter);

        /**
         * Add attributes key and value in the map
         * 
         * @param rawAttributes not parsed attribute as string
         * @param attributes map where to be added parsed attribute
         * 
        */
        void addAttributes(std::string &rawAttributes, std::map<std::string, std::string> &attributes);
        
        /**
         * Helper function to check if string is a number
         * 
         * @param str string to be checked if is a number
         * 
         * @return true if str is number otherwise false 
        */
        bool isNumber(std::string &str);

        /**
         * Parse XPath query and filter nodes from tree by this path
         * 
         * @param query XPath query as string
         * 
         * @return vector from XmlNode pointers which are filtered nodes from XPath query
        */
        std::vector<XmlNode*> parseXPathQuery(std::string &query);

        /**
         * Free allocated memory for the tree
         * 
         * @param node Pointer to root element of the tree
         * 
        */
        void deleteTree(XmlNode *node);
    public:
        XmlDocument() : root(nullptr) { }
        ~XmlDocument();

        /**
         * Function to build XML tree from input document
         * 
         * @param is document input file stream 
         * 
        */
        void buildDocumentTree(std::istream &is);

        // /**
        //  * Loading XML document by provided path
        //  * 
        //  * @param is document input file stream 
        //  * 
        // */
        // bool loadXmlDocument();

         /**
         * Getter for XML document root
         * 
         * @return XmlNode pointer which is document root
         * 
        */
        XmlNode *getDocumentRoot() const;

         /**
         * Evaluate XPath query and return values from filtered nodes
         * This function use parseXPathQuery as helper to parse provided query
         * 
         * @param query XPath query as string
         * 
         * @return vector from strings which are filtered node values
        */
        std::vector<std::string> evaluateXPath(std::string &xpath);

};
#endif