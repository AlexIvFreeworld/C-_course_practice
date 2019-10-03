#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int throws();
int visual_cube(int sum_cube);
int main() {
	srand(time(NULL));
	int sum_throws[2][5]; // computer -1, player -2
	int queue_number;
	char player_name[15];
	char yes;
	int total_sum_computer = 0;
	int total_sum_player = 0;
	cout << "\nComputer plays against you\n\nWhat is your name? : ";
	cin >> player_name;
	cout << "\nWill you throw first or second? (enter 1 or 2) : ";
	cin >> queue_number;
	if (queue_number == 2) {
		for (int j = 1; j <= 5; j++) {
			cout << "\n\nThrow computer ";
			int a = throws();
			sum_throws[queue_number-1][j] = a;
			cout << "\n\nThrow " << player_name << " (enter any key) ";
			cin >> yes;
			int b = throws();
			sum_throws[queue_number][j] = b;
			cout << endl;
		}
	}
	else if (queue_number == 1) {
		for (int j = 1; j <= 5; j++) {
			cout << "\n\nThrow " << player_name << " (enter any key) ";
			cin >> yes;
			int b = throws();
			sum_throws[queue_number+1][j] = b;
			cout << "\n\nThrow computer ";
			int a = throws();
			sum_throws[queue_number][j] = a;
			cout << endl;
		}
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i == 1) {
				total_sum_computer += sum_throws[i][j];
			}
			else 
			{
				 total_sum_player += sum_throws[i][j];
			}
		}
	}
	if (total_sum_computer > total_sum_player) {
		cout << "\n\nComputer win : " << total_sum_computer << " against " << total_sum_player;
		cout << "\n\nAverage amount per game computer : " << (float)total_sum_computer / 5;
		cout << "\nAverage amount per game " << player_name << " : " << (float)total_sum_player / 5;
	}
	else if (total_sum_computer < total_sum_player) {
		cout << "\n\n" << player_name << " win : " << total_sum_player << " against " << total_sum_computer;
		cout << "\n\nAverage amount per game computer : " << (float)total_sum_computer / 5;
		cout << "\nAverage amount per game " << player_name << " : " << (float)total_sum_player / 5;
	}
	else if (total_sum_computer == total_sum_player) {
		cout << "\n\nDead heat !!!!!";
		cout << "\n\nAverage amount per game computer : " << (float)total_sum_computer / 5;
		cout << "\nAverage amount per game " << player_name << " : " << (float)total_sum_player / 5;
	}
	int end_;
	cin >> end_;
	return (0);
}
int throws() {
	int sum, sum_cube_1, sum_cube_2;
	sum_cube_1 = rand() % 6 + 1;
	sum_cube_2 = rand() % 6 + 1;
	sum = sum_cube_1 + sum_cube_2;
	visual_cube(sum_cube_1);
	visual_cube(sum_cube_2);
	return (sum);
}
int visual_cube(int sum_cube) {

	switch (sum_cube) {
	case 1:
		cout << "\n\n\t|   |\n\t| + |\n\t|   |";
		break;
	case 2:
		cout << "\n\n\t|  +|\n\t|   |\n\t|+  |";
		break;
	case 3:
		cout << "\n\n\t|  +|\n\t| + |\n\t|+  |";
		break;
	case 4:
		cout << "\n\n\t|+ +|\n\t|   |\n\t|+ +|";
		break;
	case 5:
		cout << "\n\n\t|+ +|\n\t| + |\n\t|+ +|";
		break;
	case 6:
		cout << "\n\n\t|+++|\n\t|   |\n\t|+++|";
		break;
	}
	return (0);
}