#pragma once
class String {

public:
	String();
	String(const char* string);
	~String();

	size_t size() const;

	const char* c_str() const;
	void append(const char* str);
	//void append(const char& c);
	static size_t powerOf2(const size_t& x);

private:
	char* string_ = nullptr;
	size_t capacity = 0;
	size_t size_ = 0;
};
