#include<stdio.h>
#include<iostream>
#include<algorithm>

int main() {
	long long nums[5000];
	int lenOfNums = 0;
	int result = 0;

	long long a = 0;

	while (std::cin >> a) {
		nums[lenOfNums++] = a;
	}
	for (int i = 0; i < lenOfNums; i++) {
		for (int j = 0; j < lenOfNums - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				long long temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}

	if (lenOfNums > 0) {
		long long base = nums[0];
		int tempResult = 1;
		for (int i = 1; i < lenOfNums; i++) {
			if (nums[i] == base + 1) {
				tempResult++;
			}
			else if (nums[i] == base) {
				continue;
			}
			else {
				result = std::max(result, tempResult);
				tempResult = 1;
			}
			base = nums[i];
		}
		result = std::max(result, tempResult);
	}
	std::cout << result << std::endl;
	return 0;
}