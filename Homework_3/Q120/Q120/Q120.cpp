#include<stdio.h>
#include<iostream>

int main() {
	bool existence[1000];
	int lenOfExistence = 0;

	int a;
	char c;
	std::cin >> c;
	c = std::cin.peek();
	if (c == ']') {
		std::cout << 1 << std::endl;
		return 0;
	}
	while (c != ']') {
		std::cin >> a >> c;
		if (a > 0) {
			existence[a] = false;
			lenOfExistence++;
		}
	}
	for (int i = 1; i < lenOfExistence + 2; i++) {
		if (existence[i]) {
			std::cout << i << std::endl;
			return 0;
		}
	}
}