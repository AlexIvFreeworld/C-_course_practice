#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
template <typename T, typename T1> T average(T arr[], T1 size);
void main() {
	srand(time(NULL));
	const int size = 10;
	float arr_a[size];
	for (int i = 0; i < size; i++) {
		arr_a[i] = (rand() % 10)+(rand() % 10)*0.1;
		cout << arr_a[i] << "\t";
	}
	cout << "\n\nAverage = " << average(arr_a, size);
	int end_;
	cin >> end_;
}
template <typename T, typename T1> T average(T arr[], T1 size) {
	int i;
	T sum = 0;
	for (i = 0; i < size; i++) {
		sum += arr[i];
	}
	return (sum / size);
}