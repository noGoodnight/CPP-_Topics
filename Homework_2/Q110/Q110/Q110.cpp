#include<iostream>
#include<string>

using namespace std;

int main() {
	int num;
	cin >> num;
	cin.get();
	int letter[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < num; i++) {
		char c;
		while ((c = getchar()) != '\n') {
			if ('a' <= c && c <= 'z') {
				letter[c - 97]++;
			}
			else if ('A' <= c && c <= 'Z') {
				letter[c - 65]++;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26-i-1; j++) {
			if (letter[j] > letter[j + 1]) {
				int temp = letter[j + 1];
				letter[j + 1] = letter[j];
				letter[j] = temp;
			}
		}
	}
	string result = "[";
	for (int i = 0; i < 26; i++) {
		if (letter[i] == 0) {
			continue;
		}
		else {
			result = result + to_string(letter[i]) + ",";
		}
	}
	result = result.substr(0, result.length() - 1) + "]";
	cout << result << endl;
}