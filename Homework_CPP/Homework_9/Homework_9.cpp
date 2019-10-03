#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;
struct video {//Создаем структуру видеофильма
	char name[100];//Название
	char producer[100];//Режиссер
	char genre[100];//Жанр
	int top = 0;//Рейтинг, нулевой рейтинг будет означать незаполненную структуру 
	double price;//Цена диска
};
void add_video(video *arr, int size, char name[]);//Функция добавления фильма
void show_video(video *arr, int size, char name[]);//Функция показывает все фильмы, все поля
void find_name(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает название
void find_name_genre(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает жанр
void find_name_producer(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает режиссер
void find_top_genre(video *arr, int size, char name[]);//Функция выдает фильм  выбраного жанра с лучшим рейтингом
int main() {
	int size = 10;//Задаем размер массива указателей на структуры
	video *arr = new video[size];//создаем масив указателей
	char name[100];
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
			menu[choice_menu - 1](arr,size,name);//в зависимости от выбраного пункта вызываем нужную функцию
		}
		else if (choice_act == 0) {
			break;
		}
	}
	int end_;
	cin >> end_;
	return (0);
}
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