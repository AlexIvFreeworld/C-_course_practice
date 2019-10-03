#include "Head_crm.h"
List_Client::List_Client(const char *name) {
	root = NULL;
	strcpy(Name_List_Client,name);
	Last_ID = 0;
	sum_clients = 0;
}
void List_Client::Add_client(Client *Z) {
	Client *y = 0;
	Client *Node = root;
	while (Node != 0) {
		y = Node;
		if (strcmp(Z->name_company,Node->name_company)<0) {
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
	else if (strcmp(Z->name_company, y->name_company) == 0) {
		cout << "This Client is already exist!" << endl;
		return;
	}
	else if (strcmp(Z->name_company,y->name_company)<0) {
		y->left = Z;
	}
	else {
		y->right = Z;
	}
	Z->Add_Task();
	sum_clients++;
}
Client::Client() {
	strcpy(name_company, "No name");
	//Client_ID = L->Get_Last_ID() + 1;
	//L->Set_Last_ID(Client_ID);
	Client_ID = NULL;
	parent = NULL;
	left = NULL;
	right = NULL;
	pTheadEvent = NULL;
	pTtask = NULL;
	pTheadCar = NULL;
	Priorety = 0;
	sum_events = 0;
	strcpy(phone_company, "----------");
	strcpy(adress_company, "----------");
	strcpy(name_contact, "----------");
	strcpy(phone_contact, "----------");
}
Client::Client(const char *name, List_Client *L) {
	strcpy(name_company, name);
	Client_ID = L->Get_Last_ID() + 1;
	L->Set_Last_ID(Client_ID);
	parent = NULL;
	left = NULL;
	right = NULL;
	pTheadEvent = NULL;
	pTtask = NULL;
	pTheadCar = NULL;
	Priorety = 0;
	sum_events = 0;
	strcpy(phone_company,"----------");
	strcpy(adress_company, "----------");
	strcpy(name_contact, "----------");
	strcpy(phone_contact, "----------");
	//Task *Temp = new Task(this);
}
int List_Client::Get_Last_ID() {
	return Last_ID;
}
int List_Client::Get_Sum_Client() {
	return sum_clients;
}
void List_Client::Set_Last_ID(int ID) {
	Last_ID = ID;
}
Client *List_Client::Get_root() {
	return root;
}
void List_Client::Show_List_Client(Client *Node) {
	if (root == NULL) {
		cout << "This List has not any client" << endl;
		return;
	}
	if (Node != NULL) {
		Show_List_Client(Node->left);
		cout << Node->Client_ID << " / " << Node->name_company << endl;
		Show_List_Client(Node->right);
	}
}
List_Client::~List_Client() {
	Delete_All_Clients(Get_root());
}

Client::~Client() {
	Delete_All_Cars();
	Delete_All_Events();
	delete pTtask;
}
Client *List_Client::Search_client(char *name) {
	Client *Node = root;
	while (Node != NULL && strcmp(name,Node->name_company)!= 0) {
		if (strcmp(name, Node->name_company) < 0) {
			Node = Node->left;
		}
		else {
			Node = Node->right;
		}
	}
	return Node;
}
void Client::Show_client() {
	if (this != 0) {
		cout << "*******************************************" << endl;
		cout << Client_ID << " | " << name_company << " | " << phone_company << endl;
		cout << adress_company << endl;
		cout << name_contact << " | " << phone_contact << endl;
		cout << "*******************************************" << endl;
	}
	else {
		cout << "This client does not exist" << endl;
	}
}

void List_Client::Fill_client(char *name) {
	Client *Temp = Search_client(name);
	if (Temp == NULL) {
		cout << "This client does not find" << endl;
		return;
	}
	else {
		Temp->Fill_Client();
	}
}
char *List_Client::Get_Name_List_Client() {
	return Name_List_Client;
}
Client *List_Client::Min(Client *Node) {
	if (Node != NULL) {
		while (Node->left != NULL) {
			Node = Node->left;
		}
	}
	return Node;
}

Client *List_Client::Next(Client *Node) {
	Client *y = 0;
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

void List_Client::Del_client(Client *Z) {
	if (Z != 0) {
		Client *Node, *y;
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
		else if (y == y->parent->left) {
			y->parent->left = Node;
		}
		else {
			y->parent->right = Node;
		}
		if (y != Z) {
			//Z->num = y->num; - копируем один узел в другой
			Z->pTheadEvent = y->pTheadEvent;
			Z->pTtask = y->pTtask;
			Z->pToffer = y->pToffer;
			Z->pTheadCar = y->pTheadCar;
			Z->Client_ID = y->Client_ID;
			Z->Priorety = y->Priorety;
			strcpy(Z->name_company,y->name_company);
			strcpy(Z->phone_company, y->phone_company);
			strcpy(Z->adress_company, y->adress_company);
			strcpy(Z->name_contact, y->name_contact);
			strcpy(Z->phone_contact, y->phone_contact);
		}
	}
	else {
		while (root != 0) {
			Del_client(root);
		}
	}
}
Event::Event(Client *Cl) {
	next = NULL;
	date_create = new my_time;
	date_action = new my_time;
	date_create->Get_Current_Date();
	char temp_time[20] = "00000000";
	date_action->Set_Time(temp_time);
	strcpy(description_event, "no description");
	//при создании события заполняем поля клиента родителя
	pTtask = Cl->pTtask;
	pTheadCar = Cl->pTheadCar;
	Client_ID = Cl->Client_ID;
	Priorety = Cl->Priorety;
	strcpy(name_company, Cl->name_company);
	strcpy(phone_company, Cl->phone_company);
	strcpy(adress_company, Cl->adress_company);
	strcpy(name_contact, Cl->name_contact);
	strcpy(phone_contact, Cl->phone_contact);
}
Event::Event(char *desc, Client *Cl) {
	next = NULL;
	date_create = new my_time;
	date_action = new my_time;
	date_create->Get_Current_Date();
	char temp_time[20] = "00000000";
	date_action->Set_Time(temp_time);
	strcpy(description_event,desc);
	//при создании события заполняем поля клиента родителя
	pTtask = Cl->pTtask;
	pTheadCar = Cl->pTheadCar;
	Client_ID = Cl->Client_ID;
	Priorety = Cl->Priorety;
	strcpy(name_company, Cl->name_company);
	strcpy(phone_company,Cl->phone_company);
	strcpy(adress_company,Cl->adress_company);
	strcpy(name_contact,Cl->name_contact);
	strcpy(phone_contact,Cl->phone_contact);
}
void Event::Show_event() {
	cout << "***********************************" << endl;
	cout << "Event with Client : " << name_company << endl;
	cout << "Date create : ";
	date_create->Show_Time();
	cout << "Date action : ";
	date_action->Show_Time();
	cout << description_event << endl;
	cout << "***********************************" << endl;
}
Event::~Event() {
	delete date_create;
	delete date_action;
}
void Client::Fill_Client() {
	cout << "\nThis company is : " << name_company;
	cout << "\nEnter company's phone : ";
	gets_s(phone_company);
	cout << "Enter company's adress : ";
	gets_s(adress_company);
	cout << "Enter contact's name : ";
	gets_s(name_contact);
	cout << "Enter contact's phone : ";
	gets_s(phone_contact);
}

void Client::Add_Event(Event *Ev) {
	if (pTheadEvent == NULL) {
		pTheadEvent = Ev;
	}
	else {
		Ev->next = pTheadEvent;
		pTheadEvent = Ev;
	}
	sum_events++;
}
void Client::Add_Event_To_Tail(Event *Ev) {
	Event *Temp = pTheadEvent;
	if (pTheadEvent == NULL) {
		pTheadEvent = Ev;
	}
	else if (Temp->next == NULL) {
		Temp->next = Ev;
	}
	else {
		while (Temp->next != NULL) {
			Temp = Temp->next;
		}
		Temp->next = Ev;
	}
	sum_events++;
}
void Client::Show_All_Events() {
	Event *Temp = pTheadEvent;
	if (pTheadEvent == NULL) {
		cout << "Client has not any events" << endl;
	}
	else {
		while (Temp->next != NULL) {
			Temp->Show_event();
			Temp = Temp->next;
		}
		Temp->Show_event();
	}
}
void Client::Show_Last_Event() {
	if (pTheadEvent == NULL) {
		cout << "Client has not any events" << endl;
	}
	else {
		pTheadEvent->Show_event();
	}
}
Car::Car(Client *Cl) {
	next = NULL;
	strcpy(Model, "No model");
	char temp_time[20] = "00000000";
	Last_Replacement_Date = new my_time;
	Next_Replacement_Date = new my_time;
	Last_Replacement_Date->Set_Time(temp_time);
	Next_Replacement_Date->Set_Time(temp_time);//расчетная дата
	Average_Mileage = NULL;
	Maximum_Tire_Mileage = NULL;
	strcpy(name_company, Cl->name_company);
	strcpy(phone_company, Cl->phone_company);
	strcpy(adress_company, Cl->adress_company);
	strcpy(name_contact, Cl->name_contact);
	strcpy(phone_contact, Cl->phone_contact);
}
Car::Car(Client *Cl, char *mod) {
	next = NULL;
	strcpy(Model,mod);
	char temp_time[20] = "00000000";
	Last_Replacement_Date = new my_time;
	Next_Replacement_Date = new my_time;
	Last_Replacement_Date->Set_Time(temp_time);
	Next_Replacement_Date->Set_Time(temp_time);//расчетная дата
	Average_Mileage = NULL;
	Maximum_Tire_Mileage = NULL;
	strcpy(name_company, Cl->name_company);
	strcpy(phone_company, Cl->phone_company);
	strcpy(adress_company, Cl->adress_company);
	strcpy(name_contact, Cl->name_contact);
	strcpy(phone_contact, Cl->phone_contact);
}
void Car::Show_Car() {
	cout << "***********************" << endl;
	cout << "Client " << name_company << endl;
	cout << "Car " << Model << endl;
	cout << "Last Replacment ";
	Last_Replacement_Date->Show_Time();
	cout << "Next Replacment ";
	Next_Replacement_Date->Show_Time();
	cout << "Average Mileage " << Average_Mileage << endl;
	cout << "Maximum Tire Mileage " << Maximum_Tire_Mileage << endl;
	cout << "***********************" << endl;
}
Car::~Car() {
	delete Last_Replacement_Date;
	delete Next_Replacement_Date;
}
void Client::Add_Car(Car *Ca) {
	Car *Temp = pTheadCar;
	if (pTheadCar == NULL) {
		pTheadCar = Ca;
	}
	else if (Temp->next == NULL) {
		Temp->next = Ca;
	}
	else {
		while (Temp->next != NULL) {
			Temp = Temp->next;
		}
		Temp->next = Ca;
	}
	Calc_Priorety();
}
Car *Client::Search_Car(char *mod) {
	Car *Temp = pTheadCar;
	if (pTheadCar == NULL) {
		cout << "This Client has not any car" << endl;
}
	else if (Temp->next == NULL) {
		if (strcmp(Temp->Model, mod) == 0) {
			return Temp;
		}
	}
	else {
		while (Temp->next != NULL) {
			if (strcmp(Temp->Model, mod) == 0) {
				return Temp;
			}
			Temp = Temp->next;
		}
		if (strcmp(Temp->Model, mod) == 0) {
			return Temp;
		}
	}
	return NULL;
}

void Client::Fill_Car(char *mod) {
	Car *Temp = Search_Car(mod);
	if (Temp == NULL) {
		cout << "This car is not found" << endl;
	}
	else {
		cout << "Client " << Temp->name_company << " Model car " << Temp->Model << endl;
		cout << "Enter Last Replacement Date : ";
		char temp_time[20];
		gets_s(temp_time);
		Temp->Last_Replacement_Date->Set_Time(temp_time);
		cout << "Enter Average Mileage : ";
		cin >> Temp->Average_Mileage;
		cout << "Maximum Tire Mileage : ";
		cin >> Temp->Maximum_Tire_Mileage;
	}
}
void Client::Show_All_Cars() {
	Car *Temp = pTheadCar;
	if (pTheadCar == NULL) {
		cout << "This Client has not any car" << endl;
	}
	else if (Temp->next == NULL) {
		Temp->Show_Car();
	}
	else {
		while (Temp->next != NULL) {
			Temp->Show_Car();
			Temp = Temp->next;
		}
		Temp->Show_Car();
	}
}
my_time::my_time() {
	//strcpy(date_ch, "00/00/0000");
	date_day = NULL;
	date_month = NULL;
	date_year = NULL;
	date_one = NULL;
}
my_time::~my_time() {

}
void my_time::Show_Time() {
	if (date_day < 10) {
		cout << setw(1) << 0 << date_day << "/";
	}
	else {
		cout << setw(2) << date_day << "/";
	}
	if (date_month < 10) {
		cout << setw(1) << 0 << date_month << "/";
	}
	else {
		cout << setw(2) << date_month << "/";
	}
	if (date_year != NULL) {
		cout << setw(4) << date_year << endl;
	}
	else {
		cout << setw(4) << "0000" << endl;
	}
}
void my_time::Set_Time(char *Ti) {
	char temp_date[20];
	char day[3];
	char month[3];
	char year[5];
	strcpy(temp_date, Ti);
	//cout << "temp_date " << temp_date << endl;
	int j = 0, k = 0, l = 0;
	for (int i = 0; i < 20; i++) {
		if (temp_date[i] >= '0' && temp_date[i] <= '9' && j < 2) {
			day[j] = temp_date[i];
			//cout << "i= " << i << " j= " << j << " - " << day[j] << endl;
			j++;
		}
		else if (temp_date[i] >= '0' && temp_date[i] <= '9' && j >= 2 && k < 2) {
			month[k] = temp_date[i];
			k++;
		}
		else if (temp_date[i] >= '0' && temp_date[i] <= '9' && k >= 2 && l < 4) {
			year[l] = temp_date[i];
			l++;
		}
	}
	day[j] = '\0';
	month[k] = '\0';
	year[l] = '\0';
	//cout << "day " << day << " month " << month << " year " << year << endl;
	//cout << "Length year = " << strlen(year) << endl;
	if (strlen(year) < 4) {
		//cout << "Incorrect date..." << endl;
		return;
	}
	
	if (atoi(day) < 1 || atoi(day) > 31) {
		//cout << "Incorrect date_day..." << endl;
		return;
	}
	if (atoi(month) < 1 || atoi(month) > 12) {
		//cout << "Incorrect date_month..." << endl;
		return;
	}
	if (atoi(year) < 2000 || atoi(year) > 2100) {
		//cout << "Incorrect date_year..." << endl;
		return;
	}
	date_day = atoi(day);
	date_month = atoi(month);
	date_year = atoi(year);
	Calc_Date_One();
}
void my_time::Calc_Date_One() {
	const int day_in_year[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const int day_in_leap_year[13] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const int start_year = 2000;
	date_one = NULL;
	date_one += date_day-1;
	if ((date_year - start_year) % 4 == 0) {
		for (int i = date_month-2; i >= 0; i--) {
			date_one += day_in_leap_year[i];
		}
	}
	else {
		for (int i = date_month-2; i >= 0; i--) {
			date_one += day_in_year[i];
		}
	}
		for (int i = date_year-1; i >= 2000; i--) {
			if ((i - start_year) % 4 == 0) {
				date_one += 366;
			}
			else {
				date_one += 365;
			}
	}

}
int my_time::Get_Date_One() {
	return date_one;
}
int my_time::Get_Date_Day() {
	return date_day;
}
int my_time::Get_Date_Month() {
	return date_month;
}
int my_time::Get_Date_Year() {
	return date_year;
}
void my_time::Set_Time_from_int(int Ti) {
	const int day_in_year[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const int day_in_leap_year[13] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const int start_year = 2000;
	int sum_day = Ti;
	int sum_year = start_year;
	while (sum_day > 366) {
		if ((sum_year - 2000) % 4 == 0) {
			sum_day -= 366;
			sum_year++;
		}
		else {
			sum_day -= 365;
			sum_year++;
		}
	}
	int sum_month = 0;
		if ((sum_year - start_year) % 4 == 0) {
			while (sum_day > 31) {
				sum_day -= day_in_leap_year[sum_month];
				sum_month++;
			}
		}
		else {
			while (sum_day > 31) {
				sum_day -= day_in_year[sum_month];
				sum_month++;
			}
		}
		//cout << "Day = " << sum_day << " Month = " << sum_month+1 << "Year = " << sum_year << endl;
		if (sum_day < 1 || sum_day > 31) {
			//cout << "Incorrect date_day..." << endl;
			return;
		}
		if (sum_month+1 < 1 || sum_month+1 > 12) {
			//cout << "Incorrect date_month..." << endl;
			return;
		}
		if (sum_year < 2000 || sum_year > 2100) {
			//cout << "Incorrect date_year..." << endl;
			return;
		}
		date_day = sum_day;
		date_month = sum_month + 1;
		date_year = sum_year;
		date_one = Ti;
}
void my_time::Plus_Time(int Da) {
	int sum_date = date_one + Da;
	Set_Time_from_int(sum_date);
}
void Car::Calc_Next_Replacement_Date() {
	int sum_day;
	if (Average_Mileage > 0) {
		sum_day = Maximum_Tire_Mileage / Average_Mileage; //на сколько хватит шин
	}
	else {
		sum_day = NULL;
	}
	Next_Replacement_Date->Set_Time_from_int(Last_Replacement_Date->Get_Date_One());
	//cout << "Next_Replacement_Date->Get_Date_One() = " << Next_Replacement_Date->Get_Date_One() << endl;
	//cout << "sum_day = " << sum_day << endl;
	Next_Replacement_Date->Plus_Time(sum_day);// получаем дату следующей замены шин
	//cout << "Next_Replacement_Date->Plus_Time(sum_day) " << Next_Replacement_Date->Get_Date_One() << endl;
}
void Client::Calc_Next_Replacement_Date_All_Cars() {
	Car *Temp = pTheadCar;
	if (pTheadCar == NULL) {
		cout << "This Client has not any car" << endl;
	}
	else if (Temp->next == NULL) {
		Temp->Calc_Next_Replacement_Date();
	}
	else {
		while (Temp->next != NULL) {
			Temp->Calc_Next_Replacement_Date();
			Temp = Temp->next;
		}
		Temp->Calc_Next_Replacement_Date();
	}
}
void my_time::Get_Current_Date() {
	time_t temp_t = time(NULL);
	tm *T = localtime(&temp_t);
	char *dt = ctime(&temp_t);
	//cout << "dt = " << dt << endl;
	date_day = T->tm_mday;
	date_month = T->tm_mon+1;
	date_year = T->tm_year+1900;
	Calc_Date_One();
	//cout << "T->tm_year = " << T->tm_year << endl;
}
void Event::Fill_Event() {
	cout << "Client : " << name_company << endl;
	cout << "Enter description : " << endl;
	gets_s(description_event);
	cout << "Enter date next action : " << endl;
	char temp_t[1000];
	gets_s(temp_t);
	date_action->Set_Time(temp_t);
}
Task::Task(Client *Cl) {
	next = NULL;
	date_create = new my_time;
	date_action = new my_time;// расчетная на основании последнего события и данных парка
	char temp_t[20] = "00000000";
	date_create->Get_Current_Date();
	date_action->Set_Time(temp_t);
	strcpy(description_task,"to call ......");
	Client_ID = Cl->Client_ID;
	Priorety = Cl->Priorety;
	strcpy(name_company, Cl->name_company);
	strcpy(phone_company, Cl->phone_company);
	strcpy(adress_company, Cl->adress_company);
	strcpy(name_contact,Cl->name_contact);
	strcpy(phone_contact, Cl->phone_contact);
	Cl->pTtask = this;
}
void Client::Add_Task() {
	if (pTtask == NULL) {
		pTtask = new Task(this);
	}
	else {
		cout << "This Client already has one task" << endl;
	}
}

Task::~Task() {
	delete date_create;
	delete date_action;
}
void Task::Show_Task() {
	cout << "*******************************" << endl;
	cout << "Task for Client : " << name_company << endl;
	cout << "Priorety : " << Priorety << endl;
	cout << "Date create : ";
	date_create->Show_Time();
	cout << "Date action : ";
	date_action->Show_Time();
	cout << description_task << endl;
	cout << "*******************************" << endl;
}
void Client::Fill_Task() {
	strcpy(pTtask->name_company, name_company);
	int date_from_cars, date_from_last_event;
	Car *Temp = pTheadCar;
	Car *Early_date = pTheadCar;
	if (pTheadCar == NULL) {
		cout << "This Client "<< name_company << " has not any car" << endl;
	}
	else if (Temp->next == NULL) {
		//date_from_cars = Temp->Next_Replacement_Date->Get_Date_One();
		Early_date = Temp;
	}
	else {
		date_from_cars = Temp->Next_Replacement_Date->Get_Date_One();
		while (Temp->next != NULL) {
			if (date_from_cars > Temp->Next_Replacement_Date->Get_Date_One()) {
				//date_from_cars = Temp->Next_Replacement_Date->Get_Date_One();
				Early_date = Temp;
			}
			Temp = Temp->next;
		}
		if (date_from_cars > Temp->Next_Replacement_Date->Get_Date_One()) {
			//date_from_cars = Temp->Next_Replacement_Date->Get_Date_One();
			Early_date = Temp;
		}
	}
	if (Early_date == NULL) {
		date_from_cars = NULL;
	}
	else {
		date_from_cars = Early_date->Next_Replacement_Date->Get_Date_One();
		//cout << "date_from_cars = " << date_from_cars << endl;
		//Early_date->Show_Car();
	}
	if (pTheadEvent == NULL) {
		cout << "This Client "<< name_company << " has not any Event " << endl;
		date_from_last_event = NULL;
	}
	else {
		date_from_last_event = pTheadEvent->date_action->Get_Date_One();
	}
	//cout << "date_from_last_event : " << date_from_last_event << endl;
	if (date_from_cars < date_from_last_event && date_from_cars!=NULL) {
		pTtask->date_action->Set_Time_from_int(date_from_cars);
		char temp_desc[1000] = "Check the condition of the car\n";
		strcpy(pTtask->description_task, temp_desc);
		strcat(pTtask->description_task, Early_date->Model);
		pTtask->Priorety = Priorety;
	}
	else if (date_from_cars > date_from_last_event && date_from_last_event!=NULL) {
		pTtask->date_action->Set_Time_from_int(date_from_last_event);
		char temp_desc_2[1000] = "Clarify the state of the park and the need";
		strcpy(pTtask->description_task, temp_desc_2);
		pTtask->Priorety = Priorety;
	}
	else if (date_from_cars < date_from_last_event && date_from_cars == NULL) {
		pTtask->date_action->Set_Time_from_int(date_from_last_event);
		char temp_desc_2[1000] = "Clarify the state of the park and the need";
		strcpy(pTtask->description_task, temp_desc_2);
		pTtask->Priorety = Priorety;
	}
	else if (date_from_cars > date_from_last_event && date_from_last_event == NULL) {
		pTtask->date_action->Set_Time_from_int(date_from_cars);
		char temp_desc[1000] = "Check the condition of the car\n";
		strcpy(pTtask->description_task, temp_desc);
		strcat(pTtask->description_task, Early_date->Model);
		pTtask->Priorety = Priorety;
	}
}
List_Manager::List_Manager() {
	pTheadTaskAll = NULL;
	pTheadTaskMain = NULL;
	pTheadTaskSpare = NULL;
	main_tasks_in_day = 2;
}
List_Manager::~List_Manager() {

}
void List_Client::Fill_Tasks_in_List_Client(Client *Node) {
	if (Node != NULL) {
		Fill_Tasks_in_List_Client(Node->left);
			//cout << "Fill_Task(); " << Node->name_company << endl;
			Node->Fill_Task();
		Fill_Tasks_in_List_Client(Node->right);
	}
}
void List_Client::Add_Tasks_in_List_Manager(Client *Node, List_Manager *LM, my_time *now) {//у всех клиентов должны быть задачи!!
	//my_time *now = new my_time;
	//now->Get_Current_Date();
	//int Current_date = now->Get_Date_One();
	//cout << "now->Get_Date_One() : " << now->Get_Date_One() << endl;
	if (Node != NULL) {
		Add_Tasks_in_List_Manager(Node->left, LM, now);
		if (Node->pTtask->date_action->Get_Date_One() == now->Get_Date_One()) {
			//cout << Node->Client_ID << " / " << Node->name_company << endl;
			//cout << "Date action : ";
			//Node->pTtask->date_action->Show_Time();
			//Node->pTtask->Show_Task();
			LM->Add_Task(Node->pTtask);
		}
		Add_Tasks_in_List_Manager(Node->right,LM, now);
	}
}
void List_Manager::Add_Task(Task *Ta) {
	Task *Temp = pTheadTaskAll;
	if (pTheadTaskAll == NULL) {
		pTheadTaskAll = Ta;
	}
	else if (Temp->next == NULL) {
		Temp->next = Ta;
	}
	else {
		while (Temp->next != NULL) {
			Temp = Temp->next;
		}
		Temp->next = Ta;
	}
}
void List_Manager::Show_All_Tasks() {
	Task *Temp = pTheadTaskAll;
	if (pTheadTaskAll == NULL) {
		cout << "This Client has not any Tasks" << endl;
	}
	else if (Temp->next == NULL) {
		Temp->Show_Task();
	}
	else {
		while (Temp->next != NULL) {
			Temp->Show_Task();
			Temp = Temp->next;
		}
		Temp->Show_Task();
	}
}
void Client::Calc_Priorety() {
	Car *Temp = pTheadCar;
	int temp_pri = 0;
	if (pTheadCar == NULL) {
		Priorety = 0;
		//cout << "Priorety = 0 in park no any car " << endl;
	}
	else if (Temp->next == NULL) {
		Priorety = 1;
		//cout << "Priorety = 1 in park one car " << endl;
	}
	else {
		while (Temp->next != NULL) {
			temp_pri++;
			Temp = Temp->next;
		}
		temp_pri++;
		Priorety = temp_pri;
	}
	//cout << "Client : " << name_company << " Priorety = " << Priorety << endl;
}
int List_Manager::Calc_Tasks() {
	Task *Temp = pTheadTaskAll;
	int sum_tasks = 0;
	if (pTheadTaskAll == NULL) {
		cout << "List has not any tasks " << endl;
	}
	else if (Temp->next == NULL) {
		sum_tasks = 1;
		cout << "List has one task " << endl;
	}
	else {
		while (Temp->next != NULL) {
			sum_tasks++;
			Temp = Temp->next;
		}
		sum_tasks++;
	}
	//cout << "sum_tasks = " << sum_tasks << endl;
	return sum_tasks;
}

void List_Manager::Sort_Tasks() {
	Task *Temp = pTheadTaskAll;
	Task *pTmax = pTheadTaskAll;
	Task *pTbefor = pTheadTaskAll;
	int sum_task_in_list = Calc_Tasks();//количество элементов списка, считаем предварительно
	if (Temp == NULL) {
		cout << "This List has not any tasks " << endl;
		return;
	}
	else if (Temp->next == NULL) {
		cout << "This List has only one task " << endl; 
		return;
	}
	else {
		for (int i = 0; i < sum_task_in_list-1; i++) {
			Temp = pTheadTaskAll;
			pTmax = pTheadTaskAll;
			pTbefor = pTheadTaskAll;
			for (int j = 1; j < sum_task_in_list - i; j++) {
				(pTbefor->next == pTmax || pTbefor == pTmax)? 0: pTbefor = pTbefor->next;
				Temp = pTmax->next;
				if (pTmax->Priorety < Temp->Priorety) {
					pTmax->next = Temp->next;
					Temp->next = pTmax;
					if (j == 1) {
						pTheadTaskAll = Temp;
						pTbefor = pTheadTaskAll;
					}
					else pTbefor->next = Temp;
				}
				else {
					//pTbefor = Temp;
					pTmax = Temp;
				}
			}
		}
	}
}
void List_Manager::Show_Main_Tasks() {
	Task *Temp = pTheadTaskAll;
	int sum_tasks = Calc_Tasks();
	if (Temp == NULL) {
		cout << "Today there are no tasks for the main manager " << endl;
	}
	else if (sum_tasks <= main_tasks_in_day) {
		cout << "Tasks today for main manager : " << endl;
		Show_All_Tasks();
	}
	else {
		cout << "Tasks today for main manager : " << endl;
		for (int i = 1; i <= main_tasks_in_day; i++) {
			Temp->Show_Task();
			Temp = Temp->next;
		}
	}
}
void List_Manager::Show_Spare_Tasks() {
	Task *Temp = pTheadTaskAll;
	int sum_tasks = Calc_Tasks();
	if (sum_tasks <= main_tasks_in_day) {
		cout << "Today there are no tasks for the spare manager " << endl;
	}
	else {
		cout << "Tasks today for spare manager : " << endl;
		int j = 0;
		for (int i = 1; i <= main_tasks_in_day; i++) {
			Temp = Temp->next;
			j++;
		}
		for (int i = j+1; i <= sum_tasks; i++) {
			Temp->Show_Task();
			Temp = Temp->next;
		}
	}
}
void Car::Write_Car_To_File(fstream *f) {
	//fstream inF("bd.bin", ios::out | ios::binary |ios::app);
	int size;
	size = strlen(Model);
	f->write((char*)&size, sizeof(int));// записываем 3 собственных поля и 2 объекта my_time по 1 полю
	f->write((char*)Model, size * sizeof(char));
	//size = strlen(owner);
	//int Date_Day = Last_Replacement_Date->Get_Date_Day();
	//inF.write((char*)&Date_Day, sizeof(int));
	//int Date_Month = Last_Replacement_Date->Get_Date_Month();
	//inF.write((char*)&Date_Month, sizeof(int));
	//int Date_Year = Last_Replacement_Date->Get_Date_Year();
	//inF.write((char*)&Date_Year, sizeof(int));
	int Date_One = Last_Replacement_Date->Get_Date_One();
	f->write((char*)&Date_One, sizeof(int));
	//Date_Day = Next_Replacement_Date->Get_Date_Day();
	//inF.write((char*)&Date_Day, sizeof(int));
	//Date_Month = Next_Replacement_Date->Get_Date_Month();
	//inF.write((char*)&Date_Month, sizeof(int));
	//Date_Year = Next_Replacement_Date->Get_Date_Year();
	//inF.write((char*)&Date_Year, sizeof(int));
	Date_One = Next_Replacement_Date->Get_Date_One();
	f->write((char*)&Date_One, sizeof(int));
	f->write((char*)&Average_Mileage, sizeof(int));
	f->write((char*)&Maximum_Tire_Mileage, sizeof(int));
}
void Car::Read_Car_From_File(fstream *f) {
	int size, data;
	f->read((char*)&size, sizeof(int));
	f->read((char*)Model, size * sizeof(char));
	Model[size] = '\0';
	f->read((char*)&data, sizeof(int));
	Last_Replacement_Date->Set_Time_from_int(data);
	f->read((char*)&data, sizeof(int));
	Next_Replacement_Date->Set_Time_from_int(data);
	f->read((char*)&Average_Mileage, sizeof(int));
	f->read((char*)&Maximum_Tire_Mileage, sizeof(int));
}
void Event::Write_Event_To_File(fstream *f) {
	int size, data;
	data = date_create->Get_Date_One();
	f->write((char*)&data, sizeof(int));
	data = date_action->Get_Date_One();
	f->write((char*)&data, sizeof(int));
	size = strlen(description_event);
	f->write((char*)&size, sizeof(int));
	f->write((char*)description_event, size * sizeof(char));
}
void Event::Read_Event_From_File(fstream *f) {
	int size, data;
	f->read((char*)&data, sizeof(int));
	date_create->Set_Time_from_int(data);
	f->read((char*)&data, sizeof(int));
	date_action->Set_Time_from_int(data);
	f->read((char*)&size, sizeof(int));
	f->read((char*)description_event, size * sizeof(char));
	description_event[size] = '\0';
}
void Client::Write_Client_To_File(fstream *f) {
	//fstream inF("bdClient.bin", ios::out | ios::binary | ios::app);
	int size, sum_cars, sum_evs;
	f->write((char*)&Client_ID, sizeof(int));
	f->write((char*)&Priorety, sizeof(int));
	f->write((char*)&sum_events, sizeof(int));
	size = strlen(name_company);
	f->write((char*)&size, sizeof(int));
	f->write((char*)name_company, size * sizeof(char));
	size = strlen(phone_company);
	f->write((char*)&size, sizeof(int));
	f->write((char*)phone_company, size * sizeof(char));
	size = strlen(adress_company);
	f->write((char*)&size, sizeof(int));
	f->write((char*)adress_company, size * sizeof(char));
	size = strlen(name_contact);
	f->write((char*)&size, sizeof(int));
	f->write((char*)name_contact, size * sizeof(char));
	size = strlen(phone_contact);
	f->write((char*)&size, sizeof(int));
	f->write((char*)phone_contact, size * sizeof(char));
	sum_cars = Priorety;
	Car *Temp = pTheadCar;
	for (int i = 1; i <= sum_cars; i++) {
		Temp->Write_Car_To_File(f);
		//cout << "This Write_Car_To_File " << endl;
		Temp = Temp->next;
	}
	sum_evs = sum_events;
	Event *TempEv = pTheadEvent;
	for (int i = 1; i <= sum_evs; i++) {
		TempEv->Write_Event_To_File(f);
		//cout << "This Write_Event_To_File " << endl;
		TempEv = TempEv->next;
	}
	//inF.close();
	//cout << "This Write_Client_To_File " << endl;
}
void Client::Read_Client_From_File(fstream *f) {
	//fstream outF("bdClient.bin", ios::in | ios::binary);
	int size, sum_cars, sum_evs;
	f->read((char*)&Client_ID, sizeof(int));
	f->read((char*)&Priorety, sizeof(int));
	f->read((char*)&sum_events, sizeof(int));
	f->read((char*)&size, sizeof(int));
	f->read((char*)name_company, size * sizeof(char));
	name_company[size] = '\0';
	f->read((char*)&size, sizeof(int));
	f->read((char*)phone_company, size * sizeof(char));
	phone_company[size] = '\0';
	f->read((char*)&size, sizeof(int));
	f->read((char*)adress_company, size * sizeof(char));
	adress_company[size] = '\0';
	f->read((char*)&size, sizeof(int));
	f->read((char*)name_contact, size * sizeof(char));
	name_contact[size] = '\0';
	f->read((char*)&size, sizeof(int));
	f->read((char*)phone_contact, size * sizeof(char));
	phone_contact[size] = '\0';
	sum_cars = Priorety;
	Car **pTnew = new Car*[sum_cars];
	for (int i = 0; i < sum_cars; i++) {
		//char temp_model[20] = "model";
		pTnew[i] = new Car(this);
		Add_Car(pTnew[i]);
		pTnew[i]->Read_Car_From_File(f);
	}
	sum_evs = sum_events;
	Event **pTnewEv = new Event*[sum_evs];
	for (int i = 0; i < sum_evs; i++) {
		pTnewEv[i] = new Event(this);
		Add_Event_To_Tail(pTnewEv[i]);
		pTnewEv[i]->Read_Event_From_File(f);
	}
	//outF.close();
}
void List_Client::Write_All_Clients_To_File(Client *Node, fstream *f) {
	if (Node != NULL) {
		Write_All_Clients_To_File(Node->left,f);
		//cout << Node->Client_ID << " / " << Node->name_company << endl;
		Node->Write_Client_To_File(f);
		Write_All_Clients_To_File(Node->right,f);
	}
}

void List_Client::Write_Client_List_To_File() {
	fstream inF("bdClient.bin", ios::out | ios::binary);
	int size;
	size = strlen(Name_List_Client);
	inF.write((char*)&size, sizeof(int));
	inF.write((char*)Name_List_Client, size * sizeof(char));
	inF.write((char*)&Last_ID, sizeof(int));
	inF.write((char*)&sum_clients, sizeof(int));
	Client *N = root;
	Write_All_Clients_To_File(N,&inF);
	inF.close();
}
void List_Client::Read_Client_List_From_File() {
	fstream outF("bdClient.bin", ios::in | ios::binary);
	if (!outF) {
		cout << "File bdClient.bin is not exist!" << endl;
		return;
	}
	int size;
	outF.read((char*)&size, sizeof(int));
	outF.read((char*)Name_List_Client, size * sizeof(char));
	Name_List_Client[size] = '\0';
	outF.read((char*)&Last_ID, sizeof(int));
	outF.read((char*)&sum_clients, sizeof(int));
	int sum_cl = sum_clients;
	sum_clients = NULL;
	Client **pTnew = new Client*[sum_cl];
	for (int i = 0; i < sum_cl; i++) {
		//char temp_model[20] = "model";
		pTnew[i] = new Client;
		pTnew[i]->Read_Client_From_File(&outF);
		Add_client(pTnew[i]);
	}
	outF.close();
}
void Show_menu(char *ch) {
	char choice[10];
	cout << "****************************************" << endl;
	cout << "Add new client - 1" << endl;
	cout << "Add new car - 2" << endl;
	cout << "Add new event - 3" << endl;
	cout << "Show tasks for main manager - 4" << endl;
	cout << "Show tasks for spare manager - 5" << endl;
	cout << "Show all clients - 6" << endl;
	cout << "Fill client - 7" << endl;
	cout << "Search client - 8" << endl;
	cout << "Show all cars for client - 9" << endl;
	cout << "Fill car - 10" << endl;
	cout << "Show all events for client - 11" << endl;
	cout << "Delete client - 12" << endl;
	cout << "Delete car - 13" << endl;
	// any thing alse
	cout << "Exit - 15" << endl;
	cout << "****************************************" << endl;
	gets_s(choice);
	strcpy(ch, choice);
}
Client *Create_Client(List_Client *L) {
	char name[100];
	cout << "Enter name company : ";
	gets_s(name);
	Client *Temp = new Client(name,L);
	return Temp;
}
Car *Create_Car(Client *Cl) {
	char model[200];
	cout << "Enter model car : ";
	gets_s(model);
	Car *Temp = new Car(Cl,model);
	return Temp;
}
Event *Create_Event(Client *Cl) {
	Event *Temp = new Event(Cl);
	Temp->Fill_Event();
	return Temp;
}
void Client::Delete_Car(char *mod) {
	Car *Temp = pTheadCar;
	Car *TempBefor = pTheadCar;
	if (pTheadCar == NULL) {
		cout << "This client has not any cars" << endl;
		return;
	}
	else if (Temp->next == NULL) {
		if (strcmp(Temp->Model, mod) == 0) {
			pTheadCar = NULL;
			delete Temp;
			Priorety--;
			return;
		}
		else {
			cout << "This client has not this car" << endl;
		}
	}
	else {
		while (Temp->next != NULL) {
			if (strcmp(Temp->Model, mod) == 0) {
				if (Temp == pTheadCar) {
					pTheadCar = Temp->next;
					delete Temp;
					Priorety--;
					return;
				}
				else {
					TempBefor->next = Temp->next;
					delete Temp;
					Priorety--;
					return;
				}
			}
			else {
				Temp = Temp->next;
				if (TempBefor->next != Temp && TempBefor != Temp) {
					TempBefor = TempBefor->next;
				}
			}
		}
		if (strcmp(Temp->Model, mod) == 0) {
			if (Temp == pTheadCar) {
				pTheadCar = Temp->next;
				delete Temp;
				Priorety--;
				return;
			}
			else {
				TempBefor->next = Temp->next;
				delete Temp;
				Priorety--;
				return;
			}
		}
		else {
			cout << "This client has not this car" << endl;
		}
	}
}
void Client::Delete_All_Cars() {
	Car *Temp = pTheadCar;
	if (pTheadCar == NULL) {
		cout << "This client has not any cars" << endl;
		return;
	}
	else if (Temp->next == NULL) {
		pTheadCar = NULL;
		delete Temp;
		Priorety--;
		return;
	}
	else {
		while (Temp->next != NULL) {
			pTheadCar = Temp->next;
			delete Temp;
			Priorety--;
			Temp = pTheadCar;
		}
		pTheadCar = NULL;
		delete Temp;
		Priorety--;
		return;
	}
}
void Client::Delete_All_Events() {
	Event *Temp = pTheadEvent;
	if (pTheadEvent == NULL) {
		cout << "This client has not any events" << endl;
		return;
	}
	else if (Temp->next == NULL) {
		pTheadEvent = NULL;
		delete Temp;
		sum_events--;
		return;
	}
	else {
		while (Temp->next != NULL) {
			pTheadEvent = Temp->next;
			delete Temp;
			sum_events--;
			Temp = pTheadEvent;
		}
		pTheadEvent = NULL;
		delete Temp;
		sum_events--;
		return;
	}
}
void List_Client::Delete_Client(char *name) {
	if (root == NULL) {
		cout << "This List has not any client" << endl;
		return;
	}
	else {
	Client *Z = Search_client(name);
	if (Z == NULL) {
		cout << "This List has not this client" << endl;
		return;
	}
	Client *pTbefor, *pTafter;
	if (Z->parent == NULL && Z->left == NULL && Z->right == NULL) {
		root = NULL;
		delete Z;
		sum_clients--;
		return;
	}
	else if (Z->parent != NULL && Z->left == NULL && Z->right == NULL) {
		pTbefor = Z->parent;
		if (pTbefor->left == Z) {
			pTbefor->left = NULL;
			delete Z;
			sum_clients--;
			return;
		}
		else {
			pTbefor->right = NULL;
			delete Z;
			sum_clients--;
			return;
		}
	}
	else if (Z->parent != NULL && Z->left == NULL && Z->right != NULL) {
		pTbefor = Z->parent;
		if (pTbefor->left == Z) {
			pTbefor->left = Z->right;
			delete Z;
			sum_clients--;
			return;
		}
		else {
			pTbefor->right = Z->right;
			delete Z;
			sum_clients--;
			return;
		}
	}
	else if (Z->parent == NULL && Z->left == NULL && Z->right != NULL) {
		root = Z->right;
		root->parent = NULL;
			delete Z;
			sum_clients--;
			return;
	}
	else if (Z->parent != NULL && Z->left != NULL && Z->right == NULL) {
		pTbefor = Z->parent;
		if (pTbefor->left == Z) {
			pTbefor->left = Z->left;
			delete Z;
			sum_clients--;
			return;
		}
		else {
			pTbefor->right = Z->left;
			delete Z;
			sum_clients--;
			return;
		}
	}
	else if (Z->parent == NULL && Z->left != NULL && Z->right == NULL) {
		root = Z->left;
		root->parent = NULL;
		delete Z;
		sum_clients--;
		return;
	}
	else if (Z->parent != NULL && Z->left != NULL && Z->right != NULL) {
		pTbefor = Z->parent;
		pTafter = Min(Z->right);
		if (pTbefor->left == Z) {
			pTbefor->left = Z->right;
			pTafter->left = Z->left;
			Z->left = NULL;
			Z->right = NULL;
			delete Z;
			sum_clients--;
			return;
		}
		else {
			pTbefor->right = Z->right;
			pTafter->left = Z->left;
			Z->left = NULL;
			Z->right = NULL;
			delete Z;
			sum_clients--;
			return;
		}
	}
	else if (Z->parent == NULL && Z->left != NULL && Z->right != NULL) {
		pTafter = Min(Z->right);
			root = Z->right;
			root->parent = NULL;
			pTafter->left = Z->left;
			Z->left = NULL;
			Z->right = NULL;
			delete Z;
			sum_clients--;
			return;
	}
	else {
		cout << "Func Delete_Client has not this case " << endl;
	}
	}
}
void List_Client::Delete_Client(Client *Z) {
	if (root == NULL) {
		cout << "This List has not any client" << endl;
		return;
	}
	else {
		if (Z == NULL) {
			cout << "This List has not this client" << endl;
			return;
		}
		Client *pTbefor, *pTafter;
		if (Z->parent == NULL && Z->left == NULL && Z->right == NULL) {
			root = NULL;
			delete Z;
			sum_clients--;
			return;
		}
		else if (Z->parent != NULL && Z->left == NULL && Z->right == NULL) {
			pTbefor = Z->parent;
			if (pTbefor->left == Z) {
				pTbefor->left = NULL;
				delete Z;
				sum_clients--;
				return;
			}
			else {
				pTbefor->right = NULL;
				delete Z;
				sum_clients--;
				return;
			}
		}
		else if (Z->parent != NULL && Z->left == NULL && Z->right != NULL) {
			pTbefor = Z->parent;
			if (pTbefor->left == Z) {
				pTbefor->left = Z->right;
				delete Z;
				sum_clients--;
				return;
			}
			else {
				pTbefor->right = Z->right;
				delete Z;
				sum_clients--;
				return;
			}
		}
		else if (Z->parent == NULL && Z->left == NULL && Z->right != NULL) {
			root = Z->right;
			root->parent = NULL;
			delete Z;
			sum_clients--;
			return;
		}
		else if (Z->parent != NULL && Z->left != NULL && Z->right == NULL) {
			pTbefor = Z->parent;
			if (pTbefor->left == Z) {
				pTbefor->left = Z->left;
				delete Z;
				sum_clients--;
				return;
			}
			else {
				pTbefor->right = Z->left;
				delete Z;
				sum_clients--;
				return;
			}
		}
		else if (Z->parent == NULL && Z->left != NULL && Z->right == NULL) {
			root = Z->left;
			root->parent = NULL;
			delete Z;
			sum_clients--;
			return;
		}
		else if (Z->parent != NULL && Z->left != NULL && Z->right != NULL) {
			pTbefor = Z->parent;
			pTafter = Min(Z->right);
			if (pTbefor->left == Z) {
				pTbefor->left = Z->right;
				pTafter->left = Z->left;
				Z->left = NULL;
				Z->right = NULL;
				delete Z;
				sum_clients--;
				return;
			}
			else {
				pTbefor->right = Z->right;
				pTafter->left = Z->left;
				Z->left = NULL;
				Z->right = NULL;
				delete Z;
				sum_clients--;
				return;
			}
		}
		else if (Z->parent == NULL && Z->left != NULL && Z->right != NULL) {
			pTafter = Min(Z->right);
			root = Z->right;
			root->parent = NULL;
			pTafter->left = Z->left;
			Z->left = NULL;
			Z->right = NULL;
			delete Z;
			sum_clients--;
			return;
		}
		else {
			cout << "Func Delete_Client has not this case " << endl;
		}
	}
}

void List_Client::Delete_All_Clients(Client *Node) {
	if (root == NULL) {
		cout << "This List has not any client" << endl;
		return;
	}
	if (Node != NULL) {
		Delete_All_Clients(Node->left);
		cout << "Delete :" << Node->Client_ID << " / " << Node->name_company << endl;
		Delete_Client(Node);
		Delete_All_Clients(Node->right);
	}
}
