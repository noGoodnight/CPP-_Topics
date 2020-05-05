#include "Leader.h"

void Leader::power() {
	if (isAlive()) {
		atk++;
	}
}

void Leader::underAttack(Role *enemy) {
	HP -= enemy->getAtk;
}