#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int func(int arr[]);
void main() {
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	cout << "\n\nFirst array : " << endl;
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n";
	func(arr);
	int end_;
	cin >> end_;
}
int func(int arr[]) {
	srand(time(NULL));
	int exch, j;
	for (int i = 0; i < 20; i++ ) {
		j = rand() % 19 + 1;
		exch = arr[i];
		arr[i] = arr[j];
		arr[j] = exch;
		}
	cout << "\n\nPost-scatter array :" << endl;
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << "\t";
	}
	j = rand() % 19 + 1;
	int random_number = arr[j];
	int k;
	for (int i = 0; i < 20; i++) {
		if (random_number == arr[i]) {
			k = i;
}
	}
	cout << "\n\nRandom_number is " << random_number << "\nIndex random number is " << k << endl;
	int right = k-1;
	int left = k + 1;
	int size = 19;
	for (int i = 0; i < right; i++) {
		for (int j = 0; j < (right-i); j++) {
			if (arr[j] < arr[j+1]) {
				exch = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = exch;
			}
		}
	}
	int b = 0;
	for (int i = size; i > left; i--) {
		for (int j = size; j > (left+b); j--) {
			if (arr[j] < arr[j - 1]) {
				exch = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = exch;
			}
		}
		b++;
	}
	cout << "\n\nArray after Left sort :" << endl;
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << "\t";
	}
	return (0);
}