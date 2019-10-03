#include <iostream>
using namespace std;
int main() {
	char arr[10] = { 0 };
	int sum = 0;
	cout << "Enter up to 10 digits : ";
	cin >> arr;
		for (int i = 0; i <= 9; i++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			sum += (arr[i]-'0');
		}
		else if (arr[i] == '-' ) {
			sum -= (arr[i+1] - '0');
			i++;
			}
	}
	cout << "Sum digits = " << sum;
	int end_;
	cin >> end_;
	return (0);
}