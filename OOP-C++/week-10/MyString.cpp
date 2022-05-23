#include <cstring>
#include "MyString.h"

MyString::MyString() : str(nullptr) { }

MyString::MyString(const char *str) {
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
}
MyString::MyString(const MyString &other) {
    copy(other);
}

MyString& MyString::operator=(const MyString &other) {
    if (this != &other){
        clear();
        copy(other);
    }

    return *this;
}

MyString::~MyString() {
    clear();
}

void MyString::append(const char *newStr) {

    int oldStrLen = this->length();
    char* res = new char[oldStrLen + strlen(newStr) + 1];

    for (int i = 0; str[i] != '\0'; ++i){
        res[i] = str[i];
    }

    for (int i = 0; newStr[i] != '\0'; ++i){
        res[oldStrLen + i] = newStr[i];
    }

    res[oldStrLen + strlen(newStr)] = '\0';

    clear();
    str = res;
}

char& MyString::operator[](int index) {
    if (index < 0 || index >= this->length()){
        throw std::out_of_range("String index out of bound");
    }

    return str[index];
}

const char& MyString::operator[](int index) const {
    if (index < 0 || index >= this->length()){
        throw std::out_of_range("String index out of bound");
    }

    return str[index];
}

const unsigned int MyString::length() const {
    return strlen(str);
}

std::vector<char*> MyString::splitBy(const char symbol) {

}

bool MyString::operator==(const MyString &other) const {
    return strcmp(this->str, other.str) == 0;
}

bool MyString::operator!=(const MyString &other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& in, MyString& myStr) {
    in >> myStr.str;
    return in;
}

std::ostream& operator<<(std::ostream& out, const MyString& myStr) {
    out << myStr.str;
    return out;
}

void MyString::copy(const MyString &other) {
    str = new char[other.length() + 1];
    strcpy(str, other.str);
}

void MyString::clear() {
    delete[] str;
}

