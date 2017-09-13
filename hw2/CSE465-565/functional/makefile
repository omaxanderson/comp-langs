all:	cppFunc	csFunc.exe

cppFunc:
		c++ -std=c++11 -O3 -o cppFunc cppFunctional.cpp
csFunc.exe:
		mcs -out:csFunc.exe csFunctional.cs

clean:
	rm cppFunc csFunc.exe *Output

run:
	mono csFunc.exe > csOutput
	./cppFunc > cppOutput
	python3 *.py > pyOutput
