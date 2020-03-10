#include <iostream>

using namespace std;

int main() {
	char c;
	char key;
	char letter[26];
	int lenOfLetter = 0;
	char result[10000];
	int lenOfResult = 0;
	int lenOfSubStr = 1;

	cin >> c;
	cin >> c >> key;
	while (key != '}') {
		letter[lenOfLetter++] = c;
		cin >> c >> key;
	}
	cin >> c >> key;
	cin.get();

	for (int i = 0; i < lenOfLetter; i++) {
		if (letter[i] == key) {
			letter[i] = letter[lenOfLetter];
			letter[lenOfLetter--] = key;
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
	result[3] = ',';
	lenOfResult = 4;

	while (lenOfSubStr <= lenOfLetter) {
		int start = 0;
		while(start < )
	}
}