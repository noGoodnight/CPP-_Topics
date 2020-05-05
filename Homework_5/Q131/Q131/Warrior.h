#pragma once
#include "Role.h"
class Warrior :
	public Role
{
public:
	inline Warrior() {
		HP = 12;
		atk = 2;
	}

	void power();

	void underAttack(Role *enemy);

	void print();
};

