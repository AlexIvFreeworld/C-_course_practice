#include <iostream>
#include <string>
using namespace std;
template <typename T, typename Y> struct MyData {
	T data_T;
	Y data_Y;
};
template <typename D> struct Elem {
	D data_elem;
	Elem *next, *prev;
	bool type_data_struct;
};
template <typename D> class List {
	Elem<D> *head, *tail;
	int count;
public:
	List();
	List(const List&L);
	~List();
	int get_count();
	Elem<D> *getElem(int n);
	void del_all();
	void del(int pos = 0);
	void insert(int pos = 0);
	void insert_my(int pos, D data);
	void add_tail(D data);
    void add_head(D data);
	void print(int pos);
	void print();
	void print_my();
	void print_my(int pos);
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
template <typename D>List<D>::List<D>() {
	head = tail = NULL;
	count = 0;
}
template <typename D>List<D>::List<D>(const List&L) {
	head = tail = NULL;
	count = 0;
	Elem<D> *temp = L.head;
	while (temp != 0) {
		add_tail(temp->data_elem);
		temp = temp->next;
	}
}
template <typename D>List<D>::~List() {
	del_all();
}
template <typename D> int List<D>::get_count() {
	return count;
}
template <typename D> Elem<D> *List<D>::getElem(int n) {
	Elem<D> *temp = head;
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
template <typename D> void List<D>::add_head(D data) {
	Elem<D> *temp = new Elem<D>;
	temp->prev = NULL;
	temp->data_elem = data;
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
template <typename D> void List<D>::add_tail(D data) {
	Elem<D> *temp = new Elem<D>;
	temp->next = NULL;
	temp->data_elem = data;
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
template <typename D> void List<D>::insert(int pos) {
	if (pos == 0) {
		cout << "Pos = ";
		cin >> pos;
	}
	if (pos < 1 || pos >count + 1) {
		cout << "Error pos " << pos << endl;
		return;
	}
	if (pos == count + 1) {
		D data;
		cout << "Data = ";
		cin >> data;
		add_tail(data);
		return;
	}
	else if (pos == 1) {
		D data;
		cout << "Data = ";
		cin >> data;
		add_head(data);
		return;
	}
	int i = 1;
	Elem<D> *ins = head;
	while (i < pos) {
		ins = ins->next;
		i++;
	}
	Elem<D> *PrevIns = ins->prev;
	Elem<D> *temp = new Elem<D>;
	cout << "Data = ";
	cin >> temp->data_elem;
	if (PrevIns != 0 && count != 1) {
		PrevIns->next = temp;
		temp->next = ins;
		temp->prev = PrevIns;
		ins->prev = temp;
	}
	count++;
}
template <typename D>void List<D>::del(int pos) {
	if (pos == 0) {
		cout << "Pos = ";
		cin >> pos;
	}
	if (pos < 1 || pos >count) {
		cout << "Error pos " << pos << endl;
		return;
	}
	int i = 1;
	Elem<D>*Del = head;
	while (i < pos) {
		Del = Del->next;
		i++;
	}
	Elem<D> *PrevDel = Del->prev;
	Elem<D> *AfterDel = Del->next;
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
template <typename D>void List<D>::print(int pos) {
	if (pos<1 || pos > count) {
		cout << "Error " << pos << endl;
		return;
	}
	Elem<D> *temp;
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
		cout << "Pos = " << pos << " Elem = " << temp->data_elem << endl;
}
template <typename D>void List<D>::print() {
	Elem<D> *temp = head;
		if (count != 0) {
			cout << "( ";
			while (temp->next != 0) {
				cout << temp->data_elem << ", ";
				temp = temp->next;
			}
			cout << temp->data_elem << " )\n";
		}
}
template <typename D> void List<D>::del_all() {
	if (count != 0) {
		for (int i = 1; i <= count; i++) {
			del(i);
		}
	}
}
template <typename D> List<D> & List<D>::operator=(const List &L) {
	if (this == &L) {
		return *this;
	}
	del_all();
	Elem<D> *temp = L.head;
	while (temp != NULL) {
		add_tail(temp->data_elem);
		temp = temp->next;
	}
	return *this;
}
template <typename D>List<D> List<D>::operator+(const List &L) {
	//List result(*this);//or List result = *this;
	List result = *this;
	Elem<D> *temp = L.head;
	while (temp != 0) {
		result.add_tail(temp->data_elem);
		temp = temp->next;
	}
	return result;
}
template <typename D> bool List<D>::operator==(const List &L) {
	if (count != L.count) {
		return false;
	}
	Elem<D> *e1, *e2;
	e1 = head;
	e2 = L.head;
	while (e1 != 0) {
		if (e1->data_elem != e2->data_elem) {
			return false;
		}
		e1 = e1->next;
		e2 = e2->next;
	}
	return true;
}
template <typename D> bool List<D>::operator!=(const List &L) {
	return !(*this == L);
}
template <typename D> bool List<D>::operator>=(const List &L) {
	if (count > L.count) {
		return true;
	}
	if (*this == L) {
		return true;
	}
	else false;
}
template <typename D> bool List<D>::operator<=(const List &L) {
	if (count < L.count) {
		return true;
	}
	if (*this == L) {
		return true;
	}
	else false;
}
template <typename D> bool List<D>::operator>(const List &L) {
	if (count > L.count) {
		return true;
	}
}
template <typename D> bool List<D>::operator<(const List &L) {
	if (count < L.count) {
		return true;
	}
}
template <typename D> List<D> List<D>::operator-() {
	List result;
	Elem<D> *temp = head;
	while (temp != 0) {
		result.add_head(temp->data_elem);
		temp = temp->next;
	}
	return result;
}
template <typename D>void List<D>::print_my() {
	Elem<D> *temp = head;
	if (count != 0) {
		cout << "( ";
		while (temp->next != 0) {
			cout << "[" << temp->data_elem.data_T << ", "<< temp->data_elem.data_Y << "]" << ", ";
			temp = temp->next;
		}
		cout << "[" << temp->data_elem.data_T << ", " << temp->data_elem.data_Y << "]" << " )\n";
	}
}
template <typename D> void List<D>::insert_my(int pos, D data) {
	if (pos == 0) {
		cout << "Pos = ";
		cin >> pos;
	}
	if (pos < 1 || pos >count + 1) {
		cout << "Error pos " << pos << endl;
		return;
	}
	if (pos == count + 1) {
		add_tail(data);
		return;
	}
	else if (pos == 1) {
		add_head(data);
		return;
	}
	int i = 1;
	Elem<D> *ins = head;
	while (i < pos) {
		ins = ins->next;
		i++;
	}
	Elem<D> *PrevIns = ins->prev;
	Elem<D> *temp = new Elem<D>;
	temp->data_elem = data;
	if (PrevIns != 0 && count != 1) {
		PrevIns->next = temp;
		temp->next = ins;
		temp->prev = PrevIns;
		ins->prev = temp;
	}
	count++;
}
template <typename D>void List<D>::print_my(int pos) {
	if (pos<1 || pos > count) {
		cout << "Error " << pos << endl;
		return;
	}
	Elem<D> *temp;
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
	cout << "Pos = " << pos << " Elem = " << "[ " << temp->data_elem.data_T << ", " << temp->data_elem.data_Y;
	cout << " ]" << endl;
}
int main() {
	List<int> L;
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
	List<int> T;
	T = L;
	T.print();
	List<int> S = -L + T;
	S.print();
	cout << "------------------------------------------------------------" << endl;
	List<char> L_ch;
	const int n2 = 5;
	char a_ch[n2] = { 'A','B','C','D','E'};
	for (int i = 0; i < n2; i++) {
		L_ch.add_tail(a_ch[i]);
	}
	L_ch.print();
	L_ch.insert();
	L_ch.print(2);
	L_ch.print(5);
	List<char> T_ch;
	T_ch = L_ch;
	T_ch.print();
	List<char>S_ch = -L_ch + T_ch;
	S_ch.print();
	cout << "------------------------------------------------------------" << endl;
	List < MyData<int, char>> L_my;
	MyData<int, char> a_my[n2] = { 1,'A',2,'B',3,'C',4,'D',5,'E' };
	for (int i = 0; i < n2; i++) {
		L_my.add_tail(a_my[i]);
	}
	L_my.print_my();
	L_my.insert_my(3,{9,'H'});
	L_my.print_my(2);
	L_my.print_my(4);
	List < MyData<int, char>> T_my;
	T_my = L_my;
	T_my.print_my();
	List < MyData<int, char>> S_my = -L_my + T_my;
	S_my.print_my();
	cout << "------------------------------------------------------------" << endl;
	MyData<int,char> A;
	MyData<char,string> B;
	MyData<string, int> C;
	A = { 5,'D' };
	B = {};
	C = { "Hello world", 7 };
	cout << "A.data " << A.data_T<<","<<A.data_Y << endl;
	cout << "B.data " << B.data_T << "," << B.data_Y << endl;
	cout << "C.data " << C.data_T << "," << C.data_Y << endl;
	Elem<int> EL_1;
	EL_1.data_elem = 6;
	Elem<MyData<int, char>> EL_2;
	EL_2.data_elem = { 5,'A' };
	cout << "EL_1 = " << EL_1.data_elem << endl;
	cout << "EL_2 = " << EL_2.data_elem.data_T << "," << EL_2.data_elem.data_Y << endl;
	EL_2.data_elem.data_T = 2;
	EL_2.data_elem.data_Y = 'M';
	cin.get();
	cin.get();
	return 0;
}