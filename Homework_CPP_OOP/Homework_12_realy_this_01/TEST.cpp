#include "Header.h"
#include "Header_TEST.h"
bool test_square_positive() {
	cout << "test_square_positive : ";
	point p1, p2;
	p1.set_X(1);
	p2.set_X(2);
	p1.set_Y(2);
	p2.set_Y(4);
	int result = 2;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_square_positive_p2_to_p1() {
	cout << "test_square_positive_p2_to_p1 : ";
	point p1, p2;
	p1.set_X(2);
	p2.set_X(1);
	p1.set_Y(4);
	p2.set_Y(2);
	int result = 2;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_square_positive_p2_to_negative_p1() {
	cout << "test_square_positive_p2_to_negative_p1 : ";
	point p1, p2;
	p1.set_X(-2);
	p2.set_X(1);
	p1.set_Y(-4);
	p2.set_Y(2);
	int result = 18;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_square_positive_p1_to_negative_p2() {
	cout << "test_square_positive_p1_to_negative_p2 : ";
	point p1, p2;
	p1.set_X(2);
	p2.set_X(-1);
	p1.set_Y(4);
	p2.set_Y(-2);
	int result = 18;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_square_positive_X_negative_Y() {
	cout << "test_square_positive_X_negative_Y : ";
	point p1, p2;
	p1.set_X(2);
	p2.set_X(1);
	p1.set_Y(-4);
	p2.set_Y(-2);
	int result = 2;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_square_negative_X_positive_Y() {
	cout << "test_square_negative_X_positive_Y : ";
	point p1, p2;
	p1.set_X(-2);
	p2.set_X(-1);
	p1.set_Y(4);
	p2.set_Y(2);
	int result = 2;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_square_negative() {
	cout << "test_square_negative : ";
	point p1, p2;
	p1.set_X(-1);
	p2.set_X(-2);
	p1.set_Y(-2);
	p2.set_Y(-4);
	int result = 2;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_square_negative_p2_to_p1() {
	cout << "test_square_negative_p2_to_p1 : ";
	point p1, p2;
	p1.set_X(-2);
	p2.set_X(-1);
	p1.set_Y(-4);
	p2.set_Y(-2);
	int result = 2;
	if (result == square(p1, p2)) {
		return true;
	}
	else {
		return false;
	}
}
void true_or_false(bool x) {
	x == 1 ? cout << "OK" << endl: cout << "Error" << endl;
}
bool test_lenght_positive() {
	cout << "test_lenght_positive : ";
	point p1, p2;
	p1.set_X(1);
	p2.set_X(2);
	p1.set_Y(2);
	p2.set_Y(4);
	char result_ch_true[8] = "223606";
	char result_ch_func[100];
	itoa(lenght(p1, p2)*100000, result_ch_func,10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_lenght_negative() {
	cout << "test_lenght_negative : ";
	point p1, p2;
	p1.set_X(-2);
	p2.set_X(-1);
	p1.set_Y(-4);
	p2.set_Y(-2);
	char result_ch_true[8] = "223606";
	char result_ch_func[100];
	itoa(lenght(p1, p2) * 100000, result_ch_func, 10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_lenght_positive_p2_to_p1() {
	cout << "test_lenght_positive_p2_to_p1 : ";
	point p1, p2;
	p1.set_X(2);
	p2.set_X(1);
	p1.set_Y(4);
	p2.set_Y(2);
	char result_ch_true[8] = "223606";
	char result_ch_func[100];
	itoa(lenght(p1, p2) * 100000, result_ch_func, 10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_lenght_positive_p1_to_negative_p2() {
	cout << "test_lenght_positive_p1_to_negative_p2 : ";
	point p1, p2;
	p1.set_X(1);
	p2.set_X(-2);
	p1.set_Y(2);
	p2.set_Y(-4);
	char result_ch_true[8] = "670820";
	char result_ch_func[100];
	itoa(lenght(p1, p2) * 100000, result_ch_func, 10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_lenght_positive_p2_to_negative_p1() {
	cout << "test_lenght_positive_p2_to_negative_p1 : ";
	point p1, p2;
	p1.set_X(-2);
	p2.set_X(1);
	p1.set_Y(-4);
	p2.set_Y(2);
	char result_ch_true[8] = "670820";
	char result_ch_func[100];
	itoa(lenght(p1, p2) * 100000, result_ch_func, 10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_lenght_negative_p2_to_p1() {
	cout << "test_lenght_negative_p2_to_p1 : ";
	point p1, p2;
	p1.set_X(-1);
	p2.set_X(-2);
	p1.set_Y(-2);
	p2.set_Y(-4);
	char result_ch_true[8] = "223606";
	char result_ch_func[100];
	itoa(lenght(p1, p2) * 100000, result_ch_func, 10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_lenght_positive_X_negative_Y() {
	cout << "test_lenght_positive_X_negative_Y : ";
	point p1, p2;
	p1.set_X(1);
	p2.set_X(2);
	p1.set_Y(-2);
	p2.set_Y(-4);
	char result_ch_true[8] = "223606";
	char result_ch_func[100];
	itoa(lenght(p1, p2) * 100000, result_ch_func, 10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}
bool test_lenght_negative_X_positive_Y() {
	cout << "test_lenght_negative_X_positive_Y : ";
	point p1, p2;
	p1.set_X(-2);
	p2.set_X(-1);
	p1.set_Y(4);
	p2.set_Y(2);
	char result_ch_true[8] = "223606";
	char result_ch_func[100];
	itoa(lenght(p1, p2) * 100000, result_ch_func, 10);
	//cout << "result true : " << result_ch_true << endl;
	//cout << "result test func : " << result_ch_func << endl;
	if (!strcmp(result_ch_true, result_ch_func)) {
		return true;
	}
	else {
		return false;
	}
}