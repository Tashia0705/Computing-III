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
	if (c.imaginary < 0) {
		out << c.real << c.imaginary << "i" << endl; 
	}
	else {
		out << c.real << "+" << c.imaginary << "i" << endl;
	}
	return out;
}
int main() {
	
	MyComplex x, y(9), z(2,-3);
	cout << x << y << z;
	x.setreal(5);
	x.setimg(7);
	y.setreal(-6);
	y.setimg(-2);
	cout << x << y;

	return 0;
}
