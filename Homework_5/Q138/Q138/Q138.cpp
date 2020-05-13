#include <iostream>
#include <string>

using namespace std;

int main() {
	char mark;
	string action;
	string Jreply[3] = { "J: escape","J: run","J: zhi" };
	string Oreply[3] = { "O: What's up?","O: you piece of shit.","O: well done." };
	
	while (cin >> mark) {
		getline(cin, action);
		if (action == ": meow") {
			cout << Jreply[0] << endl << Oreply[0] << endl;
		}
		else if (action == ": chase") {
			cout << Jreply[1] << endl;
		}
		else if (action == ": hide") {
			cout << Oreply[1] << endl;
		}
		else if (action == ": catch") {
			cout << Jreply[2] << endl << Oreply[2] << endl;;
		}
	}
}