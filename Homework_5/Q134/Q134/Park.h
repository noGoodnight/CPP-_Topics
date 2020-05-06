#pragma once
#include"Car.h"
#include<string>
#include<vector>

using namespace std;

class ParkingCar {
public:
	Car *car;
	int location;
};

enum ParkStatus {
	Sunny = 1,
	Rainy = 0
};

class Park
{
private:
	double profit;
	ParkStatus status;
protected:
	int length;
public:
	vector<ParkingCar*> *parkingSpace;
	vector<ParkingCar*> *waitingSpace;

	inline Park(int len) {
		length = len;
		parkingSpace = new vector<ParkingCar*>;
		waitingSpace = new vector<ParkingCar*>;
		profit = 0.0;
	}

	inline  ~Park() {
		delete parkingSpace;
		delete waitingSpace;
	}

	inline double getProfit() {
		return profit;
	}

	inline void addProfit(double x) {
		profit += x;
	}

	inline void setStatus(ParkStatus ps) {
		status = ps;
	}

	void print();

	void goTime();

	void carIn(Car *car);

	void carOut(int location, vector<ParkingCar*>*, int);

	void carInS(Car *car);

	void carOutS(int location, vector<ParkingCar*>*, int);

	void carInR(Car *car);

	void carOutR(int location, vector<ParkingCar*>*, int);
};



