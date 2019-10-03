#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int fill_arr(int **arr, int n, int m); //заполн€ет массив случайными числами
int show_arr(int **arr, int n, int m); //выводит массив на экран
int shift_arr(int **arr, int n, int m, int t, int d);//сдвигает элементы массива на один шаг
int main() {
	int n, m, num, t, d;//n - число строк, m - число столбцов, num - число сдвигов, t - выбор строк или столбцов дл€ сдвига, d - выбор направлени€ сдвига
	srand(time(NULL));
	cout << "Enter number of rows :";
	cin >> n;
	cout << "Enter number of colums :";
	cin >> m;
	cout << "Enter type of shift rows (-1), columns (1) :";
	cin >> t;
	cout << "Enter direction of shift back (-1), forward (1) :";
	cin >> d;
	cout << "Enter number of shifts :";
	cin >> num;
	int **arr = new int *[n]; //создание динамического массива
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	fill_arr(arr, n, m);
	show_arr(arr, n, m);
	for (int i = 1; i <= num; i++) {
		shift_arr(arr, n, m, t, d); //вызов функции сдвига заданное количество num
	}
	cout << endl;
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
int shift_arr(int **arr, int n, int m, int t, int d) {
	int *p_exch = new int;//создание места дл€ временного хранени€ значени€ €чейки массива
	if (t == 1) {
		if (d == -1) {//сдвиг столбцов назад
			for (int i = 0; i < n; i++) {//проход по строкам
				*p_exch = arr[i][0];//запись первого элемнта в обмен
				for (int j = 0; j < (m-1); j++) {
					arr[i][j] = arr[i][j + 1];//замена значени€ элемента строки на значение следующего за ним элемента  
				}
				arr[i][m - 1] = *p_exch;//замена значени€ последнего элемента на значение первого 
			}
		}
		else if (d == 1) {//сдвиг столбцов вперед
			for (int i = 0; i < n; i++) {
				*p_exch = arr[i][m-1];//запись последнего элемнта в обмен
				for (int j = m-1; j > 0; j--) {
					arr[i][j] = arr[i][j - 1];//замена значени€ элемента строки на значение предидущего элемента 
				}
				arr[i][0] = *p_exch;//замена значени€ первого элемента на значение последнего 
			}
		}
	}
	else if (t == -1) {
		if (d == -1) {//сдвиг строк назад
			for (int i = 0; i < m; i++) {//проход по столбцам аналогично проходу по строкам
				*p_exch = arr[0][i];
				for (int j = 0; j < (n-1); j++) {
					arr[j][i] = arr[j + 1][i];
				}
				arr[n-1][i] = *p_exch;
			}
		}
		else if (d == 1) {//сдвиг строк вперед
			for (int i = 0; i < m; i++) {//проход по столбцам аналогично проходу по строкам
				*p_exch = arr[n-1][i];
				for (int j = (n-1); j > 0; j--) {
					arr[j][i] = arr[j - 1][i];
				}
				arr[0][i] = *p_exch;
			}
		}
	}
	return(0);
}
