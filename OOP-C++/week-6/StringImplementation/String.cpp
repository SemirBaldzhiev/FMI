#pragma warning (disable: 4996)

#include "String.h"
#include <cstring>

String::String(const char* str) {
	size = strlen(str);
	string = new char[size + 1];
	std::strcpy(string, str);
}

String::~String() {
	delete[] string;
}

String::String(const String& str) {
	copy(str);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

String::String(String&& str) {
	delete[] string;
	size = str.size;
	string = str.string;
	str.clear();
}

String& String::operator=(String&& str) {
	if (this != &str) {
		delete[] string;
		size = str.size;
		string = str.string;
		str.clear();
	}

	return *this;
}

bool String::operator==(const String& str)
{
	return !strcmp(string, str.string);
}

void String::copy(const String& str) {
	delete[] string;
	size = str.size;
	string = new char[size + 1];
	std::strcpy(string, str.string);
}

void String::clear() {
	delete[] string;
	size = 0;
}

const char* String::c_str() const {
	return string;
}


std::ostream& operator<<(std::ostream out, const String& str){
	out << str.c_str();
	return out;
}

std::istream& operator>>(std::istream in, String& str)
{
	const size_t MAX_STR = 512;

	char buff[MAX_STR];
	in >> buff;

	String temp = String(buff);

	str = temp;

	return in;
}


bool operator==(const String& str1, const String& str2)
{
	return !strcmp(str1.string, str2.string);
}
