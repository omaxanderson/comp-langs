#include <iostream>

union Item {
	int x;
	double y;
};

enum DataType { INTEGER, DOUBLE };

struct DiscriminatedItem {
	DataType dateType;
	Item item;
};

int main(int argc, char *argv[])
{
	Item item;
	item.x = 100;
	std::cout << item.x << ' ' << item.y << std::endl;
	item.y = 3.14;
	std::cout << item.x << ' ' << item.y << std::endl;

	DiscriminatedItem ditem;
	ditem.dateType = INTEGER;
	ditem.item.x = 100;
	std::cout << ditem.item.x << ' ' << ditem.item.y << std::endl;	// still not enforced
	return 0;
}
