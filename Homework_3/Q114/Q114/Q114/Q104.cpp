#include<iostream>

void print(int nums[]) {
	std::cout << '[';
	for (int i = 0; i < 4; i++) {
		std::cout << nums[i];
		if (i != 3) {
			std::cout << ',' << ' ';
		}
		else {
			std::cout << ']' << std::endl;
		}
	}
}

int main() {
	int nums[50000];
	int lenOfNums = 0;
	int result[50000][4];
	int lenOfResult = 0;
	int target;

	int a;
	char c;
	char d;

	std::cin >> c;
	d = std::cin.peek();
	if (d == ']') {
		std::cout << -1 << std::endl;
		return 0;
	}
	while (c != ']') {
		std::cin >> a >> c;
		nums[lenOfNums++] = a;
	}
	std::cin >> target;
	if (lenOfNums < 4) {
		std::cout << -1 << std::endl;
		return 0;
	}

	for (int i = 0; i < lenOfNums; i++) {
		for (int j = 0; j < lenOfNums - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
	}

	for (int i = 0; i < lenOfNums - 3; i++) {
		if (i != 0) {
			if (nums[i - 1] == nums[i]) {
				continue;
			}
		}
		for (int j = i + 1; j < lenOfNums - 2; j++) {
			if (j != i + 1) {
				if (nums[j - 1] == nums[j]) {
					continue;
				}
			}
			int lower = j + 1;
			int upper = lenOfNums - 1;
			while (lower < upper) {
				if (nums[i] + nums[j] + nums[lower] + nums[upper] == target) {
					result[lenOfResult][0] = nums[i];
					result[lenOfResult][1] = nums[j];
					result[lenOfResult][2] = nums[lower];
					result[lenOfResult++][3] = nums[upper];
					int temp = nums[lower];
					while (temp == nums[lower + 1] && lower < upper) {
						lower++;
					}
					lower++;
					temp = nums[upper];
					while (temp == nums[upper - 1] && lower < upper) {
						upper--;
					}
					upper--;
				}
				else if (nums[i] + nums[j] + nums[lower] + nums[upper] < target) {
					int temp = nums[lower];
					while (temp == nums[lower + 1] && lower < upper) {
						lower++;
					}
					lower++;
				}
				else if (nums[i] + nums[j] + nums[lower] + nums[upper] > target) {
					int temp = nums[upper];
					while (temp == nums[upper - 1] && lower < upper) {
						upper--;
					}
					upper--;
				}
			}
		}
	}

	if (lenOfResult == 0) {
		std::cout << -1 << std::endl;
	}
	else {
		for (int i = 0; i < lenOfResult; i++) {
			print(result[i]);
		}
	}
	return 0;
}