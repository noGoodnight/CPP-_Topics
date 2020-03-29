#include<stdio.h>
#include<iostream>

int main() {
	int numOfBoys = 0;
	int numOfGirls = 0;
	char informations[10000];
	int index = 0;

	std::cin >> informations;
	while (informations[index]) {
		switch (informations[index])
		{
		case 'b':
			if (informations[++index] == 'o') {
				if (informations[++index] == 'y') {
				}
				else {
					index--;
				}
			}
			else {
				index--;
			}
			numOfBoys++;
			break;
		case 'o':
			if (informations[++index] == 'y') {
			}
			else {
				index--;
			}
			numOfBoys++;
			break;
		case 'y':
			numOfBoys++;
			break;
		case 'g':
			if (informations[++index] == 'i') {
				if (informations[++index] == 'r') {
					if (informations[++index] == 'l') {
					}
					else {
						index--;
					}
				}
				else {
					index--;
				}
			}
			else {
				index--;
			}
			numOfGirls++;
			break;
		case 'i':
			if (informations[++index] == 'r') {
				if (informations[++index] == 'l') {
				}
				else {
					index--;
				}
			}
			else {
				index--;
			}
			numOfGirls++;
			break;
		case 'r':
			if (informations[++index] == 'l') {
			}
			else {
				index--;
			}
			numOfGirls++;
			break;
		case 'l':
			numOfGirls++;
			break;
		default:
			while (informations[++index] == '.') {}
			index--;
			break;
		}
		index++;
	}
	std::cout << numOfBoys << ' ' << numOfGirls << std::endl;
	return 0;
}