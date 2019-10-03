#include "Header.h"
int square(point p1, point p2) {
	return (p2.get_x() - p1.get_x())*(p2.get_y() - p1.get_y());
}
float lenght(point p1, point p2) {
	return sqrt((p2.get_x() - p1.get_x())*(p2.get_x() - p1.get_x()) + (p2.get_y() - p1.get_y())*(p2.get_y() - p1.get_y()));
}
void calc_p1_p2() {
	point p1(1, 2), p2(2, 4);
	cout << "Square : " << square(p1, p2) << endl;
	cout << "Lenght : " << lenght(p1, p2) << endl;
}