#include "Header.h"
void find_name(video *arr, int size, char name[]) {
	int k = 0;//подсчет найденных фильмов
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].name, name)) {//проходим массив сравнива€ название фильма в случае совпадени€ выдаем на экран
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_genre(video *arr, int size, char name[]) {
	int k = 0;//подсчет найденных фильмов
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i].genre, name)) {//проходим массив сравнива€ жанр в случае совпадени€ выдаем на экран
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
			k++;
		}
	}
	(k > 0) ? cout << endl : cout << "Video not found" << endl;
}
void find_name_producer(video *arr, int size, char name[]) {
	int k = 0;//подсчет найденных фильмов
	for (int i = 0; i < size; i++) {//проходим массив сравнива€ режиссера в случае совпадени€ выдаем на экран
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
			ofstream o("video.txt", ofstream::app);//—оздаем файл дл€ записи новых фильмов с возможностью добавлени€
			o << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;//ƒобавл€ем в файл новую запись
			o.close();
			break;
		}
	}
}
void show_video(video *arr, int size, char name[]) {
	for (int i = 0; i < size; i++) {//проходим массив, показыва€ только заполненные структуры (рейтинг отличный от 0)
		if (arr[i].top != 0) {
			cout << arr[i].name << "\t" << arr[i].producer << "\t" << arr[i].genre << "\t" << arr[i].top << "\t" << arr[i].price << endl;
		}
	}
}
void find_top_genre(video *arr, int size, char name[]) {
	int top_genre = size;//переменна€ дл€ записи лучшего рейтинга, на начало прохода равно самому низкому рейтингу
	int k;//переменна€ дл€ записи последнего фильма с лучшим рейтингом
	for (int i = 0; i < size; i++) {
		if (arr[i].top <= top_genre && strcmp(arr[i].genre, name) == 0) {//проходим массив сравнива€ рейтинг и жанр, если жанп совпадает а рейтинг лучше записывам
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
char **find_piece_string(char str[]) {
	char a[100];
	strcpy (a,str);
	int k = 0;
	//char c = ' ';
	char **b = new char* [10];
	for (int i = 0; i < 10; i++) {
		//for (int j = 0; j < 20; j++) {
			b[i] = new char[100];
		//}
	}
	for (int i = 0; i < 10; i++) {
		int l = 0;
			for (int j = k; j<sizeof(a)/sizeof(char); j++){
			if (a[j] == '\t') {
				b[i][l] = '\0';
				k++;
				break;
			}
			else {
				b[i][l] = a[j];
				k++;
				l++;

			}
		}
	}
	//for (int i = 0; i < 4; i++) {
	//	cout << endl;
	//	for (int j = 0; j < 100; j++) {
	//		cout << b[i][j];
	//	}
	//}
	return b;
}
char *find_piece_string_2(char str[]) {
	char a[100];
	strcpy(a, str);
	int size = 0;
	for (int i = 0; i < sizeof(a) / sizeof(char);i++) {
		if (a[i] != ' ' && a[i + 1] == ' ' && a[i + 2] == ' ') {
			size++;
			break;
		}
		else {
			size++;
		}
	}
	char *str_1 = new char[size+1];
	for (int i = 0; i < size; i++) {
		str_1[i] = a[i];
	}
	str_1[size] = '\0';
	return str_1;
}
video *create_new_video(char *b[]) {
	video *new_arr = new video;
	strcpy(new_arr->name, *b);
	strcpy(new_arr->producer, *(b + 1));
	strcpy(new_arr->genre, *(b+2));
	new_arr->top = atoi(*(b+3));
	new_arr->price = atof(*(b+4));
	return new_arr;
}
char **add_string_from_file_to_arr(void) {
	ifstream i("video.txt");
	char **str_arr = new char*[100];
	for (int i = 0; i < 100; i++) {
		str_arr[i] = new char[100];
	}
	int k = 0;
	if (i.is_open()) {
		while (!i.eof()) {
			i.getline(str_arr[k],100);
			k++;
		}
	}
	return str_arr;
}
video *create_video_arr(void) {
	video *video_arr = new video[10];
	for (int i = 0; i < 10; i++) {
		strcpy(video_arr[i].name, "No");
		strcpy(video_arr[i].genre, "No");
		strcpy(video_arr[i].producer, "No");
		video_arr[i].top = 0;
		video_arr[i].price = 0.00;
	}
	return video_arr;
}