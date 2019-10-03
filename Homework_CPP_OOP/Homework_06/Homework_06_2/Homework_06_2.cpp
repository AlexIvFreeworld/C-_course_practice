#include "Homework_06_2.h"
int main() {
	black_jack();
 	cin.get();
	return 0;
}
void deck::fill_deck() {
	char suit[10];
	char name[10];
	card *p_new_card = 0;
	for (int i = 1; i <= 4; i++) {
		switch (i) {
		case 1:
			strcpy(suit, "clab");
			break;
		case 2:
			strcpy(suit, "spade");
			break;
		case 3:
			strcpy(suit, "heart");
			break;
		case 4:
			strcpy(suit, "diamond");
			break;
		default:
			cout << "Error make suit" << endl;
		}
		for (int j = 2; j <= 14; j++) {
			(j == 11) ? strcpy(name, "jack") : 0;
			(j == 12) ? strcpy(name, "queen") : 0;
			(j == 13) ? strcpy(name, "king") : 0;
			(j == 14) ? strcpy(name, "ace") : 0;
			(j>=2 && j<=10)?itoa(j, name, 10):0;
			if (i == 1 && j == 2) {
				first_card = new card(suit, name);
				amount_cards++;
				p_new_card = first_card;
			}
			else {
				p_new_card->p_next_card = new card(suit, name);
				amount_cards++;
				p_new_card = p_new_card->p_next_card;
			}
		}
	}
}
void black_jack() {
	cout << "New game" << endl;
	deck *pTdeck = new deck;
	char player_name[100];
	cout << "Enter your name" << endl;
	gets_s(player_name);
	player *pTplayer = new player(player_name);
	dealer *pTdealer = new dealer;
	//подготовка - очистить колоду, заполнить, перемешать
	int game=1;
	char game_ch[100];
	do {
		//system("cls");
		int distribution=1;
		do {
			cout << "--------------------------------------------" << endl;
			pTdeck->delete_all_card();
			pTplayer->delete_all_card();
			pTdealer->delete_all_card();
			cout << "--------------------------------------------" << endl;
			pTdeck->fill_deck();
			pTdeck->shuffle_deck();
			system("cls");
			//показать состояние игрока, запросить ставку у игрока, сделать ставку
			pTplayer->show_money();
			int bet=1;
			char bet_ch[100];
			cout << "Enter your bet" << endl;
			bet = atoi(gets_s(bet_ch));
			distribution = pTplayer->make_bet(bet);
			if (distribution == 3) continue;
			else if(distribution == 4) {
				distribution = 1;
				continue;
			}
			//раздать по две карты дилеру и игроку, показать результат раздачи
			pTplayer->take_card(*pTdeck);
			pTplayer->take_card(*pTdeck);
			pTdealer->take_card(*pTdeck);
			pTdealer->take_card(*pTdeck);
			distribution = distribution_result(*pTplayer, *pTdealer);
		} while (distribution == 1);
		//запросить игрока взять карту, взять карту дилеру, показать результаты раунда
		if (distribution == 2) {
			int change_1=2;
			char change_ch[100];
			do {
				cout << "Do you take card? (yes - 1/no - 0)" << endl;
				gets_s(change_ch);
				change_1 = any_enter(change_ch);
				if (change_1 == 1) {
					pTplayer->take_card(*pTdeck);
					if (pTdealer->get_num_points() <= 17) pTdealer->take_card(*pTdeck);
					//посчитать результат, перебор, блэк джек или можно еще
					//если можно еще предложить игроку карту (вернуться в начало блока)
					change_1 = round_result(*pTplayer, *pTdealer);
				}
				else if (change_1 == 0) {
					//посчитать результат, вывести на экран, отдать стввку победителю
					if (pTplayer->get_num_points() > pTdealer->get_num_points()) {
						cout << "----------------Player vin----------------" << endl;
						pTplayer->show_players_cards();
						cout << "Player has " << pTplayer->get_num_points() << " points" << endl;
						pTdealer->show_dealer_cards();
						cout << "Dealer has " << pTdealer->get_num_points() << " points" << endl;
						pTplayer->vin_2_bet();
					}
					else if (pTplayer->get_num_points() < pTdealer->get_num_points()) {
						cout << "----------------Dealer vin----------------" << endl;
						pTplayer->show_players_cards();
						cout << "Player has " << pTplayer->get_num_points() << " points" << endl;
						pTdealer->show_dealer_cards();
						cout << "Dealer has " << pTdealer->get_num_points() << " points" << endl;
						pTplayer->lose_bet();
					}
					else if (pTplayer->get_num_points() == pTdealer->get_num_points()) {
						cout << "----------------Dead heat----------------" << endl;
						pTplayer->show_players_cards();
						cout << "Player has " << pTplayer->get_num_points() << " points" << endl;
						pTdealer->show_dealer_cards();
						cout << "Dealer has " << pTdealer->get_num_points() << " points" << endl;
						pTplayer->vin_bet();
					}
				}
			} while (change_1 == 1);
		}
		else {
			game = 0;
		}
		if (game != 0) {
			cout << "Continue this game? (yes - 1, no - 0)" << endl;
			gets_s(game_ch);
			game = any_enter(game_ch);
			//system("cls");
		}
	} while (game == 1);
	pTdeck->delete_all_card();
	pTplayer->delete_all_card();
	pTdealer->delete_all_card();
	delete pTdeck;
	delete pTplayer;
	delete pTdealer;
	cout << "Game over" << endl;
	cin.get();
}
void deck::show_deck() {
	card *pTcard = first_card;
	if (first_card == NULL) {
		cout << "Deck is empty" << endl;
	}
	else {
		while (pTcard->p_next_card != NULL) {
			pTcard->show_up();
			pTcard = pTcard->p_next_card;
		}
		pTcard->show_up();
	}
}
void deck::shuffle_deck() {
	srand(time(NULL));
	card *P1, *P2, *P_end;
	int N;
	if (first_card == NULL) {
		cout << "Deck is empty" << endl;
	}
	else {
		for (int i = 1; i <= 52; i++) {
			N = rand() % 26 + 1;
			P1 = position_P_with_N(N);
			P2 = P1->p_next_card;
			P_end = position_P_with_N(52);
			P_end->p_next_card = P2;
			P1->p_next_card = P_end;
			position_P_with_N(52)->p_next_card = 0;
		}
	}
}
card *deck::position_P_with_N(int N) {
	card *P = first_card;
	for (int i = 1; i <= N; i++) {
		(i == 1) ? 0 : P = P->p_next_card;
	}
	return P;
}
void deck::get_amount_cards() {
	cout << "Amount cards " << amount_cards << endl;
}
void player::take_card(deck &obj) {
	card *P_p, *P_end;
	if (obj.get_first_card() == NULL) {
		cout << "Deck is empty " << endl;
	}
	else {
		if (first_player_card == NULL) {
			P_p = obj.position_P_penultimate();
			first_player_card = obj.position_P_penultimate()->p_next_card;
			P_p->p_next_card = NULL;
			(num_points <= 21)? num_points += first_player_card->get_value_1():num_points += first_player_card->get_value_2();
		}
		else {
			P_p = obj.position_P_penultimate();
			P_end = position_P_end();
			P_end->p_next_card = obj.position_P_penultimate()->p_next_card;
			P_p->p_next_card = NULL;
			(num_points <= 21) ? num_points += P_end->p_next_card->get_value_1() : num_points += P_end->p_next_card->get_value_2();
		}
	}
}
card *deck::position_P_penultimate() {
	card *P_end = first_card;
	if (first_card == NULL) {
		cout << "Deck is empty" << endl;
	}
	else {
		while (P_end->p_next_card->p_next_card != NULL) {
			P_end = P_end->p_next_card;
		}
	}
	return P_end;
}
card *player::position_P_end() {
	card *P_end = first_player_card;
	if (first_player_card == NULL) {
		cout << "Player has not any cards" << endl;
	}
	else {
		while (P_end->p_next_card != NULL) {
			P_end = P_end->p_next_card;
		}
	}
	return P_end;
}
void player::show_players_cards() {
	card *pTcard = first_player_card;
	if (first_player_card == NULL) {
		cout << "Player has not any cards" << endl;
	}
	else {
		cout << "Player has any cards" << endl;
		while (pTcard->p_next_card != NULL) {
			pTcard->show_up();
			pTcard = pTcard->p_next_card;
		}
		pTcard->show_up();
	}
}
int player::make_bet(int b) {
	if (b <= money && b!=0 && money>0) {
		money -= b;
		bet = b;
		return 1;
	}
	else if(b > money && money==0 || b==0 && money==0){
		cout << "----------Do not enouth money------------" << endl;
		return 3;
	}
	else if (b == 0 && money>0) {
		cout << "--------------Increase your bet-------------" << endl;
		return 4;
	}
	else {
		cout << "---------------Do not enouth money-----------" << endl;
		return 4;
	}
}
void player::delete_all_card() {
	card *P_s;
	if (first_player_card == NULL) {
		cout << "Player has not any cards" << endl;
	}
	else {
		while (first_player_card->p_next_card != NULL) {
			P_s = first_player_card;
			first_player_card = first_player_card->p_next_card;
			delete P_s;
		}
		P_s = first_player_card;
		first_player_card = NULL;
		delete P_s;
	}
	num_points = 0;
}
void deck::delete_all_card() {
	card *P_s;
	if (first_card == NULL) {
		cout << "Deck is empty" << endl;
	}
	else {
		while (first_card->p_next_card != NULL) {
			P_s = first_card;
			first_card = first_card->p_next_card;
			delete P_s;
		}
		P_s = first_card;
		first_card = NULL;
		delete P_s;
	}
}
void player::show_money() {
	cout << "Player " << name << " has " << money << " $" << endl;
}
void player::show_name() {
	cout << "Player " << name << endl;
}
void player::vin_bet() {
	money += bet;
	bet = 0;
}
void player::vin_2_bet() {
	money += bet*2;
	bet = 0;
}
void player::lose_bet() {
	bet = 0;
}
void dealer::show_name() {
	cout << name << endl;
}
void dealer::show_dealer_cards() {
	card *pTcard = first_dealer_card;
	if (first_dealer_card == NULL) {
		cout << "Dealer has not any cards" << endl;
	}
	else {
		cout << "Dealer has any cards" << endl;
		while (pTcard->p_next_card != NULL) {
			if (pTcard == first_dealer_card) {
				pTcard->show_down();
			}
			else {
				pTcard->show_up();
			}
			pTcard = pTcard->p_next_card;
		}
		pTcard->show_up();
	}
}
void dealer::take_card(deck &obj) {
	card *P_p, *P_end;
	if (obj.get_first_card() == NULL) {
		cout << "Deck is empty " << endl;
	}
	else {
		if (first_dealer_card == NULL) {
			P_p = obj.position_P_penultimate();
			first_dealer_card = obj.position_P_penultimate()->p_next_card;
			P_p->p_next_card = NULL;
			(num_points <= 21) ? num_points += first_dealer_card->get_value_1() : num_points += first_dealer_card->get_value_2();

		}
		else {
			P_p = obj.position_P_penultimate();
			P_end = position_P_end();
			P_end->p_next_card = obj.position_P_penultimate()->p_next_card;
			P_p->p_next_card = NULL;
			(num_points <= 21) ? num_points += P_end->p_next_card->get_value_1() : num_points += P_end->p_next_card->get_value_2();
		}
	}
}
void dealer::delete_all_card() {
	card *P_s;
	if (first_dealer_card == NULL) {
		cout << "Dealer has not any cards" << endl;
	}
	else {
		while (first_dealer_card->p_next_card != NULL) {
			P_s = first_dealer_card;
			first_dealer_card = first_dealer_card->p_next_card;
			delete P_s;
		}
		P_s = first_dealer_card;
		first_dealer_card = NULL;
		delete P_s;
	}
	num_points = 0;
}
card *dealer::position_P_end() {
	card *P_end = first_dealer_card;
	if (first_dealer_card == NULL) {
		cout << "Dealer has not any cards" << endl;
	}
	else {
		while (P_end->p_next_card != NULL) {
			P_end = P_end->p_next_card;
		}
	}
	return P_end;
}
int player::get_num_points() {
	return num_points;
}
int dealer::get_num_points() {
	return num_points;
}
int distribution_result(player &P, dealer &D) {
	int pl = P.get_num_points();
	int di = D.get_num_points();
	int change=1;
	char change_ch[100];
	if (pl == 21 && di == 21) {
		cout << "----------------Dead heat---------------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//возврат ставки игроку
		P.vin_bet();
		//запрос на начало новой игры или выход
		cout << "Continue game (1) or quit game(0)?" << endl;
		gets_s(change_ch);
		change = any_enter(change_ch);
	}
	else if (pl == 21 && di < 21 || pl == 21 && di > 21) {
		cout << "----------------Black jack---------------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//возврат ставки игроку в двойном размере
		P.vin_2_bet();
		//запрос на начало новой игры или выход
		cout << "Continue game (1) or quit game(0)?" << endl;
		gets_s(change_ch);
		change = any_enter(change_ch);

	}
	else if (pl < 21 && di < 21) {
		//карты игрока и дилера на экран
		cout << "--------------------------------------------" << endl;
		P.show_players_cards();
		cout << "--------------------------------------------" << endl;
		D.show_dealer_cards();
		cout << "--------------------------------------------" << endl;
		//переход на начало кона
		change = 2;
	}
	else if (pl > 21 && di <= 21) {
		cout << "----------------A lot at player----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//забрать у игрока ставку
		P.lose_bet();
		//запрос на начало новой игры или выход
		cout << "Continue game (1) or quit game(0)?" << endl;
		gets_s(change_ch);
		change = any_enter(change_ch);

	}
	else if (pl > 21 && di > 21) {
		cout << "----------------A lot at player and dealer----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//вернуть ставку игроку
		P.vin_bet();
		//запрос на начало новой игры или выход
		cout << "Continue game (1) or quit game(0)?" << endl;
		gets_s(change_ch);
		change = any_enter(change_ch);

	}
	else if (pl < 21 && di > 21) {
		cout << "----------------A lot at dealer----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//вернуть ставку игроку
		P.vin_2_bet();
		//запрос на начало новой игры или выход
		cout << "Continue game (1) or quit game(0)?" << endl;
		gets_s(change_ch);
		change = any_enter(change_ch);

	}
	else if (pl < 21 && di == 21) {
		cout << "----------------Dealer has black jack----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//забрать ставку игрока
		P.lose_bet();
		//запрос на начало новой игры или выход
		cout << "Continue game (1) or quit game(0)?" << endl;
		gets_s(change_ch);
		change = any_enter(change_ch);
	}
	return change;
}
int round_result(player &P, dealer &D) {
	int pl = P.get_num_points();
	int di = D.get_num_points();
	int change=2;
	if (pl == 21 && di == 21) {
		cout << "----------------Dead heat----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//возврат ставки игроку
		P.vin_bet();
		change = 2;
	}
	else if (pl == 21 && di < 21 || pl == 21 && di > 21) {
		cout << "----------------Black jack----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//возврат ставки игроку в двойном размере
		P.vin_2_bet();
		change = 2;
	}
	else if (pl < 21 && di < 21) {
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		D.show_dealer_cards();
		//переход на начало кона
		change = 1;
	}
	else if (pl > 21 && di < 21) {
		cout << "----------------A lot at player----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//забрать у игрока ставку
		P.lose_bet();
		change = 2;
	}
	else if (pl > 21 && di > 21) {
		cout << "----------------A lot at player and dealer----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//вернуть ставку игроку
		P.vin_bet();
		change = 2;
	}
	else if (pl < 21 && di > 21) {
		cout << "----------------A lot at dealer----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//вернуть ставку игроку
		P.vin_2_bet();
		change = 2;
	}
	else if (pl < 21 && di == 21) {
		cout << "----------------Dealer has black jack----------------" << endl;
		//результаты по игроку и дилеру на экран
		P.show_players_cards();
		cout << "Amount points " << P.get_num_points() << endl;
		D.show_dealer_cards();
		cout << "Amount points " << D.get_num_points() << endl;
		//забрать ставку игрока
		P.lose_bet();
		change = 2;
	}
	return change;
}
int any_enter(char str[]) {
	int n = atoi(str);
	(n >= 1) ? n = 1 : n = 0;
	return n;
}