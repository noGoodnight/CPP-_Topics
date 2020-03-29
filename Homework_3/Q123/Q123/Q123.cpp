#include<stdio.h>
#include<iostream>

bool isInvalid(int group[]) {
	bool existence[10];
	for (int i = 0; i < 9; i++) {
		if (group[i] == 0) {
			continue;
		}
		else {
			if (!existence[group[i]]) {
				return true;
			}
			else {
				existence[group[i]] = false;
			}
		}
	}
	return false;
}

int main() {
	int matrix[9][9];
	int group[9];
	
	char a, b, c, d, e, f, g, h, k, l;
	for (int i = 0; i < 9; i++) {
		std::cin >> c >> c >> a >> c >> c >> c >> b >> c >> c >> c >> d >> c >> c >> c >> e >> c >> c >> c >> f >> c >> c >> c >> g >> c >> c >> c >> h >> c >> c >> c >> k >> c >> c >> c >> l >> c >> c;
		if (48 < a && a <= 57) {
			group[0] = a - 48;
		}
		else {
			group[0] = 0;
		}
		matrix[i][0] = group[0];
		if (48 < b && b <= 57) {
			group[1] = b - 48;
		}
		else {
			group[1] = 0;
		}
		matrix[i][1] = group[1];
		if (48 < d && d <= 57) {
			group[2] = d - 48;
		}
		else {
			group[2] = 0;
		}
		matrix[i][2] = group[2];
		if (48 < e && e <= 57) {
			group[3] = e - 48;
		}
		else {
			group[3] = 0;
		}
		matrix[i][3] = group[3];
		if (48 < f && f <= 57) {
			group[4] = f - 48;
		}
		else {
			group[4] = 0;
		}
		matrix[i][4] = group[4];
		if (48 < g && g <= 57) {
			group[5] = g - 48;
		}
		else {
			group[5] = 0;
		}
		matrix[i][5] = group[5];
		if (48 < h && h <= 57) {
			group[6] = h - 48;
		}
		else {
			group[6] = 0;
		}
		matrix[i][6] = group[6];
		if (48 < k && k <= 57) {
			group[7] = k - 48;
		}
		else {
			group[7] = 0;
		}
		matrix[i][7] = group[7];
		if (48 < l && l <= 57) {
			group[8] = l - 48;
		}
		else {
			group[8] = 0;
		}
		matrix[i][8] = group[8];
		if (isInvalid(group)) {
			std::cout << "false" << std::endl;
			return 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			group[j] = matrix[j][i];
		}
		if (isInvalid(group)) {
			std::cout << "false" << std::endl;
			return 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			group[j] = matrix[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3];
		}
		if (isInvalid(group)) {
			std::cout << "false" << std::endl;
			return 0;
		}
	}
	std::cout << "true" << std::endl;
	return 0;
}