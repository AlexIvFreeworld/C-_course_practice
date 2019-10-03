#include <iostream>
using namespace std;
class elem {
public:
	elem *next;
	int data;
	elem(int data_);
	~elem() { 
	}
};
elem::elem(int data_) {
	data = data_;
	next = 0;
	//cout << "Constructor " << this << "next " << next << endl;
}

class list {
	elem *head;
public:
	list();
	void add(int x);
	void search(int x);
	void insert_first(int x);
	void insert_end(int x);
	void insert_middle(int n, int x);
	void del_end();
	void del_all();
	void del_number(int n);
	void show();
	void sort_min_to_max();
	~list() { 
	}
};
list::list() {
	head = 0;
}
void list::add(int x) {
	if (head == NULL) {
		head = new elem(x);
	}
	else {
		elem *tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new elem(x);
	}
}
void list::show() {
		if (head == NULL) {
			cout << "The list is empty" << endl;
		}
		else {
			elem *tmp = head;
			while (tmp->next != NULL) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << tmp->data << " ";
			cout << "The list end" << endl;
		}
	}
void list::search(int x) {
	if (head == NULL) {
		cout << "The list is empty" << endl;
	}
	else {
		elem *tmp = head;
		int i = 1;
		int sum_elem = 0;
		while (tmp != 0) {
			if (tmp->data == x) {
				cout << "Volume " << x << " is in the elem " << i << endl;
				i++;
				sum_elem++;
				tmp = tmp->next;
			}
			else {
				i++;
				tmp = tmp->next;
			}
		}
		if (sum_elem == 0) cout << "Not found elem with volume " << x << endl;
	}
}
void list::insert_first(int x) {
	elem *tmp = new elem(x);
	tmp->next = head;
	head = tmp;
}
void list::insert_end(int x) {
	if (head == 0) {
		head = new elem(x);
	}
	else {
		elem *tmp = head;
		while (tmp->next != 0)
		{
			tmp = tmp->next;
		}
		tmp->next = new elem(x);
	}
}
void list::insert_middle(int n, int x) {
	int sum_insert = 0;
	elem *tmp;
	if (head == 0) {
		insert_first(x);
	}
	else {
		tmp = head;
		int i = 1;
					if (n < 1) {
					tmp = new elem(x);
					tmp->next = head;
					head = tmp;
					i++;
					sum_insert++;
			}
		while (tmp->next != 0) {
			if (i == n) {
				elem *middle = new elem(x);
				middle->next = tmp->next;
				tmp->next = middle;
				i++;
				sum_insert++;
				break;
			}
			else {
				tmp = tmp->next;
				i++;
			}
		}
		if (sum_insert==0) tmp->next = new elem(x);
	}
}
void list::del_end() {
	if (head == NULL) {
		cout << "List empty yet" << endl;
	}
	else {
		elem *tmp = head;
		elem *tmp_befor = head;
		while (tmp->next != NULL) {
			tmp_befor = tmp;
			tmp = tmp->next;
		}
		delete tmp;
		tmp_befor->next = 0;
	}
}
void list::del_all() {
	elem *tmp = head;
	if (head == NULL) {
		cout << "List empty yet" << endl;
	}
	else {
		while (head->next != NULL) {
			head = tmp->next;
			delete tmp;
			tmp = head;
		}
		head = 0;
		delete tmp;
	}
}
void list::del_number(int n) {
	int sum_del = 0;
	int num_elem = 1;
	elem *tmp = head;
	elem *tmp_befor = head;
	if (head == 0) {
		cout << "List is empty yet" << endl;
		}
	else {
		while (tmp->next != NULL) {
			if (n==1) {
				head = tmp->next;
				delete tmp;
				sum_del++;
				tmp = head;
				break;
			}
			else if (n != 1 && num_elem == n) {
				tmp_befor->next = tmp->next;
				delete tmp;
				sum_del++;
				tmp = tmp_befor->next;
				break;
			}
			else {
				tmp_befor = tmp;
				tmp = tmp->next;
				num_elem++;
			}
		}
		if (num_elem == n && sum_del==0) {
		tmp_befor->next = tmp->next;
		cout << "tmp_befor->next " << tmp_befor->next << endl;
		delete tmp;
		sum_del++;
		tmp = tmp_befor->next;
		}
		if (sum_del == 0) cout << "Not found number for deleting" << endl;
	}
}
void list::sort_min_to_max() {
	int count_elem = 1;
	if (head == NULL) {
		cout << "List is empty " << endl;
	}
	else {
		elem *tmp_1 = head;
		elem *tmp_2;
		elem *tmp_0 = head;
		while (tmp_1->next != NULL) {
			count_elem++;
			tmp_1 = tmp_1->next;
		}
		//cout << "Count elem - " << count_elem << endl;
		for (int i = 1; i <= count_elem - 1; i++) {
			tmp_1 = head;
			for (int j = 1; j <= count_elem - i; j++) {
					if (tmp_1->data > tmp_1->next->data) {
						tmp_2 = tmp_1->next;
						tmp_1->next = tmp_2->next;
                        tmp_2->next = tmp_1;
						if (j == 1) {
							head = tmp_2;
							tmp_0 = tmp_2;
						} 
						else if (j>1){
							tmp_0->next = tmp_2;
							tmp_0 = tmp_2;
						}
						//cout << "for j = " << j << endl;
					}
					else {
						tmp_2 = tmp_1;
						tmp_0 = tmp_2;
						tmp_1 = tmp_1->next;
					}
				}
			}
		}
	}
int main() {
	list L;
	cout << "------------------------Add---------------------------------------" << endl;
	L.add(1);
	L.add(2);
	L.add(4);
	L.add(3);
	L.show();
	cout << "------------------------insert_first---------------------------------------" << endl;
	L.insert_first(9);
	L.show();
	cout << "------------------------insert_end---------------------------------------" << endl;
	L.insert_end(7);
	L.show();
	cout << "------------------------insert_middle---------------------------------------" << endl;
	L.insert_middle(2, 11);
	L.show();
	cout << "------------------------del_end---------------------------------------" << endl;
	L.del_end();
	L.show();
	cout << "------------------------del_number---------------------------------------" << endl;
	L.del_number(3);
	L.show();
	cout << "------------------------sort_min_to_max---------------------------------------" << endl;
	L.sort_min_to_max();
	L.show();
	cout << "------------------------del_all---------------------------------------" << endl;
	L.del_all();
	L.show();
 	cin.get();
	return 0;
}