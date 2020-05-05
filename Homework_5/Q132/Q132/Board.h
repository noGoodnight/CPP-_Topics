#pragma once
class Board
{
private:
	int len, numOfPieces,target;
	char *pieces;
public:
	inline Board(int x,int y) {
		numOfPieces = 0;
		len = x;
		target = y;
		pieces = new char[x*x];
	}
	
	char getPiece(int x, int y, char c);

	bool isEnd(int x, int y,char c);
};

