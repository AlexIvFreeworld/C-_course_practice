#include <iostream>
using namespace std;
double sum(double &pa, char &pb, double &pc);
void main() {
	double a, c;
	char b;
	double *pa = &a;
	char *pb = &b;
	double *pc = &c;
	cout << "\nEnter first number : ";
	cin >> *pa;
	cout << "\nEnter one of the operators (+,-,/,*) : ";
	cin >> *pb;
	cout << "\nEnter second number : ";
	cin >> *pc;
	cout << "\nResult : " << sum(*pa, *pb, *pc);
	int end_;
	cin >> end_;
}
double sum(double &pa, char &pb, double &pc) {
	double res;
	switch (pb)	{
	case '-':
		res = pa - pc;
		break;
	case '+':
		res = pa + pc;
		break;
	case '/':
		res = pa / pc;
		break;
	case '*':
		res = pa * pc;
		break;
	default:
		break;
	}
	return (res);
}