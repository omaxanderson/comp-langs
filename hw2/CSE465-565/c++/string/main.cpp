#include <iostream>

#include "string.h"

int main() {
	String s1("ABCD"), s2("123"), s3;
	for (int i=0; i<10000; i++) {
		s1 += s2;
		
		String tmp1;
		tmp1 = s1;
		String *tmp2 = new String(s1);
		delete tmp2;
	}
	
	return 0;
}

