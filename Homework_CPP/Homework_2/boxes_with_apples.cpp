#include <iostream>
using namespace std;
int main() {
	int amount_boxes_with_apples_store;
	int max_amount_boxes_with_apple_truck;
	int amount_trucks = 0;
	cout << "Enter amount boxes with apples in the store (things) : ";
	cin >> amount_boxes_with_apples_store;
	cout << "Enter max amount boxes with apple in the first truck : ";
	cin >> max_amount_boxes_with_apple_truck;
	while (amount_boxes_with_apples_store > 0) {
		amount_boxes_with_apples_store -= max_amount_boxes_with_apple_truck;
		amount_trucks++;
		if (amount_boxes_with_apples_store > 0) {
			cout << "Enter max amount boxes with apple in the next truck : ";
			cin >> max_amount_boxes_with_apple_truck;
		}
	}
	cout << "Amount trucks = " << amount_trucks;
	int end_;
	cin >> end_;
	return (0);
}