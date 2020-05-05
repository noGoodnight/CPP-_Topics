#include<iostream>
#include"Game.h"
#include"Player.h"
#include<iostream>
#include<vector>
#include"Role.h"
#include"Leader.h"
#include"Warrior.h"
#include"Magician.h"

using namespace std;

int main() {
	Game *game = new Game;
	game->go();
	delete game;
}