#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int x;
	int y;
	long long int result = 1;
	char c;

	cin >> c;
	cin >> c;
	cin >> x;
	cin >> c;
	cin >> c;
	cin >> c;
	cin >> y;
	result = (long long int)pow(x, y);
	if (result > INT_MAX || result < INT_MIN) {
		result = -1;
	}
	cout << result << endl;
}