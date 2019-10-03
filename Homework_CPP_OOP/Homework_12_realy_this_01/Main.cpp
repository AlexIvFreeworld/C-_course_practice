#include "Header.h"
#include "Header_TEST.h"
int main() {
	cout << "Result tested square :\n\n";
	true_or_false(test_square_positive());
	true_or_false(test_square_negative());
	true_or_false(test_square_positive_p2_to_p1());
	true_or_false(test_square_positive_p2_to_negative_p1());
	true_or_false(test_square_positive_p1_to_negative_p2());
	true_or_false(test_square_positive_X_negative_Y());
	true_or_false(test_square_negative_X_positive_Y());
	true_or_false(test_square_negative_p2_to_p1());
	cout << "\nResult tested lenght :\n\n";
	true_or_false(test_lenght_positive());
	true_or_false(test_lenght_negative());
	true_or_false(test_lenght_positive_p2_to_p1());
	true_or_false(test_lenght_positive_p1_to_negative_p2());
	true_or_false(test_lenght_positive_p2_to_negative_p1());
	true_or_false(test_lenght_negative_p2_to_p1());
	true_or_false(test_lenght_positive_X_negative_Y());
	true_or_false(test_lenght_negative_X_positive_Y());
	int end_;
	cin >> end_;
	return 0;
}