#include <iostream>
using namespace std;
int main() {
	int price;
	int discount;
	int total;
	cout << "price - ";
	cin >> price;
	cout << "discount - ";
	cin >> discount;
	total = price - price * discount / 100;
	cout << "total = " << total;
	int i;
	cin >> i;
	}