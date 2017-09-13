all:	str1 str2
	
str1:	
	c++ -p -std=c++11 -o str1 string.cpp main.cpp
str2:	
	c++ -DUSE_CAPACITY -p -std=c++11 -o str2 string.cpp main.cpp
clean:	
	rm gmon.out str1 str2
