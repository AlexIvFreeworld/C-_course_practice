#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	const int size = 100;//������ ������ �������
	char str[size];//������� ������ ��� ������
	char ch;//���������� ��� ������
	cout << "\n\nEnter any line " << endl;
	gets_s(str);//���������� ��������� ������ � ������
	cout << "\n\nEnter any symbol " << endl;
	cin >> ch;//���������� ��������� ������ � ����������
	int k = 0;// ���������� ��� ������ ���������� ����������
	cout << "\n\nCoincidences positions :" << endl;
	for (int i = 0; i < size; i++) {
		if (str[i] == ch) {
			cout << (i + 1) << "\t";//��� ���������� ������� �� ����� ������� ������� � ������
			k++;
		}
		else if (str[i] == '\0') {//��� ���������� ����� ������ ������� �� �����
			break;
		}
	}
	if (k == 0) {//���� �� ���� ���������� ������� ���������
		cout << "\n\nSymbol not found";
	}
	int end_;
	cin >> end_;
	return (0);
}