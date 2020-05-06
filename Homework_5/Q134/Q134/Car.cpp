#include "Car.h"

using namespace std;

void Car::goTime() {
	time++;
}

bool Car::exit() {
	if (status == waiting) {
		return endWaiting();
	}
	else {
		return endParking();
	}
}

bool Car::endWaiting() {
	return time == waitTime;
}

bool Car::endParking() {
	return time == parkTime;
}