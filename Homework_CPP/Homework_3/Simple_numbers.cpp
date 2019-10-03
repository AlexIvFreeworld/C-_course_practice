#include <iostream>
using namespace std;
int main() {
	int arr_simple_numbers[1000] = { 0 };
	int k = 0;
	for (int i = 2; i <= 1000; i++) {
		int amount_true = 0;
			for (int j = 1; j <= i; j ++) {
			if ((i%j) == 0 && j != 1 && i != j) {
				amount_true++;
		}
		}
		if (amount_true == 0) {
			arr_simple_numbers [k] = i;
			k++;
					}
	}
	for (int i = 0; i <= 1000; i++) {
		if (arr_simple_numbers[i] > 0 && arr_simple_numbers[i] <= 1000) {
			cout << arr_simple_numbers[i] << ",";
		}
	}
	int end_;
	cin >> end_;
	return (0);
}