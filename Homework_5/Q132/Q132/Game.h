#pragma once
#include "Board.h"
#include <iostream>

using namespace std;

class Game
{
private:
	Board *board;
public:
	inline Game() {
		int x,y;
		cin >> x >> y;
		board = new Board(x, y);
	}

	inline ~Game() {
		delete board;
	}

	void go();
};

