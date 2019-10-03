//#include <iostream>
//#include <string.h>
#include "Header.h"
//#pragma warning(disable : 4996)
//using namespace std;
void find_name(video *arr, int size, char name[]) {
	int k = 0;//подсчет найденных фильмов
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].name, name)) {//проходим массив сравнивая название фильма в случае совпадения выдаем на экран
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_genre(video *arr, int size, char name[]) {
	int k = 0;//подсчет найденных фильмов
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].genre, name)) {//проходим массив сравнивая жанр в случае совпадения выдаем на экран
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_producer(video *arr, int size, char name[]) {
	int k = 0;//подсчет найденных фильмов
	for (int i = 0; i < size; i++) {//проходим массив сравнивая режиссера в случае совпадения выдаем на экран
		if (!strcmp(arr[i].producer, name)) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void add_video(video *arr, int size, char name[]) {
	for (int i = 0; i < size; i++) {
		if (arr[i].top == 0) {
			cout << "Enter name : ";
			cin >> arr[i].name;
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
void show_video(video *arr, int size, char name[]) {
	for (int i = 0; i < size; i++) {//проходим массив, показывая только заполненные структуры (рейтинг отличный от 0)
		if (arr[i].top != 0) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
		}
	}
}
void find_top_genre(video *arr, int size, char name[]) {
	int top_genre = size;//переменная для записи лучшего рейтинга, на начало прохода равно самому низкому рейтингу
	int k;//переменная для записи последнего фильма с лучшим рейтингом
	for (int i = 0; i < size; i++) {
		if (arr[i].top <= top_genre && strcmp(arr[i].genre, name) == 0) {//проходим массив сравнивая рейтинг и жанр, если жанп совпадает а рейтинг лучше записывам
			top_genre = arr[i].top;
			k = i;
		}
	}
	cout << arr[k].name << "\t" << arr[k].producer << "\t" << arr[k].genre << "\t" << arr[k].top << "\t" << arr[k].price << endl;
}