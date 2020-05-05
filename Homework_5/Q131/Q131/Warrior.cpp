#include "Warrior.h"

void Warrior::power() {
	if (isAlive()) {
		HP++;
	}
}

void Warrior::underAttack(Role *enemy) {
	HP -= enemy->getAtk;
}