#include "Header.h"
int main() {
	point_3d A;
	point_3d B(1,2,3);
	B.show();
	point_3d *PA = &A;
	point_3d *P_arr_point = new point_3d[10];
	point_3d *PC = new point_3d;
	PC->show();
	PC->set_X(1.25);
	PC->set_Y(2.25);
	PC->set_Z(3.25);
	PC->show();
	get_Point_3d(A);
	get_Point_3d(B);
	get_Point_3d(PA);
	get_Point_3d(P_arr_point);
	delete[] P_arr_point;
	delete PC;
	get_Point_3d(A);
	get_Point_3d(B);
	B.show();
	int end_;
	cin >> end_;
	return 0;
}
void get_Point_3d(point_3d p) {
	cout << "This is function getPoint3d with value" << endl;
}
void get_Point_3d(point_3d *p) {
	cout << "This is function getPoint3d with pointer" << endl;
}