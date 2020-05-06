#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<char> *sc = new stack<char>;
	char c;
	cin >> c;
	while (c != 26) {
		sc->push(c);
		cin >> c;
	}
	while (!sc->empty()) {
		c = sc->top();
		sc->pop();
		cout << c;
	}
	cout << endl;
}