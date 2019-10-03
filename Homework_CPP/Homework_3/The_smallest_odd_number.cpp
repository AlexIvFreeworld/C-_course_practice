#include <iostream>
using namespace std;
int main() {
	int arr[10] = { 0 };
	int arr_sort[10] = { 0 };
	int k = 9;
	for (int i = 0; i <= k; i++) {
		cout << "Enter number " << (i + 1) << " of 10 : ";
		cin >> arr[i];
	}
	cout << "\n\nFirst array :\n";
	for (int i = 0; i <= k; i++) {
		cout << arr[i] << ",";
	}
	for (int i = 0; i <= k; i++) {
		int amount_true_more = 0;
		for (int j = 0; j <= k; j++) {
			if (arr[i] > arr[j]) {
				amount_true_more++;
			}
		}
				arr_sort[amount_true_more] = arr[i];
	}
	cout << "\n\nSmallest odd number : ";
	k = 9;
	for (int i = 0; i <= k; i++) {
		if ((arr_sort[i] % 2) != 0) {
			cout << arr_sort[i];
			break;
		}
		else if (i == k) {
			cout << "is not";
		}
	}
	int end_;
	cin >> end_;
	return (0);
}