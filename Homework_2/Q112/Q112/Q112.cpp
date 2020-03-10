#include<iostream>

using namespace std;

int main() {
	int year;
	int month;
	int day;
	int ordinaryYear[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYear[13] = { 0, 31,29,31,30,31,30,31,31,30,31,30,31 };
	char c;
	int result = 0;
	bool isLeap = false;

	cin >> year >> c >> month >> c >> day;
	cin.get();
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 == 0) {
			isLeap = true;
		}
		else if(year % 100 == 0 && year % 400 != 0){
			isLeap = false;
		}
		else {
			isLeap = true;
		}
	}
	if (0 < month &&month < 13) {
		for (int i = 0; i < month; i++) {
			result += isLeap ? leapYear[i] : ordinaryYear[i];
		}
		if (day > (isLeap ? leapYear[month] : ordinaryYear[month])) {
			result = -1;
		}
		else {
			result += day;
		}
	}
	else {
		result = -1;
	}

	cout << result << endl;
}