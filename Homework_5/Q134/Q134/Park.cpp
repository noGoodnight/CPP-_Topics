#include "Park.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Park::print() {
	if (parkingSpace->size() == 0) {
		cout << "null" << endl;
	}else{
		for (int i = 0; i < parkingSpace->size(); i++) {
			cout << parkingSpace->at(i)->car->getName();
			if (i == parkingSpace->size() - 1) {
				cout << endl;
			}
			else {
				cout << " ";
			}
		}
	}
}

void Park::goTime() {
	int size = parkingSpace->size();
	int tempSize;
	for (int i = 0; i < size; i++) {
		parkingSpace->at(i)->car->goTime();
	}
	for (int i = 0; i < waitingSpace->size(); i++) {
		waitingSpace->at(i)->car->goTime();
	}
	tempSize = waitingSpace->size();
	for (int i = 0; i < tempSize; i++) {
		if (waitingSpace->at(i)->car->exit()) {
			carOut(i, waitingSpace, 0);
			i--;
			tempSize--;
		}
	}
	tempSize = size;
	for (int i = 0; i < tempSize; i++) {
		if (parkingSpace->at(i)->car->exit()) {
			carOut(i, parkingSpace,1);
			i = -1;
			tempSize = parkingSpace->size();
		}
	}
}

void Park::carIn(Car *car) {
	if (status == Sunny) {
		carInS(car);
	}
	else {
		carInR(car);
	}
}

void Park::carOut(int location, vector<ParkingCar*> *vp,int standard) {
	if (status == Sunny) {
		carOutS(location, vp, standard);
	}
	else {
		carOutR(location, vp, standard);
	}
}

void Park::carInS(Car *car) {
	if (waitingSpace->size() != 0) {
		ParkingCar *pc = new ParkingCar;
		pc->car = car;
		pc->location = -1;
		waitingSpace->push_back(pc);
	}
	else {
		if (parkingSpace->size() == 0) {
			if (length >= car->getLen()) {
				ParkingCar *pc = new ParkingCar;
				car->status = parking;
				car->time = 0;
				pc->car = car;
				pc->location = 0;
				parkingSpace->push_back(pc);
				addProfit(car->cost);
			}
			else {
				ParkingCar *pc = new ParkingCar;
				pc->car = car;
				pc->location = -1;
				waitingSpace->push_back(pc);
			}
		}
		else if (length - parkingSpace->at(parkingSpace->size() - 1)->location - parkingSpace->at(parkingSpace->size() - 1)->car->getLen() >= car->getLen()) {
			ParkingCar *pc = new ParkingCar;
			car->time = 0;
			car->status = parking;
			pc->car = car;
			pc->location = parkingSpace->at(parkingSpace->size() - 1)->location + parkingSpace->at(parkingSpace->size() - 1)->car->getLen();
			parkingSpace->push_back(pc);
			addProfit(car->cost);
		}
		else {
			ParkingCar *pc = new ParkingCar;
			pc->car = car;
			pc->location = -1;
			waitingSpace->push_back(pc);
		}
	}
}

void Park::carOutS(int location, vector<ParkingCar*> *vp, int standard) {
	vector<ParkingCar*>::iterator it = vp->begin() + location;
	int l = (*it)->car->getLen();

	if (standard == 1) {
		while (it != vp->end()) {
			(*it)->location -= l;
			it++;
		}
	}
	it = vp->begin() + location;
	vp->erase(it);

	if (standard == 1) {
		while (waitingSpace->size() > 0) {
			ParkingCar *pc = waitingSpace->at(0);
			if (parkingSpace->size() == 0) {
				if (length >= pc->car->getLen()) {
					pc->car->time = 0;
					pc->car->status = parking;
					pc->location = 0;
					parkingSpace->push_back(pc);
					addProfit(pc->car->cost);
					waitingSpace->erase(waitingSpace->begin());
				}
				else {
					break;
				}
			}
			else if (length - parkingSpace->at(parkingSpace->size() - 1)->location - parkingSpace->at(parkingSpace->size() - 1)->car->getLen() >= pc->car->getLen()) {
				pc->car->time = 0;
				pc->car->status = parking;
				pc->location = parkingSpace->at(parkingSpace->size() - 1)->location + parkingSpace->at(parkingSpace->size() - 1)->car->getLen();
				parkingSpace->push_back(pc);
				addProfit(pc->car->cost);
				waitingSpace->erase(waitingSpace->begin());
			}
			else {
				break;
			}
		}
	}
}

