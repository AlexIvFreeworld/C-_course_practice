#include <iostream>
using namespace std;
void main() {
	int inch; //diagonal in inches
	float cent; //diagonal in centimeters
	int cent_round; //diagonal in centimeters, integer value
	int c; // fractional part of cent
	const float cent_in_inch = 2.54;
	cout << "Enter the diagonal in inches:\n";
	cin >> inch;
	cent = inch * cent_in_inch;
	cent_round = (int)cent;
	c = (cent * 100) - (cent_round * 100);
	(c >= 50) ? cent_round++ : cent_round = (int)cent; //round cent_round up or down
	cout << "Diagonal in centimeters: " << "\t" << cent_round;
	int end_;
	cin >> end_;
}