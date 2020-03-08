#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	char key;
	char *letters;
	int lenOfLetters;
	
	getline(cin, str);
	key = str[str.length() - 1];
	letters = &key;
	lenOfLetters = 1;

	for (int i = 1; i < str.length() - 3; i++) {
		if (str[i] == ',') {
			continue;
		}
		else if(str[i] != key){
			letters[lenOfLetters] = str[i];
			lenOfLetters++;
		}
	}

	//sort(letters, letters + lenOfLetters - 1);
	cout << 1 << endl;

}