#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	const int size = 100;//задаем размер массива
	char str[size];//создаем массив под строку
	cout << "\nEnter line : " << endl;
	gets_s(str);//записываем введенную строку в массив
	int j = 0;//переменная для количества элементов строки
	while (str[j] != '\0') {
		j++;//считаем элементы строки
}
	cout << "\n\nNumber of all elements : " << size << endl;//выводим размер массива
	cout << "\n\nNumber of occupied array elements : " << j << endl;//выводим количество занятых ячеек массива
	cout << "\n\nNumber of free array elements : " << size - 1 - j << endl;//считаем пустые ячейки  с учетом того что одна будет под символ конца строки '\0' выводим результат
	int end_;
	cin >> end_;
	return (0);
}