#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	const int size = 100;//������ ������ �������
	char str[size];//������� ������ ��� ������
	cout << "\nEnter line : " << endl;
	gets_s(str);//���������� ��������� ������ � ������
	int j = 0;//���������� ��� ���������� ��������� ������
	while (str[j] != '\0') {
		j++;//������� �������� ������
}
	cout << "\n\nNumber of all elements : " << size << endl;//������� ������ �������
	cout << "\n\nNumber of occupied array elements : " << j << endl;//������� ���������� ������� ����� �������
	cout << "\n\nNumber of free array elements : " << size - 1 - j << endl;//������� ������ ������  � ������ ���� ��� ���� ����� ��� ������ ����� ������ '\0' ������� ���������
	int end_;
	cin >> end_;
	return (0);
}