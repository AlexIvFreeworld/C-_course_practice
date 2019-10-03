#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
template <typename T> T func(T a, T b);
template <typename T> T func(T a, T b, T c);
void main() {
	float a, b, c;
	srand(time(NULL));
	a = rand() % 100;
	b = rand() % 100;
	c = rand() % 100;
	func(a, b);
	func(a, b, c);
	int end_;
	cin >> end_;
}
template <typename T> T func(T a, T b) {
	T res;
	res = (-b) / a;
	cout << "\n\nFor\n" << a << "x + " << b << " = 0" << " \nx = " << res;
	return (0);
}
template <typename T> T func(T a, T b, T c) {
	T D, res_1, res_2;
	D = b * b - 4 * a * c;
	if (D > 0) {
		res_1 = (-b - sqrt(D)) / (a * 2);
		res_2 = (-b - sqrt(D)) / (a * 2);
		cout << "\n\nFor\n" << a << "x2 + " << b << "*x" << " + " << c << " = 0" << " \nx1 = " << res_1 << " x2 = " << res_2;
	}
	else if (D < 0) {
		cout << "\n\nFor\n" << a << "x2 + " << b << "*x" << " + " << c << " = 0" << " \nNo roots";
	}
	else if (D == 0) {
		res_1 = (-b - sqrt(D)) / (a * 2);
		cout << "\n\nFor\n" << a << "x2 + " << b << "*x" << " + " << c << " = 0" << " \nx = " << res_1;
	}
	return (0);
}