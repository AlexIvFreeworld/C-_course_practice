#include <iostream>//binary tree
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;
template <typename T,typename D>class Tree {
public:
	template <typename T, typename D> class Elem {
	public:
		T data_1;
		D data_2;
		Elem *left, *right, *parent;
		Elem(T i_data_1, D i_data_2) {
			data_1 = i_data_1;
			data_2 = i_data_2;
		}
	};
	Elem<T, D> *root;
	Tree();
	~Tree();
	void Print(Tree<T, D>::Elem<T, D> *Node);
	Tree<T,D>::Elem<T, D> *Search(Tree<T,D>::Elem<T, D> *Node, T Key);
	Tree<T, D>::Elem<T, D> *Min(Tree<T, D>::Elem<T, D> *Node);
	Tree<T, D>::Elem<T, D> *Max(Tree<T, D>::Elem<T, D> *Node);
	Tree<T, D>::Elem<T, D> *Next(Tree<T, D>::Elem<T, D> *Node);
	Tree<T, D>::Elem<T, D> *Previous(Tree<T, D>::Elem<T, D> *Node);
	void Insert(Tree<T, D>::Elem<T, D> *Z);
	void Delete(Tree<T, D>::Elem<T, D> *Z = 0);
	Tree<T, D>::Elem<T, D> *getRoot();
};

template <typename T, typename D>Tree<T,D>::Tree() {
	root = NULL;
}
template <typename T, typename D>Tree<T,D>::~Tree() {
	Delete();
}
template <typename T, typename D> void Tree<T,D>::Print(Tree<T, D>::Elem<T, D> *Node) {
	if (Node != NULL) {
		Print(Node->left);
		cout << Node->data_1 << "," << Node->data_2 << endl;
		Print(Node->right);
	}
}
template <typename T, typename D> Tree<T,D>::Elem<T, D> *Tree<T, D>::Search(Tree<T,D>::Elem<T, D> *Node, T Key) {
	while (Node != NULL && Key != Node->data_1) {
		if (Key < Node->data_1) {
			Node = Node->left;
		}
		else {
			Node = Node->right;
		}
	}
	return Node;
}
template <typename T, typename D>Tree<T, D>::Elem<T,D> *Tree<T,D>::Min(Tree<T, D>::Elem<T,D> *Node) {
	if (Node != NULL) {
		while (Node->left != NULL) {
			Node = Node->left;
		}
	}
	return Node;
}
template <typename T, typename D>Tree<T, D>::Elem<T,D> *Tree<T,D>::Max(Tree<T, D>::Elem<T,D> *Node) {
	if (Node != NULL) {
		while (Node->right != NULL) {
			Node = Node->right;
		}
	}
	return Node;
}
template <typename T, typename D>Tree<T, D>::Elem<T,D> *Tree<T,D>::Next(Tree<T, D>::Elem<T,D> *Node) {
	Tree<T, D>::Elem<T, D> *y = 0;
	if (Node != 0) {
		if (Node->right != 0) {
			return Min(Node->right);
		}
		y = Node->parent;
		while (y != 0 && Node == y->right) {
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
template <typename T, typename D>Tree<T, D>::Elem<T,D> *Tree<T,D>::Previous(Tree<T, D>::Elem<T,D> *Node) {
	Tree<T, D>::Elem<T, D> *y = 0;
	if (Node != 0) {
		if (Node->left != 0) {
			return Max(Node->left);
		}
		y = Node->parent;
		while (y != 0 && Node == y->left) {
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
template <typename T, typename D>void Tree<T,D>::Insert(Tree<T, D>::Elem<T,D> *Z) {
	Z->left = 0;
	Z->right = 0;
	Tree<T, D>::Elem<T,D> *y = 0;
	Tree<T, D>::Elem<T, D> *Node = root;
	while (Node != 0) {
		y = Node;
		if (Z->data_1 < Node->data_1) {
			Node = Node->left;
		}
		else {
			Node = Node->right;
		}
	}
	Z->parent = y;
	if (y == 0) {
		root = Z;
	}
	else if (Z->data_1 < y->data_1){
		y->left = Z;
	}
	else {
		y->right = Z;
	}
}
template <typename T, typename D>void Tree<T,D>::Delete(Tree<T, D>::Elem<T,D> *Z) {
	if (Z != 0) {
		Tree<T, D>::Elem<T, D> *Node, *y;
		if (Z->left == 0 || Z->right == 0) {
			y = Z;
		}
		else {
			y = Next(Z);
		}
		if (y->left != 0) {
			Node = y->left;
		}
		else {
			Node = y->right;
		}
		if (Node != 0) {
			Node->parent = y->parent;
		}
		if (y->parent == 0) {
			root = Node;
		}
		else if (y == y->parent->left) {//пришли слева
			y->parent->left = Node;
		}
		else {
			y->parent->right = Node;
		}
		if (y != Z) {
			Z->data_1 = y->data_1;
			Z->data_2 = y->data_2;
		}
	}
	else {
		while (root != 0) {
			Delete(root);
		}
	}
}
template <typename T, typename D>Tree<T, D>::Elem<T,D> *Tree<T,D>::getRoot() {
	return root;
}
int main() {
	Tree<int,char> T;
	Tree<int, char>::Elem<int, char> L10(10,'A'),L8(8,'B'),L12(12,'C'),L6(6,'D'),L9(9,'E'),L11(11,'F'),L13(13,'G');
	T.Insert(&L10);
	T.Insert(&L8);
	T.Insert(&L12);
	T.Insert(&L6);
	T.Insert(&L9);
	T.Insert(&L11);
	T.Insert(&L13);
	T.Print(T.getRoot());
	cout << "-------------------------------------------" << endl;
	T.Print(&L8);
	cout << "-------------------------------------------" << endl;
	T.Print(&L12);
	cout << "previous L13 = " << T.Previous(&L13)->data_1 << endl;
	cout << "previous L12 = " << T.Previous(&L12)->data_1 << endl;
	cout << "previous L11 = " << T.Previous(&L11)->data_1 << endl;
	cout << "previous L10 = " << T.Previous(&L10)->data_1 << endl;
	cout << "previous L9 = " << T.Previous(&L9)->data_1 << endl;
	cout << "previous L8 = " << T.Previous(&L8)->data_1 << endl;
	cout << "-------------------------------------------" << endl;
	cout << "next L6 "  << T.Next(&L6)->data_1 << endl;
	cout << "next L8 " << T.Next(&L8)->data_1 << endl;
	cout << "next L9 " << T.Next(&L9)->data_1 << endl;
	cout << "next L10 " << T.Next(&L10)->data_1 << endl;
	cout << "next L11 " << T.Next(&L11)->data_1 << endl;
	cout << "next L12 " << T.Next(&L12)->data_1 << endl;
	cout << "-------------------------------------------" << endl;
	T.Delete(&L8);
	cout << "-------------------T.Delete(&L8)------------------------" << endl;
	T.Print(T.getRoot());
	cout << "L8.data_1 = " << L8.data_1 << endl;
	cout << "L8.right " << L8.right<< endl;
	cin.get();
	return 0;
}
