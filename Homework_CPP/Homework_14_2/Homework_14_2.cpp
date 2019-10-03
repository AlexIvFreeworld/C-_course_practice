#include <iostream>
using namespace std;
int main() {
	int a = 9998;
	int b = 9999;
	cout << "a = " << a << "\t" << "b = " << b << endl;
	if (b < 10000 && a < 10000 && a < b) {
		a = b * 10000 + a;
		b = a % b;
		a = a / 10000;
		cout << "a = " << a << "\t" << "b = " << b << endl;
	}
	else if (b < 10000 && a < 10000 && a > b) {
		b = a * 10000 + b;
		a = b % a;
		b = b / 10000;
		cout << "a = " << a << "\t" << "b = " << b << endl;
	}
	else {
		cout << "Number a or b too big..." << endl;
	}
	cin.get();
	return 0;
}