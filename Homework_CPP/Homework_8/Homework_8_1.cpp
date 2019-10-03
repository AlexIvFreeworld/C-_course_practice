#include <iostream>
#include <string.h>
using namespace std;
struct video {
	char name[100];
	char producer[100];
	char genre[100];
	int top = 0;
	double price;
};
void add_video(video *arr, int size);
void show_video(video *arr, int size);
void find_name(video *arr, int size, char search_name[]);
void find_name_genre(video *arr, int size, char name_genre[]);
void find_name_producer(video *arr, int size, char name_producer[]);
void find_top_genre(video *arr, int size, char name_genre[]);
int main() {
	int size = 10;
	video *arr = new video[size];
	arr[0] = { "Name_1", "Producer_1", "genre", 10, 10.50 };
	arr[1] = { "Name_2", "Producer_2", "genre", 9, 20.50 };
	arr[2] = { "Name_3", "Producer_3", "genre2", 8, 30.50 };
	arr[3] = { "Name_4", "Producer_1", "genre2", 7, 10.50 };
	arr[5] = { "Name_5", "Producer_2", "genre", 6, 20.50 };
	arr[6] = { "Name_6", "Producer_3", "genre2", 5, 30.50 };
	int choice;
	while (true) {
		cout << "Add new video? yes - 1, no - 0 : ";
		cin >> choice;
		if (choice == 1) {
			add_video(arr, size);
		}
		else {
			break;
		}
	}
	show_video(arr, size);
	char search_name[100];
	char name_genre[100];
	char name_producer[100];
	cout << "Enter name for search: ";
	cin >> search_name;
	find_name(arr, size, search_name);
	cout << "Enter genre for search: ";
	cin >> name_genre;
	find_name_genre(arr, size, name_genre);
	cout << "Enter producer for search: ";
	cin >> name_producer;
	find_name_producer(arr, size, name_producer);
	cout << "Enter genre for search best video in these genre : ";
	cin >> name_genre;
	find_top_genre(arr, size, name_genre);
	int end_;
	cin >> end_;
	return (0);
}
void find_name(video *arr, int size, char search_name[]) {
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (!strcmp (arr[i].name,search_name)) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_genre(video *arr, int size, char name_genre[]) {
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].genre, name_genre)) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_producer(video *arr, int size, char name_producer[]) {
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].producer, name_producer)) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void add_video(video *arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i].top == 0) {
			cout << "Enter name : ";
			cin >>arr[i].name;
			cout << "Enter producer : ";
			cin >> arr[i].producer;
			cout << "Enter genre : ";
			cin >> arr[i].genre;
			cout << "Enter top : ";
			cin >> arr[i].top;
			cout << "Enter price : ";
			cin >> arr[i].price;
			break;
		}
	}
}
void show_video(video *arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i].top != 0) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
		}
	}
}
void find_top_genre(video *arr, int size, char name_genre[]) {
	int top_genre = size;
	int k;
	for (int i = 0; i < size; i++) {
		if (arr[i].top <= top_genre && strcmp(arr[i].genre, name_genre) == 0) {
		    top_genre = arr[i].top;
			k = i;
		}
	}
	cout << arr[k].name << "\t" << arr[k].producer << "\t" << arr[k].genre << "\t" << arr[k].top << "\t" << arr[k].price << endl;
}