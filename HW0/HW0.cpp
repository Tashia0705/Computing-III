#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

	cout << "Hello, world\n";
	if (argc == 1) {
		cout << "there were no arguments passed\n";
	}
	else {
		for (int i = 0; i < argc; i++) {
			cout << "argv[" << i <<"] = " << argv[i] << endl;
		}
	}
	return 0;
}
