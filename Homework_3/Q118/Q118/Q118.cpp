#include<stdio.h>
#include<iostream>
#include<algorithm>

int main() {
	int area = 0;
	int width[10000];
	int height[10000];
	
	int a = 0;
	int upper = 0;
	int len = 0;
	while (std::cin >> a) {
		height[upper] = a;
		width[upper] = 1;
		area = std::max(area, height[upper] * width[upper]);
		for (int i = 0; i < len; i++) {
			width[upper + 1 + i] = i + 2;
			if (a < height[upper - len + i]) {
				height[upper + 1 + i] = a;
			}
			else {
				height[upper + 1 + i] = height[upper - len + i];
			}
			area = std::max(area, width[upper + 1 + i] * height[upper + 1 + i]);
		}
		len++;
		upper += len;
	}
	std::cout << area << std::endl;
	return 0;
}