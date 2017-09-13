#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>

#include "rational.h"

template <class ITER, class TYPE>
ITER myfind(ITER b, ITER e, TYPE key) {
	while (b != e) {
		if (*b == key)
			return b;
		b++;
	}
	return b;
}

void print(double v) {
	std::cout << v << ' ' ;
}

double sqr(double x) {
	return x*x;
}

int main(int argc, char *argv[]) {
// List of ints
	std::list<int> l;
	std::list<int>::const_iterator li;

	l.push_back(25);
	l.push_back(-75);
	l.push_back(50);
	l.push_back(10);
	l.push_back(20);
	l.push_back(-5);

// Double array
	const int N = 5;
	double dbl[N] = { 0, 2.17, 1.60, 1.7, 3.14 };
// Rationals
	Rational rats[N] = { Rational(3, 4), Rational(1, 4), Rational(5, 4), Rational(1, 8), Rational(1, 8) };
	
// STL Find
	li = std::find(l.begin(), l.end(), -75);
	if (li != l.end())
		std::cout << "List found " << *li << std::endl;
	else
		std::cout << "List not found " << std::endl;

	double *di = std::find(dbl, dbl+N, 3.14);
	if (di != &dbl[N])
		std::cout << "Double array found " << *di << std::endl;
	else
		std::cout << "Double array not found " << std::endl;

// Homemade find
	li = myfind(l.begin(), l.end(), -75);
	if (li != l.end())
		std::cout << "List found " << *li << std::endl;
	else
		std::cout << "List not found " << std::endl;

	di = myfind(dbl, dbl+N, 3.14);
	if (di != &dbl[N])
		std::cout << "Double array found " << *di << std::endl;
	else
		std::cout << "Double array not found " << std::endl;

// sort
	// sort does not work with lists
	// sort does not work with sets
	std::sort(dbl, dbl+N);

	for (int i=0; i<5; i++) {
		std::cout << dbl[i] << ' ';
	}
	std::cout << std::endl;

	double result[N];
	std::transform(dbl, dbl+N, result, sqr);
	std::for_each(result, result+N, print);

	std::fill(dbl, dbl+N, 3.14);

	double sum = std::accumulate(dbl, dbl+N, 0);
	std::cout << sum << std::endl;

	Rational ratSum = std::accumulate(rats, rats+N, Rational());
	std::cout << ratSum << std::endl;
	return 0;
}
