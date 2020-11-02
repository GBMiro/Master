#pragma once
class String
{
public:
	String();

	String(const char* string);

	String(const String& string);
	String(String&& string);

	~String();

	size_t length() const;

	void clear();

	String& operator=(String&& string);

	String& operator=(const String& string);

	bool operator==(const String& string) const;

	String operator+(const String& string) const;

private:
	char* str;
	size_t size;
};

inline void copy(const char* src, char* dst, size_t length);
