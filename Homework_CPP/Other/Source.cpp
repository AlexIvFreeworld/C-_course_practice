#include <iostream> // Подключение библиотеки ввода вывода
using namespace std; // Пространство имен. свои переменные
// Main fuction TO DO
void main()
{
	cout<< "Hello, world\n";
	"<< endl";
	cout << "Hello, world2\b";
	cout << "Hello, world2\t-tab";
	cout << "Hello, world2\\";
	cout << "Hello, world2\"";
	cout << "Hello, world2\'";
	int j;
	int i = 5;
	short m = 50000;
	cout << i << "\t" << sizeof(i);
	cout << "\n";
	cout << m << "\t" << sizeof(m);
	float v = 5.456;
	cout << "\n";
	cout << v << "\t" << sizeof(v);
	double v1 = 10.6789;
	cout << "\n";
	cout << v1 << "\t" << sizeof(v1);
	char v2 = 'a';
	cout << "\n";
	cout << v2 << "\t" << sizeof(v2)<<"\t"<<(int)v2;
	bool v3 = true;
	cout << "\n";
	cout << v3 << "\t" << sizeof(v3) << "\t" << (int)v3;
	const int day_19 = 365;
	const int hour = 24;
	const int millsecund_hour = 3600000;
	int amount_millsecund_19;
	amount_millsecund_19 = day_19*hour*millsecund_hour;
	cout << "\n"<< "amount_millsecund_19 "<< amount_millsecund_19;
	int price = 9999;
	int disc;
	float price_with_disc;
	cout << "\n";
	cin >> disc;
	price_with_disc = price-price*disc/100;
	cout << "\n" << "price_with_disc " << price_with_disc;
	int a = 5;
	cout << a++;
	cout << ++a;
	cin >> j;
}
 /*Многострочный комментарий*/