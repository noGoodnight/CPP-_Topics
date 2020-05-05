#include "Board.h"
#include <algorithm>

using namespace std;

char Board::getPiece(int x, int y, char c) {
	pieces[x*len + y] = c;
	numOfPieces++;
	if (isEnd(x, y,c)) {
		return c;
	}
	else if(numOfPieces == len *len){
		return 'F';
	}
	else {
		return 'C';
	}
}

bool Board::isEnd(int x, int y,char c) {
	int start, end;
	bool result = false;

	start = max(0, y - target + 1);
	end = min(len, y + target);
	if (end - start >= target) {
		for (int i = 0; i <= end - start - target; i++) {
			for (int j = 0; j < target; j++) {
				if (j == target - 1 && pieces[x*len + start + i + j] == c) {
					result = true;
					return result;
				}
				else if (pieces[x*len + start + i + j] != c) {
					break;
				}
			}
			if (!result) {
				continue;
			}
		}
	}

	start = max(0, x - target + 1);
	end = min(len, x + target);
	if (end - start >= target) {
		for (int i = 0; i <= end - start - target; i++) {
			for (int j = 0; j<target; j++) {
				if (j == target - 1 && pieces[start + i + j *len + y] == c) {
					result = true;
					return result;
				}
				else if (pieces[start + i + j *len + y] != c) {
					break;
				}
			}
			if (!result) {
				continue;
			}
		}
	}

	for (int i = x; i >= 0; i--) {
		start = i;
		if (y - (x - i) == 0) {
			break;
		}
	}
	for (int i = x; i <= len; i++) {
		end = i;
		if (y - (x - i) == len) {
			break;
		}
	}
	if (end - start >= target) {
		for (int i = 0; i <= end - start - target; i++) {
			for (int j = 0; j < target; j++) {
				if (j == target - 1 && pieces[start + i + j *len + y - (x - start - i - j)] == c) {
					result = true;
					return result;
				}
				else if (pieces[start + i + j * len + y - (x - start - i - j)] != c) {
					break;
				}
			}
			if (!result) {
				continue;
			}
		}
	}

	for (int i = x; i >= 0; i--) {
		start = i;
		if (y + (x - i) == len - 1) {
			break;
		}
	}
	for (int i = x; i <= len; i++) {
		end = i;
		if (y + (x - i) < 0) {
			break;
		}
	}
	if (end - start >= target) {
		for (int i = 0; i <= end - start - target; i++) {
			for (int j = 0; j < target; j++) {
				if (j == target - 1 && pieces[start + i + j * len + y + (x - start - i - j)] == c) {
					result = true;
					return result;
				}
				else if (pieces[start + i + j * len + y + (x - start - i - j)] != c) {
					break;
				}
			}
			if (!result) {
				continue;
			}
		}
	}
	return false;
}