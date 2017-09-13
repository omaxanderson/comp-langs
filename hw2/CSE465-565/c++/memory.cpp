// memory.cpp
#include <iostream>

void ok() {
	std::cout << "OK" << std::endl;
	const int N = 10;
	int **ary = new int*[N];
	for (int i=0; i<N; i++) {
		ary[i] = new int [N];
	}
	for (int i=0; i<N; i++) {
		delete [] ary[i];
	}
	delete [] ary;
}

int leaky() {
	std::cout << "Leaky" << std::endl;
	int sz = 100;
	int *vals = new int [sz];
	int sum = 0;
	int i;
	for (i=0; i<sz; i++) {
		sum += vals[i];
	}
	return sum;
}

int overrun1() {
	std::cout << "Overrun1" << std::endl;
	int sz = 10;
	int *vals = new int[sz];
	int sum = 0;
	int i;
	for (i=0; i<=sz; i++) {
		sum += vals[i];
	}
	delete [] vals;
	return sum;
}

void overrun2() {
	std::cout << "Overrun2" << std::endl;
	int p1 = 110, p2 = -1;
	int a[100];
	int b[100];
	a[p1] = -4;
	b[p2] = -4;
}

void overrun3() {
	std::cout << "Overrun3" << std::endl;
	int p1 = -110;
	int a[100];
	a[p1] = -4;
}

void baddelete() {
	std::cout << "Bad Delete" << std::endl;
	int a;
	int *p = &a;
	delete p;
}

void wonkyAddress() {
	std::cout << "Wonky Address" << std::endl;
	int *a = (int*)0xf3f390;
	*a = 0;
}

int main(int argc, char *argv []) {
	int i;
	std::cout << "Enter integer 0-6" << std::endl;
	std::cin >> i;

	switch (i) {
		case 0: ok(); break;
		case 1: overrun1(); break;
		case 2: overrun2(); break;
		case 3: overrun3(); break;
		case 4: leaky(); break;
		case 5: baddelete(); break;
		case 6: wonkyAddress(); break;
	}

	std::cout << "DONE!" << std::endl;
}
