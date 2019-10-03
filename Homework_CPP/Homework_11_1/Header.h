#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
using namespace std;
#ifndef VIDEO_H
#define VIDEO_H
struct video {//Создаем структуру видеофильма
	char name[100];//Название
	char producer[100];//Режиссер
	char genre[100];//Жанр
	int top = 0;//Рейтинг, нулевой рейтинг будет означать незаполненную структуру 
	double price;//Цена диска
};
#endif
void F_menu();//Функция организации меню (определение в файле Func_menu)
void add_video(video *arr, int size, char name[]);//Функция добавления фильма в массив и в файл
void show_video(video *arr, int size, char name[]);//Функция показывает все фильмы, все поля
void find_name(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает название
void find_name_genre(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает жанр
void find_name_producer(video *arr, int size, char name[]);// Функция выдает фильмы если совпадает режиссер
void find_top_genre(video *arr, int size, char name[]);//Функция выдает фильм  выбраного жанра с лучшим рейтингом
void show_video_from_file(void);//Функция выдает все добавленные фильмы из файла, если файл еще не создан сообщение об этом
char **find_piece_string(char str[]);
char *find_piece_string_2(char str[]);
video *create_new_video(char *p_arr[]);
char **add_string_from_file_to_arr(void);
video *create_video_arr(void);