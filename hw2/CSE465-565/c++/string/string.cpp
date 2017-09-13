#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>

#include "string.h"

String::String()
{ setString(""); }

String::String(const char *str)
{ setString(str); }

// Copy constructor
String::String( const String &copy )
{ setString( copy.sPtr ); }

// Destructor
String::~String()
{ delete [] sPtr; }

// Overloaded = operator; avoids self assignment
const String &String::operator=( const String &right ) {
   if (&right != this) {           // avoid self assignment
      delete [] sPtr;              // prevents memory leak
      setString( right.sPtr );     // call utility function
   }
   return *this;   // enables cascaded assignments
}

const String &String::operator+=( const String &right ) {
	int i, j;
	int oldLen = length;
	length += right.length;				// new String length
#ifdef USE_CAPACITY
	int finalLength = length + right.length;
	if (finalLength > capacity) {
		char *oldStr = sPtr;			// hold to be able to delete
		capacity = 2 * finalLength;
		sPtr = new char[ capacity + 1 ]; // create space
		assert( sPtr != nullptr );		// terminate if memory not allocated
		for (i=0; i<oldLen; i++) {
			sPtr[i] = oldStr[i];
		}
		for (j=0; j<right.length; j++, i++) {
			sPtr[i] = right.sPtr[j];
		}
		sPtr[length] = '\0';
		delete [] oldStr;				// reclaim old space
	} else {
		int i=length;
		for (j=0; j<right.length; j++, i++) {
			sPtr[i] = right.sPtr[j];
		}
	}
	length = finalLength;
#else
	char *oldStr = sPtr;			// hold to be able to delete
	sPtr = new char[ length + 1 ];	// create space
	assert( sPtr != nullptr );		// terminate if memory not allocated
	for (i=0; i<oldLen; i++) {
		sPtr[i] = oldStr[i];
	}
	for (j=0; j<right.length; j++, i++) {
		sPtr[i] = right.sPtr[j];
	}
	sPtr[length] = '\0';
	delete [] oldStr;			// reclaim old space
#endif
	return *this;				// enables cascaded calls
}

// Is this String equal to right String?
bool String::operator==( const String &right ) const
{
	if (length != right.length)			// same as strcmp(sPtr, right.sPtr)
		return false;
	for (int i=0; i<length; i++) {
		if (sPtr[i] != right.sPtr[i]) {
			return false;
		}
	}
	return true;
}

char &String::operator[]( int subscript ) {
   assert( subscript >= 0 && subscript < length );
   return sPtr[ subscript ];  // lvalue
}

const char &String::operator[]( int subscript ) const {
   assert( subscript >= 0 && subscript < length );
   return sPtr[ subscript ];  // rvalue
}

void String::setString(const char *str) {
	length = strlen(str);			// strlen finds '\0'
#ifdef USE_CAPACITY
	capacity = 2 * length;
	sPtr = new char [capacity + 1];
#else
	sPtr = new char[ length + 1 ];	// allocate storage
#endif
	assert( sPtr != 0 );		// terminate if memory not allocated
	for (int i=0; i<=length; i++)	// could be replaced with strcpy
		sPtr[i] = str[i];
}

// Overloaded output operator
std::ostream &operator<<( std::ostream &output, const String &s ) {
	for (int i=0; i<s.length; i++)			// could be: output << s.sPtr;
		output << s.sPtr[i];
   return output;   // enables cascading
}
