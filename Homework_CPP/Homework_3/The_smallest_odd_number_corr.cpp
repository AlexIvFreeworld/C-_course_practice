#include <iostream>
using namespace std;
int main() {
	int arr[10] = { 0 };
	int k = 9;
	for (int i = 0; i <= k; i++) {
		cout << "Enter number " << (i + 1) << " of 10 : ";
		cin >> arr[i];
	}
	cout << "\n\nFirst array :\n";
	for (int i = 0; i <= k; i++) {
		cout << arr[i] << ",";
	}
	int min = arr[0];
	for (int i = 0; i <= k; i++) {
			if (arr[i] <= min && arr[i]%2 != 0) {
				min = arr[i];
			}
		}
	if (min % 2 != 0) {
		cout << "\n\nThe smallest odd number is " << min;
	}
	else {
		cout << "\n\nThe smallest odd number is not";
	}
	int end_;
	cin >> end_;
	return (0);
}