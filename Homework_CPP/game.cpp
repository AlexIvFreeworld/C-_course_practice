#include <iostream>
using namespace std;
int main() {
	int buddies;
	int after_battle;
	cout << "You are pirate. How many the person in your command, without you?\n\n";
	cin >> buddies;
	cout << "\n\nSuddenly you are attacked by 10 musheketeers \n\n";
	cout << "10 musheketeers and 10 pirates perish in fight.\n\n";
	after_battle = 1 + buddies - 10;
	cout << "Remains only " << after_battle << " pirates\n\n";
	cout << "The condition killed totals 107 gold coins \n\n";
	cout << "It on " << (107 / after_battle) << " coins on everyone\n\n";
	cout << "Pirates arrange greater fight because of remained\t";
	cout << (107 % after_battle) << " coins\n\n";
	int i;
	cin >> i;
}