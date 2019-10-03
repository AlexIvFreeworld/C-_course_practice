#include <iostream>
#include <string.h>
using namespace std;
struct video {//Создаем структуру видеофильма
	char name[100]; //Название
	char producer[100];//Режиссер
	char genre[100];//Жанр
	int top = 0;//Рейтинг, нулевой рейтинг будет означать незаполненную структуру 
	double price; //Цена диска
};
void add_video(video *arr, int size);//Функция добавления фильма
void show_video(video *arr, int size);//Функция показывает все фильмы, все поля
void find_name(video *arr, int size, char search_name[], char name_genre[], char name_producer[]);// Функция выдает фильмы если совпадает название, жанр или режиссер
void find_top_genre(video *arr, int size, char name_genre[]);//Функция выдает фильм заданного жанра с лучшим рейтингом
int main() {
	int size = 10;//Задаем размер массива указателей на структуры
	video *arr = new video[size]; //создаем масив указателей
	arr[0] = { "Name_1", "Producer_1", "genre", 10, 10.50 };//заполняем структуры
	arr[1] = { "Name_2", "Producer_2", "genre", 9, 20.50 };
	arr[2] = { "Name_3", "Producer_3", "genre2", 8, 30.50 };
	arr[3] = { "Name_4", "Producer_1", "genre2", 7, 10.50 };
	arr[5] = { "Name_5", "Producer_2", "genre", 6, 20.50 };
	arr[6] = { "Name_6", "Producer_3", "genre2", 5, 30.50 };
	show_video(arr, size);//показываем все заполненные структуры
	int choice;
	while (true) {
		cout << "Add new video? yes - 1, no - any key : ";
		cin >> choice;
		if (choice == 1) {//Выбираем добавлять или нет фильм
			add_video(arr, size);
		}
		else {
			break;
		}
	}
	show_video(arr, size);//показываем все заполненные cтруктуры с учетом добавленых
	char search_name[100];
	char name_genre[100];
	char name_producer[100];
	cout << "Enter name for search: ";
	cin >> search_name;//Записываем название фильма для поиска
	cout << "Enter genre for search: ";
	cin >> name_genre;//Записываем жанр фильма для поиска
	cout << "Enter producer for search: ";
	cin >> name_producer;//Записываем режиссера фильма для поиска
	find_name(arr, size, search_name, name_genre, name_producer);
	cout << "Enter genre for search best video in these genre : ";
	cin >> name_genre;//Записываем жанр фильма для поиска фильма с лучшим рейтингом
	find_top_genre(arr, size, name_genre);
	int end_;
	cin >> end_;
	return (0);
}
void find_name(video *arr, int size, char search_name[], char name_genre[], char name_producer[]) {
	int k = 0;//подсчет найденных фильмов
	for (int i = 0; i < size; i++) {//проходим массив сравнивая название, жанр и режиссера в случае хотя бы одного совпадения совпадения выдаем на экран
		if (strcmp(arr[i].name, search_name)==0 || strcmp(arr[i].genre, name_genre)==0 || strcmp(arr[i].producer, name_producer)==0) {
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
void show_video(video *arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i].top != 0) {//проходим массив, показывая только заполненные структуры (рейтинг отличный от 0)
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
		}
	}
}
void find_top_genre(video *arr, int size, char name_genre[]) {
	int top_genre = size;//переменная для записи лучшего рейтинга, на начало прохода равно самому низкому рейтингу
	int k;//переменная для записи последнего фильма с лучшим рейтингом
	for (int i = 0; i < size; i++) {
		if (arr[i].top <= top_genre && strcmp(arr[i].genre, name_genre) == 0) {//проходим массив сравнивая рейтинг и жанр, если он лучше записывам
			top_genre = arr[i].top;
			k = i;
		}
	}
	cout << arr[k].name << "\t" << arr[k].producer << "\t" << arr[k].genre << "\t" << arr[k].top << "\t" << arr[k].price << endl;
}