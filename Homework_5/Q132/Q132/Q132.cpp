#include "Game.h"
#include "Board.h"

using namespace std;

int main() {
	Game *game = new Game;
	game->go();
	delete game;
}