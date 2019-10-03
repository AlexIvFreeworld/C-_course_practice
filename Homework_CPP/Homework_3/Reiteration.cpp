#include <iostream>
using namespace std;
int main() {
	int arr[10] = { 0 };
	int arr_reiterations[10] = { 0 };
	int k = 9;
	int amount_reiterations = 0;
	int i_arr_reiterations = 0;
	for (int i = 0; i <= k; i++) {
		cout << "Enter number " << (i + 1) << " of 10 : ";
		cin >> arr[i];
	}
	cout << "\n\nFirst array :\n";
	for (int i = 0; i <= k; i++) {
		cout << arr[i] << ",";
	}
	for (int i = 0; i <= k; i++) {
		int amount_reiterations = 0;
		for (int j = i; j <= k; j++) {
			if (i != j && arr[i] == arr[j]) {
				amount_reiterations++;
			}
		}
		if (amount_reiterations == 1) {
			arr_reiterations[i_arr_reiterations] = arr[i];
			i_arr_reiterations++;
		}
}
	cout << "\n\nRepeating numbers : ";
	if (i_arr_reiterations == 0) {
		cout << "are not";
	}
	else {
		for (int i = 0; i <= i_arr_reiterations - 1; i++) {
			cout << arr_reiterations[i] << ",";
		}
	}
	int end_;
	cin >> end_;
	return (0);
}