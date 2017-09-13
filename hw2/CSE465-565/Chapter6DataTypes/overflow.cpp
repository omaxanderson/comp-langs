#include <iostream>
#include <cmath>
#include <limits>

const double INF = std::numeric_limits<double>::infinity();

bool isNan(double v)
{ return v != v; }		// works only for NaN

void Display(double v) {
	if (v == std::numeric_limits<double>::infinity()) {
		std::cout << "INFINITY" << std::endl;
	} else if (isNan(v)) {
		std::cout << "NAN" << std::endl;
	} else {
		std::cout << v << std::endl;
	}
}

int main(int argc, char *argv[]) {
		long x = 1;
		int cnt = 0;
		int zero = 0;
		Display(1.4/zero);
		Display(0.0/zero);
		Display(sqrt(-1.0));
		Display(std::numeric_limits<double>::min()/std::numeric_limits<double>::min());
		Display(std::numeric_limits<double>::min()/std::numeric_limits<double>::max());
		Display(std::numeric_limits<double>::max()/std::numeric_limits<double>::min());
		Display(std::numeric_limits<double>::max()/std::numeric_limits<double>::max());

	return 0;
}
