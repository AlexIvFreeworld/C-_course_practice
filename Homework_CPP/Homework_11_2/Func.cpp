#include "Header.h"
void create_new_video(List_video *L_video_1, string name, string producer, string genre, int top, double price) {
	for (int i = 0; i < L_video_1->stat_ID; i++) {
		if (L_video_1->p_to_arr_video[i].ID == 0) {
			L_video_1->p_to_arr_video[i].ID = L_video_1->stat_ID;
			L_video_1->p_to_arr_video[i].name = name;
			L_video_1->p_to_arr_video[i].producer = producer;
			L_video_1->p_to_arr_video[i].genre = genre;
			L_video_1->p_to_arr_video[i].top = top;
			L_video_1->p_to_arr_video[i].price = price;
			L_video_1->stat_ID++;
			L_video_1->num_video++;
			break;
		}
	}
}
void show_all_video(List_video *L_video_1) {
	if (L_video_1->num_video == 0) {
		cout << "List video is empty" << endl;
	}
	else {
		for (int i = 0; i < L_video_1->stat_ID; i++) {
			if (L_video_1->p_to_arr_video[i].ID > 0) {
				cout << "\n" << L_video_1->p_to_arr_video[i].ID << "\t";
				cout << L_video_1->p_to_arr_video[i].name << "\t";
				cout << L_video_1->p_to_arr_video[i].producer << "\t";
				cout << L_video_1->p_to_arr_video[i].genre << "\t";
				cout << L_video_1->p_to_arr_video[i].top << "\t";
				cout << L_video_1->p_to_arr_video[i].price << endl;
			}
		}
		cout << "Amount video = " << L_video_1->num_video << endl;
	}
}
void add_video_to_file(List_video *L_video_1, string file_name) {
	ofstream F_video(file_name);
	for (int i = 0; i < L_video_1->stat_ID; i++) {
		if (L_video_1->p_to_arr_video[i].ID > 0) {
			F_video << L_video_1->p_to_arr_video[i].ID << "\t" << L_video_1->p_to_arr_video[i].name << "\t";
			F_video << L_video_1->p_to_arr_video[i].producer << "\t" << L_video_1->p_to_arr_video[i].genre << "\t";
			F_video << L_video_1->p_to_arr_video[i].top << "\t" << L_video_1->p_to_arr_video[i].price << endl;
		}
	}
	F_video.close();
	cout << "All video add to file" << endl;
}
void add_video_from_file(List_video *L_video_1, string file_name) {
	ifstream F_video(file_name);
	int j = 0;//amount elem in L_video_1
	string line;
	int n_str_end = num_string_in_file(file_name);
	for (int n_str = 1; n_str <= n_str_end; n_str++) {
		getline(F_video,line);
		int k = 0;//amount elem in line
		char ID[100], name[100], producer[100], genre[100], top[100], price[100];
		for (int i = 0; line[k] != '\t'; i++) {
			ID[i] = line[k];
			ID[i + 1] = '\0';
			k++;
		}
		k++;
		for (int i = 0; line[k] != '\t'; i++) {
			name[i] = line[k];
			name[i + 1] = '\0';
			k++;
		}
		k++;
		for (int i = 0; line[k] != '\t'; i++) {
			producer[i] = line[k];
			producer[i + 1] = '\0';
			k++;
		}
		k++;
		for (int i = 0; line[k] != '\t'; i++) {
			genre[i] = line[k];
			genre[i + 1] = '\0';
			k++;
		}
		k++;
		for (int i = 0; line[k] != '\t'; i++) {
			top[i] = line[k];
			top[i + 1] = '\0';
			k++;
		}
		k++;
		for (int i = 0; line[k] != '\0'; i++) {
			price[i] = line[k];
			price[i + 1] = '\0';
			k++;
		}
		L_video_1->p_to_arr_video[j].ID = atoi(ID);
		L_video_1->p_to_arr_video[j].name = name;
		L_video_1->p_to_arr_video[j].producer = producer;
		L_video_1->p_to_arr_video[j].genre = genre;
		L_video_1->p_to_arr_video[j].top = atoi(top);
		L_video_1->p_to_arr_video[j].price = atof(price);
		L_video_1->stat_ID++;
		L_video_1->num_video++;
		j++;
	}
}
int num_string_in_file(string file_name) {
	ifstream F_video(file_name);
	if (F_video.is_open()) {
		char line[100];
		int num_string = 0;
		while (!F_video.eof()) {
			F_video.getline(line, 100);
			cout << "String" << num_string << "|" << line << endl;
			num_string++;
		}
		cout << "Num string in the file : " << num_string << endl;
		return --num_string;
	}
	else {
		cout << "File is not open" << endl;
		return 0;
	}
}