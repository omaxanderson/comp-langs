all:	overflow overflow.class Overflow.exe Enum.exe union

union:
	c++ -o union -O3 -std=c++11 union.cpp
overflow:
	c++ -o overflow -O3 -std=c++11 overflow.cpp
overflow.class:
	javac overflow.java
Enum.exe:
	mcs Enum.cs
Overflow.exe:
	mcs Overflow.cs
clean:	
	rm overflow overflow.class Overflow.exe Enum.exe union
