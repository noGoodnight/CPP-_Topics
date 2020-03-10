#include <iostream>
#include <string>

using namespace std;

int main() {
	char c;
	char key;
	char letter[26];
	int lenOfLetter = 0;
	char result[INT_MAX];
	int lenOfResult = 0;
	int lenOfSubStr = 1;
	int lower = 0;
	int start;
	string s = "";

	cin >> c;
	cin >> c >> key;
	while (key != '}') {
		letter[lenOfLetter++] = c;
		cin >> c >> key;
	}
	letter[lenOfLetter++] = c;
	cin >> c >> key;
	cin.get();

	for (int i = 0; i < lenOfLetter; i++) {
		if (letter[i] == key) {
			letter[i] = letter[--lenOfLetter];
			letter[lenOfLetter] = key;
		}
	}


	for (int i = 0; i < lenOfLetter; i++) {
		for (int j = 0; j < lenOfLetter - i-1; j++) {
			if (letter[j] > letter[j + 1]) {
				int temp = letter[j + 1];
				letter[j + 1] = letter[j];
				letter[j] = temp;
			}
		}
	}

	result[0] = '{';
	result[1] = key;
	result[2] = '}';
	lenOfResult = 3;

	while (lenOfSubStr <= lenOfLetter) {
		start = lower;
		while (start < lenOfResult){
			if (result[start] == '{'&&result[start + lenOfSubStr + 1] == '}') {
				break;
			}
		}

		while (result[start] == '{'&&result[start + lenOfSubStr + 1] == '}') {
			int gap = lenOfLetter;
			int anotherStart = 0;
			for (int i = 0; i < lenOfLetter; i++) {
				if (letter[i] == result[start + lenOfSubStr]) {
					anotherStart = i + 1;
					gap = lenOfLetter - anotherStart;
					break;
				}
			}
			for (int i = 0; i < gap; i++) {
				for (int j = 1; j <= lenOfSubStr; j++) {
					if (j == 1) {
						result[lenOfResult++] = '{';
					}
					result[lenOfResult++] = result[start + j];
					if (j == lenOfSubStr) {
						result[lenOfResult++] = letter[anotherStart+i];
						result[lenOfResult++] = '}';
					}
				}
			}
			start += (lenOfSubStr + 2);
		}
		lower = start;
		lenOfSubStr++;
	}

	lower = 0;
	lenOfSubStr = 1;
	lenOfLetter++;
	while (lenOfSubStr <= lenOfLetter) {
		start = lower;
		while (start < lenOfResult) {
			if (result[start] == '{'&&result[start + lenOfSubStr + 1] == '}') {
				break;
			}
		}

		while (result[start] == '{'&&result[start + lenOfSubStr + 1] == '}') {
			for (int i = 0; i < lenOfSubStr; i++) {
				for (int j = 1; j < lenOfSubStr - i; j++) {
					if (result[start + j] > result[start + j + 1]) {
						int temp = result[start + j];
						result[start + j] = result[start + j + 1];
						result[start + j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < lenOfSubStr + 2; i++) {
				if (i == 0 || i == lenOfSubStr) {
					string temp(1, result[start + i]);
					s += temp;
				}
				else {
					string temp(1, result[start + i]);
					s += temp;
					s += ",";
				}
			}
			start += (lenOfSubStr + 2);
		}
		lower = start;
		lenOfSubStr++;
	}
	
	s = s.substr(0, s.length() - 1);
	cout << s << endl;

}