#include "String.h"

String::String() {
	str = nullptr;
	size = 0;
}

String::String(const char* string) {
	int i = 0;
	const char* aux = string;

	while (*string != ('\0')) {
		++i;
		++string;
	}

	size = i + 1;
	str = new char[size];
	i = 0;

	while (*aux != ('\0')) {
		str[i] = *aux;
		++aux;
		++i;
	}

	str[size - 1] = '\0';
}

String::String(const String& string) {
	size = string.size;
	str = new char[size];

	char* aux = string.str;
	
	int i = 0;
	while (*aux != ('\0')) {
		str[i] = *aux;
		++aux;
		++i;
	}

	str[size - 1] = '\0';
}

String::String(String&& string)  {
	size = string.size;
	str = string.str;
	string.str = nullptr;
}

String::~String() {
	delete str;
}

int String::length() const {
	return size - 1 >= 0 ? size - 1 : 0 ;
}

void String::clear() {
	delete str;
	str = nullptr;
	size = 0;
}

bool String::operator==(const String& string) const {
	bool equals = true;
	char* str1 = string.str;
	char* str2 = this->str;

	if (this->length() != string.length()) equals = false;

	while (equals and *str1 != '\0') {
		if (*str1 != *str2) equals = false;
		++str1;
		++str2;
	}
	return equals;
}

String String::operator+(const String& string) const {

	String res = String();
	delete res.str;
	int newSize = length() + string.length() + 1;
	res.str = new char[newSize];
	res.size = newSize;

	int i = 0;
	char* str1 = str;
	char* str2 = string.str;

	while (*str1 != '\0') {
		res.str[i] = *str1;
		++str1;
		++i;
	}
	
	while (*str2 != '\0') {
		res.str[i] = *str2;
		++str2;
		++i;
	}

	res.str[newSize - 1] = '\0';

	return res;
}

inline String getMeAString()
{
	return String("Another string");
}
