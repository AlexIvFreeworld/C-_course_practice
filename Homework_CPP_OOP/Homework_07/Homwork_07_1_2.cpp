#include <iostream>
using namespace std;
class list {
	int priorety;
	int data;
	bool in_list;
public:
	list *pTnext_list;
	list(int d, int pri);
	//void show_list();
	 bool get_in_list();
	 void set_in_list(bool in);
	 int get_data();
	 int get_priorety();
};
list::list(int d, int pri) {
	data = d;
	priorety = pri;
	pTnext_list = NULL;
	in_list = false;
}
//void list::show_list() {
//	cout << data << "[" << priorety << "]" << "   ";
//}
bool list::get_in_list() {
	return in_list;
}
void list::set_in_list(bool in) {
	in_list = in;
}
int list::get_data() {
	return data;
}
int list::get_priorety() {
	return priorety;
}
class queue {
	list *pThead;
	list *pTop;
public:
	queue();
	void show_queue();
	void pop(list *L);
	list *push();
};
queue::queue() {
	pThead = NULL;
	pTop = NULL;
}
void queue::show_queue() {
	list *pTemp = pThead;
	if (pThead == NULL) {
		cout << "The queue is empty" << endl;
	}
	else {
		while (pTemp->pTnext_list != NULL) {
			cout << pTemp->get_data() << "[" << pTemp->get_priorety() << "]" << "   ";
			pTemp = pTemp->pTnext_list;
		}
		cout << pTemp->get_data() << "[" << pTemp->get_priorety() << "]" << "   ";
		cout << endl;
	}
}
void queue::pop(list *L) {
	if (L->get_in_list()) {
		cout << "This list already in the queue!" << endl;
	}
	else {
		list *pTnow = pThead;
		if (pThead == NULL) {
			pThead = L;
			pTop = L;
			L->set_in_list(true);
		}
		else {
			pTop->pTnext_list = L;
			pTop = L;
			L->set_in_list(true);
		}
	}
}
list *queue::push() {
	list *pTemp = pThead;
	if (pThead == NULL) {
		cout << "The queue already empty!" << endl;
	}
	else if (pThead->pTnext_list == NULL) {
		pThead = NULL;
		pTop = NULL;
		pTemp->set_in_list(false);
	}
	else {
		pThead = pTemp->pTnext_list;
		pTemp->pTnext_list = NULL;
		pTemp->set_in_list(false);
	}
	return pTemp;
}
int main() {
	list L1(1, 10), L2(2, 10), L3(3, 10);
	queue QU;
	QU.pop(&L1);
	QU.pop(&L2);
	QU.pop(&L3);
	QU.pop(&L1);
	cout << "------Queue after adding-------" << endl;
	QU.show_queue();
	cout << "\n------Extracting first list-------" << endl;
	QU.push();
	cout << "\n------Queue after extracting first list-------" << endl;
	QU.show_queue();
	cout << "\n------Extracting three lists-------" << endl;
	QU.push();
	QU.push();
	QU.push();
	cout << "\n------Queue after extracting three lists-------" << endl;
	QU.show_queue();
	cin.get();
	return 0;
}