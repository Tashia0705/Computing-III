#include <iostream>
using namespace std;

template <class T>
class MyComplex {
public:
	MyComplex();
	MyComplex(T rl);
	MyComplex(T rl, T img);
	T getReal();
	T getImaginary();
	void setReal(T rl);
	void setImaginary(T img);

	template <class T1>friend ostream& operator<< (ostream& out, const MyComplex<T1>& c);
	template <class T1>friend istream& operator>> (istream& in, MyComplex<T1>& c);

	template <class T1>friend MyComplex<T1> operator+ (const MyComplex<T1>& x, const MyComplex<T1>& y);
	template <class T1>friend MyComplex<T1> operator- (const MyComplex<T1>& x, const MyComplex<T1>& y);
	template <class T1>friend MyComplex<T1> operator* (const MyComplex<T1>& x, const MyComplex<T1>& y);
	template <class T1>friend MyComplex<T1> operator/ (const MyComplex<T1>& x, const MyComplex<T1>& y);
	MyComplex<T> operator!();

	template <class T1>friend MyComplex<T1> operator+ (T1 x, const MyComplex<T1>& y);
	template <class T1>friend MyComplex<T1> operator- (T1 x, const MyComplex<T1>& y);
	template <class T1>friend MyComplex<T1> operator* (T1 x, const MyComplex<T1>& y);

	template <class T1>friend MyComplex<T1> operator+ (const MyComplex<T1>& x, T1 y);
	template <class T1>friend MyComplex<T1> operator- (const MyComplex<T1>& x, T1 y);
	template <class T1>friend MyComplex<T1> operator* (const MyComplex<T1>& x, T1 y);
	template <class T1>friend MyComplex<T1> operator/ (const MyComplex<T1>& x, T1 y);
private:
	T real;
	T imaginary;
};

//Default constructor and other consturctors
template <class T>
MyComplex<T>::MyComplex() {
	real = 0;
	imaginary = 0;
}

template <class T>
MyComplex<T>::MyComplex(T rl) {
	real = rl;
	imaginary = 0;
}

template <class T>
MyComplex<T>::MyComplex(T rl, T img) {
	real = rl;
	imaginary = img;
}
//Accessor and mutator functions
template <class T>
T MyComplex<T>::getReal() {
	return real;
}

template <class T>
T MyComplex<T>::getImaginary() {
	return imaginary;
}

template <class T>
void MyComplex<T>::setReal(T rl) {
	real = rl;
}

template <class T>
void MyComplex<T>::setImaginary(T img) {
	imaginary = img;
}

//Overloaded version of insertion operator
template <class T>
ostream& operator<< (ostream& out, const MyComplex<T>& c) {
	if (!c.imaginary) {
		out << c.real;
	}
	else if (!c.real) {
		out << c.imaginary << "i";
	}
	else if (c.imaginary < 0) {
		out << c.real << c.imaginary << "i";
	}
	else {
		out << c.real << "+" << c.imaginary << "i";
	}
	return out;
}

//Overloaded version of extraction operator
template <class T>
istream& operator>> (istream& in, MyComplex<T>& c) {
	cout << "Enter complex numbers: ";
	in >> c.real >> c.imaginary;
	return in;
}

//Arithmetic functions (+, -, *,/)
template <class T>
MyComplex<T> operator+ (const MyComplex<T>& x, const MyComplex<T>& y) {
	MyComplex<T> result(x.real + y.real, x.imaginary + y.imaginary);
	return result;
}

template <class T>
MyComplex<T> operator- (const MyComplex<T>& x, const MyComplex<T>& y) {
	MyComplex<T> result(x.real - y.real, x.imaginary - y.imaginary);
	return result;
}

template <class T>
MyComplex<T> operator* (const MyComplex<T>& x, const MyComplex<T>& y) {
	T a = x.real;
	T b = x.imaginary;
	T c = y.real;
	T d = y.imaginary;
	MyComplex<T> result((a * c - b * d), (a * d + b * c));
	return result;
}

template <class T>
MyComplex<T> operator/ (const MyComplex<T>& x, const MyComplex<T>& y) {
	T a = x.real;
	T b = x.imaginary;
	T c = y.real;
	T d = y.imaginary;
	MyComplex<T> result((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d));
	return result;
}

//Function that returns the cojugate
template <class T>
MyComplex<T> MyComplex<T>::operator!() {
	return MyComplex<T>(this->real, -(this->imaginary));
}
//Functions with first operand as double
template <class T>
MyComplex<T> operator+ (T x, const MyComplex<T>& y) {
	MyComplex<T> result(y.real + x, y.imaginary);
	return result;
}

template <class T>
MyComplex<T> operator- (T x, const MyComplex<T>& y) {
	MyComplex<T> result(x - y.real, y.imaginary);
	return result;
}

template <class T>
MyComplex<T> operator* (T x, const MyComplex<T>& y) {
	MyComplex<T> result(y.real * x, y.imaginary * x);
	return result;
}

//Functions with second operand as double
template <class T>
MyComplex<T> operator/ (const MyComplex<T>& x, T y) {
	MyComplex<T> result((x.real / y), (x.imaginary / y));
	return result;
}

template <class T>
MyComplex<T> operator+ (const MyComplex<T>& x, T y) {
	MyComplex<T> result(x.real + y, x.imaginary);
	return result;
}

template <class T>
MyComplex<T> operator- (const MyComplex<T>& x, T y) {
	MyComplex<T> result(x.real - y, x.imaginary);
	return result;
}

template <class T>
MyComplex<T> operator* (const MyComplex<T>& x, T y) {
	MyComplex<T> result(x.real * y, x.imaginary * y);
	return result;
}
int main(int argc, const char* argv[]) {
	
	MyComplex<double> num1, num2(2.7), num3(4.5, 5.3);
	cout << "Test Number 1: " << num1 << endl;
	cout << "Test Number 2: " << num2 << endl;
	cout << "Test Number 3: " << num3 << endl;
	
	MyComplex<double> num4, num5;
	num3.setReal(-6.0);
	cout << "Test Number 3: " << num3 << endl;
	num4.setReal(42.0);
	num4.setImaginary(-24);
	cout << "Test Number 4: " << num4 << endl;
	num5.setImaginary(20.8);
	cout << "Test Number 5: " << num5 << endl;
	
	MyComplex<double> num6;
	cin >> num6;
	cout << "Test Number 6: " << num6 << endl;
	
	MyComplex<double>sum, sub, multiply;
	sum = num2 + num6;
	cout << "Sum: " << sum << endl;
	sub = num3 - num6;
	cout << "Difference: " << sub << endl;
	multiply = num2 * num6;
	cout << "Product: " << multiply << endl;
	
	num6 = !num6;
	cout << "Test conjugate of Number 6: " << num6 << endl;
	
	MyComplex<int> num7(6, 9), num8(20, 16);
	MyComplex<int> div, sum2, multiply2, sub2;
	div = num8 / num7;
	cout << "Remainder: " << div << endl;
	div = num8 / 4;
	cout << "Remainder of Complex and Double: " << div << endl;
	sum2 = num8 + 6;
	cout << "Sum of Complex and Double: " << sum2 << endl;
	sub2 = 10 - num7;
	cout << "Difference of Complex and Double: " << sub2 << endl;
	multiply2 = num8 * 5;
	cout << "Product of Complex and Double: " << multiply2 << endl;
	return 0;
}
