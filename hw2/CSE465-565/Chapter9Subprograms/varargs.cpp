#include <iostream>
#include <string>
#include <cstdarg>
#include <cmath>

double f(int b, ...)
{
	va_list vl;
	va_start(vl, b);	// b is the last named parameter
	double sum = 0;
	for (int i=0; true; i++) {
		int e = va_arg(vl, int);
		if (e == 0) {
			break;
		}
		sum += pow((double)b, e);
	}
	va_end(vl);
	return sum;
}

int main(int argc, char *argv[])
{
	std::cout << f(2, 4, 1, 1, 3, 0) << std::endl;
}
