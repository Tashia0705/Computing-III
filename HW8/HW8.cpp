#include <iostream>
#include <cmath>
using namespace std;

class Rational {
public:
	//accessor
	long getnum();
	long getdenom();
	//mutator
	void setnum(long num);
	void setdenom(long denom);
	//constructor
	Rational();
	Rational(long num);
	Rational(long num, long den);
	//insertion operator
	friend ostream& operator<<(ostream& out, const Rational& r);
	//arithmetic
	friend Rational operator+(Rational& x, Rational& y);
	friend Rational operator-(Rational& x, Rational& y);
	friend Rational operator/(Rational& x, Rational& y);
	friend Rational operator*(Rational& x, Rational& y);
private:
	long numerator;
	long denominator;

	long gcd(long numerator, long denominator);
};
//accessor and mutator functions
long Rational::getnum() {
	return numerator;
}
long Rational::getdenom() {
	return denominator;
}
void Rational::setnum(long num) {
	numerator = num;
}
void Rational::setdenom(long denom) {
	denominator = denom;
}
//gcd
long gcd(long numerator, long denominator) {
	if (numerator == 0) {
		return denominator;
	}
	return gcd(denominator % numerator, numerator);
}
//constructors
Rational::Rational() {
	numerator = 0;
	denominator = 0;
}
Rational::Rational(long num) {
	numerator = num;
	denominator = 0;
}
Rational::Rational(long num, long den) {
	numerator = num;
	denominator = den;
}
//insertion operator
ostream& operator<<(ostream& out, const Rational& r) {
	if (r.denominator == 0) {
		out << r.numerator << endl;
	}
	else if (r.numerator < 0 && r.denominator < 0) {
		out << r.numerator << "/" << fabs(r.denominator) << endl;
	}
	else if (r.denominator < 0){
		out << -(r.numerator) << "/" << fabs(r.denominator) << endl;
	}
	else {
		out << r.numerator << "/" << r.denominator << endl;
	}
	return out;
}
//arithmetic
Rational operator+(Rational& x, Rational& y) {
	Rational result;
	x.numerator = x.numerator * y.denominator;
	y.numerator = y.numerator * x.denominator;
	result.numerator = x.numerator + y.numerator;
	result.denominator = x.denominator * y.denominator;
	long divisor = gcd(result.numerator, result.denominator);
	result.numerator = result.numerator / divisor;
	result.denominator = result.denominator / divisor;
	return result;
}
Rational operator-(Rational& x, Rational& y) {
	Rational result;
	x.numerator = x.numerator * y.denominator;
	y.numerator = y.numerator * x.denominator;
	result.numerator = x.numerator - y.numerator;
	result.denominator = x.denominator * y.denominator;
	long divisor = gcd(result.numerator, result.denominator);
	result.numerator = result.numerator / divisor;
	result.denominator = result.denominator / divisor;
	return result;
}
Rational operator/(Rational& x, Rational& y) {
	Rational result;
	result.numerator = x.numerator * y.denominator;
	result.denominator = x.denominator * y.numerator;
	long divisor = gcd(result.numerator, result.denominator);
	result.numerator = result.numerator / divisor;
	result.denominator = result.denominator / divisor;
	return result;
}
Rational operator*(Rational& x, Rational& y) {
	Rational result;
	result.numerator = x.numerator * y.numerator;
	result.denominator = x.denominator * y.denominator;
	long divisor = gcd(result.numerator, result.denominator);
	result.numerator = result.numerator / divisor;
	result.denominator = result.denominator / divisor;
	return result;
}
int main() {
	Rational num1(21, 2), num2(12, -5),add;
	add = num1 + num2;
	cout << "addition:" << add;
	Rational num3(69, 5), num4(-2, 8), sub;
	sub = num3 - num4;
	cout<< "subtraction:" << sub;
	Rational num5(7, 2), num6(3, 4), div;
	div = num5 / num6;
	cout << "division:" <<div;
	Rational num7(9, 2), num8(32, 1), multi;
	multi = num7 * num8;
	cout << "multiplication:" << multi;
	return 0;
}
