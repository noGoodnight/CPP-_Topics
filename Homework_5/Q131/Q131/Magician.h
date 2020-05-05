#pragma once
#include "Role.h"
class Magician :
	public Role
{
private:
	bool miss;
public:
	inline Magician() {
		HP = 12;
		atk = 2;
		miss = true;
	}

	void power();

	void underAttack(Role *enemy);
};

