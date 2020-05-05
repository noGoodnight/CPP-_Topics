#include "Player.h"
#include<iostream>

using namespace std;

void Player::addRole() {
	int type;
	Role *temp;

	cin >> type;
	switch (type)
	{
	case 1:
		temp = new Warrior;
		roles->push_back(temp);
		break;
	case 2:
		temp = new Magician;
		roles->push_back(temp);
		break;
	case 3:
		temp = new Leader;
		roles->push_back(temp);
		break;
	default:
		break;
	}

	if (roles->size() == 1) {
		fighter = roles->at(0);
	}
}