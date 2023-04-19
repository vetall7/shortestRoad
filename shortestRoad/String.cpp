#define _CRT_SECURE_NO_WARNINGS
#include  "string.h "

using namespace std;


char& String::operator[](int i) const {
	return str[i];
}

void String::append(const char a)
{
	char* str2 = new char[length + 2];
	if (str != nullptr) {
		memcpy(str2, str, length);  //kopijuje blok pamieci
		delete[] str;
	}
	str2[length] = a;
	str2[length + 1] = '\0';
	length++;
	str = str2;
}

String::String(String&& other) {
	this->str = other.str;
	this->length = other.length;
	other.str = nullptr;
	other.length = 0;
}
bool String::contains(const char* subStr) const {
	if (subStr == nullptr) {
		return false;
	}

	size_t subStrLength = strlen(subStr);
	if (subStrLength > length) {
		return false;
	}

	for (size_t i = 0; i <= length - subStrLength; i++) {
		bool found = true;
		for (int j = 0; j < subStrLength; j++) {
			if (str[i + j] != subStr[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			return true;
		}
	}

	return false;
}

int String::containString(const String& other) const {
	unsigned int lengthString = strlen(this->str);
	unsigned int lengthSubString = strlen(other.str);
	bool flag = false;
	int index = NO_STRING;
	for (size_t i = 0; i < lengthString; i++) {
		if (!flag && lengthSubString > lengthString - i) {
			return NO_STRING;
		}
		if (!flag && this->str[i] == *other.str) {
			flag = true;
			index = i;
		}
		if (this->str[i] != other.str[i - index]) {
			flag = false;
		}
		if (i - index == lengthSubString - 1 && flag) return index;
	}
	return NO_STRING;
}


String& String::operator=(String&& other) {
	if (this == &other) {
		return *this;
	}

	delete[] str;
	str = other.str;
	length = other.length;
	other.str = nullptr;
	other.length = 0;
	return *this;
}



bool operator==(const String& a, const String& b) {
	if (a.length != b.length) {
		return false;
	}
	return (memcmp(a.str, b.str, a.length) == 0);  // por?wnuje bloki pamieci
}

size_t String::size() const {
	return length;
}


String::String(const String& other)
{
	length = other.length;
	str = new char[length + 1];
	for (size_t i = 0; i < length; i++) {
		str[i] = other.str[i];
	}
	str[length] = '\0';
}

String String::cut(size_t i, size_t j) const
{
	String temp;
	for (size_t k = i; k < j; k++) {
		temp.append(str[k]);
	}
	return move(temp);  //r-value
}

bool String::is_consist(char a) const
{
	for (size_t i = 0; i < length; i++) {
		if (str[i] == a) {
			return true;
		}
	}
	return false;
}


void String::Print() const {
	cout << str;
}

String& String::operator=(const String& other)
{
	if (this->str != nullptr) {
		delete[] str;
	}

	length = 0;
	while (other.str[length] != '\0') {
		length++;
	}
	this->str = new char[length + 1];
	for (size_t i = 0; i < length; i++) {
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
	return *this;
}


String::String(const char* str) {
	if (str == nullptr) {
		this->str = nullptr;
		length = 0;
	}
	else {
		length = strlen(str);
		this->str = new char[length + 1];
		strcpy(this->str, str);   //kopia czarow z str do this->str
	}
}


String::~String() {
	delete[] str;
}

ostream& operator<<(ostream& os, const String& other)
{
	os << other.str;
	return os;
}

void String::remove_spaces() {
	int spaces_counter = 0;
	for (size_t i = 0; i < length; i++) {
		if (str[i] == ' ') {
			spaces_counter++;
		}
	}
	if (spaces_counter == 0) {
		return;
	}
	char* temp_arr = new char[length - spaces_counter + 1];
	int counter = 0;
	for (size_t i = 0; i < length; i++) {
		if (str[i] != ' ') {
			temp_arr[counter] = str[i];
			counter++;
		}
	}
	temp_arr[counter] = '\0';
	delete[] str;
	str = temp_arr;
	length -= spaces_counter;
}
