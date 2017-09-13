#ifndef _CATALOG_H_
#define _CATALOG_H_

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

class Catalog {
public:
	class const_iterator {
	friend Catalog;
	private:
		void updateIndices() {
			if (whichList == 0) {
				if (whichItem >= (int)lists[0]->size()) {
					whichList = 1;
					whichItem = 0;
				}
			}
			if (whichList == 1) {
				if (whichItem >= (int)lists[1]->size()) {
					whichList = 2;
					whichItem = 0;
				}
			}
		}
	public:
		const_iterator() {
			lists[0] = lists[1] = nullptr;
			whichList = 2;
			whichItem = 0;
		}
		const_iterator(const std::vector<std::string> &ugClasses,
						const std::vector<std::string> &gradClasses,
						int listID=0, int itemID=0) {
			lists[0] = &ugClasses;
			lists[1] = &gradClasses;
			whichItem = itemID;
			whichList = listID;
			updateIndices();
		}
		bool operator == (const const_iterator &i) const {
			return lists[0] == i.lists[0] && lists[1] == i.lists[1] &&
					whichList == i.whichList && whichItem == i.whichItem;
		}
		bool operator != (const const_iterator &i) const {
			return !(*this == i);
		}
		const_iterator &operator++() {	// prefix ++
			if (whichList < 2) {
				whichItem++;
				updateIndices();
			}
			return *this;
		}
		const_iterator operator ++(int) {	// postfix ++
			const_iterator i = *this;
			this->operator++();
			return i;
		}
		const std::string &operator *() {
			return lists[whichList]->operator[](whichItem);
		}
	private:
		const std::vector<std::string> *lists[2];
		int whichList;
		int whichItem;
	};

	Catalog() {
		ugClasses.push_back("CSE 174");
		ugClasses.push_back("CSE 271");
		ugClasses.push_back("CSE 274");
		ugClasses.push_back("CSE 465");
		ugClasses.push_back("CSE 486");

		gradClasses.push_back("CSE 627");
		gradClasses.push_back("CSE 612");
		gradClasses.push_back("CSE 615");
	}
	const_iterator begin() const {
		return Catalog::const_iterator(ugClasses, gradClasses);
	}
	const_iterator end() const {
		return Catalog::const_iterator(ugClasses, gradClasses, 2, 0);
	}

private:
	std::vector<std::string> ugClasses;
	std::vector<std::string> gradClasses;
};

#endif
