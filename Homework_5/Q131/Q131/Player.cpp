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
}

void Player::attack(Player *p2) {
	Role *fighter1, *fighter2;
	fighter1 = roles->at(0);
	fighter2 = p2->roles->at(0);
	fighter1->underAttack(fighter2);
	fighter2->underAttack(fighter1);
	fighter1->power();
	fighter2->power();
}

void Player::print() {
	int i = 0;
	while (i < roles->size()) {
		roles->at(i)->print();
		if (i != roles->size() - 1) {
			cout << endl;
		}
		i++;
	}
}