#include <iostream>
using namespace std;
int main() {
	char arr[10] = { 0 };
	char arr_1[1];
	int sum = 0;
	cout << "Enter up to 10 digits : ";
	cin >> arr;
	for (int i = 0; i <= 9; i++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			arr_1[0] = arr[i];
			sum += atoi (arr_1);
		}
	}
	cout << "Sum digits = " << sum;
	int end_;
	cin >> end_;
	return (0);
}