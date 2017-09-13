#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include "catalog.h"

int main()
{
	std::vector<int> vec;
	std::vector<int>::const_iterator vi;
	vec.push_back(3);
	vec.push_back(13);
	vec.push_back(-3);
	vec.push_back(7);
	for (vi = vec.begin(); vi != vec.end(); vi++) {
		std::cout << *vi << ' ';
	}
	std::cout << std::endl;

	Catalog cat;
	Catalog::const_iterator catIter;
	for (catIter = cat.begin(); catIter != cat.end(); catIter++) {
		std::cout << *catIter << ' ';
	}
	std::cout << std::endl;

	return 0;
}
