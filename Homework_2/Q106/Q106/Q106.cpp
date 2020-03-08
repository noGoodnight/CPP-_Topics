#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	char c;
	char key;
	char *str = new char;
	int lenOfStr = 0;
	char **result = new char*;
	int lenOfResults = 0;

	while ((c = getchar()) != '\n') {
		if (c == '{' || c == ',') {
			continue;
		}
		else if (c <= 'z' && 'a' <= c) {
			str[lenOfStr] = c;
			lenOfStr++;
		}
		else if (c == '}') {
			key = getchar();
			key = getchar();
			break;
		}
	}
	lenOfResults = (int)pow(2, lenOfStr - 1);

	for (int i = 0; i < lenOfResults; i++) {
		int index = 0;
		int k = i;
		for (int j = 0; j < lenOfStr; j++) {
			if (str[j] == key) {
				result[i][index] == key;
				index++;
			}
			else {
				if (k % 2 != 0) {
					result[i][index] = str[j];
					index++;
				}
				k = k / 2;
			}
		}
		for (int j = 0; j < index; j++) {
			for (int k = 0; k < index-1-j; k++) {
				if (result[i][k] > result[i][k + 1]) {
					char temp = result[i][k];
					result[i][k] = result[i][k + 1];
					result[i][k + 1] = temp;
				}
			}
		}
		result[i][index] = '\0';
	}

	for (int i = 0; i < lenOfResults; i++) {
		int index = 0;
		for (int j = 0; j < lenOfResults - 1 - i; j++) {
			while (result[j][index] == result[j + 1][index]) {
				index++;
			}
			if (result[j][index] > result[j + 1][index]) {
				char* temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
		}
	}
}