#include "Game.h"
#include <iostream>

using namespace std;

void Game::go() {
	int x, y;
	bool first = true;
	char c;
	cin >> x >> y;
	c = board->getPiece(x, y, first ? 'O' : 'X');

	while (c == 'C') {
		first = !first;
		cin >> x >> y;
		c = board->getPiece(x, y, first ? 'O' : 'X');
	}

	switch (c)
	{
	case 'F':
		cout << "Dogfall";
		break;
	default:
		cout << (first ? 'O' : 'X') << " Success";
		break;
	}
}