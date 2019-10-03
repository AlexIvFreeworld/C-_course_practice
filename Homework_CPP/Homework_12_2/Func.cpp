#include "Header.h"
#include "Header_TEST.h"
void set_boiler(list_boiler *L_boiler, string Brand, string Model, int Volume, int Price, int Power) {
	for (int i = 0; i < L_boiler->stat_ID; i++) {
		if (L_boiler->P_arr_boiler[i].ID == 0) {
			L_boiler->P_arr_boiler[i].ID = L_boiler->stat_ID;
			L_boiler->P_arr_boiler[i].brand = Brand;
			L_boiler->P_arr_boiler[i].model = Model;
			L_boiler->P_arr_boiler[i].Volume = Volume;
			L_boiler->P_arr_boiler[i].price = Price;
			L_boiler->P_arr_boiler[i].power = Power;
			L_boiler->sum_boiler++;
			L_boiler->stat_ID++;
			break;
			}
	}
}
void show_all_boiler(list_boiler *L_boiler) {
	if (L_boiler->sum_boiler == 0) {
#ifndef TEST
		cout << "The List is empty" << endl;
#else
		L_boiler->res_test = 1;
#endif
	}
	else {
		for (int i = 0; i < L_boiler->stat_ID; i++) {
			if (L_boiler->P_arr_boiler[i].ID > 0) {
#ifndef TEST
				cout << "\n" << L_boiler->P_arr_boiler[i].ID << "\t";
				cout << L_boiler->P_arr_boiler[i].brand << "\t";
				cout << L_boiler->P_arr_boiler[i].model << "\t";
				cout << L_boiler->P_arr_boiler[i].Volume << "\t";
				cout << L_boiler->P_arr_boiler[i].price << "\t";
				cout << L_boiler->P_arr_boiler[i].power << endl;
#else
				L_boiler->res_test = 2;
#endif
			}
		}
		cout << L_boiler->sum_boiler << endl;
        cout << L_boiler->stat_ID << endl;
	}
}
void delete_all_boiler(list_boiler *L_boiler) {
	for (int i = 0; i < L_boiler->stat_ID; i++) {
		L_boiler->P_arr_boiler[i].ID = 0;
	}
	L_boiler->sum_boiler = 0;
#ifndef TEST
	cout << "List cleared" << endl;
#else
	L_boiler->res_test = 1;
#endif
}
void find_boiler_with_model(list_boiler *L_boiler, string Model) {
	int num_item_found = 0;
	for (int i = 0; i < L_boiler->stat_ID; i++) {
		if (L_boiler->P_arr_boiler[i].model == Model && L_boiler->P_arr_boiler[i].ID > 0) {
#ifndef TEST
			cout << "\n" << L_boiler->P_arr_boiler[i].ID << "\t";
			cout << L_boiler->P_arr_boiler[i].brand << "\t";
			cout << L_boiler->P_arr_boiler[i].model << "\t";
			cout << L_boiler->P_arr_boiler[i].Volume << "\t";
			cout << L_boiler->P_arr_boiler[i].price << "\t";
			cout << L_boiler->P_arr_boiler[i].power << endl;
#else
			L_boiler->res_test = 1;
#endif
			num_item_found++;
		}
	}
#ifndef TEST
	num_item_found > 0 ? cout << "Found " << num_item_found << " boiler" : cout << "Boiler is not found";
#else
	num_item_found > 0 ? 0: L_boiler->res_test = 2;
#endif
}
void delete_some_boiler(list_boiler *L_boiler, int ID) {
	for (int i = 0; i < L_boiler->stat_ID; i++) {
		if (L_boiler->P_arr_boiler[i].ID == ID) {
			L_boiler->P_arr_boiler[i].ID = 0;
			L_boiler->sum_boiler--;
#ifdef TEST
			L_boiler->res_test = 1;
#endif
		}
	}
}
list_boiler *create_new_list_boiler() {
	list_boiler L_boiler;
	L_boiler.P_arr_boiler = new boiler[100];
	L_boiler.sum_boiler = 0;
	L_boiler.stat_ID = 1;
	L_boiler.res_test = 0;
	return &L_boiler;
}
int get_int() {
	char change_h[10];
	int change;
	cin >> change_h;
	change = atoi(change_h);
	return change;
	}
string get_str() {
	string str;
	getline(cin, str);
	return str;
}
void menu(list_boiler *L_boiler, int change_test, int change_ID) {
	string Brand, Model, basket;
	int Volume, Price, Power, change, ID;
	char change_h[10];

	do {
#ifndef TEST
		cout << "\n\nEnter some number: 1 - Add new boiler, 2 - Show all boiler's, ";
		cout << "3 - Delete all boiler's, 4 - Delete some boiler, 5 - Find boiler with model ";
		cout << "6 - Out from menu" << endl;
#endif
        #ifndef TEST
		change = get_int();
		system("cls");
        #else
		change = get_int_test(change_test);
		#endif
		switch (change) {
		case 1:
#ifndef TEST
			getline(cin, basket);
#endif
			#ifndef TEST
			cout << "Enter Brand " << endl;
			Brand = get_str();
            #else
			Brand = get_str_test();
            #endif
            #ifndef TEST
			cout << "Enter Model " << endl;
			Model = get_str();
            #else
			Model = get_str_test();
            #endif
#ifndef TEST
			cout << "Enter Volume " << endl;
			Volume = get_int();
#else
			Volume = get_int_test_1();
#endif
#ifndef TEST
			cout << "Enter Price " << endl;
			Price = get_int();
#else
			Price = get_int_test_1();
#endif
#ifndef TEST
			cout << "Enter Power " << endl;
			Power = get_int();
#else
			Power = get_int_test_1();
#endif
			set_boiler(L_boiler, Brand, Model, Volume, Price, Power);
#ifdef TEST
			change = 6;
#endif
			break;
		case 2:
			show_all_boiler(L_boiler);
#ifdef TEST
			change = 6;
#endif
			break;
		case 3:
			delete_all_boiler(L_boiler);
#ifdef TEST
			change = 6;
#endif
			break;
		case 4:
#ifndef TEST
			show_all_boiler(L_boiler);
			cout << "Enter ID to delete boiler" << endl;
			cin >> ID;
#else
			ID = change_ID;
#endif
			delete_some_boiler(L_boiler, ID);
#ifdef TEST
			change = 6;
#endif
			break;
		case 5:
#ifndef TEST
			getline(cin, basket);
			cout << "Enter Model for searching" << endl;
			getline(cin, Model);
#else
			Model = "Model_2";
#endif
			find_boiler_with_model(L_boiler, Model);
#ifdef TEST
			change = 6;
#endif
			break;
		case 6:
			break;
		default:
			cout << "Wrong number";
		}
	} while (change != 6);
}
void boilers() {
	list_boiler L_boiler = *create_new_list_boiler();
	menu(&L_boiler, 0,0);
	delete[] L_boiler.P_arr_boiler;
}