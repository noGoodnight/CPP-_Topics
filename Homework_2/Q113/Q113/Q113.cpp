#include<iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	cin.get();
	int result;
	if (num > 3) {
		result = num * (num - 1) / (num - 2);
		num -= 3;
		while (num >= 4) {
			result = result + num - (num - 1)*(num - 2) / (num - 3);
			num -= 4;
		}
		if (num > 0) {
			result += 1;
		}
	}
	else if (num == 3) {
		result = 6;
	}
	else if (num == 2) {
		result = 2;
	}
	else if (num == 1) {
		result = 1;
	}
	cout << result << endl;
}