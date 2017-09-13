#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class String {
   friend std::ostream &operator<<( std::ostream &, const String & );

public:
   String();					// default ctor
   String( const char *str);	// default ctor
   String( const String & );    // copy constructor
   ~String();                   // destructor
   const String &operator=( const String & );  // assignment
   const String &operator+=( const String & ); // concatenation
   bool operator==( const String & ) const; // s1 == s2?

   // test s1 != s2
   bool operator!=( const String & right ) const
      { return !( *this == right ); }
      
   char &operator[]( int );       // subscript operator
   const char &operator[]( int ) const; // subscript operator

   int getLength() const          // return string length
   { return length; }
   
private:
   int length;                   // string length 
   char *sPtr;                   // pointer to start of string
#ifdef USE_CAPACITY
   int capacity;
#endif
   void setString( const char * );
};

#endif
