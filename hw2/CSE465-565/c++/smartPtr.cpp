#include <memory>
#include <vector>
#include <iostream>
#include <memory>

class Item {
public:
	Item(int I) : id(I) {
	}
	~Item() {
		std::cout << "~" << id << std::endl;
	}
	int id;
};

void problematic() {
	Item *i1 = new Item(10);
	std::unique_ptr<Item> i2(i1);
	std::unique_ptr<Item> i3(i1);

	// use smart pointers here
}

void uniquePtr() {
	Item i1(1);
	Item *i2 = new Item(2);
	Item *i3 = new Item(3);
	std::unique_ptr<Item> i4(new Item(4));
	std::cout << i1.id << std::endl;
	std::cout << i2->id << std::endl;
	std::cout << i3->id << std::endl;
	std::cout << i4->id << std::endl;
	delete i2;
}

void uniquePtrInVector() {
	std::vector<Item*> v1;
	std::vector<std::unique_ptr<Item>> v2; 
	v1.push_back(new Item(11));
	v1.push_back(new Item(12));
	v1.push_back(new Item(13));
	v2.push_back(std::unique_ptr<Item>(new Item(21)));
	v2.push_back(std::unique_ptr<Item>(new Item(22)));
	v2.push_back(std::unique_ptr<Item>(new Item(23)));
}

void useSharedPtr(std::shared_ptr<Item> ptr) {
	std::cout << "Entering useSharedPtr" << std::endl;
	auto ptr1 = ptr;
	std::cout << ptr->id << std::endl;
	std::cout << "Exiting useSharedPtr" << std::endl;
}

void sharedPtr() {
	auto item1 = std::make_shared<Item>(101);
	std::shared_ptr<Item> item2(new Item(102));
	useSharedPtr(item1);	
	auto item3 = item1;
	item1 = std::make_shared<Item>(103);
	std::cout << item3->id << std::endl;
	item3 = std::make_shared<Item>(104);
}

int main(int argc, char *argv[]) {
	uniquePtr();
//	problematic();
	uniquePtrInVector();
	sharedPtr();
}

/* output
1
2
3
4
~2
~4
~1
~21
~22
~23
Entering useSharedPtr
101
Exiting useSharedPtr
101
~101
~104
~102
~103
*/
