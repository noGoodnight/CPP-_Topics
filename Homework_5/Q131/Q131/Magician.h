#pragma once
#include "Role.h"
class Magician :
	public Role
{
private:
	bool miss;
public:
	inline Magician() {
		HP = 2;
		atk = 6;
		miss = true;
	}

	void power();

	void underAttack(Role *enemy);

	void print();
};

