#include "Q137.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

void MyString::reverse() {
	string s(head), sr;
	sr.assign(s.rbegin(), s.rend());
	for (int i = 0; i < sr.length(); i++) {
		head[i] = sr[i];
	}
}

void MyString::print() {
	string s(head);
	cout << s;
}

int main() {
	MyString *ms = new MyString;
	cin.getline(ms->head, 100);
	ms->reverse();
	ms->print();
}