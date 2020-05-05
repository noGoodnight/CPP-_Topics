#include "Game.h"
#include<iostream>

using namespace std;

Game::Game() {
	int num;
	cin >> num;
	p1 = new Player(num), p2 = new Player(num);
	for (int i = 0; i < num; i++) {
		p1->addRole();
	}
	for (int i = 0; i < num; i++) {
		p2->addRole();
	}
}

void Game::go() {
	while (p1->isAlive() && p2->isAlive()) {
		p1->attack(p2);
		if (!(p1->roles->at(0)->isAlive())) {
			p1->roles->erase(p1->roles->begin());
		}
		if (!(p2->roles->at(0)->isAlive())) {
			p2->roles->erase(p2->roles->begin());
		}
	}
	end();
}

void Game::end() {
	if (p1->isAlive() || p2->isAlive()) {
		if (p1->isAlive()) {
			p1->print();
		}
		else {
			p2->print();
		}
	}
	else {
		cout << "All Dead";
	}
}