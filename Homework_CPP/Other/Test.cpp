#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	//int arr[5];
	//for (int i = 0; i <= 4; i++) {
	//	cout << "\nEnter i : ";
	//	cin >> arr[i];
	//}
	////int min = arr[0];
	////for (int i = 0; i <= 4; i++) {

	////	if (min > arr[i]) {
	////		min = arr[i];
	////	}
	////}
	////cout << "\nMIN = " << min;
	//int even_number = 0, odd_number = 0;
	//for (int i = 0; i <= 4; i++) {
	//	if (arr[i] % 2 == 0) {
	//		even_number += arr[i];
	//	}
	//	else {
	//		odd_number += arr[i];
	//	}
	//}
	//cout << "\nSum even number = " << even_number << "\nSum odd number = " << odd_number;
	srand(time(NULL));
	int a, b;
	for (int i = 0; i <= 10; i++) {
		a = rand() % 11 + 100;
		b = rand() % 11;
		cout << "\nrandom namber = " << a << "\t" << b;
	}
	int end_;
	cin >> end_;
	return (0);
}