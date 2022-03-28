#include <iostream>
#ifndef STRING_H
#define STRING_H

class String {
private:
	char* string;
	size_t size;

public:
	String();
	String(const char* string);
	String(const String& str);
	~String();
	String(String&& sring);
	String& operator=(const String& other);
	String& operator=(String&& other);

	const char* c_str() const;

	friend std::ostream& operator<<(std::ostream out, const String& str);
	friend std::istream& operator>>(std::istream in, String& str);

	bool operator==(const String& str);

	friend bool operator==(const String& str1, const String& str2);
	// friend bool operator==(String& str1, const String& str2);
	// friend bool operator==(const String& str1, String& str2);


private:
	void copy(const String& str);
	// void move(String&& str);
	void clear();


};



#endif 