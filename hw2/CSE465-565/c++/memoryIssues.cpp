#include <memory>
#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
	int *a = new int;
	a = new int;		// lost memory

	int *b = new int;
	delete b;
	// b is dangling pointer

	int *c = new int [10];
	delete c;				// delete array as item

	int d = 34;
	int *e = &d;
//	delete e;				// deleting wrong memory

	int *f = new int [10];
	f[10] = 0;				// array overrun
	delete [] f;
}	
