#include "Header.h"
#include "Header_TEST.h"
int main() {
	true_or_false(test_menu_stat_1_add_one_boiler());
	true_or_false(test_menu_stat_2_show_all_boiler());
	true_or_false(test_menu_stat_3_delete_all_boilers());
	true_or_false(test_menu_stat_4_delete_some_boiler());
	true_or_false(test_menu_stat_5_find_some_boiler());
	true_or_false(test_delete_all_then_delete_some_boiler());
	true_or_false(test_delete_boiler_with_ID0_and_list_empty());
	int end_;
	cin >> end_;
	return 0;
}