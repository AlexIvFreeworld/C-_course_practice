#include "Header.h"
int main() {
	List_video L_video_1;
	L_video_1.p_to_arr_video = new video[100];
	L_video_1.num_video = 0;
	L_video_1.stat_ID = 1;
	string name, producer, genre, file_name, basket;
	int top, change;
	char change_ch[100];
	double price;
	file_name = "Video.txt";
	add_video_from_file(&L_video_1, file_name);
	do {
		cout << endl;
		cout << "Show all video - 1, Add new video - 2, Exit menu - 6" << endl;
		cin >> change_ch;
		change = atoi(change_ch);
		switch (change) {
		case 1:
			show_all_video(&L_video_1);
			break;
		case 2:
			getline(cin, basket);
			cout << "Enter Name" << endl;
			getline(cin, name);
			cout << "Enter Producer" << endl;
			getline(cin, producer);
			cout << "Enter Genre" << endl;
			getline(cin, genre);
			cout << "Enter Top" << endl;
			cin >> top;
			cout << "Enter Price" << endl;
			cin >> price;
			create_new_video(&L_video_1, name, producer, genre, top, price);
			break;
		}
	} while (change != 6);
	add_video_to_file(&L_video_1, file_name);
	int end_;
	cout << "Press any key for out";
	cin >> end_;
	return (0);
}