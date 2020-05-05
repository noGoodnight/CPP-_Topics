#include "Leader.h"
#include <iostream>

using namespace std;

void Leader::power() {
	if (isAlive()) {
		atk++;
	}
}

void Leader::underAttack(Role *enemy) {
	HP -= enemy->getAtk();
}

void Leader::print() {
	cout << "Leader " << atk << " " << HP;
}