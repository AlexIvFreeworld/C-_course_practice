#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	const int size = 100;//������ ������ �������
	char str[size];//������� ������ ��� ������
	char ch;//���������� ��� ������
	cout << "\n\nEnter line " << endl;
	gets_s(str);//���������� ��������� ������ � ������
	cout << "\n\nEnter symbol " << endl;
	cin >> ch;//���������� ��������� ������ � ����������
	int k = 0;// ���������� ��� ������ ������� ������� ��� ����������
	for (int i = 0; i < size; i++) {
		if (str[i] == ch) {
			k = i;//��� ������ ���������� ����������� �������� ������� �������
		}
		else if (str[i] == '\0') {//��� ���������� ����� ������ ������� �� �����
			break;
		}
	}
	if (k == 0) {
		cout << "\n\nNot found";//���� �� ���� ���������� ������� ���������
	}
	else {
		cout << "\n\nlast coincidence position : " << (k + 1) << endl;//���� ���������� ���� ������� ��������� �������
	}
	int end_;
	cin >> end_;
	return (0);
}