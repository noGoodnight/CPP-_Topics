#include "Magician.h"
#include <iostream>

using namespace std;

void Magician::power() {
	miss = false;
}

void Magician::underAttack(Role *enemy) {
	if (miss) {}
	else {
		HP -= enemy->getAtk();
	}
}

void Magician::print() {
	cout << "Magician " << atk << " " << HP ;
}