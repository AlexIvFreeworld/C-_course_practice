#include <iostream>
using namespace std;
class my_time {
	int format_time;//0 - local, 1- am, 2 - pm
	int hour_time;
	int minute_time;
	int sum_minute;
public:
	my_time(int h, int m) {
		if (h >= 0 && h <= 23 && m >= 0 && m <= 60 || h == 24 && m == 0) {
			hour_time = h;
			minute_time = m;
			format_time = 0;
			sum_minute = hour_time * 60 + minute_time;
		}
		else cout << "Incorrect format date in " << h << " or " << m << endl;
	}
	my_time(int h, int m, int f) {
		if (h >= 0 && h <= 11 && m >= 0 && m <= 60 || h == 12 && m == 0) {
			hour_time = h;
			minute_time = m;
			if (f == 1 || f == 2) {
				format_time = f;
				(f==1)?sum_minute = hour_time * 60 + minute_time: sum_minute = (hour_time+12) * 60 + minute_time;
			}
			else cout << "Incorrect format date in " << f << endl;
		}
		else cout << "Incorrect format date in "<< h << " or " << m << endl;
	}
	void show();
	bool operator == (const my_time &obj);
	my_time operator + (const my_time &obj);
	my_time operator - (const my_time &obj);
	void convert_usa_to_local();
};
void my_time::show() {
	if (format_time == 0) {
		cout << "Time " << hour_time << ":" << minute_time << " " << sum_minute << endl;
	}
	else if (format_time == 1) {
		cout << "Time " << hour_time << ":" << minute_time << " am" << " " << sum_minute << endl;
	}
	else if (format_time == 2) {
		cout << "Time " << hour_time << ":" << minute_time << " pm" << " " << sum_minute << endl;
	}
}
bool my_time::operator == (const my_time &obj) {
	return (sum_minute == obj.sum_minute);
}
my_time my_time::operator + (const my_time &obj) {
	my_time T(0,0);
	T.sum_minute = (sum_minute + obj.sum_minute)%1440;
	T.hour_time = T.sum_minute / 60;
	T.minute_time = T.sum_minute % 60;
	T.format_time = 0;
	return T;
}
my_time my_time::operator - (const my_time &obj) {
	my_time T(0, 0);
	if (sum_minute >= obj.sum_minute) {
		T.sum_minute = sum_minute - obj.sum_minute;
		T.hour_time = T.sum_minute / 60;
		T.minute_time = T.sum_minute % 60;
		T.format_time = 0;
	}
	else {
		T.sum_minute = (sum_minute - obj.sum_minute)+1440;
		T.hour_time = T.sum_minute / 60;
		T.minute_time = T.sum_minute % 60;
		T.format_time = 0;
		//cout << "Error Second time is bigger then first " << endl;
		//exit(1);
	}
	return T;
}
void my_time::convert_usa_to_local() {
	if (format_time == 0) {
		cout << "This format is local already " << endl;
	}
	else if(format_time==1) {
		format_time == 0;
	}
	else if (format_time == 2) {
		hour_time += 12;
		//sum_minute += 12 * 60;
		format_time = 0;
	}
}
int main() {
	my_time T1(23, 50);
	my_time T2(1, 30, 1);
	my_time T3(1, 30, 2);
	my_time T4(12, 30, 2);//incorrect format
	my_time T5(11, 50, 2);
	T1.show();
	T2.show();
	T3.show();
	T4.show();
	T5.show();
	cout << "---------------------Compare----------------------------" << endl;
	T1.show();
	T2.show();
	
	cout << ((T1 == T2) ? "true" : "false") << endl;
	T1.show();
	T5.show();
	
	cout << ((T1 == T5) ? "true" : "false") << endl;
	cout << "---------------------Addition----------------------------" << endl;
	T2.show();
	T3.show();
	T1 = T2 + T3;
	T1.show();
	cout << "----------------------------------------------------------" << endl;
	T2.show();
	T5.show();
	T1 = T2 + T5;
	T1.show();
	cout << "---------------------Subtraction----------------------------" << endl;
	T2.show();
	T5.show();
	T1 = T2 - T5;
	T1.show();
	cout << "----------------------------------------------------------" << endl;
	T3.show();
	T2.show();
	T1 = T3 - T2;
	T1.show();
	cout << "---------------------Convertation----------------------------" << endl;
	my_time T7(11,55,2);
	T7.show();
	T7.convert_usa_to_local();
	T7.show();
 	cin.get();
	return 0;
}