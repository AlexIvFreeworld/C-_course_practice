#include <iostream>
using namespace std;
void any_stars(int n, ...);
int main() {
	any_stars(6, 3, 4, 5, 2, 7, 8);
 	cin.get();
	return 0;
}
void any_stars(int n, ...) {
	int *p = &n;
	int k;
	for (n; n; n--) {
		k = *(++p);
		cout << k << "\t";
		for (int i = 1; i <= k; i++) {
			cout << "*";
		}
		cout << endl;
	}
}