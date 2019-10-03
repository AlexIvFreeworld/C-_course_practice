#include <iostream>
using namespace std;
int main() {
	char arr[10] = { 0 };
	int sum = 0;
	cout << "Enter up to 10 digits : ";
	cin >> arr;
	if (arr[0] == '-') {
		sum -= (arr[1] - '0');
	}
	for (int i = 0; i <= 9; i++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			sum += (arr[i] - '0');
		}
	}
	cout << "Sum digits = " << sum;
	int end_;
	cin >> end_;
	return (0);
}