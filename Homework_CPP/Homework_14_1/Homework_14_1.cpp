#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
char *revers_copy(char str[]);
char *revers_origin(char *str);
void show_str(char str[]);
int main() {
	char str_orig[100] = "Hello";
	cout << "--------------Return Copy str_orig-----------------------" << endl;
	show_str(str_orig);
	show_str(revers_copy(str_orig));
	cout << "--------------Return Origin str_orig---------------------" << endl;
	show_str(str_orig);
	show_str(revers_origin(str_orig));
	cin.get();
}
char *revers_copy(char str[]) {
	int size = strlen(str)+1;
	char *P_str_copy = new char[size];
	strcpy(P_str_copy, str);
	char temp;
	for (int i = 0; i < (float)(size-2) / 2; i++) {
		temp = P_str_copy[i];
		P_str_copy[i] = P_str_copy[size-2-i];
		P_str_copy[size - 2 - i] = temp;
	}
	return P_str_copy;
	delete []P_str_copy;
}
char *revers_origin(char *str) {
	int size = strlen(str) + 1;
	char temp;
	for (int i = 0; i < (float)(size - 2) / 2; i++) {
		temp = str[i];
		str[i] = str[size - 2 - i];
		str[size - 2 - i] = temp;
	}
	return str;
}
void show_str(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		cout << str[i];
		i++;
	}
	cout << endl;
}