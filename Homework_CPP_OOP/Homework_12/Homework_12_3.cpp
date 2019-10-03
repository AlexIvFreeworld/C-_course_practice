#include <iostream>
using namespace std;
#pragma warning(disable : 4996)
#define PI 3.141592
class Circle {
protected:
	float R;
public:
	Circle() {
		cout << "Constructor Circle with default" << endl;

	};
	Circle(float r) {
		R = r;
		cout << "Constructor Circle" << endl;

	}
	float Get_R() {
		return R;
	}
	float Get_Lenght_Circle() {
		return 2*PI*R;
	}
	float Get_Area_Circle() {
		return PI*R*R;
	}
	void Set_R(float r) {
		R = r;
	}
	void Show_Circle() {
		cout << "R = " << R << " Length Circle = " << Get_Lenght_Circle() << " Area Circle = " << Get_Area_Circle() << endl;
	}
	~Circle() {
		cout << "Destructor Circle" << endl;
	}
};
class Square {
protected:
	float L;
public:
	Square() {
		cout << "Constructor Square with default" << endl;
	};
	Square(float l) {
		L = l;
		cout << "Constructor Square" << endl;
	}
	float Get_L() {
		return L;
	}
	float Get_Lenght_Square() {
		return 4 * L;
	}
	float Get_Area_Square() {
		return L*L;
	}
	void Set_R(float l) {
		L = l;
	}
	void Show_Square() {
		cout << "L = " << L << " Length Square = " << Get_Lenght_Square() << " Area Square = " << Get_Area_Square() << endl;
	}
	~Square() {
		cout << "Destructor Square" << endl;
	}
};
class CircleInSquare : public Square, public Circle {
public:
	float L2;
	CircleInSquare(float l2) {
		L2 = l2;
		L = L2;
		R = L / 2;
		cout << "Constructor CircleInSquare" << endl;
	}
	void Show_CircleInSquare() {
		Show_Square();
		Show_Circle();
	}
	~CircleInSquare() {
		cout << "Destructor CircleInSquare" << endl;

}
};
void F();
int main() {
	F();
	cin.get();
	return 0;
}
void F() {
	CircleInSquare CS1(10.0);
	CS1.Show_CircleInSquare();
}
