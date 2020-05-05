#pragma once
#include "Role.h"
class Leader :
	public Role
{
public:
	inline Leader() {
		HP = 6;
		atk = 6;
	}

	void power();

	void underAttack(Role *enemy);

	void print();
};

