#include <iostream>
using namespace std;
int main() {
	int fabric_length;
	int pillow_length;
	int amount_pillows = 0;
	cout << "Enter fabric length (m) : ";
	cin >> fabric_length;
	cout << "Enter pillow length (m) : ";
	cin >> pillow_length;
	while (fabric_length >= pillow_length) {
			fabric_length -= pillow_length;
			amount_pillows++;
		}
	cout << "Amount pillows = " << amount_pillows;
	int end_;
	cin >> end_;
	return (0);
}