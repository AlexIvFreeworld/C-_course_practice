#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int fill_arr(int **arr, int n, int m);
int show_arr(int **arr, int n, int m);
int main() {
	int n, m;
	srand(time(NULL));
	cout << "Enter number of rows : ";
	cin >> n;
	cout << "Enter number of colums : ";
	cin >> m;
	int **arr = new int *[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	fill_arr(arr, n, m);
	show_arr(arr, n, m);
	int end_;
	cin >> end_;
	return (0);
}
int fill_arr(int **arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 40 + 10;
		}
	}
	return (0);
}
int show_arr(int **arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	return (0);
}