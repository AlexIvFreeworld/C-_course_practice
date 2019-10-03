#include <iostream>
#include <string>
using namespace std;
template <typename T> class myArray {
public:
	template <typename T> class Elem {
	public:
		Elem<T> *next;
		Elem<T> *prev;
		int i_elem;
		T data;
		bool elem_filled;
	};
	Elem<T> *head;
	Elem<T> *tail;
	int size;
	myArray();
	myArray(int i_size);
	int GetSize();
	void del_elem();
	void add_elem();
	void show();
	void SetSize(int i_size, int grow=1);
	int GetUpperBound();
	bool IsEmpty();
	void SetAt(int i_i_elem, T i_data);
	void FreeExtra();
	void RemoveAll();
	T GetAt(int i_i_elem);
	void Add(T i_data);
	T operator[](int i_i_elem);
	void Append(myArray *arr_1);
	void operator=(myArray *arr_1);
	myArray *GetData();
	void InsertAt(int i_i_elem, T i_data);
	void RemoveAt(int i_i_elem);
};
template <typename T> myArray<T>::myArray() {
	size = 0;
	head = tail = 0;
}
template <typename T> myArray<T>::myArray(int i_size) {
	size = i_size;
	head = tail = 0;
	myArray<T>::Elem<T> *temp = head;
	if (size <= 0) {
		cout << "Incorrect size" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				head = temp = new myArray<T>::Elem<T>;
			}
			else {
				temp->next = new myArray<T>::Elem<T>;
				temp = temp->next;
			}
			temp->elem_filled = false;
			temp->i_elem = i;
			temp->next = 0;
			temp->prev = tail;
			tail = temp;
		}
	}
}
template <typename T>int myArray<T>::GetSize() {
	return size;
}
template <typename T> void myArray<T>::del_elem() {
	myArray<T>::Elem<T> *temp = tail;
	if (head == 0) {
		cout << "This array's size already = 0 " << endl;
		return;
	}
	else if (head->next == 0) {
		tail = head = 0;
		delete temp;
		size--;
	}
	else {
		tail = temp->prev;
		tail->next = 0;
		temp->prev = 0;
		delete temp;
		size--;
	}
}
template <typename T> void myArray<T>::add_elem() {
	myArray<T>::Elem<T> *temp = head;
	if (head == 0) {
		head = temp = new myArray<T>::Elem<T>;
}
	else {
		for (int i = 1; i < size; i++) {
			temp = temp->next;
		}
		temp->next = new myArray<T>::Elem<T>;
		temp = temp->next;
	}
	size++;
	temp->elem_filled = false;
	temp->i_elem = size-1;
	temp->next = 0;
	temp->prev = tail;
	tail = temp;
}
template <typename T> void myArray<T>::show() {
	myArray<T>::Elem<T> *temp = head;
	if (head == 0) {
		cout << "This array's size = 0 " << endl;
		return;
	}
	else {
		cout << "( ";
		for (int i = 0; i < size-1; i++) {
			cout << temp->i_elem << " : " << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->i_elem << " : " << temp->data << " )" << endl;
	}
}
template <typename T> void myArray<T>::SetSize(int i_size, int grow) {
	if (i_size >= size) {
		int size_total = i_size - size + grow;
		for (int i = 1; i <= size_total; i++) {
			add_elem();
			//cout << "adding " << i << "  " << size_total << endl;
		}
	}
	else {
		for (int i = 1; i <= (size - i_size); i++) {
			del_elem();
		}
	}
}
template <typename T> int myArray<T>::GetUpperBound() {
	myArray<T>::Elem<T> *temp = head->next;
	if (head == 0) {
		cout << "This array's size = 0 " << endl;
		return -2;
	}
	else if (head->next == 0) {
		if (head->elem_filled == false) {
			cout << "This array has not elements " << endl;
			return -1;
		}
		else {
			return head->i_elem;
		}
	}
	else {
		while (temp->next != 0) {
			if (temp->elem_filled == false) {
				return temp->prev->i_elem;
			}
			else {
				temp = temp->next;
			}
		}
		if (temp->elem_filled == false) {
			return temp->prev->i_elem;
		}
		else {
			return temp->i_elem;
		}
	}
}
template <typename T> bool myArray<T>::IsEmpty() {
	if (GetUpperBound() == 0) {
		return true;
	}
	else {
		return false;
	}
}
template <typename T> void myArray<T>::SetAt(int i_i_elem, T i_data) {
	myArray<T>::Elem<T> *temp = head;
	if (i_i_elem >= 0 && i_i_elem < size) {
		for (int i = 0; i <= i_i_elem; i++) {
			(i==0)? 0:temp = temp->next;
		}
		temp->data = i_data;
		temp->elem_filled = true;
	}
	else {
		cout << "Incorrect volume i or size = 0 " << endl;
	}
}
template <typename T> void myArray<T>::RemoveAll() {
	if (size == 0) {
		cout << "This Array already empty " << endl;
	}
	else {
		int sum_del = size;
		for (int i = 1; i <= sum_del; i++) {
			del_elem();
		}
	}
}
template <typename T> void myArray<T>::FreeExtra() {
	if (size == 0) {
		cout << "This Array already empty " << endl;
	}
	else {
		int sum_del = size - (GetUpperBound() + 1);
		for (int i = 1; i <= sum_del; i++) {
			del_elem();
			//cout << "Deleting - " << i << "sum_del = " << sum_del << endl;
		}
	}
}
template <typename T> T myArray<T>::GetAt(int i_i_elem) {
	return operator[](i_i_elem);
}
template <typename T> void myArray<T>::Add(T i_data) {
	if (size == 0 || size == GetUpperBound() + 1) {
		SetSize(size);
		tail->data = i_data;
		tail->elem_filled = true;
	}
	else {
		myArray<T>::Elem<T> *temp = head;
		for (int i = 1; i <= GetUpperBound() + 1; i++) {
			temp = temp->next;
		}
		temp->data = i_data;
		temp->elem_filled = true;
	}
}
template <typename T> T myArray<T>::operator[](int i_i_elem) {
	myArray<T>::Elem<T> *temp = head;
	if (i_i_elem >= 0 && i_i_elem < size) {
		for (int i = 0; i <= i_i_elem; i++) {
			(i == 0) ? 0 : temp = temp->next;
		}
		return temp->data;
	}
	else {
		cout << "Incorrect volume i or size = 0 " << endl;
		return 0;
	}
}
template <typename T> void myArray<T>::Append(myArray *arr_1) {
	for (int i = 0; i < arr_1->size; i++) {
		Add(arr_1->operator[](i));
	}
}
template <typename T> void myArray<T>::operator=(myArray *arr_1) {
	RemoveAll();
	for (int i = 0; i < arr_1->size; i++) {
		Add(arr_1->operator[](i));
	}
}
template <typename T> myArray<T> *myArray<T>::GetData() {
	return this;
}
template <typename T> void myArray<T>::InsertAt(int i_i_elem, T i_data) {
	if (i_i_elem >= 0 && i_i_elem < size) {
		if (i_i_elem > GetUpperBound()) {
			Add(i_data);
		}
		else {
			Add(i_data);
			T temp_data;
			myArray<T>::Elem<T> * temp = head;
			for (int i = 0; i <= GetUpperBound(); i++) {
				(i==0)? 0:temp = temp->next;
			}
			for (int i = 1; i <= GetUpperBound() - i_i_elem; i++) {
				temp_data = temp->prev->data;
				temp->prev->data = temp->data;
				temp->data = temp_data;
				temp = temp->prev;
			}
		}
	}
	else {
		cout << "Incorrect volume i or size = 0 " << endl;
	}
}
template <typename T> void myArray<T>::RemoveAt(int i_i_elem) {
	T temp_data;
	myArray<T>::Elem<T> * temp = head;
	if (i_i_elem >= 0 && i_i_elem < size) {
		if (i_i_elem > GetUpperBound()) {
			cout << "This elem is already empty" << endl;
		}
		else if (i_i_elem == GetUpperBound()) {
			for (int i = 0; i <= GetUpperBound(); i++) {
				(i == 0) ? 0 : temp = temp->next;
			}
			temp->elem_filled = false;
		}
		else {
			for (int i = 0; i <= i_i_elem; i++) {
				(i == 0) ? 0 : temp = temp->next;
			}
			for (int i = 1; i <= GetUpperBound() - i_i_elem; i++) {
				temp_data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp_data;
				temp = temp->next;
			}
			temp->elem_filled = false;
		}
	}
	else {
		cout << "Incorrect volume i or size = 0 " << endl;
	}
}

int main() {
	cout << "------------------create <int> arr(5)-----------------------" << endl;
	myArray<int> arr(5);
	cout << "arr.GetSize() = " << arr.GetSize() << endl;
	arr.show();
	cout << "------------------arr.del_elem 6 times-----------------------" << endl;
	arr.del_elem();
	arr.del_elem();
	arr.del_elem();
	arr.del_elem();
	arr.del_elem();
	arr.del_elem();
	arr.show();
	cout << "------------------arr.add_elem 3 times-----------------------" << endl;
	arr.add_elem();
	arr.add_elem();
	arr.add_elem();
	cout << "size = " << arr.GetSize() << endl;
	arr.show();
	cout << "------------------arr.SetSize(5, 5)-----------------------" << endl;
	arr.SetSize(5, 5);
	cout << "size = " << arr.GetSize() << endl;
	arr.show();
	cout << "GetUpperBound() = " << arr.GetUpperBound() << endl;
	cout << "IsEmpty() = " << arr.IsEmpty() << endl;
	cout << "------------------arr.SetAt(0, 10), SetAt(1, 20), SetAt(2, 30)-----------------------" << endl;
	arr.SetAt(0, 10);
	arr.SetAt(1, 20);
	arr.SetAt(2, 30);
	arr.show();
	cout << "GetUpperBound() = " << arr.GetUpperBound() << endl;
	cout << "IsEmpty() = " << arr.IsEmpty() << endl;
	cout << "------------------arr.RemoveAll()-----------------------" << endl;
	arr.RemoveAll();
	arr.show();
	cout << "------------------arr.SetSize(5, 5)-----------------------" << endl;
	arr.SetSize(5, 5);
	cout << "size = " << arr.GetSize() << endl;
	arr.show();
	cout << "-----------------arr.SetAt(0, 10), SetAt(1, 20), SetAt(2, 30)-----------------------" << endl;
	arr.SetAt(0, 10);
	arr.SetAt(1, 20);
	arr.SetAt(2, 30);
	arr.show();
	cout << "GetUpperBound() = " << arr.GetUpperBound() << endl;
	cout << "arr.GetSize() = " << arr.GetSize() << endl;
	cout << "------------------arr.FreeExtra()-----------------------" << endl;
	arr.FreeExtra();
	arr.show();
	cout << "arr.GetAt(1) = " << arr.GetAt(1) << endl;
	cout << "arr.GetAt(2) = " << arr.GetAt(2) << endl;
	cout << "arr.GetAt(-2) = " << arr.GetAt(-2) << endl;
	cout << "------------------arr.Add(55)-----------------------" << endl;
	arr.Add(55);
	arr.show();
	cout << "------------------arr.add_elem() 2 times-----------------------" << endl;
	arr.add_elem();
	arr.add_elem();
	arr.show();
	cout << "------------------arr.Add(66)-----------------------" << endl;
	arr.Add(66);
	arr.show();
	cout << "------------------operator[]-----------------------" << endl;
	cout << "arr[0] = " << arr[0] << endl;
	cout << "arr[1] = " << arr[1] << endl;
	cout << "arr[2] = " << arr[2] << endl;
	cout << "------------------create <int> A,B,C-----------------------" << endl;
	myArray<int> A,B,C;
	cout << "------------------A.Add(1) A.Add(2) A.Add(3)-----------------------" << endl;
	A.Add(1);
	A.Add(2);
	A.Add(3);
	A.show();
	cout << "------------------B.Add(4) B.Add(5) B.Add(6)-----------------------" << endl;
	B.Add(4);
	B.Add(5);
	B.Add(6);
	B.show();
	cout << "------------------C.Append(&A)-----------------------" << endl;
	C.Append(&A);
	C.show();
	cout << "------------------C.Append(&B)-----------------------" << endl;
	C.Append(&B);
	C.show();
	cout << "------------------A = C-----------------------" << endl;
	A = C;
	A.show();
	cout << "------------------GetData-----------------------" << endl;
	cout << "A.GetData() = "<< A.GetData() << endl;
	cout << "B.GetData() = " << B.GetData() << endl;
	cout << "C.GetData() = " << C.GetData() << endl;
	myArray<int> *ptr = A.GetData();
	cout << "------------------*ptr = A.GetData(), ptr->show() -----------------------" << endl;
	ptr->show();
	cout << "------------------InsertAt(0, 99)-----------------------" << endl;
	A.InsertAt(0, 99);
	A.show();
	cout << "------------------A.add_elem() 2 times-----------------------" << endl;
	A.add_elem();
	A.add_elem();
	A.show();
	cout << "------------------A.InsertAt(8, 11)-----------------------" << endl;
	A.InsertAt(8, 11);
	A.show();
	cout << "------------------A.RemoveAt(0)-----------------------" << endl;
	A.RemoveAt(0);
	A.show();
	cout << "------------------A.RemoveAt(3)-----------------------" << endl;
	A.RemoveAt(3);
	A.show();
	cout << "------------------A.RemoveAt(8)-----------------------" << endl;
	A.RemoveAt(8);
	A.show();
	cout << "------------------A.FreeExtra()-----------------------" << endl;
	A.FreeExtra();
	A.show();
	cin.get();
	return 0;
}