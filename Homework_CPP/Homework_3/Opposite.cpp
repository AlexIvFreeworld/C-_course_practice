#include <iostream>
using namespace std;
int main() {
	int arr[10] = { 0 };
	int k = 9;
	int i_start, k_end;
	for (int i = 0; i <= k; i++) {
		cout << "Enter number " << (i + 1) << " of 10 : ";
		cin >> arr[i];
	}
	cout << "\n\nFirst array :\n";
		for (int i = 0; i <= k; i++) {
		cout << arr[i] << ",";
	}
	for (int i = 0; i < k; i++) {
		i_start = arr[i];
		k_end = arr[k];
		arr[i] = k_end;
		arr[k] = i_start;
		k--;
	}
	cout << "\n\nIn resalt array :\n";
	k = 9;
	for (int i = 0; i <= k; i++ ) {
		cout << arr[i] << ",";
	}
	int end_;
	cin >> end_;
	return (0);
}