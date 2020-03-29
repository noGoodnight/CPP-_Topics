#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

int main() {
	int matrix[100][100];
	int lenOfEdge = 0;
	int angle;
	
	int a;
	char c = ' ';
	while (c != '\n') {
		std::cin >> a;
		matrix[0][lenOfEdge++] = a;
		scanf("%c", &c);
	}
	for (int i = 1; i < lenOfEdge; i++) {
		for (int j = 0; j < lenOfEdge; j++) {
			std::cin >> a;
			matrix[i][j] = a;
		}
	}
	std::cin >> angle;
	angle = angle % 360;

	switch (angle)
	{
	case 0:
		for (int i = 0; i < lenOfEdge; i++) {
			for (int j = 0; j < lenOfEdge; j++) {
				std::cout << matrix[i][j];
				if (j != lenOfEdge - 1) {
					std::cout << ' ';
				}
				else {
					std::cout << std::endl;
				}
			}
		}
		break;
	case 90:
		for (int i = 0; i < lenOfEdge; i++) {
			for (int j = lenOfEdge - 1; j >= 0; j--) {
				std::cout << matrix[j][i];
				if (j != 0) {
					std::cout << ' ';
				}
				else {
					std::cout << std::endl;
				}
			}
		}
		break;
	case 180:
		for (int i = lenOfEdge - 1; i >= 0; i--) {
			for (int j = lenOfEdge - 1; j >= 0; j--) {
				std::cout << matrix[i][j];
				if (j != 0) {
					std::cout << ' ';
				}
				else {
					std::cout << std::endl;
				}
			}
		}
		break;
	case 270:
		for (int i = lenOfEdge - 1; i >= 0; i--) {
			for (int j = 0; j < lenOfEdge; j++) {
				std::cout << matrix[j][i];
				if (j != lenOfEdge - 1) {
					std::cout << ' ';
				}
				else {
					std::cout << std::endl;
				}
			}
		}
		break;
	default:
		break;
	}
	return 0;
}