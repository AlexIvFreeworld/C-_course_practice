#include <iostream>
using namespace std;
int translation(int number, int system);
int main() {
	int a, b;
	cout << "Enter number : ";
	cin >> a;
	cout << "Enter the number system from 2 to 36 : ";
	cin >> b;
	translation(a, b);
	int end_;
	cin >> end_;
	return (0);
}
int translation(int number, int system) {
	int arr[100];
	int remainder;
	int result_before = number;
	int result_after;
	for (int i = 0;;i++) {
		if (result_before >= system) {
			result_after = result_before / system;
			remainder = result_before - result_after * system;
			arr[i] = remainder;
			result_before = result_after;
		}
		else {
			break;
		}
	}
	cout << "\n\nThe number " << number << " in the number system " << system << " is : " << result_before;
		for (int i = 99; i >= 0; i--) {
			if (arr[i] >= 0) {
				if (arr[i] >= 10 && arr[i] <= 35) {
					char a;
					switch (arr[i]) {
					case 10: a = 'A';
						break;
					case 11: a = 'B';
						break;
					case 12: a = 'C';
						break;
					case 13: a = 'D';
						break;
					case 14: a = 'E';
						break;
					case 15: a = 'F';
						break;
					case 16: a = 'G';
						break;
					case 17: a = 'H';
						break;
					case 18: a = 'I';
						break;
					case 19: a = 'J';
						break;
					case 20: a = 'K';
						break;
					case 21: a = 'L';
						break;
					case 22: a = 'M';
						break;
					case 23: a = 'N';
						break;
					case 24: a = 'O';
						break;
					case 25: a = 'P';
						break;
					case 26: a = 'Q';
						break;
					case 27: a = 'R';
						break;
					case 28: a = 'S';
						break;
					case 29: a = 'T';
						break;
					case 30: a = 'U';
						break;
					case 31: a = 'V';
						break;
					case 32: a = 'W';
						break;
					case 33: a = 'X';
						break;
					case 34: a = 'Y';
						break;
					case 35: a = 'Z';
						break;
					default: a = arr[i];
					}
					cout << a;
				}
				else {
				cout << arr[i];
			}
		}
	}
	return (0);
}