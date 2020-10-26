#pragma once
class String
{
public:
	String();

	String(const char* string);

	String(const String& string);
	String(String&& string);

	~String();

	int length() const;

	void clear();

	bool operator==(const String& string) const;

	String operator+(const String& string) const;


private:
	char* str = nullptr;
	int size = 0;
};
