#ifndef XML_VALIDATOR_H_
#define XML_VALIDATOR_H_

#include <string>
#include <fstream>

class XmlValidator {

    public:
        XmlValidator();
        XmlValidator(const XmlValidator &other) = delete;
        XmlValidator& operator=(const XmlValidator &other) = delete;
        ~XmlValidator();

        /**
         * Check for valid XML syntax
         * 
         * @param input Input stream which should be validated
         * 
         * @return True if XML is valid otherwise false
        */
        bool isValidXml(std::istream &input);

    private:
        /**
         * Validate XML tag name 
         * Cannot contains any special characters and white spaces
         * 
         * @param tagName String representing XML tag name
         * 
         * @return True if XML tag name is valid otherwise false
        */
        bool isValidName(std::string &tagName);

        /**
         * Validate XML attributes
         * Cannot contains any special characters and white spaces
         * Attributes format is: key="value"
         * They are separated with space from each other
         *
         * @param tagName String representing XML attribute
         * 
         * @return True if XML attribute is valid otherwise false
        */
        bool isValidAttribute(std::string &attribute);
};


#endif