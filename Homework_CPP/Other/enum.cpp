#include <iostream>
using namespace std;
int main () {
	enum coins { penny = 1, nickel = 5, dime = 10, quarter = 25, half = 50, dollar_coin = 100 };
	int coin;
	cout << "Please enter a value of american coin" << endl;
	cin >> coin;
	switch (coin) {
	case penny:
		cout << "penny = 1 cent " << endl;
		cout << "It has Abraham Lincoln on one side and the Lincoln Memorial on the other." << endl;
		break;
	case nickel:
		cout << "nicel = 5 cents" << endl;
		cout << "It has Thomas Jefferson on the front and Monticello on the back" << endl;
		break;
	default:
		cout << "not found" << endl;
	}
	enum command {straight, right, left = -1};
	enum direction { north = 1, west, south, east};
	int Command, Direction;
	cout << "Enter the start direction the robot" << endl;
	cout << "\t 1 - North\n" << "\t 2 - West\n" << "\t 3 - South\n" << "\t 4 - East\n";
	cin >> Direction;
	cout << "Select action" << endl;
	cout << "\t 0 - sttaight on\n" << "\t 1 - turn right\n" << "\t -1 turn left\n";
	cin >> Command;
	switch (Direction) {
	case north:
		switch (Command) {
		case straight:
			cout << "The robot is looking at the notrh\n";
			break;
		case right:
			cout << "The robot is looking at the east\n";
			break;
		case left:
			cout << "The robot is looking at the west\n";
			break;
		}
	break;
	case south:
		switch (Command) {
		case straight:
			cout << "The robot is looking at the south\n";
			break;
		case right:
			cout << "The robot is looking at the west\n";
			break;
		case left:
			cout << "The robot is looking at the east\n";
			break;
		}
	break;
	case east:
		switch (Command) {
		case straight:
			cout << "The robot is looking at the east\n";
			break;
		case right:
			cout << "The robot is looking at the south\n";
			break;
		case left:
			cout << "The robot is looking at the north\n";
			break;
		}
		break;
	case west:
		switch (Command) {
		case straight:
			cout << "The robot is looking at the west\n";
			break;
		case right:
			cout << "The robot is looking at the north\n";
			break;
		case left:
			cout << "The robot is looking at the south\n";
			break;
		}
		break;
	default:
		cout << "not found" << endl;
	}
	int end_;
	cin >> end_;
}