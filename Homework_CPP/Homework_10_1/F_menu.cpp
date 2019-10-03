//#include <iostream>
//#include <string.h>
#include "Header.h"
//#pragma warning(disable : 4996)
//using namespace std;
//void add_video(video *arr, int size, char name[]);//Функция добавления фильма
//void show_video(video *arr, int size, char name[]);//Функция показывает все фильмы, все поля
//void find_name(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает название
//void find_name_genre(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает жанр
//void find_name_producer(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает режиссер
//void find_top_genre(video *arr, int size, char name[]);//Функция выдает фильм  выбраного жанра с лучшим рейтингом
void F_menu() {
	int size = 10;//Задаем размер массива указателей на структуры
	char name[100];
	video *arr = new video[size];//создаем масив указателей
	void(*menu[6])(video *arr, int size, char name[]);//Масссив указателей на 6 функций
	menu[0] = add_video;//Присваиваем каждой функции свой указатель из массива
	menu[1] = show_video;
	menu[2] = find_name;
	menu[3] = find_name_genre;
	menu[4] = find_name_producer;
	menu[5] = find_top_genre;
	arr[0] = { "Name_1", "Producer_1", "genre", 10, 10.50 };//заполняем структуры для проверки работы
	arr[1] = { "Name_2", "Producer_2", "genre", 9, 20.50 };
	arr[2] = { "Name_3", "Producer_3", "genre2", 8, 30.50 };
	arr[3] = { "Name_4", "Producer_1", "genre2", 7, 10.50 };
	arr[5] = { "Name_5", "Producer_2", "genre", 6, 20.50 };
	arr[6] = { "Name_6", "Producer_3", "genre2", 5, 30.50 };
	int choice_act, choice_menu;//переменные для записи выбора необходимости дальнейшего действия и меню
	while (true) {
		cout << "Start new action? yes - 1, no - 0 : ";
		cin >> choice_act;
		if (choice_act == 1) {//Вывод меню на экран
			cout << "Choos any action :" << endl;
			cout << "Add new video - 1 : " << endl;
			cout << "Show all videos - 2 : " << endl;
			cout << "Search video by name - 3 : " << endl;
			cout << "Search video by genre - 4 : " << endl;
			cout << "Search video by producer - 5 : " << endl;
			cout << "Search for the most popular video in the genre - 6 : " << endl;
			cin >> choice_menu;
			if (choice_menu > 2 && choice_menu < 7) {//для первых двух функций имя необязательно
				cout << "Enter name : ";
				cin >> name;
			}
			menu[choice_menu - 1](arr, size, name);//в зависимости от выбраного пункта вызываем нужную функцию
		}
		else if (choice_act == 0) {
			break;
		}
	}
}