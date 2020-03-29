#include<stdio.h>
#include<iostream>

int main() {
	char origins[10000];
	int frequency[10000];
	int lenOfOrigins = 0;
	int gap = 0;

	char c;
	char temp = '\0';
	int time = 0;
	while (std::cin >> c) {
		if (c == 26) {
			break;
		}
		if (lenOfOrigins == 0 || c != temp) {
			origins[lenOfOrigins++] = c;
			frequency[lenOfOrigins - 1] = 0;
		}
		frequency[lenOfOrigins - 1] += 1;
		temp = c;
	}

	for (int i = 0; i < lenOfOrigins; i++) {
		int lenOfNum = 0;
		int num = frequency[i];
		while (num > 0) {
			num = num / 10;
			lenOfNum++;
		}
		gap += (1 + lenOfNum) - frequency[i];
	}

	if (gap > 0) {
		for (int i = 0; i < lenOfOrigins; i++) {
			for (int j = 0; j < frequency[i]; j++) {
				std::cout << origins[i];
			}
		}
	}
	else {
		for (int i = 0; i < lenOfOrigins; i++) {
			std::cout << origins[i];
			std::cout << frequency[i];
		}
	}
	std::cout << std::endl;
	return 0;
}