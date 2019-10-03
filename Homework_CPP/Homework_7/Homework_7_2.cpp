#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	const int size = 100;//задаем размер массива
	char str[size];//создаем массив под строку
	char ch;//переменная под символ
	cout << "\n\nEnter any line " << endl;
	gets_s(str);//записываем введенную строку в массив
	cout << "\n\nEnter any symbol " << endl;
	cin >> ch;//записываем введенный символ в переменную
	int k = 0;// переменная для записи количества совпадений
	cout << "\n\nCoincidences positions :" << endl;
	for (int i = 0; i < size; i++) {
		if (str[i] == ch) {
			cout << (i + 1) << "\t";//при совпадении выводим на экран позицию символа в строке
			k++;
		}
		else if (str[i] == '\0') {//при достижении конца строки выходим из цикла
			break;
		}
	}
	if (k == 0) {//если не было совпадений выводим сообщение
		cout << "\n\nSymbol not found";
	}
	int end_;
	cin >> end_;
	return (0);
}