#include <iostream>;

using namespace std;

int main() {
	int x;
	int y;
	int result = 1;
	char c;

	cin >> c;
	cin >> c;
	cin >> x;
	cin >> c;
	cin >> c;
	cin >> c;
	cin >> y;
	for (int i = 0; i < y; i++) {
		result = result * x;
		if (INT_MAX / x < result || INT_MIN / x > result) {
			result = -1;
			break;
		}
	}
	cout << -1 << endl;
}