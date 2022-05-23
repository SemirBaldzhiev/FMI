//
// Created by User on 5/17/2022.
//

#ifndef WEEK_10_MYSTRING_H
#define WEEK_10_MYSTRING_H

#include <fstream>
#include <vector>

class MyString{
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    void append(const char* newStr);
    char& operator[](int index);
    const char& operator[](int index) const;
    const unsigned int length() const;
    std::vector<char*> splitBy(const char symbol);

    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    friend std::istream& operator>>(std::istream& in, MyString& myStr);
    friend std::ostream& operator<<(std::ostream& out, const MyString& myStr);

private:
    char* str;

    void copy(const MyString& other);
    void clear();
};

#endif //WEEK_10_MYSTRING_H
