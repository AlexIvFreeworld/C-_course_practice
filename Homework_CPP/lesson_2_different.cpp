#include <iostream>
using namespace std;
int main() {
	int N;
	cout << "Enter digit\n\n";
	cin >> N;
	cout << "\n\n" << ((N >= 1) && (N <= 10));
	cout << "\n\n If you see 1 your digit is in diapazon\n\n";
	cout << "\n\n If you see 0 your digit is not in diapazon\n\n";
	cout << "Enter digit\n\n";
	int M;
	cout << "Enter digit\n\n";
	cin >> M;
	cout << "\n\n" << ((M < 1) || (M > 10));
	cout << "\n\n If you see 0 your digit is in diapazon\n\n";
	cout << "\n\n If you see 1 your digit is not in diapazon\n\n";
	cout << !(5 == 3) << "\n\n";
	cout << !(3 != 2) << "\n\n";
	int X = 10, Y = 15;
	if (X > Y) {
		cout << "Test!!!!";
	}
	int A = 10, B = 5, C = 12;
	if (A > B && A < C) {
		cout << "A between B and C\n\n";
	}
	int A1 = 10, B1 = 15;
	if (A1 - B1) {
		cout << "A1 != B1\n\n";
	}
	int A2 = 0;
	if (++A2) {
		cout << "Best test!!!!\n\n";
	}
	int A3, B3;
	cout << "Enter first digit:\n";
	cin >> A3;
	cout << "Enter second digit:\n";
	cin >> B3;
	(B3 != 0) ? cout << "Result A3/B3= " << A3 << "/" << B3 << "=" << A3 / B3 << "\n" : cout << "You can't divide by zero!!!!\n";
	int A4, B4;
	cout << "Enter first digit:\n";
	cin >> A4;
	cout << "Enter second digit:\n";
	cin >> B4;
	int max = (A4 > B4) ? A4 : B4;
	int min = (A4 < B4) ? A4 : B4;
	cout << "\nMaximum :" << max << "\nMinimum :" << min << '\n';
	int end_;
	cin >> end_;
}