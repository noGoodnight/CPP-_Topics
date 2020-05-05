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
	
	void addRole();

	void attack(Player *p2);

	void print();

	inline bool isAlive() {
		return roles->size() != 0;
	}

	inline Player(int x) {
		roles = new vector<Role*>;
	}

	inline ~Player() {
		delete roles;
	}
};

