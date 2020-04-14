#include<iostream>

typedef int(*func)(int, int);

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int division(int a, int b) {
	return a / b;
}

int encrypt(func f, int a, int b) {
	a = ((a + 52) / 2 + 13) * 3;
	b = (b - 18) * 4 + 12;
	return f(a, b);
}

int main() {
	int num;
	func op[4] = { add,sub,mul,division };

	std::cin >> num;
	for (int i = 0; i < num; i++) {
		func f = NULL;
		char function[10];
		int a;
		int b;
		std::cin >> function >> a >> b;
		switch (function[0])
		{
		case 'a':
			f = op[0];
			break;
		case 's':
			f = op[1];
			break;
		case 'm':
			f = op[2];
			break;
		case 'd':
			f = op[3];
			break;
		default:
			break;
		}
		std::cout << encrypt(f, a, b) << std::endl;
	}
}