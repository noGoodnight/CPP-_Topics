#include<iostream>

using namespace std;

int main() {
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	char d;
	cin >> d >> x1 >> d >> y1 >> d >> x2 >> d >> y2 >> d >> x3 >> d >> y3 >> d;
	cin.get();
	int a = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	int b = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
	int c = (x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1);
	if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3) || (x1 - x2)*(y1 - y3) == (x1 - x3)*(y1 - y2)) {
		cout << "NT" << endl;
	}
	else {
		if (a == b || b == c || c == a) {
			if (a + b == c || b + c == a || c + a == b) {
				cout << "LRT" << endl;
			}
			else {
				cout << "OIT" << endl;
			}
		}
		else if (a + b == c || b + c == a || c + a == b) {
			cout << "ORT" << endl;
		}
		else {
			cout << "OT" << endl;
		}
	}
}