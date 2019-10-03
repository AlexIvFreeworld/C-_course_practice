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
class stack {
	list *pThead;
	list *pTop;
public:
	stack();
	void show_stack();
	void pop(list *L);
	list *push();
};
stack::stack() {
	pTop = NULL;
	pThead = NULL;
}
void stack::show_stack() {
	list *pTemp = pThead;
	if (pThead == NULL) {
		cout << "The stack is empty" << endl;
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
void stack::pop(list *L) {
	if (L->get_in_list()) {
		cout << "This list already in the stack!" << endl;
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
list *stack::push() {
	list *pTemp = pThead;
	if (pThead == NULL) {
		cout << "The stack is already empty!" << endl;
	}
	else if (pThead->pTnext_list == NULL) {
		pTemp = pTop;
		pTop = NULL;
		pThead = NULL;
		pTemp->set_in_list(false);
	}
	else {
		while (pTemp->pTnext_list != pTop) {
			pTemp = pTemp->pTnext_list;
		}
		pTop = pTemp;
		pTemp = pTop->pTnext_list;
		pTop->pTnext_list = NULL;
		pTemp->set_in_list(false);
	}
	return pTemp;
}
int main() {
	list L1(1, 10), L2(2, 10), L3(3, 10);
	stack ST;
	cout << "------Adding-------" << endl;
	ST.pop(&L1);
	ST.pop(&L2);
	ST.pop(&L3);
	ST.pop(&L1);
	ST.pop(&L2);
	cout << "------Stack after adding-------" << endl;
	ST.show_stack();
	cout << "\n------Extracting-------" << endl;
	ST.push();
	ST.push();
	ST.push();
	ST.push();
	ST.push();
	cout << "\n------Stack after extracting-------" << endl;
	ST.show_stack();
	cin.get();
	return 0;
}