#include <iostream>
using namespace std;
int main() {
	const double PI = 3.141592;
	double radius, circumference, area;
	cout << "Welcom to program of work with rounds\n\n";
	cout << "Put the radius from rounds\n\n";
	cin >> radius;
	cout << "\n\n";
	area = PI * radius * radius;
	circumference = PI * (radius * 2);
	cout << "Square of round " << area << "\n\n";
	cout << "Lenght of round " << circumference << "\n\n";
	cout << "Thanks!!!!! Bye!!!!\n\n";
	int i;
	cin >> i;
}