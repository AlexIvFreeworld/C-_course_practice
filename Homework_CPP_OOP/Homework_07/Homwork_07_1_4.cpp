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
class QueuePriorety {
	list *pThead;
	list *pTop;
public:
	QueuePriorety();
	void show_queue();
	void pop(list *L);
	list *push();
};
QueuePriorety::QueuePriorety() {
	pThead = NULL;
	pTop = NULL;
}
void QueuePriorety::show_queue() {
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
void QueuePriorety::pop(list *L) {
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
list *QueuePriorety::push() {
	list *pTemp = pThead;
	list *pTpri = pThead;
	if (pThead == NULL) {
		cout << "The queue already empty!" << endl;
	}
	else if (pThead->pTnext_list == NULL) {
		pThead = NULL;
		pTop = NULL;
		pTpri->set_in_list(false);
	}
	else {
		//to search elem with hight priorety
		while (pTemp->pTnext_list != NULL) {
			pTemp = pTemp->pTnext_list;
			if (pTpri->get_priorety() < pTemp->get_priorety()) {
				pTpri = pTemp;
			}
		}
		pTemp = pThead;
		if (pTpri == pThead) {
			pThead = pTemp->pTnext_list;
			pTemp->pTnext_list = NULL;
			pTpri->set_in_list(false);
		}
		else if (pTpri == pTop) {
			while (pTemp->pTnext_list != pTop) {
				pTemp = pTemp->pTnext_list;
			}
			pTop = pTemp;
			pTop->pTnext_list = NULL;
			pTpri->set_in_list(false);
		}
		else {
			while (pTemp->pTnext_list != pTpri) {
				pTemp = pTemp->pTnext_list;
			}
			pTemp->pTnext_list = pTpri->pTnext_list;
			pTpri->pTnext_list = NULL;
			pTpri->set_in_list(false);
		}
	}
	return pTpri;
}
int main() {
	list L1(1, 10), L2(2, 20), L3(3, 30);
	QueuePriorety QU;
	cout << "------Adding hight priorety first------------" << endl;
	QU.pop(&L3);
	QU.pop(&L2);
	QU.pop(&L1);
	QU.pop(&L3);
	cout << "------Queue after adding hight priorety first-------" << endl;
	QU.show_queue();
	cout << "\n------Extracting priorety list (first)-------" << endl;
	QU.push();
	cout << "\n------Queue after extracting priorety list (first)-------" << endl;
	QU.show_queue();
	cout << "-----------Adding hight priorety last--------------" << endl;
	QU.pop(&L3);
	cout << "------Queue after adding hight priorety last-------" << endl;
	QU.show_queue();
	cout << "\n------Extracting priorety list (last)-------" << endl;
	QU.push();
	cout << "\n------Queue after extracting priorety list (last)-------" << endl;
	QU.show_queue();
	cout << "---------------Extracting one item and adding two item---------------" << endl;
	QU.push();
	QU.pop(&L3);
	QU.pop(&L2);
	cout << "\n------Queue after extracting and adding (hight priorety middle)-------" << endl;
	QU.show_queue();
	cout << "\n------Extracting priorety list (middle)-------" << endl;
	QU.push();
	cout << "\n------Queue after extracting priorety list (middle)-------" << endl;
	QU.show_queue();
	cin.get();
	return 0;
}