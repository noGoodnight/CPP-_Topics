#include<iostream>

using namespace std;

int main() {
	int i;
	bool isMinus;
	int nums[32];
	int result = 0;
	cin >> i;
	if (i < 0) {
		isMinus = true;
	}
	else {
		isMinus = false;
	}
	while (i > 0) {
		if (i % 2 == 1) {
			result++;
			i = (i - 1) % 2;
		}
		else {
			i = i / 2;
		}
	}
	
}