#include <iostream>
#include "Park.h"
#include "Car.h"
#include "LargeCar.h"
#include "MidCar.h"
#include "SmallCar.h"
#include <String>

using namespace std;

int main() {
	Park *park;
	string s;
	int len;

	cin >> len >> s;
	park = new Park(2 * len);
	if (s.at(0) == 's') {
		park->setStatus(Sunny);
	}
	else {
		park->setStatus(Rainy);
	}
	cin >> s;
	while (s.at(0) != 'e') {
		cin >> s;
		Car *car;
		switch (s.at(0))
		{
		case 'S':
			car = new SmallCar;
			cin >> s;
			car->setName(s);
			park->carIn(car);
			break;
		case 'M':
			car = new MidCar;
			cin >> s;
			car->setName(s);
			park->carIn(car);
			break;
		case 'L':
			car = new LargeCar;
			cin >> s;
			car->setName(s);
			park->carIn(car);
			break;
		default:
			break;
		}
		park->print();
		park->goTime();
		cin >> s;
	}
	while (park->parkingSpace->size() != 0 || park->waitingSpace->size() != 0) {
		park->print();
		park->goTime();
	}
	cout << "null" << endl << park->getProfit();
	delete park;
}