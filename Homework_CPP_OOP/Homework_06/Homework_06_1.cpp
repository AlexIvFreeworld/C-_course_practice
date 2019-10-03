#include <iostream>
using namespace std;
class comp_number {
	double real_num;
	double imag_num;
public:
	comp_number() {
		real_num = 0;
		imag_num = 0;
	}
	comp_number(double r, double i) {
		real_num = r;
		imag_num = i;
	}
	//double get_real_num();
	//double get_imag_num();
	comp_number operator+(const comp_number&obj);
	comp_number operator-(const comp_number&obj);
	comp_number operator*(const comp_number&obj);
	comp_number operator/(const comp_number&obj);
	void show();
};
//double comp_number::get_real_num() {
//	return real_num;
//}
//double comp_number::get_imag_num() {
//	return imag_num;
//}
comp_number comp_number::operator+(const comp_number&obj){
	comp_number A;
	A.real_num = real_num + obj.real_num;
	A.imag_num = imag_num + obj.imag_num;
	return A;
}
comp_number comp_number::operator-(const comp_number&obj) {
	comp_number A;
	A.real_num = real_num + (-obj.real_num);
	A.imag_num = imag_num + (-obj.imag_num);
	return A;
}
comp_number comp_number::operator*(const comp_number&obj) {
	comp_number A;
	A.real_num = (real_num * obj.real_num) + (imag_num * obj.imag_num);
	A.imag_num = (real_num * obj.imag_num) + (imag_num * obj.real_num);
	return A;
}
comp_number comp_number::operator/(const comp_number&obj) {
	comp_number A;
	double denom;
	A.real_num = (real_num * obj.real_num) +( imag_num * obj.imag_num);
	cout << A.real_num << endl;
	A.imag_num =( imag_num * obj.real_num) - (real_num * obj.imag_num);
	cout << A.imag_num << endl;
	denom = (obj.real_num*obj.real_num) + (obj.imag_num*obj.imag_num);
	cout << denom << endl;
	A.real_num = A.real_num/denom;
	A.imag_num = A.imag_num/denom;
	return A;
}
void comp_number::show() {
	if (real_num != 0 && imag_num==0) {
		cout << real_num << endl;
	}
	else if (real_num == 0 && imag_num != 0) {
		cout << imag_num << "i" << endl;
	}
	else if (real_num == 0 && imag_num == 0) {
		cout << 0 << endl;
	}
	else {
		cout << real_num << ((imag_num<0)?"":"+") << imag_num << "i" << endl;
	}
}
int main() {
	comp_number C1(2, 3), C2(5, -4);
	comp_number C3 = C1 - C2;
	C3.show();
	C3 = C1 + C2;
	C3.show();
	C3 = C1 * C2;
	C3.show();
	C3=C1/C2;
	C3.show();
 	cin.get();
	return 0;
}
