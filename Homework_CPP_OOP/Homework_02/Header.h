#include <iostream>
using namespace std;
#ifndef POINT_3D
#define POINT_3D
class point_3d {
	double x, y, z;
public:
	point_3d();
	point_3d(double x, double y, double z);
	void show();
	void set_X(double x);
	void set_Y(double y);
	void set_Z(double z);
	double get_X();
	double get_Y();
	double get_Z();
	~point_3d();
};
#endif
point_3d::point_3d() {
	x = y = z = 0;
	cout << "This is constructor without parametrs" << endl;
}
point_3d::point_3d(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	cout << "This is constructor with parametrs\t" << x << "\t" << y << "\t" << z << endl;
}
void point_3d::show() {
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	cout << "Z = " << z << endl;
}
void point_3d::set_X(double x) {
	this->x = x;
	cout << "This is function set_X" << endl;
}
void point_3d::set_Y(double y) {
	this->y = y;
	cout << "This is function set_Y" << endl;
}
void point_3d::set_Z(double z) {
	this->z = z;
	cout << "This is function set_Z" << endl;
}
double point_3d::get_X() {
	return x;
	cout << "This is function get_X" << endl;
}
double point_3d::get_Y() {
	return y;
	cout << "This is function get_Y" << endl;
}
double point_3d::get_Z() {
	return z;
	cout << "This is function get_Z" << endl;
}
point_3d::~point_3d() {
	cout << "I am in destructor" << endl;
}
void get_Point_3d(point_3d p);
void get_Point_3d(point_3d *p);