#pragma once
#include <iostream>
#define NO_STRING -1
using namespace std;
class String {
private:
	char* str;
	size_t length;
public:
	String() {
		str = nullptr;
		length = 0;
	}
	String(const char* str);
	int containString(const String& other) const;
	~String();
	void Print() const;
	String& operator=(const String& other);
	friend ostream& operator<<(ostream& os, const String& str);
	friend bool operator==(const String& a, const String& b);
	size_t size() const;
	char& operator[](int i) const;
	void append(const char a);
	String(String&& other);
	String(const String& other);
	String cut(size_t i, size_t j) const;
	bool is_consist(char a) const;
	String& operator=(String&& other);
	void remove_spaces();
	bool contains(const char* subStr) const;
};