#include <iostream>
using namespace std;
int take_lost_elem(int arr[]);
int take_lost_elem_2(int arr[]);
int main() {
	int arr[100] = { 3,7,1,2,8,5,9,6 };
	//int arr[100] = { 11,13,5,3,7,1 };
	cout << "lost_elem var-1 = " << take_lost_elem(arr) << endl;
	cout << "lost_elem var-2 = " << take_lost_elem_2(arr) << endl;
	cin.get();
	return 0;
}
int take_lost_elem(int arr[]) {
	int lost_elem, sum_arr_orig=0, sum_arr_full=0, min_arr_orig, max_arr_orig;
	min_arr_orig = arr[0];
	max_arr_orig = arr[0];
	int i = 0;
	while (arr[i]!='\0') {
		arr[i] < min_arr_orig ? min_arr_orig = arr[i] : 0;
		arr[i] > max_arr_orig ? max_arr_orig = arr[i] : 0;
		sum_arr_orig += arr[i];
		i++;
	}
	for (int j = min_arr_orig; j <= max_arr_orig; j++) {
		sum_arr_full+= j;
	}
	lost_elem = sum_arr_full - sum_arr_orig;
	return lost_elem;
}
int take_lost_elem_2(int arr[]) {
	int lost_elem, step;
	int size = 0;
	while (arr[size] != '\0') {
		size++;
	}
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	int sum_step =0, num_step=0;
		for (int i = 0; i < size-1; i++) {
			sum_step += arr[i + 1] - arr[i];
			num_step++;
		}
		step = sum_step / num_step;
	for (int i = 0; i < size - 1; i++) {
		if (arr[i + 1] - arr[i] > step) {
			lost_elem = arr[i] + step;
			break;
}
		}
	return lost_elem;
}