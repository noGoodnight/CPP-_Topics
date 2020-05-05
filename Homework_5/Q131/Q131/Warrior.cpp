#include "Warrior.h"
#include <iostream>

using namespace std;

void Warrior::power() {
	if (isAlive()) {
		HP++;
	}
}

void Warrior::underAttack(Role *enemy) {
	HP -= enemy->getAtk();
}

void Warrior::print() {
	cout << "Warrior " << atk << " " << HP;
}