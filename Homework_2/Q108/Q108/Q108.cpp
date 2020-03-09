#include<iostream>

using namespace std;

int main() {
	int lower;
	int upper;
	int result = 0;
	bool isPrime;
	char c;

	cin >> c >> lower >> upper >> c;

	for (int i = lower; i <= upper; i++) {
		isPrime = true;
		if (i == 1) {
			continue;
		}
		else {
			for (int j = 2; j <= i / 2; j++) {
				if (i % j == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				result += i;
			}
		}
	}
	cout << result << endl;
}