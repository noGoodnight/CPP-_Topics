#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

typedef void(*Mul)(std::string[], std::string[], int, int, int);

void dataMul(std::string x[], std::string y[], int h, int w, int l) {
	std::cout << 1 << std::endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			double temp = 0.0;
			for (int k = 0; k < l; k++) {
				double a, b;
				std::stringstream ss1;
				std::stringstream ss2;
				ss1 << x[i * 50 + k];
				ss1 >> a;
				ss2 << y[k * 50 + j];
				ss2 >> b;
				temp += a * b;
			}
			if (int(temp) == temp) {
				std::cout << int(temp);
			}
			else {
				std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << temp;
			}
			if (j == w - 1) {
				std::cout << std::endl;
			}
			else {
				std::cout << " ";
			}
		}
	}
}

std::string addition(std::string s1, std::string s2) {
	std::string result = "";
	std::string s = s1 + s2;
	for (int i = 0; i < s.length(); i++) {
		std::string c(&s.at(i), 1);
		if (result.find(c) == std::string::npos) {
			result += c;
		}
	}
	return result;
}

std::string multiply(std::string s1, std::string s2) {
	return s1 + s2;
}

void nonDataMul(std::string x[], std::string y[], int h, int w, int l) {
	std::cout << -1 << std::endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			std::string temp = "";
			for (int k = 0; k < l; k++) {
				std::string a = x[i * 50 + k];
				std::string b = y[k * 50 + j];
				temp = addition(temp, multiply(a, b));
			}
			std::cout << temp;
			if (j == w - 1) {
				std::cout << std::endl;
			}
			else {
				std::cout << " ";
			}
		}
	}
}

void mul(std::string x[], std::string y[], int h, int w, int l, int d) {
	Mul func[2] = { dataMul,nonDataMul };
	(d > 0) ? func[0](x, y, h, w, l) : func[1](x, y, h, w, l);
}

int main() {
	std::string matrix1[50][50];
	std::string matrix2[50][50];

	int d1, d2;
	int h1, h2, w1, w2;
	std::cin >> d1 >> h1 >> w1;
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			std::cin >> matrix1[i][j];
		}
	}
	std::cin >> d2 >> h2 >> w2;
	for (int i = 0; i < h2; i++) {
		for (int j = 0; j < w2; j++) {
			std::cin >> matrix2[i][j];
		}
	}

	mul(&matrix1[0][0], &matrix2[0][0], h1, w2, h2, d1 + d2);
}