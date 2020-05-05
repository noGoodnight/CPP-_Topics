#pragma once
#include "Role.h"
class Leader :
	public Role
{
public:
	inline Leader() {
		HP = 12;
		atk = 2;
	}

	void power();

	void underAttack(Role *enemy);
};

