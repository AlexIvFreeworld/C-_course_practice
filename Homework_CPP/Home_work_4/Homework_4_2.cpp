#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	const int amount_athletes = 5;
	const int amount_throws = 3;
	int arr[5][3];
	srand(time(NULL));
	for (int i = 1; i <= amount_athletes; i++) {
		cout << "Athlete number " << i << " results : ";
		for (int j = 1; j <= amount_throws; j++) {
			arr[i][j] = rand() % 20 + 60;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
int max = arr[1][1];
int best_athlete = 1, best_throw = 1;
for (int i = 1; i <= amount_athletes; i++) {
	for (int j = 1; j <= amount_throws; j++) {
		if (arr[i][j] > max) {
			max = arr[i][j];
		}
	}
}
for (int i = 1; i <= amount_athletes; i++) {
	for (int j = 1; j <= amount_throws; j++) {
		if (arr[i][j] == max) {
			best_athlete = i;
			best_throw = j;
			cout << "\n\nThe best atthlete number " << best_athlete << " the best trow number " << best_throw << " result " << max << " (m)";
		}
	}
}
	int end_;
	cin >> end_;
	return (0);
}