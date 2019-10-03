#include <iostream>
using namespace std;
class My {
	My() {
		cout << "Constructor " << this << endl;
	}
public:
static	int num_object;
static My *get_instance();
~My() {
	num_object--;
	cout << "Destructor " << this << endl;
}
};
int My::num_object=0;
My * My::get_instance() {
	num_object++;
	return new My;
}
void f();
int main() {
	f();
	cout << "Count objects after delete - " << My::num_object << endl;
 	cin.get();
	return 0;
}
void f() {
	My *A = My::get_instance();
	My *B = My::get_instance();
	My *C = My::get_instance();
	cout << "Count objects - " << My::num_object << endl;
	cout << "Count objects - " << A->num_object << endl;
	delete A;
	delete B;
	delete C;
}