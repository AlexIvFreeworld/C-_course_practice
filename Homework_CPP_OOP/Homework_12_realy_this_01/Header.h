#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;
class point {
private:
	int x;
	int y;
public:
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	point() {
		x = 0;
		y = 0;
	}
	void set_X(int x) {
		this->x = x;
	}
	void set_Y(int y) {
		this->y = y;
	}
	int get_x() {
		return this->x;
	}
	int get_y() {
		return this->y;
	}
	~point() {
	}
};
int square(point p1, point p2);
float lenght(point p1, point p2);
void calc_p1_p2();