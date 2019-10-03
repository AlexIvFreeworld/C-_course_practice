#include <iostream>
using namespace std;
int main() {
	int start_range, end_range;
	int sum_odd_number = 0;
	int remainder_after_division;
	cout << "\nEnter start range of number : ";
	cin >> start_range;
	cout << "\nEnter end range of number : ";
	cin >> end_range;
	while (start_range <= end_range) {
		remainder_after_division = start_range % 2;
		if (remainder_after_division != 0) {
			sum_odd_number += start_range;
		}
		start_range++;
	}
	cout << "\n\nSum odd numbers = " << sum_odd_number;
	int end_;
	cin >> end_;
	return (0);
}