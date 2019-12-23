#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int x0, y0, r1, r2, x, y;
	float L;
	cout << "Input coordinates of circle's center (x0, y0): ";
	cin >> x0 >> y0;
	cout << "\nInput circle's radiuses r1 and r2: ";
	cin >> r1 >> r2;
	cout << "\nInput point coordinates (x, y): ";
	cin >> x >> y;
	L = sqrt(pow(x - x0, 2) + pow(y - y0, 2));
	if ((r1 < L) && (L < r2)) {
		cout << "\nThis point is situated inside the circle";
	}
	else {
		cout << "\nThis point is not situated inside the circle";
	}
	int end_;
	cin >> end_;
}