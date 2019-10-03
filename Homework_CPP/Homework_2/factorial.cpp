#include <iostream>
using namespace std;
int main() {
	int factorial = 1;
	int range;
	cout << "Enter range from 0 to infinity : ";
	cin >> range;
	while (range > 1) {
		factorial = factorial * range;
		range--;
	}
	cout << "Factorial = " << factorial;
	int end_;
	cin >> end_;
	return (0);
}