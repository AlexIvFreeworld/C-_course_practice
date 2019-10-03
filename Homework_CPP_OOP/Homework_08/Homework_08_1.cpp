#include <iostream>
using namespace std;
struct Elem {
	int data;
	Elem *next, *prev;
};
class List {
	Elem *head, *tail;
	int count;
public:
	List();
	List(const List&L);
	~List();
	int get_count();
	Elem *getElem(int n);
	void del_all();
	void del(int pos = 0);
	void insert(int pos = 0);
	void add_tail(int data);
	void add_head(int data);
	void print(int pos);
	void print();
	List&operator=(const List &L);
	List operator+(const List &L);
	bool operator==(const List &L);
	bool operator!=(const List &L);
	bool operator<=(const List &L);
	bool operator>=(const List &L);
	bool operator<(const List &L);
	bool operator>(const List &L);
	List operator-();
};
List::List() {
	head = tail = NULL;
	count = 0;
}
List::List(const List&L) {
	head = tail = NULL;
	count = 0;
	Elem *temp = L.head;
	while (temp != 0) {
		add_tail(temp->data);
		temp = temp->next;
	}
}
List::~List() {
	del_all();
}
int List::get_count() {
	return count;
}
Elem *List::getElem(int n) {
	Elem *temp = head;
	if (n>count || n<1){
		cout << "Incorrect position " << n << endl;
		return 0;
	}
	else {
		for (int i = 1; i <= n; i++) {
			(i == 1)? temp = temp: temp = temp->next;
		}
	}
	return temp;
}
void List::add_head(int data) {
	Elem *temp = new Elem;
	temp->prev = NULL;
	temp->data = data;
	temp->next = head;
	if (head != NULL) {
		head->prev = temp;
	}
	if (count == 0) {
		head = tail = temp;
	}
	else {
		head = temp;
	}
	count++;
}
void List::add_tail(int data) {
	Elem *temp = new Elem;
	temp->next = NULL;
	temp->data = data;
	temp->prev = tail;
	if (tail != NULL) {
		tail->next = temp;
	}
	if (count == 0) {
		head = tail = temp;
	}
	else {
		tail = temp;
	}
	count++;
}
void List::insert(int pos) {
	if (pos == 0) {
		cout << "Pos = ";
		cin >> pos;
	}
	if (pos < 1 || pos >count + 1) {
		cout << "Error pos " << pos << endl;
		return;
	}
	if (pos == count + 1) {
		int data;
		cout << "Data = ";
		cin >> data;
		add_tail(data);
		return;
	}
	else if (pos == 1) {
		int data;
		cout << "Data = ";
		cin >> data;
		add_head(data);
		return;
	}
	int i = 1;
	Elem *ins = head;
	while (i < pos) {
		ins = ins->next;
		i++;
	}
	Elem *PrevIns = ins->prev;
	Elem *temp = new Elem;
	cout << "Data = ";
	cin >> temp->data;
	if (PrevIns != 0 && count != 1) {
		PrevIns->next = temp;
		temp->next = ins;
		temp->prev = PrevIns;
		ins->prev = temp;
	}
	count++;
}
void List::del(int pos) {
	if (pos == 0) {
		cout << "Pos = ";
		cin >> pos;
	}
	if (pos < 1 || pos >count) {
		cout << "Error pos " << pos << endl;
		return;
	}
	int i = 1;
	Elem *Del = head;
	while (i < pos) {
		Del = Del->next;
		i++;
	}
	Elem *PrevDel = Del->prev;
	Elem *AfterDel = Del->next;
	if (PrevDel != 0 && count != 1) {
		PrevDel->next = AfterDel;
	}
	if (AfterDel != 0 && count != 1) {
		AfterDel->prev = PrevDel;
	}
	if (pos == 1) {
		head = AfterDel;
	}
	if (pos == count) {
		tail = PrevDel;
	}
	delete Del;
	count--;
}
void List::print(int pos) {
	if (pos<1 || pos > count) {
		cout << "Error " << pos << endl;
		return;
	}
	Elem *temp;
	if (pos <= count / 2) {
		int i = 1;
		temp = head;
		while (i < pos) {
			temp = temp->next;
			i++;
		}
	}
	else {
		int i = 1;
		temp = tail;
		while (i <= count - pos) {
			temp = temp->prev;
			i++;
		}
	}
		cout << "Pos = " << pos << "Elem = " << temp->data << endl;
}
void List::print() {
	if (count != 0) {
		Elem *temp = head;
		cout << "( ";
		while (temp->next != 0) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}
void List::del_all() {
	if (count != 0) {
		for (int i = 1; i <= count; i++) {
			del(i);
		}
	}
}
List & List::operator=(const List &L) {
	if (this == &L) {
		return *this;
	}
	del_all();
	Elem *temp = L.head;
	while (temp != NULL) {
		add_tail(temp->data);
		temp = temp->next;
	}
	return *this;
}
List List::operator+(const List &L) {
	//List result(*this);//or List result = *this;
	List result = *this;
	Elem *temp = L.head;
	while (temp != 0) {
		result.add_tail(temp->data);
		temp = temp->next;
	}
	return result;
}
bool List::operator==(const List &L) {
	if (count != L.count) {
		return false;
	}
	Elem *e1, *e2;
	e1 = head;
	e2 = L.head;
	while (e1 != 0) {
		if (e1->data != e2->data) {
			return false;
		}
		e1 = e1->next;
		e2 = e2->next;
	}
	return true;
}
bool List::operator!=(const List &L) {
	return !(*this == L);
}
bool List::operator>=(const List &L) {
	if (count > L.count) {
		return true;
	}
	if (*this == L) {
		return true;
	}
	else false;
}
bool List::operator<=(const List &L) {
	if (count < L.count) {
		return true;
	}
	if (*this == L) {
		return true;
	}
	else false;
}
bool List::operator>(const List &L) {
	if (count > L.count) {
		return true;
	}
}
bool List::operator<(const List &L) {
	if (count < L.count) {
		return true;
	}
}
List List::operator-() {
	List result;
	Elem *temp = head;
	while (temp != 0) {
		result.add_head(temp->data);
		temp = temp->next;
	}
	return result;
}

int main() {
	List L;
	const int n = 10;
	int a[n] = {0,1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			L.add_head(a[i]);
		}
		else {
			L.add_tail(a[i]);
		}
	}
	L.print();
	L.insert();
	L.print(2);
	L.print(8);
	List T;
	T = L;
	T.print();
	List S = -L + T;
	S.print();
	cin.get();
	cin.get();
	return 0;
}