#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;
struct video {//������� ��������� �����������
	char name[100];//��������
	char producer[100];//��������
	char genre[100];//����
	int top = 0;//�������, ������� ������� ����� �������� ������������� ��������� 
	double price;//���� �����
};
void F_menu();//������� ����������� ���� (����������� � ����� Func_menu)
void add_video(video *arr, int size, char name[]);//������� ���������� ������ � ������ � � ����
void show_video(video *arr, int size, char name[]);//������� ���������� ��� ������, ��� ����
void find_name(video *arr, int size, char name[]);// ������� ������ ������ ���� ��������� ��������
void find_name_genre(video *arr, int size, char name[]);// ������� ������ ������ ���� ��������� ����
void find_name_producer(video *arr, int size, char name[]);// ������� ������ ������ ���� ��������� ��������
void find_top_genre(video *arr, int size, char name[]);//������� ������ �����  ��������� ����� � ������ ���������
void show_video_from_file(void);//������� ������ ��� ����������� ������ �� �����, ���� ���� ��� �� ������ ��������� �� ����