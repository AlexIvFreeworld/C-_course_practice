#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;
class Integer {
	int i;
public:
	Integer(int i) {
		this->i = i;
		cout << "This is constuctor with parametrs adress "<< &this->i << endl;
	}
	Integer(const Integer&obj) {
		i = obj.i;
		cout << "This is COPY_constuctor, adress "<< &i << endl;
	}
	Integer operator + (const Integer &b);
	Integer operator - (const Integer &b);
	Integer operator / (const Integer &b);
	Integer operator % (const Integer &b);
	Integer operator * (const Integer &b);
	Integer operator ++ ();
	Integer operator ++ (int);
	Integer operator -- ();
	Integer operator -- (int);
	void show();
	
	~Integer() {
		cout << "This is DESTRUCTOR, adress "<< &i << endl;
	}
};
Integer Integer::operator + (const Integer &b) {
	//Integer temp (i + b.i);
	Integer temp(i);
	temp.i = temp.i + b.i;
	cout << "This is operator +" << endl;
	return temp;
}
Integer Integer::operator - (const Integer &b) {
	Integer temp(i - b.i);
	cout << "This is operator -" << endl;
	return temp;
}
Integer Integer::operator / (const Integer &b) {
	Integer temp(i / b.i);
	cout << "This is operator /" << endl;
	return temp;
}
Integer Integer::operator % (const Integer &b) {
	Integer temp(i % b.i);
	cout << "This is operator %" << endl;
	return temp;
}
Integer Integer::operator * (const Integer &b) {
	Integer temp(i * b.i);
	cout << "This is operator *" << endl;
	return temp;
}
Integer Integer::operator ++() {
	Integer temp(++i);
	cout << "This is operator ++PREF" << endl;
	return temp;
}
Integer Integer::operator ++(int) {
	Integer temp(i++);
	cout << "This is operator P0ST++" << endl;
	return temp;
}
Integer Integer::operator --() {
	Integer temp(--i);
	cout << "This is operator --PREF" << endl;
	return temp;
}
Integer Integer::operator --(int) {
	Integer temp(i--);
	cout << "This is operator P0ST--" << endl;
	return temp;
}
void Integer::show() {
	cout << i << endl;
}
void myFunc();
int main() {
	myFunc();
	int end_;
	cin >> end_;
	return 0;
}
void myFunc() {
	Integer a(10), b(3);
	Integer c = a + b;
	c.show();
	Integer c1 = a - b;
	c1.show();
	Integer c2 = a / b;
	c2.show();
	Integer c3 = a % b;
	c3.show();
	Integer c4 = ++a;
	c4.show();
	Integer c5 = b++;
	c5.show();
	Integer a1(15), b1(7);
	Integer c6 = ++a1;
	c6.show();
	a1.show();
	Integer c7 = b1++;
	c7.show();
	b1.show();
}
