#include <iostream>
using namespace std;
int FibIter(int N);
int FibRecur(int N);
void main() {
	int n;
	cout << "\n\nFind the fibonacci number with FibIter for n = ";
	cin >> n;
	cout << "\n\nFibonacci number = " << FibIter(n);
	cout << "\n\nFind the fibonacci number with FibRecur for n = ";
	cin >> n;
	cout << "\n\nFibonacci number = " << FibRecur(n);
	int end_;
	cin >> end_;
}
int FibIter(int N) {
	int F1 = 0;
	int F2 = 1;
	int FN;
	if (N == 0) {
		FN = 0;
	}
	else if (N == 1) {
		FN = 1;
	}
	else if (N > 1) {
		for (int i = 2; i <= N; i++) {
			FN = F1 + F2;
			F1 = F2;
			F2 = FN;
		}
	}
	return (FN);
}
int FibRecur(int N) {
	if (N == 0) return 0;
	else if (N == 1) return 1;
	else if (N > 1) return FibRecur(N- 1) + FibRecur(N - 2);
}