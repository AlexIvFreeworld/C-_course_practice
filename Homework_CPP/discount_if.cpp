#include <iostream>
using namespace std;
int main() {
	int summ, discount, summ_with_discount;
	cout << "Enter the summ: ";
	cin >> summ;
	if (summ >= 500 && summ <= 1000) {
		discount = 5;
		summ_with_discount = summ - summ * discount / 100;
		cout << "\nYour sum with discount 5% : " << summ_with_discount;
	}
	else {
		if (summ >= 1000 && summ <= 10000) {
			discount = 10;
			summ_with_discount = summ - summ * discount / 100;
			cout << "\nYour sum with discount 10%: " << summ_with_discount;
		}
		else {
			if (summ >= 10000) {
				discount = 20;
				summ_with_discount = summ - summ * discount / 100;
				cout << "\nYour sum with discount 20%: " << summ_with_discount;
			}
			else
				cout << "\nYou have not discount";
		}
	}
	int end_;
	cin >> end_;
}