#include <iostream>;
#include <string>;
#include <algorithm>;

using namespace std;

int main() {
	string romanNums;
	int maximum;
	int result;

	maximum = 0;
	result = 0;
	getline(cin, romanNums);
	for (int i = 0; i < romanNums.length(); i++) {
		if (romanNums[i] == 'M') {
			result += 1000;
		}
		else if (romanNums[i] == 'D') {
			result += 500;
		}
		else if (romanNums[i] == 'C') {
			if (i != romanNums.length() - 1 && romanNums[i + 1] == 'D') {
				result += 400;
				i += 1;
			}
			else if (i != romanNums.length() - 1 && romanNums[i + 1] == 'M') {
				result += 900;
				i += 1;
			}
			else {
				result += 100;
			}
		}
		else if (romanNums[i] == 'L') {
			result += 50;
		}
		else if (romanNums[i] == 'X') {
			if (i != romanNums.length() - 1 && romanNums[i + 1] == 'L') {
				result += 40;
				i += 1;
			}
			else if (i != romanNums.length() - 1 && romanNums[i + 1] == 'C') {
				result += 90;
				i += 1;
			}
			else {
				result += 10;
			}
		}
		else if (romanNums[i] == 'V') {
			result += 5;
		}
		else if (romanNums[i] == 'I') {
			if (i != romanNums.length() - 1 && romanNums[i + 1] == 'V') {
				result += 4;
				i += 1;
			}
			else if (i != romanNums.length() - 1 && romanNums[i + 1] == 'X') {
				result += 9;
				i += 1;
			}
			else {
				result += 1;
			}
		}
		else if (romanNums[i] == ' ') {
			maximum = max(result, maximum);
			result = 0;
		}
		else if (romanNums[i] == '"') {
			continue;
		}
	}
	maximum = max(result, maximum);

	cout << maximum << endl;
}