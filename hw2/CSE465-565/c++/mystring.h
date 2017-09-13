#ifndef _MYSTRING_
#define _MYSTRING_

#include <cstring>
#include <iostream>
#include <initializer_list>

#pragma warning(disable: 4996)

const bool DUMP = true;

class mystring {
private:
	char *str;
	int len;
	void allocateAndInitialize(const char *strValue) {
		allocateAndInitialize(strValue, strlen(strValue));
	}
	void allocate(int length) {
		len = length;
		str = new char[len + 1];
	}
	void allocateAndInitialize(const char *strValue, int length) {
		allocate(length);
		strcpy(str, strValue);
	}
	void message(std::initializer_list<const char *> msgs) {
		if (DUMP) {
			for (auto msg = msgs.begin(); msg != msgs.end(); msg++) {
				if (*msg == nullptr)
					std::cout << "null";
				else
					std::cout << *msg;
			}
			std::cout << std::endl;
		}
	}
	mystring(int length) {
		allocate(length);
	}
public:
	mystring() {
		message({ "default ctor" });
		allocateAndInitialize("");
	}
	mystring(const char *initStr) {
		message({ "ctor w/ initial value (", initStr, ")" });
		allocateAndInitialize(initStr);
	}
	~mystring() {
		message({ "~(", str, ")" });
		delete[] str;
	}
	mystring(const mystring &other) : mystring(other.len) {
		message({ "copy ctor(", other.str, ")" });
		strcpy(str, other.str);
	}
	mystring &operator = (const mystring &other) {
		message({ "=(", str, "=", ")" });
		if (this != &other) {
			delete [] str;
			allocateAndInitialize(other.str, other.len);
		}
		return *this;
	}
	mystring operator !() {
		mystring result(len);
		int pos = len - 1;
		for (int i = 0; i < len; i++, pos--) {
			result.str[i] = str[pos];
		}
		result.str[len] = '\0';
		return result;
	}
	mystring(mystring &&other) : str(nullptr), len(0) {
		message({ "move ctor(", other.str, ")" });
		str = other.str;
		len = other.len;

		other.str = nullptr;
		other.len = 0;
	}
	mystring &operator = (mystring &&other) 	{
		message({ "move =(", str,"=", ")" });
		if (this != &other) {
			delete [] str;
			str = other.str;
			len = other.len;
			other.str = nullptr;
			other.len = 0;
		}
		return *this;
	}
};

#endif
