#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int sidea;
	int sideb;
	int sidec;

	cout << "please enter the 3 sides of a triangle (all value should be positive):\n";
	cout << "Please enter side 1:\n";
	cin >> sidea;
	cout << "Please enter side 2:\n";
	cin >> sideb;
	cout << "Please enter side 3:\n";
	cin >> sidec;
	if ((sidea || sideb || sidec) == 0) {
		return 0;
	}

	if (((sidea == sideb) || (sidea == sidec) || (sideb == sidec))) {
		if ((sidea == sideb) && (sidea == sidec)) {
			cout << sidea << " " << sideb << " " << sidec << " Equilateral triangle";
			return 0;
		}
		cout << sidea << " " << sideb << " " << sidec << " Isosceles triangle";
	}

	if ((sidea != sideb) && (sidea != sidec)) {
		cout << sidea << " " << sideb << " " << sidec << " Scalene triangle";
		return 0;
	}



	return 0;
}
