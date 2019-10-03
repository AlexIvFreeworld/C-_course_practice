#include "Header.h"
void find_name(video *arr, int size, char name[]) {
	int k = 0;//������� ��������� �������
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].name, name)) {//�������� ������ ��������� �������� ������ � ������ ���������� ������ �� �����
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_genre(video *arr, int size, char name[]) {
	int k = 0;//������� ��������� �������
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].genre, name)) {//�������� ������ ��������� ���� � ������ ���������� ������ �� �����
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_producer(video *arr, int size, char name[]) {
	int k = 0;//������� ��������� �������
	for (int i = 0; i < size; i++) {//�������� ������ ��������� ��������� � ������ ���������� ������ �� �����
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
			ofstream o("video.txt", ofstream::app);//������� ���� ��� ������ ����� ������� � ������������ ����������
			o << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;//��������� � ���� ����� ������
			o.close();
			break;
		}
	}
}
void show_video(video *arr, int size, char name[]) {
	for (int i = 0; i < size; i++) {//�������� ������, ��������� ������ ����������� ��������� (������� �������� �� 0)
		if (arr[i].top != 0) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
		}
	}
}
void find_top_genre(video *arr, int size, char name[]) {
	int top_genre = size;//���������� ��� ������ ������� ��������, �� ������ ������� ����� ������ ������� ��������
	int k;//���������� ��� ������ ���������� ������ � ������ ���������
	for (int i = 0; i < size; i++) {
		if (arr[i].top <= top_genre && strcmp(arr[i].genre, name) == 0) {//�������� ������ ��������� ������� � ����, ���� ���� ��������� � ������� ����� ���������
			top_genre = arr[i].top;
			k = i;
		}
	}
	cout << arr[k].name << "\t" << arr[k].producer << "\t" << arr[k].genre << "\t" << arr[k].top << "\t" << arr[k].price << endl;
}
void show_video_from_file(void) {
	ifstream i("video.txt");
	char str[100];
	if (i.is_open()) {
		cout << "New videos : " << endl;
		while (!i.eof()) {
			i.getline(str, 100);
			cout << str << endl;
		}
	}
	else {
		cout << "File is not found " << endl;
	}
}