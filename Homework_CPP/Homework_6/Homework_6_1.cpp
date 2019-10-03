#include <iostream>
using namespace std;
void main() {
	const int size = 10;
	int arr[size];
	cout << "\n\nArray before sort :" << endl;
	for (int i = 0; i < size; i++) {
		arr[i] = i+1;
		cout << arr[i] << "\t";
	}
	int *p = arr;
	int exch;
	for (int i = 0; i < size; i+=2) {
		exch = *(p+i);
		*(p+i) = *(p + i + 1);
		*(p + i + 1) = exch;
	
	}
	cout << "\n\nArray after sort :" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	int end_;
	cin >> end_;
}