#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	const int amount_columns = 3;
	const int amount_lines = 4;
	int arr[3][4];
	int sum_0 = 0;
	srand(time(NULL));
	for (int i = 0; i < amount_lines; i++) {
		for (int j = 0; j < amount_columns; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << "\t";
			if (arr[i][j] == 0) {
				sum_0++;
			}
		}
		cout << endl;
	}
	cout << "\n\nAmount numbers 0 = " << sum_0;
	int end_;
	cin >> end_;
	return (0);
}