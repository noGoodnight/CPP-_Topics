#pragma once
#include<iostream>
#include<vector>
#include"Role.h"
#include"Leader.h"
#include"Warrior.h"
#include"Magician.h"

using namespace std;

class Player
{
public:
	vector<Role*> *roles;
	Role *fighter;
	
	void addRole();

	void attack(Player *p2);

	void go(Player *p2);

	inline bool isAlive() {
		return roles->size() != 0;
	}

	inline Player() {
		delete roles;
		delete fighter;
	}
};

