#include <iostream>
#include <string>

void f1(std::string a)
{ a += "!"; }

void f2(std::string &a)
{ a += "!"; }

void f3(std::string *a)
{ *a += "!"; }

void f4(std::string *a)
{ a = new std::string("new string"); }

void f5(std::string *&a)
{ a = new std::string("new string"); }

int main(int argc, char *argv[]) {
	std::string s1 = "hello";
	std::string s2 = "hello";
	std::string *p1 = new std::string("hello");
	std::string *p2 = new std::string("hello");
	std::string *p3 = new std::string("hello");
	
	f1(s1);
	f2(s2);
	f3(p1);
	f4(p2);
	f5(p3);

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	std::cout << *p3 << std::endl;
}
