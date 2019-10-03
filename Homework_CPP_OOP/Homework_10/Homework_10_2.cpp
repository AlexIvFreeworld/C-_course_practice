#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;
#pragma warning(disable : 4996)
class my_directory {
public:
	char *company;
	char *owner;
	char *phone;
	char *adress;
	char *business;
	my_directory();
	my_directory(char *co, char *ow, char *ph, char *ad, char *bu);
	~my_directory();
	void Add_to_directory();
	void Show();
};
my_directory::my_directory() {
	company = NULL;
	owner = NULL;
	phone = NULL;
	adress = NULL;
	business = NULL;
}
my_directory::my_directory(char *co, char *ow, char *ph, char *ad, char *bu) {
	company = new char [strlen(co)+1];
	if (!company) {
		cout << "Memory allocation error" << endl;
		exit(1);
	}
	strcpy(company, co);
	owner = new char [strlen(ow)+1];
	if (!owner) {
		cout << "Memory allocation error" << endl;
		exit(1);
	}
	strcpy(owner, ow);
	phone = new char[strlen(ph)+1];
	if (!phone) {
		cout << "Memory allocation error" << endl;
		exit(1);
	}
	strcpy(phone, ph);
	adress = new char[strlen(ad)+1];
	if (!adress) {
		cout << "Memory allocation error" << endl;
		exit(1);
	}
	strcpy(adress, ad);
	business = new char [strlen(bu)+1];
	if (!business) {
		cout << "Memory allocation error" << endl;
		exit(1);
	}
	strcpy(business, bu);
}
my_directory::~my_directory() {
	delete[] company;
	delete[] owner;
	delete[] phone;
	delete[] adress;
	delete[] business;
}
void my_directory::Add_to_directory() {
	fstream inF("dir.txt", ios::out | ios::binary | ios::app);
	int size;
	size = strlen(company);
	inF.write((char*)&size, sizeof(int));
	inF.write((char*)company, size * sizeof(char));
	size = strlen(owner);
	inF.write((char*)&size, sizeof(int));
	inF.write((char*)owner, size * sizeof(char));
	size = strlen(phone);
	inF.write((char*)&size, sizeof(int));
	inF.write((char*)phone, size * sizeof(char));
	size = strlen(adress);
	inF.write((char*)&size, sizeof(int));
	inF.write((char*)adress, size * sizeof(char));
	size = strlen(business);
	inF.write((char*)&size, sizeof(int));
	inF.write((char*)business, size * sizeof(char));
	inF.close();
}
void my_directory::Show() {
	cout << "\nCompany : ";
	cout << company << endl;
	cout << "Owner : ";
	cout << owner << endl;
	cout << "Phone : ";
	cout << phone << endl;
	cout << "Adress : ";
	cout << adress << endl;
	cout << "Business : ";
	cout << business << endl;
	cout << "------------------------------------------" << endl;
}
void Show_all_directory();
void Search_by_name();
void Search_by_owner();
void Read_obj(fstream *F, my_directory *D, char *key, int D_n);
void Search_by_phone();
void Search_by_adress();
void Search_by_business();
char Enter_choice(char *str);
int main() {
	char choice;
	char str[20];
	my_directory *Temp;
	do {
		cout << "\nAdd new record (press 1)"
			"\nShow all directory (press 2)"
			"\nSearch by company (press 3)"
			"\nSearch by owner (press 4)"
			"\nSearch by phone (press 5)"
			"\nSearch by adress (press 6)"
			"\nSearch by business (press 7)"
			"\nExit from directory (press 8)\n";
		choice = Enter_choice(gets_s(str));
		system("cls");
		switch (choice) {
		case '1':
			char company[100];
			char owner[100];
			char phone[15];
			char adress[100];
			char business[100];
			cout << "\nEnter company : ";
			gets_s(company);
			cout << "Enter owner : ";
			gets_s(owner);
			cout << "Enter phone : ";
			gets_s(phone);
			cout << "Enter adress : ";
			gets_s(adress);
			cout << "Enter business : ";
			gets_s(business);
			Temp = new my_directory(company, owner, phone, adress, business);
			Temp->Add_to_directory();
			delete Temp;
			break;
		case '2':
			Show_all_directory();
			break;
		case '3':
			Search_by_name();
			break;
		case '4':
			Search_by_owner();
			break;
		case '5':
			Search_by_phone();
			break;
		case '6':
			Search_by_adress();
			break;
		case '7':
			Search_by_business();
			break;
		case '8':
			cout << "Good bay!" << endl;
			break;
		default:
			cout << "Incorrect number" << endl;
}
	} while (choice != '8');
	cin.get();
	cin.get();
	return 0;
}
void Show_all_directory() {
	char key[20] = "00000";
	fstream outF("dir.txt", ios::in | ios::binary);
	if (!outF) {
		cout << "The file did not open for reading" << endl;
		exit(1);
	}
	fstream *F = &outF;
	my_directory *D = new my_directory;
	int D_n = 6;
	Read_obj(F, D, key, D_n);
	delete D;
	outF.close();
}
void Search_by_name() {
	char key[20];
	cout << "Enter name company for searching : ";
	gets_s(key);
	fstream outF("dir.txt", ios::in | ios::binary);
	if (!outF) {
		cout << "The file did not open for reading" << endl;
		exit(1);
	}
	fstream *F = &outF;
	my_directory *D = new my_directory;
	int D_n = 1;
	Read_obj(F, D, key, D_n);
	delete D;
	outF.close();
}
void Search_by_owner() {
	char key[20];
	cout << "Enter owner for searching : ";
	gets_s(key);
	fstream outF("dir.txt", ios::in | ios::binary);
	if (!outF) {
		cout << "The file did not open for reading" << endl;
		exit(1);
	}
	fstream *F = &outF;
	my_directory *D = new my_directory;
	int D_n = 2;
	Read_obj(F, D, key, D_n);
	delete D;
	outF.close();
}
void Read_obj(fstream *F, my_directory *D, char *key, int D_n) {
	int size;
	char D_name[20];
	while (F->read((char*)&size, sizeof(int))) {
		D->company = new char[size + 1];
		if (!D->company) {
			cout << "Memory allocation error" << endl;
			exit(1);
		}
		F->read((char*)D->company, size * sizeof(char));
		D->company[size] = '\0';
		F->read((char*)&size, sizeof(int));
		D->owner = new char[size + 1];
		if (!D->owner) {
			cout << "Memory allocation error" << endl;
			exit(1);
		}
		F->read((char*)D->owner, size * sizeof(char));
		D->owner[size] = '\0';
		F->read((char*)&size, sizeof(int));
		D->phone = new char[size + 1];
		if (!D->phone) {
			cout << "Memory allocation error" << endl;
			exit(1);
		}
		F->read((char*)D->phone, size * sizeof(char));
		D->phone[size] = '\0';
		F->read((char*)&size, sizeof(int));
		D->adress = new char[size + 1];
		if (!D->adress) {
			cout << "Memory allocation error" << endl;
			exit(1);
		}
		F->read((char*)D->adress, size * sizeof(char));
		D->adress[size] = '\0';
		F->read((char*)&size, sizeof(int));
		D->business = new char[size + 1];
		if (!D->business) {
			cout << "Memory allocation error" << endl;
			exit(1);
		}
		F->read((char*)D->business, size * sizeof(char));
		D->business[size] = '\0';
		switch (D_n) {
		case 1:
			strcpy(D_name, D->company);
			break;
		case 2:
			strcpy(D_name, D->owner);
			break;
		case 3:
			strcpy(D_name, D->phone);
			break;
		case 4:
			strcpy(D_name, D->adress);
			break;
		case 5:
			strcpy(D_name, D->business);
			break;
		default:
			strcpy(D_name, "00000");
			strcpy(key, "00000");
		}
		if (!strncmp(D_name, key, 4)) {
			D->Show();
		}
	}
}
void Search_by_phone() {
	char key[20];
	cout << "Enter phone for searching : ";
	gets_s(key);
	fstream outF("dir.txt", ios::in | ios::binary);
	if (!outF) {
		cout << "The file did not open for reading" << endl;
		exit(1);
	}
	fstream *F = &outF;
	my_directory *D = new my_directory;
	int D_n = 3;
	Read_obj(F, D, key, D_n);
	delete D;
	outF.close();
}
void Search_by_adress() {
	char key[20];
	cout << "Enter adress for searching : ";
	gets_s(key);
	fstream outF("dir.txt", ios::in | ios::binary);
	if (!outF) {
		cout << "The file did not open for reading" << endl;
		exit(1);
	}
	fstream *F = &outF;
	my_directory *D = new my_directory;
	int D_n = 4;
	Read_obj(F, D, key, D_n);
	delete D;
	outF.close();
}
void Search_by_business() {
	char key[20];
	cout << "Enter business for searching : ";
	gets_s(key);
	fstream outF("dir.txt", ios::in | ios::binary);
	if (!outF) {
		cout << "The file did not open for reading" << endl;
		exit(1);
	}
	fstream *F = &outF;
	my_directory *D = new my_directory;
	int D_n = 5;
	Read_obj(F, D, key, D_n);
	delete D;
	outF.close();
}
char Enter_choice(char *str) {
	return str[0];
}
