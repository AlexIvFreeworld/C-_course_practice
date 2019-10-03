#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main() {
	srand(time(NULL));
	const int size = 10;
	int exch;
	int arr[size];
	int *p_arr = arr;
	cout << "\nFirst array :" << endl;
	for (int i = 0; i < size; i++) {
		*(p_arr + i) = rand() % 100;
		cout << *(p_arr + i) << "\t";
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (*(p_arr + j) > *(p_arr + j + 1)) {
				exch = *(p_arr + j + 1);
				*(p_arr + j + 1) = *(p_arr + j);
				*(p_arr + j) = exch;
			}
		}
	}
	cout << "\nArray after sort :" << endl;
	for (int i = 0; i < size; i++) {
		cout << *(p_arr + i) << "\t";
	}
	int end_;
	cin >> end_;
	return (0);
}