#include <iostream>
#include <string>
using namespace std;
#ifndef BOILER_H
#define BOILER_H
struct boiler {
	int ID = 0;
	string brand;
	string model;
	int Volume;
	int price;
	int power;
};
#endif
#ifndef LIST_BOILER_H
#define LIST_BOILER_H
struct list_boiler {
	boiler *P_arr_boiler;
	int sum_boiler;
	int stat_ID;
	int res_test;
};
#endif
void set_boiler(list_boiler *L_boiler, string Brand, string Model, int Volume, int Price, int Power);
void show_all_boiler(list_boiler *L_boiler);
void delete_all_boiler(list_boiler *L_boiler);
void find_boiler_with_model(list_boiler *L_boiler, string Model);
void delete_some_boiler(list_boiler *L_boiler, int ID);
void menu(list_boiler *L_boiler, int change_test, int change_ID);
list_boiler *create_new_list_boiler();
int get_int();
string get_str();
void boilers();