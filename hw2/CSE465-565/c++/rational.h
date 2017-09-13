#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#include <iostream>

// This class represents a "rational number."  A rational
// number is a number that can be represented with an integer
// numerator and denominator.  This class provides a set of
// member functions/operators that allow users to easily use
// this class.

class Rational  {
friend std::ostream &operator << (std::ostream &os, const Rational &r);
friend std::istream &operator >> (std::istream &is, Rational &r);
// What does the "friend" signify here?
public:
	Rational();							
	Rational(int n, int d=1); 
	Rational(const Rational &rat);// copy constructor
	
	Rational operator + (const Rational &arg) const;
	Rational operator - (const Rational &arg) const;
	Rational operator - () const;
	Rational operator * (const Rational &arg) const;
	Rational operator / (const Rational &arg) const;
	Rational Reciprocal() const;

	bool operator == (const Rational &arg) const;

	// Explain how != works.
	bool operator != (const Rational &arg) const 
		{ return !(*this == arg); }

private:
	void Reduce();	// Why is Reduce() declared private?
	int num, denom;
};

#endif
