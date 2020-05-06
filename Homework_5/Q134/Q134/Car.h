#pragma once
#include<string>

using namespace std;

enum carStatus
{
	parking = 1,
	waiting = 0
};

class Car
{
protected:
	int len, parkTime, waitTime;
	string name;
public:
	int time;
	carStatus status;
	double cost;
	inline Car() {
		status = waiting;
		time = 0;
	}

	inline void setName(string x) {
		name = x;
	}

	inline string getName() {
		return name;
	}

	inline int getLen() {
		return len;
	}

	void goTime();

	bool exit();

	bool endWaiting();

	bool endParking();
};