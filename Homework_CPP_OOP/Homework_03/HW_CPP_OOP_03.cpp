#include <iostream> 
using namespace std;
class Person {
	string name;
	int age;
	char sex;
	int number;
public:
	    Person() {
		cout << "This is constructor without parametrs" << endl;
	}
		Person(string name, int age, char sex, int number) {
		this->name = name;
		this->age = age;
		this->sex = sex;
		this->number = number;
		cout << "This is constructor" << endl;
	}
	Person(Person&obj) {
		name = obj.name;
		age = obj.age;
		sex = obj.sex;
		number = obj.number;
		cout << "This is Copy_constructor with adress " << &obj << endl;
	}
	void set_name(string name) {
		this->name = name;
	}
	void set_age(int age) {
		this->age = age;
	}
	void set_sex(char sex) {
		this->sex = sex;
	}
	void set_number(int number) {
		this->number = number;
	}
	string get_name() {
		return name;
	}
	int get_age() {
		return age;
	}
	char get_sex() {
		return sex;
	}
	int get_number() {
		return number;
	}
	~Person() {
		cout << "This is destructor" << endl;
	}
};
void create_person();
Person func(Person p);
int main() {
	create_person();
	int end_;
	cin >> end_;
	return 0;
}
Person func(Person p) {
	cout << "This is func(Person p)" << endl;
	return p;
}
void create_person() {
	Person P1("Ivan", 40, 'M', 123);
	cout << "adress P1 " << &P1 << endl;
	P1 = func(P1);
	Person P2;
	P2 = func(P1);
}