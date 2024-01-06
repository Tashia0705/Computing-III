#include <iostream>
using namespace std;

class MyComplex {
public:
	//accessor and mutator functions
	int getreal();
	int getimg();

	void setreal(double rl);
	void setimg(double img);
	//constructors
	MyComplex();
	MyComplex(double rl);
	MyComplex(double rl, double img);
	//insertion operator
	friend ostream& operator<<(ostream& out, const MyComplex& c);
	//extraction operator
	friend istream& operator>>(istream& in,  MyComplex& c);
	//arithmetic
	friend MyComplex operator+ (const MyComplex& x, const MyComplex& y);
	friend MyComplex operator- (const MyComplex& x, const MyComplex& y);
	friend MyComplex operator* (const MyComplex& x, const MyComplex& y);

	MyComplex operator!();
private:
	double real;
	double imaginary;
};

//accessor and mutator functions
int MyComplex::getreal() {
	return real;
}
int MyComplex::getimg() {
	return imaginary;
}
void MyComplex::setreal(double rl) {
	real = rl;
}
void MyComplex::setimg(double img) {
	imaginary = img;
}
//constructors
MyComplex::MyComplex() {
	real = 0;
	imaginary = 0;
}
MyComplex::MyComplex(double rl) {
	real = rl;
	imaginary = 0;
}
MyComplex::MyComplex(double rl, double img) {
	real = rl;
	imaginary = img;
}

//instertion operator
ostream& operator<<(ostream& out, const MyComplex& c) {
	if (!c.imaginary) {
		out << c.real << endl;
	}
	else if (!c.real) {
		out << c.imaginary << "i" << endl;
	}
	else if(c.imaginary < 0){
		out << c.real << c.imaginary << "i" << endl;
	}
	else {
		out << c.real << "+" << c.imaginary << "i" << endl;
	}
	return out;
}
//extraction operator
istream& operator>>(istream& in, MyComplex& c){
	cout << "enter a comlplex number: ";
	in >> c.real >> c.imaginary;
	return in;
}
//arithmetic functions
MyComplex operator+ (const MyComplex& x, const MyComplex& y) {
	MyComplex result(x.real + y.real, x.imaginary + y.imaginary);
	return result;
}
MyComplex operator- (const MyComplex& x, const MyComplex& y) {
	MyComplex result(x.real - y.real, x.imaginary - y.imaginary);
	return result;
}
MyComplex operator* (const MyComplex& x, const MyComplex& y) {
	double a = x.real;
	double b = x.imaginary;
	double c = y.real;
	double d = y.imaginary;
	MyComplex result((a * c - b * d), (a * d + b * c));
	return result;
}
MyComplex MyComplex::operator!() {
	return MyComplex(this->real, -(this->imaginary));
}
int main() {

	MyComplex x, y(9), z(2, -3);
	cout << x << y << z;
	x.setreal(5);
	x.setimg(7);
	y.setreal(-6);
	y.setimg(-2);
	cout << x << y;

	MyComplex a, sum, subtract, multiply, b(2, 1);
	cin >> a;
	cout << a;
	sum = x + y;
	cout << "Adding two complex numbers:" << sum;
	subtract = x - y;
	cout << "Subtracting two complex numbers:" << subtract;
	multiply = x * y;
	cout << "Multiplying two complex numbers:" << multiply;
	cout << "conjugate number:" << !b;

	return 0;
}
