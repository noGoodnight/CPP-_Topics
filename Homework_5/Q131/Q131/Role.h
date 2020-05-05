#pragma once
class Role
{
protected:
	int HP, atk;

public:
	inline int getHP() {
		return HP;
	}

	inline int getAtk() {
		return atk;
	}

	inline bool isAlive() {
		return HP > 0;
	}

	virtual void underAttack(Role *enemy);
	
	virtual void power();

	virtual void print();
};

