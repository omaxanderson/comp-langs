all:	params Parameters.class Parameters.exe varargs varargs.class varargs.exe 

params:
	c++ -o params -O3 -std=c++11 params.cpp
varargs:
	c++ -o varargs -O3 -std=c++11 varargs.cpp
Parameters.class:
	javac Parameters.java
varargs.class:
	javac varargs.java
Parameters.exe:
	mcs Parameters.cs
varargs.exe:
	mcs varargs.cs
clean:	
	rm params Parameters.class Parameters.exe varargs varargs.class varargs.exe 
