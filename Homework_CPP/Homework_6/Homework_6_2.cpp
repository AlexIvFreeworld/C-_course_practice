#include <iostream>
using namespace std;
void main() {
	const int n = 10, m = 10;
	int A[n],B[m],C[n + m];
	int *pa = A, *pb = B, *pc = C;
	int exch;
	cout << "\n\nArray A :" << endl;
	for (int i = 0; i < n; i++) {
		*(pa + i) = i + 1;
		cout << *(pa + i) << "\t";
	}
	cout << "\n\nArray B :" << endl;
	for (int i = 0; i < m; i++) {
		*(pb + i) = i*3 + 1;
		cout << *(pb + i) << "\t";
	}

	cout << "\n\nArray C after A+B :" << endl;
	for (int i = 0; i < (n + m); i++) {
		if (i < n) {
			*(pc + i) = *(pa + i);
		}
		else {
			*(pc + i) = *(pb + i - n);
		}
	}
	for (int i = 0; i < (n + m); i++) {
		cout << *(pc + i) << "\t";
	}
	cout << "\n\nArray C after sort :" << endl;
	for (int i = 0; i < (n + m); i++) {
		for (int j = 0; j < (n + m - i - 1); j++) {
			if (*(pc + j) > *(pc + j + 1)) {
				exch = *(pc + j + 1);
				*(pc + j + 1) = *(pc + j);
				*(pc + j) = exch;
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < (n + m); i++) {
		cout << *(pc + i) << "\t";
	}
	int end_;
	cin >> end_;
}