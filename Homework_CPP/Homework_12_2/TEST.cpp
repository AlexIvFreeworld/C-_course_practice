#include "Header.h"
#include "Header_TEST.h"
bool test_menu_stat_1_add_one_boiler() {
int ID = 1;
string Brand = "Something";
string Model = "Something";
int Volume = 400;
int Price = 400;
int Power = 400;
int sum_boiler = 1;
int state_ID = 2;
int sum_mistake = 0;
int change_test = 1;
list_boiler L_boiler = *create_new_list_boiler();
menu(&L_boiler, change_test,0);
L_boiler.P_arr_boiler[0].ID != 1 ? sum_mistake++:0;
L_boiler.P_arr_boiler[0].brand != Brand ? sum_mistake++ : 0;
L_boiler.P_arr_boiler[0].model != Model ? sum_mistake++ : 0;
L_boiler.P_arr_boiler[0].Volume != Volume ? sum_mistake++ : 0;
L_boiler.P_arr_boiler[0].price != Price ? sum_mistake++ : 0;
L_boiler.P_arr_boiler[0].power != Power ? sum_mistake++ : 0;
L_boiler.sum_boiler != sum_boiler ? sum_mistake++ : 0;
L_boiler.stat_ID != state_ID ? sum_mistake++ : 0;
cout << "test_menu_stat_1_add_one_boiler is : ";
return sum_mistake == 0 ? true : false;
delete[] L_boiler.P_arr_boiler;
}
void true_or_false(bool x) {
	x == true ? cout << "OK" << endl: cout << "Error" << endl;
}
int get_int_test(int change_test) {
	int change = change_test;
	return change;
}
int get_int_test_1() {
	int change = 400;
	return change;
}
string get_str_test() {
	string str = "Something";
	return str;
}
bool test_menu_stat_2_show_all_boiler() {
	int change_test = 2;
	list_boiler L_boiler = *create_new_list_boiler();
	menu(&L_boiler, change_test,0);
	cout << "test_menu_stat_2_show_all_boiler is : ";
	return L_boiler.res_test != 0 ? true : false;
	delete[] L_boiler.P_arr_boiler;
}
bool test_menu_stat_3_delete_all_boilers() {
	list_boiler L_boiler = *create_new_list_boiler();
	int sum_mistake = 0;
	int change_test = 1;
	menu(&L_boiler, change_test,0);
	change_test = 1;
	menu(&L_boiler, change_test,0);
	change_test = 1;
	menu(&L_boiler, change_test,0);
	change_test = 3;
	menu(&L_boiler, change_test,0);
	cout << "test_menu_stat_3_delete_all_boilers is : ";
	L_boiler.sum_boiler == 0 ? 0:sum_mistake++;
	L_boiler.stat_ID == 1 ? 0:sum_mistake++;
	L_boiler.res_test != 0 ? 0 : sum_mistake++;
	return sum_mistake == 0 ? true : false;
	delete[] L_boiler.P_arr_boiler;
}
bool test_menu_stat_4_delete_some_boiler() {
	list_boiler L_boiler = *create_new_list_boiler();
	int sum_mistake = 0;
	int change_test = 1;
	int change_ID = 2;
	menu(&L_boiler, change_test, change_ID);
	change_test = 1;
	menu(&L_boiler, change_test,change_ID);
	change_test = 1;
	menu(&L_boiler, change_test, change_ID);
	change_test = 4;
	menu(&L_boiler, change_test,change_ID);
	cout << "test_menu_stat_4_delete_some_boiler is : ";
	L_boiler.sum_boiler == 2 ? 0 : sum_mistake++;
	L_boiler.stat_ID == 4 ? 0 : sum_mistake++;
	L_boiler.P_arr_boiler[change_ID-1].ID == 0 ? 0 : sum_mistake++;
	return sum_mistake == 0 ? true : false;
	delete[] L_boiler.P_arr_boiler;
}
bool test_menu_stat_5_find_some_boiler() {
	list_boiler L_boiler = *create_new_list_boiler();
	set_boiler(&L_boiler, "Brand_1", "Model_1", 100, 100, 100);
	set_boiler(&L_boiler, "Brand_2", "Model_2", 200, 200, 200);
	set_boiler(&L_boiler, "Brand_3", "Model_3", 300, 300, 300);
	int change_test = 5;
	menu(&L_boiler, change_test, 0);
	cout << "test_menu_stat_5_find_some_boiler is : ";
	return L_boiler.res_test == 1 ? true : false;
	delete[] L_boiler.P_arr_boiler;
}
bool test_delete_all_then_delete_some_boiler() {
	list_boiler L_boiler = *create_new_list_boiler();
	int sum_mistake = 0;
	set_boiler(&L_boiler, "Brand_1", "Model_1", 100, 100, 100);
	set_boiler(&L_boiler, "Brand_2", "Model_2", 200, 200, 200);
	set_boiler(&L_boiler, "Brand_3", "Model_3", 300, 300, 300);
	int change_test = 3;
	menu(&L_boiler, change_test, 0);
	L_boiler.res_test = 0;
	change_test = 4;
	int change_ID = 2;
	menu(&L_boiler, change_test, change_ID);
	cout << "test_delete_all_then_delete_some_boiler is : ";
	L_boiler.res_test == 1 ? sum_mistake++ : 0;
	L_boiler.sum_boiler != 0 ? sum_mistake++ : 0;
	return sum_mistake == 0 ? true : false;
	delete[] L_boiler.P_arr_boiler;
}
bool test_delete_boiler_with_ID0_and_list_empty() {
	list_boiler L_boiler = *create_new_list_boiler();
	int sum_mistake = 0;
	int change_test = 4;
	int change_ID = 0;
	menu(&L_boiler, change_test, change_ID);
	cout << "test_delete_all_then_delete_some_boiler is : ";
	L_boiler.res_test == 1 ? sum_mistake++ : 0;
	L_boiler.sum_boiler != 0 ? sum_mistake++ : 0;
	return sum_mistake == 0 ? true : false;
	delete[] L_boiler.P_arr_boiler;
}