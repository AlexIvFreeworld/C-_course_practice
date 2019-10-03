#include <iostream>
using namespace std;
void main() {
	int capacity_phone;
	int capacity_powerbank;
	const int amount_day = 3;
	cout << "Enter the capacity of your smartphone mAh: \n";
	cin >> capacity_phone;
	capacity_powerbank = capacity_phone * amount_day;
	cout << "Minimum battery capacity for charging three times: " << capacity_powerbank << " mAh\n";
	int end_;
	cin >> end_;
}