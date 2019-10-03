#include <iostream>
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)
class card {
	char suit[10];
	char name[10];
	int value_1;
	int value_2;
public:
	card *p_next_card;
	card(char s[], char n[]) {
		if (strcmp(n, "ace") == 0) {
			value_1 = 11;
			value_2 = 1;
		}
		else if (strcmp(n, "king") == 0 || strcmp(n, "queen") == 0 || strcmp(n, "jack") == 0) {
			value_1 = value_2 = 10;
		}
		else if (atoi(n) >= 2 && atoi(n) <= 10) {
			value_1 = value_2 = atoi(n);
		}
		else {
			cout << "Incorrect name card" << endl;
		}
		strcpy(name, n);
		if (strcmp(s, "clab") || strcmp(s, "spade") || strcmp(s, "heart") || strcmp(s, "diamond")) {
			strcpy(suit, s);
		}
		else {
			cout << "Incorrect suit card" << endl;
		}
		p_next_card = NULL;
	}
	void show_up() {
		cout << suit << " " << name << " " << endl;
	}
	void show_down() {
		cout << "************" << endl;
	}
	int get_value_1() {
		return value_1;
	}
	int get_value_2() {
		return value_2;
	}
};
class deck {
	card *first_card;
	int amount_cards;
public:
	deck() {
		first_card = NULL;
		amount_cards = 0;
	}
	void fill_deck();
	void shuffle_deck();
	void get_amount_cards();
	void show_deck();
	card *get_first_card() {
		return first_card;
	}
	card *position_P_with_N(int N);
	card *position_P_penultimate();
	void delete_all_card();
};
class dealer;
class player {
	char name[100];
	card *first_player_card;
	int money;
	int bet;
	int num_points;
public:
	player(char n[]){
		strcpy(name, n);
		first_player_card = NULL;
		money = 1000;
		bet = 0;
		num_points = 0;
	}
	void show_money();
	void show_name();
	void show_players_cards();
	void take_card(deck &obj);
	void delete_all_card();
	int make_bet(int b);
	void vin_bet();
	void vin_2_bet();
	void lose_bet();
	card *position_P_end();
	int get_num_points();
	friend int distribution_result(player &P, dealer &D);
	friend int round_result(player &P, dealer &D);
};
class dealer {
	char name[100];
	card *first_dealer_card;
	int num_points;
public:
	dealer() {
		strcpy(name,"Dealer");
		first_dealer_card = NULL;
		num_points = 0;
	}
	void show_name();
	void show_dealer_cards();
	void take_card(deck &obj);
	void delete_all_card();
	card *position_P_end();
	int get_num_points();
	friend int distribution_result(player &P, dealer &D);
	friend int round_result(player &P, dealer &D);
};
void black_jack();
int any_enter(char str[]);