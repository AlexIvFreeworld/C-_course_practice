#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
using namespace std;
#ifndef VIDEO_H
#define VIDEO_H
struct video {//������� ��������� �����������
	char name[100];//��������
	char producer[100];//��������
	char genre[100];//����
	int top = 0;//�������, ������� ������� ����� �������� ������������� ��������� 
	double price;//���� �����
};
#endif
void F_menu();//������� ����������� ���� (����������� � ����� Func_menu)
void add_video(video *arr, int size, char name[]);//������� ���������� ������ � ������ � � ����
void show_video(video *arr, int size, char name[]);//������� ���������� ��� ������, ��� ����
void find_name(video *arr, int size, char name[]);// ������� ������ ������ ���� ��������� ��������
void find_name_genre(video *arr, int size, char name[]);// ������� ������ ������ ���� ��������� ����
void find_name_producer(video *arr, int size, char name[]);// ������� ������ ������ ���� ��������� ��������
void find_top_genre(video *arr, int size, char name[]);//������� ������ �����  ��������� ����� � ������ ���������
void show_video_from_file(void);//������� ������ ��� ����������� ������ �� �����, ���� ���� ��� �� ������ ��������� �� ����
char **find_piece_string(char str[]);
char *find_piece_string_2(char str[]);
video *create_new_video(char *p_arr[]);
char **add_string_from_file_to_arr(void);
video *create_video_arr(void);