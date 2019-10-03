#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int fill_arr(int **arr, int n, int m); //��������� ������ ���������� �������
int show_arr(int **arr, int n, int m); //������� ������ �� �����
int shift_arr(int **arr, int n, int m, int t, int d);//�������� �������� ������� �� ���� ���
int main() {
	int n, m, num, t, d;//n - ����� �����, m - ����� ��������, num - ����� �������, t - ����� ����� ��� �������� ��� ������, d - ����� ����������� ������
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
	int **arr = new int *[n]; //�������� ������������� �������
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	fill_arr(arr, n, m);
	show_arr(arr, n, m);
	for (int i = 1; i <= num; i++) {
		shift_arr(arr, n, m, t, d); //����� ������� ������ �������� ���������� num
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
	int *p_exch = new int;//�������� ����� ��� ���������� �������� �������� ������ �������
	if (t == 1) {
		if (d == -1) {//����� �������� �����
			for (int i = 0; i < n; i++) {//������ �� �������
				*p_exch = arr[i][0];//������ ������� ������� � �����
				for (int j = 0; j < (m-1); j++) {
					arr[i][j] = arr[i][j + 1];//������ �������� �������� ������ �� �������� ���������� �� ��� ��������  
				}
				arr[i][m - 1] = *p_exch;//������ �������� ���������� �������� �� �������� ������� 
			}
		}
		else if (d == 1) {//����� �������� ������
			for (int i = 0; i < n; i++) {
				*p_exch = arr[i][m-1];//������ ���������� ������� � �����
				for (int j = m-1; j > 0; j--) {
					arr[i][j] = arr[i][j - 1];//������ �������� �������� ������ �� �������� ����������� �������� 
				}
				arr[i][0] = *p_exch;//������ �������� ������� �������� �� �������� ���������� 
			}
		}
	}
	else if (t == -1) {
		if (d == -1) {//����� ����� �����
			for (int i = 0; i < m; i++) {//������ �� �������� ���������� ������� �� �������
				*p_exch = arr[0][i];
				for (int j = 0; j < (n-1); j++) {
					arr[j][i] = arr[j + 1][i];
				}
				arr[n-1][i] = *p_exch;
			}
		}
		else if (d == 1) {//����� ����� ������
			for (int i = 0; i < m; i++) {//������ �� �������� ���������� ������� �� �������
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
