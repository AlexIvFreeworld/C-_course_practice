#include <iostream>
using namespace std;
int main() {
	int amount_symbol;
	char symbol;
	char type_line;
	enum type_lines {horizontal = '0', vertical = '1'};
	cout << "Enter amount symbol : ";
	cin >> amount_symbol;
	cout << "Enter sybol : ";
	cin >> symbol;
	cout << "Enter type line, if horizontal - 0, if vertical - 1 : ";
	cin >> type_line;
	while (amount_symbol >= 1) {
		if (type_line == horizontal) {
			cout << symbol;
		}
		else if (type_line == vertical) {
			cout << symbol << "\n";
		}
		else {
			cout << "error enter";
			break;
		}
		amount_symbol--;
	}
	//if (type_line == horizontal) {
	//	while (amount_symbol >= 1) {
	//		cout << symbol;
	//		amount_symbol--;
	//	}
	//}
	//else if (type_line == vertical) {
	//	while (amount_symbol >= 1) {
	//		cout << symbol << "\n";
	//		amount_symbol--;
	//	}
	//}
	//else {
	//	cout << "error enter";
	//}
	int end_;
	cin >> end_;
	return (0);
}