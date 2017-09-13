#include "rational.h"

// IO
// A rational number can be entered via the keyboard or
// file.  It format is: "1/2".  Thus numerator and 
// denominator must be separated by a "/"

std::ostream &operator << (std::ostream &os, const Rational &r) {
	os << r.num << "/" << r.denom;
	return os;
}

std::istream &operator >> (std::istream &is, Rational &r) {
	char ch;
	is >> r.num >> ch >> r.denom;
	r.Reduce();
	return is;
}

Rational::Rational() { 
	num = 0; denom = 1;
}

Rational::Rational(int n, int d) { 
	if (d == 0) {
		d = n = 1;	// don't allow 0 denominators
	}

	num = n; 
	denom = d;
	Reduce();
}

Rational::Rational(const Rational &rat)	{ // copy constructor
	num = rat.num; 
	denom = rat.denom;	// Should not need to reduce
}

Rational Rational::operator + (const Rational &arg) const {
	int d = denom*arg.denom;
	int n = num*arg.denom + arg.num*denom;

	return Rational(n, d);
}

Rational Rational::operator - () const {
	return Rational(-num, denom);
}

Rational Rational::operator * (const Rational &arg) const {
	int d = denom*arg.denom;
	int n = num*arg.num;
	return Rational(n, d);
}

Rational Rational::Reciprocal() const {
	if (num == 0)
		return Rational(0, 1);
	else
		return Rational(denom, num);
}

Rational Rational::operator / (const Rational &arg) const {
	return (*this) * arg.Reciprocal();
}

Rational Rational::operator - (const Rational &arg) const {
	return (*this) + (-arg);
}

bool Rational::operator == (const Rational &arg) const {
	return (num == arg.num && denom == arg.denom);
}

// This function reduces a rational into its lowest form.
// For example, 4/8 is converted to 1/2.

void Rational::Reduce() {
	if (denom < 0) {	// don't want negative denoms
		num = -num;
		denom = -denom;
	}

	if (num == 0)		// normalize zero to be 0/1
		denom = 1;

	for (int i=denom; i>=2; i--) {
		if (num % i == 0 && denom % i == 0) {
			num /= i;
			denom /= i;
		}
	}
}
