#include <iostream>
using namespace std;
void main() {
	cout << "Hello\b world\n";
	cout << "\\\n";
	cout << "Hello\tworld\n";
	cout << "\*\n";
	cout << "\'\n";
	cout << "\"\n";
	cout << "\t\t\tHello\t\tworld\n\n\n\n";
	cout << R"(Hello\tworld\nworld)"<< "\n";
	cout << R"("Hello\tworld\nworld")";
	int i;
	cin >> i;
}