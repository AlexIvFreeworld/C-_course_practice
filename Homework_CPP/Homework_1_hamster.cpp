#include <iostream>
using namespace std;
void main() {
	int feed_day_gram;
	const float amount_day = 30;
	const int gram_in_kilogram = 1000;
	float amount_kilogram;
	cout << "Enter the amount of feed for the hamster per day gram: ";
	cin >> feed_day_gram;
	amount_kilogram = feed_day_gram * amount_day / gram_in_kilogram;
	cout << "The amount of feed for a hamster for " << amount_day << " days "<< amount_kilogram<< " kg\n";
	int end_;
	cin >> end_;
}
