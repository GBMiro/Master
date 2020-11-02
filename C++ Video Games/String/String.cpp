#include "String.h"

String::String() {
	str = nullptr;
	size = 0;
}

String::String(const char* string) {
	size_t i = 0;

	while (string[i] != ('\0')) {
		++i;
	}

	size = i;
	
	if (string != nullptr) {
		str = new char[size + 1];
		copy(string, str, size);
	}
}

String::String(const String& string) {
	size = string.size;
	str = new char[size + 1];
	
	copy(string.str, str, size);
}

String::String(String&& string)  {
	size = string.size;
	str = string.str;
	string.str = nullptr;
}

String::~String() {
	delete[] str;
}

size_t String::length() const {
	return size;
}

void String::clear() {
	delete[] str;
	str = nullptr;
	size = 0;
}

String& String::operator=(String&& string)
{
	delete[] str;
	str = string.str;
	size = string.size;
	string.str = nullptr;

	return *this;
}

String& String::operator=(const String& string)
{
	clear();
	if (string.str != nullptr) {
		size = string.size;
		str = new char[size + 1];
		copy(string.str, str, size);
	}

	return *this;
}

bool String::operator==(const String& string) const {
	bool equals = true;
	size_t len = this->length();
	if (len != string.length()) equals = false;

	for (int i = 0; i < len and equals; ++i) {
		if (this->str[i] != string.str[i]) equals = false;
	}

	return equals;
}

String String::operator+(const String& string) const {

	String res = String();
	size_t len1 = length();
	size_t len2 = string.length();
	size_t newSize = len1 + len2;
	res.str = new char[newSize + 1];
	res.size = newSize;

	copy(this->str, res.str, len1);
	copy(string.str, res.str + len1, len2);

	return res;
}

void copy(const char* src, char* dst, size_t length) {
	for (int i = 0; i < length; ++i) {
		dst[i] = src[i];
	}
	dst[length] = '\0';
}
