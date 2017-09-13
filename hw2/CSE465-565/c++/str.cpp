#include <iostream>
#include "mystring.h"

/*
BASIC CONSTRUCTION AND DESTRUCTION
default ctor
ctor w/ initial value (hello)
ctor w/ initial value (world)
copy ctor(world)
copy ctor(world)
~(world)
~(world)
~(world)
~(hello)
~()

MOVE ASSIGNMENT & COPY CTOR
ctor w/ initial value (M1)
copy ctor(M1)
move ctor(1M)
~(null)
copy ctor(1M)
~(1M)
~(1M)
~(M1)
*/

void basicConstruction() {
	std::cout << std::endl << "BASIC CONSTRUCTION AND DESTRUCTION" << std::endl;
	mystring s1;
	mystring s2 = "hello";
	mystring s3("world");
	mystring s4(s3);
	mystring s5 = s3;
}

mystring f(mystring param) {
	return mystring(param);
}

void moveCopyCtor() {
	std::cout << std::endl << "MOVE ASSIGNMENT & COPY CTOR" << std::endl;
	mystring s1("M1");
	mystring s2 = f(!s1);	// ! reverses a string
}

int main(int argc, char *argv[]) {
	basicConstruction();
	moveCopyCtor();
}
