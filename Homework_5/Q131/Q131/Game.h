#pragma once
#include"Player.h"
#include<iostream>
#include<vector>
#include"Role.h"
#include"Leader.h"
#include"Warrior.h"
#include"Magician.h"

using namespace std;

class Game
{
public:
	Player *p1, *p2;

	Game();
	~Game() {
		delete p1, p2;
	}

	void go();

	void end();
};

