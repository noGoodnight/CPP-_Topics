#include "Magician.h"

void Magician::power() {
	miss = false;
}

void Magician::underAttack(Role *enemy) {
	if (miss) {}
	else {
		HP -= enemy->getAtk;
	}
}