void Park::carInR(Car *car) {
	if (waitingSpace->size() != 0) {
		ParkingCar *pc = new ParkingCar;
		pc->car = car;
		pc->location = -1;
		waitingSpace->push_back(pc);
	}
	else {
		if (parkingSpace->size() == 0) {
			if (length >= car->getLen()) {
				ParkingCar *pc = new ParkingCar;
				car->status = parking;
				car->time = 0;
				pc->car = car;
				pc->location = 0;
				parkingSpace->push_back(pc);
				addProfit(car->cost);
			}
			else {
				ParkingCar *pc = new ParkingCar;
				pc->car = car;
				pc->location = -1;
				waitingSpace->push_back(pc);
			}
		}
		else {
			bool insertSuccess = false;
			if (parkingSpace->at(0)->location >= car->getLen()) {
				ParkingCar *pc = new ParkingCar;
				car->status = parking;
				car->time = 0;
				pc->car = car;
				pc->location = 0;
				parkingSpace->insert(parkingSpace->begin(), pc);
				addProfit(car->cost);
			}
			else {
				int size = parkingSpace->size();
				for (int i = 0; i < size; i++) {
					if (i != size - 1) {
						if (parkingSpace->at(i + 1)->location - parkingSpace->at(i)->location - parkingSpace->at(i)->car->getLen() >= car->getLen()) {
							ParkingCar *pc = new ParkingCar;
							car->status = parking;
							car->time = 0;
							pc->car = car;
							pc->location = parkingSpace->at(i)->location + parkingSpace->at(i)->car->getLen();
							parkingSpace->insert(parkingSpace->begin() + i + 1, pc);
							addProfit(car->cost);
							insertSuccess = true;
							break;
						}
					}
					else {
						if ((length - parkingSpace->at(i)->location - parkingSpace->at(i)->car->getLen() >= car->getLen())) {
							ParkingCar *pc = new ParkingCar;
							car->status = parking;
							car->time = 0;
							pc->car = car;
							pc->location = parkingSpace->at(i)->location + parkingSpace->at(i)->car->getLen();
							parkingSpace->push_back(pc);
							addProfit(car->cost);
							insertSuccess = true;
						}
					}
				}

				if (!insertSuccess) {
					ParkingCar *pc = new ParkingCar;
					pc->car = car;
					pc->location = -1;
					waitingSpace->push_back(pc);
				}
			}
		}
	}
}

void Park::carOutR(int location, vector<ParkingCar*> *vp,int standard) {
	vector<ParkingCar*>::iterator it = vp->begin() + location;
	vp->erase(it);

	if (standard == 1) {
		while (waitingSpace->size() > 0) {
			ParkingCar *pc = waitingSpace->at(0);
			if (parkingSpace->size() == 0) {
				if (length >= pc->car->getLen()) {
					pc->car->time = 0;
					pc->car->status = parking;
					pc->location = 0;
					parkingSpace->push_back(pc);
					addProfit(pc->car->cost);
					waitingSpace->erase(waitingSpace->begin());
				}
				else {
					break;
				}
			}
			else {
				if (parkingSpace->at(0)->location >= pc->car->getLen()) {
					pc->car->status = parking;
					pc->car->time = 0;
					pc->location = 0;
					parkingSpace->insert(parkingSpace->begin(), pc);
					addProfit(pc->car->cost);
					waitingSpace->erase(waitingSpace->begin());
				}else{
					bool insertSuccess = false;
					int size = parkingSpace->size();
					for (int i = 0; i<size; i++) {
						if (i != parkingSpace->size() - 1) {
							if (parkingSpace->at(i + 1)->location - parkingSpace->at(i)->location - parkingSpace->at(i)->car->getLen() >= pc->car->getLen()) {
								pc->car->status = parking;
								pc->car->time = 0;
								pc->location = parkingSpace->at(i)->location + parkingSpace->at(i)->car->getLen();
								parkingSpace->insert(parkingSpace->begin() + i + 1, pc);
								addProfit(pc->car->cost);
								waitingSpace->erase(waitingSpace->begin());
								insertSuccess = true;
								break;
							}
						}
						else {
							if ((length - parkingSpace->at(i)->location - parkingSpace->at(i)->car->getLen() >= pc->car->getLen())) {
								pc->car->status = parking;
								pc->car->time = 0;
								pc->location = parkingSpace->at(i)->location + parkingSpace->at(i)->car->getLen();
								parkingSpace->push_back(pc);
								addProfit(pc->car->cost);
								waitingSpace->erase(waitingSpace->begin());
								insertSuccess = true;
							}
						}
					}
					if (!insertSuccess) {
						break;
					}
				}
			}
		}
	}
}