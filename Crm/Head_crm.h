#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;
class Client;
class Event;
class Task;
class Offer;
//class Park;
class Car;
class List_Manager;
//class Manager;
class Price;
class Report;
class my_time;
class List_Client {
	Client *root;
	char Name_List_Client[100];
	int Last_ID;
	int sum_clients;
public:
	List_Client(const char *name);
	void Add_client(Client *Z);
	Client *Min(Client *Node);
	Client *Next(Client *Node);
	void Del_client(Client *Z = 0);
	void Fill_client(char *name);
	Client *Search_client(char *name);
	void Show_List_Client(Client *Node);
	//Client *Max(Client *Node);
	Client *Get_root();
	char *Get_Name_List_Client();
	int Get_Last_ID();
	int Get_Sum_Client();
	void Set_Last_ID(int ID);
	~List_Client();
	void Fill_Tasks_in_List_Client(Client *Node);
	void Add_Tasks_in_List_Manager(Client *Node, List_Manager *LM, my_time *now);
	void Write_All_Clients_To_File(Client *Node, fstream *f);
	void Write_Client_List_To_File();
	void Read_Client_List_From_File();
	void Delete_Client(char *name);
	void Delete_Client(Client *Cl);
	void Delete_All_Clients(Client *Node);
};
class Client {
public:
	Client *parent;
	Client *left;
	Client *right;
	Event *pTheadEvent;
	Task *pTtask;
	Offer *pToffer;
	Car *pTheadCar;
	int Client_ID;
	int Priorety;//рассчитываем в зависимости от парка
	int sum_events;
	char name_company[100];
	char phone_company[20];
	char adress_company[200];
	char name_contact[100];
	char phone_contact[20];
	Client();
	Client(const char *name, List_Client *L);
	~Client();
	void Fill_Client();
	void Show_client();
	void Add_Event(Event *Ev);
	void Add_Event_To_Tail(Event *Ev);
	void Show_All_Events();
	void Show_Last_Event();
	void Create_Task();
	Car *Search_Car(char *mod);
	void Fill_Car(char *mod);
	void Add_Car(Car *Ca);
	void Show_All_Cars();
	void Calc_Next_Replacement_Date_All_Cars();
	void Add_Task();
	void Fill_Task();
	void Calc_Priorety();
	void Write_Client_To_File(fstream *f);
	void Read_Client_From_File(fstream *f);
	void Delete_Car(char *mod);
	void Delete_All_Cars();
	void Delete_All_Events();
};
class Event : public Client {
public:
	Event *next;
	my_time *date_create;
	my_time *date_action;//или заполняется
	char description_event[1000];
	//по завершению описания формирует новую задачу
	Event(Client *Cl);
	Event(char *desc, Client *Cl);
	void Fill_Event();
	void Show_event();
	~Event();
	void Write_Event_To_File(fstream *f);
	void Read_Event_From_File(fstream *f);
};
//class List_Task {
//	Task *pTheadTask;
//};
class Task : public Client {
public:
	//Client *pTclient;
	Task *next;
	//int Task_ID;
	my_time *date_create;
	my_time *date_action;// расчетная на основании последнего события и данных парка
	char description_task[1000];
	Task(Client *Cl);
	~Task();
	void Show_Task();
};
//class Offer :public Client {
//	int Offer_ID;
//	char Pos_1[300];
//	char Pos_2[300];
//	char Pos_3[300];
//};
//class Park :public Client {
	//Car *head;
	//расчет необходимого количества, частота закупок и т.д
//};
class Car : public Client {
public:
	Car *next;
	char Model[200];
	my_time *Last_Replacement_Date;
	my_time *Next_Replacement_Date;//расчетная дата
	int Average_Mileage;// средний пробег в день
	int Maximum_Tire_Mileage;// максимальный пробег шин
	Car(Client *Cl);
	Car(Client *Cl, char *mod);
	void Show_Car();
	~Car();
	void Calc_Next_Replacement_Date();
	void Write_Car_To_File(fstream *f);
	void Read_Car_From_File(fstream *f);
};
class List_Manager {
	Task *pTheadTaskAll;
	Task *pTheadTaskMain;
	Task *pTheadTaskSpare;
	int main_tasks_in_day;
public:
	List_Manager();
	~List_Manager();
	//Task *Find_Task(int T);
	void Add_Task(Task *Ta);
	void Show_All_Tasks();
	int Calc_Tasks();
	void Sort_Tasks();
	void Show_Main_Tasks();
	void Show_Spare_Tasks();
	//Manager *head;
	//List_Task *pTlistTask;
	//логика распределения задач по менеджерам
};
//class Manager {
//	Manager *next;
//	Task **arr_task_today;
//	int Manager_ID;
//	char Manager_name[100];
//};
//class Price {
//	char Pos_1[300];
//	char Pos_2[300];
//	char Pos_3[300];
//	char Pos_4[300];
//	char Pos_5[300];
//};
//class Report {
//	Report *next;
//	int data_create;
//	int plan_contacts;
//	int fact_contacts;
//	float result;
//};
class my_time {
	//char date_ch[10];
	int date_day;
	int date_month;
	int date_year;
	int date_one;
public:
	my_time();
	~my_time();
	void Show_Time();
	//my_time operator+(const my_time *obj);
	void Plus_Time(int Da);//получение новой даты после добавления n-дней
	void Set_Time(char *Ti);
	//char *Get_Date_ch();
	int Get_Date_Day();
	int Get_Date_Month();
	int Get_Date_Year();
	int Get_Date_One();
	void Calc_Date_One();//посчитать дни от 01 января 2000 по текущую дату 
	void Set_Time_from_int(int Ti);
	void Get_Current_Date();
};
void Show_menu(char *ch);
Client *Create_Client(List_Client *L);
Car *Create_Car(Client *Cl);
Event *Create_Event(Client *Cl);