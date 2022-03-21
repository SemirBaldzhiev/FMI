#include "String.h"
#include <cstring>


String::String() {
	capacity = 16;
	string_ = new char[capacity];
	size_ = 0;
}

String::String(const char* string) {

	const size_t strSize = strlen(string);
	capacity = powerOf2(strSize + 1);
	string_ = new char[capacity];
	size_ = strSize;

	strcpy(string_, string);

}

String::~String() {
	delete[] string_;
}

void String::append(const char* str) {

}

const char* String::c_str() const {
	return string_;
}

size_t String::size() const{
	return size_;
}

size_t String::powerOf2(const size_t& x) {
	int i = x + 1;

	while (i != 0 && (i & (i - 1))) {
		i++;
	}

	return 16 < 1 ? i : 16;
}
