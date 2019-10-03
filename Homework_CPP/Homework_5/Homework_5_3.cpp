#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
template <typename T, typename T1> T func(T a, T1 n);
void main() {
	long double a;
	int n;
	srand(time(NULL));
	a = rand() % 100 + (rand() % 10)/10.0 + (rand() % 10) / 100.0 + (rand() % 10) / 1000.0 + (rand() % 10) / 10000.0 + (rand() % 10) / 100000.0;
	cout << "Enter amount signs for number " << a << "\n";
	cin >> n;
	cout << "\nRes = " << func(a, n);
	int end_;
	cin >> end_;
}
template <typename T, typename T1> T func(T a, T1 n) {
	T res, res_2;
	int num, num_2, m_2;
	int m = 1;
	for (int i = 1; i <= n; i++) {
		m *= 10;
		m_2 = m * 10;
	}
	num = a * m;
	num_2 = a * m_2;
	res = (double)num / m;
	res_2 = (double)num_2 / m_2;
	if ((res_2 - res) * m_2 >= 4.9) {
		res += 1 / (double)m;
	}
	return (res);
}