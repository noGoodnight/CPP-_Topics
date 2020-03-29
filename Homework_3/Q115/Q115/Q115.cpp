#include<stdio.h>
#include<iostream>

int main() {
	int result[10000];
	int lenOfResult = 0;
	bool noExisted[10000];

	int a;
	while (std::cin >> a) {
		if (noExisted[a]) {
			result[lenOfResult++] = a;
			noExisted[a] = false;
		}
	}

	for (int i = 0; i < lenOfResult; i++) {
		if (i != lenOfResult - 1) {
			std::cout << result[i] << ' ';
		}
		else {
			std::cout << result[i] << std::endl;
		}
	}
}