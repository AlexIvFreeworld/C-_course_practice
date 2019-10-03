#include "Head_crm.h"
int main() {
	//---------------Подготовка БД в ОЗУ------------------
    List_Client L2("Tire");
	L2.Read_Client_List_From_File();
	//cout << "Sum Client in List" << L2.Get_Sum_Client() << endl;
	L2.Fill_Tasks_in_List_Client(L2.Get_root());
	//---------------Формирование задач на определенную дату------------------
	char cur_date[20] = "12-10-2019";
	my_time now;
	now.Set_Time(cur_date);
	List_Manager LM;
	L2.Add_Tasks_in_List_Manager(L2.Get_root(), &LM, &now);
	LM.Sort_Tasks();
	//---------------Предоставление выбора действий------------------
	int ch = 0;
	char choice[10];
	char name[100];
	char model[200];
	do {
		cout << "Sum Client in List = " << L2.Get_Sum_Client() << endl;
		Show_menu(choice);
		ch = atoi(choice);
		switch (ch) {
		case 1:
			L2.Add_client(Create_Client(&L2));
			break;
		case 2:
			cout << "Enter name company : ";
			gets_s(name);
			L2.Search_client(name)->Add_Car(Create_Car(L2.Search_client(name)));
			break;
		case 3:
			cout << "Enter name company : ";
			gets_s(name);
			L2.Search_client(name)->Add_Event(Create_Event(L2.Search_client(name)));
			break;
		case 4:
			LM.Show_Main_Tasks();
			break;
		case 5:
			LM.Show_Spare_Tasks();
			break;
		case 6:
			L2.Show_List_Client(L2.Get_root());
			break;
		case 7:
			cout << "Enter name company : ";
			gets_s(name);
 			L2.Fill_client(name);
			break;
		case 8:
			cout << "Enter name company : ";
			gets_s(name);
			L2.Search_client(name)->Show_client();
			break;
		case 9:
			cout << "Enter name company : ";
			gets_s(name);
			L2.Search_client(name)->Show_All_Cars();
			break;
		case 10:
			cout << "Enter name company : ";
			gets_s(name);
			cout << "Enter model car : ";
			gets_s(model);
			L2.Search_client(name)->Fill_Car(model);
			break;
		case 11:
			cout << "Enter name company : ";
			gets_s(name);
			L2.Search_client(name)->Show_All_Events();
			break;
		case 12:
			cout << "Enter name company : ";
			gets_s(name);
			L2.Delete_Client(name);
			break;
		case 13:
			cout << "Enter name company : ";
			gets_s(name);
			cout << "Enter model car : ";
			gets_s(model);
			L2.Search_client(name)->Delete_Car(model);
			break;
		default:
			if (ch != 15) cout << "Incorrect choice" << endl;
		}
	} while (ch != 15);
	cout << "Good buy!!" << endl;
	//---------------Запись БД в файл------------------
	L2.Write_Client_List_To_File();
	cin.get();
	return 0;
}