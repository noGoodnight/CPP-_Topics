#include<iostream>
#include<string>

using namespace std;

int main() {
	char c;
	char p[INT_MAX];
	int len = 0;
	int numOfParts;
	string result = "";

	while ((c = getchar()) != '\n') {
		if (c == '-') {
			continue;
		}
		else if ('a' <= c && c <= 'z') {
			p[len++] = c - 32;
		}
		else {
			p[len++] = c;
		}
	}

	cin >> numOfParts;

	int temp = len;
	for (int i = 0; i < len / numOfParts; i++) {
		for (int j = 0; j < numOfParts; j++) {
			string s(1, p[--temp]);
			result = s + result;
		}
		if (temp != 0) {
			result = "-" + result;
		}
	}
	while (temp > 0) {
		string s(1, p[--temp]);
		result = s + result;
	}

	cout << result << endl;
}