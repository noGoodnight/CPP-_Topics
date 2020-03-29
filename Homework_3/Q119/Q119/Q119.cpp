#include<stdio.h>
#include<iostream>
#include<algorithm>

struct Order{
	char name[100];
	int lenOfName = 0;
	int time;
	int amount;
	char city[100];
	int lenOfCity = 0;
	bool invalid;
};

bool isInvalid(Order o1, Order o2) {
	if (o1.lenOfName != o2.lenOfName) {
		return false;
	}
	for (int i = 0; i < o1.lenOfName; i++) {
		if (o1.name[i] != o2.name[i]) {
			return false;
		}
	}
	bool differentCity = false;
	if (o1.lenOfCity != o2.lenOfCity) {
		differentCity = true;
	}
	else {
		for (int i = 0; i < o1.lenOfName; i++) {
			if (o1.city[i] != o2.city[i]) {
				differentCity = true;
			}
		}
	}
	if (!differentCity) {
		return false;
	}
	if (std::max(o1.time, o2.time) - std::min(o1.time, o2.time) > 60) {
		return false;
	}
	return true;
}

int main() {
	Order orders[100];
	int lenOfOrders = 0;

	int a;
	char c;
	std::cin >> c;
	while (c != ']') {
		std::cin >> c;
		if (c == ']') {
			break;
		}
		std::cin >> c;
		Order order;
		while (c != ',') {
			order.name[order.lenOfName++] = c;
			std::cin >> c;
		}
		std::cin >> a;
		order.time = a;
		std::cin >> c;
		std::cin >> a;
		order.amount = a;
		std::cin >> c;
		std::cin >> c;
		while (c != '"') {
			order.city[order.lenOfCity++] = c;
			std::cin >> c;
		}
		if (order.amount > 1000) {
			order.invalid = true;
		}
		else {
			order.invalid = false;
		}
		orders[lenOfOrders++] = order;
		std::cin >> c;
	}

	int printNum = 0;
	std::cout << '[';
	for (int i = 0; i < lenOfOrders; i++) {
		if (!orders[i].invalid) {
			for (int j = 0; j < lenOfOrders; j++) {
				if (i == j) {
					continue;
				}
				if (orders[i].invalid) {
					break;
				}
				else {
					bool result = isInvalid(orders[i], orders[j]);
					if (result) {
						orders[i].invalid = true;
						orders[j].invalid = true;
						if (printNum == 0) {
							std::cout << '"';
							printNum++;
						}
						else {
							std::cout << ',' << '"';
							printNum++;
						}
						for (int k = 0; k < orders[i].lenOfName; k++) {
							std::cout << orders[i].name[k];
						}
						std::cout << ',' << orders[i].time << ',' << orders[i].amount << ',';
						for (int k = 0; k < orders[i].lenOfCity; k++) {
							std::cout << orders[i].city[k];
						}
						std::cout << '"';
					}
				}
			}
		}
		else {
			if (printNum == 0) {
				std::cout << '"';
				printNum++;
			}
			else {
				std::cout << ',' << '"';
				printNum++;
			}
			for (int k = 0; k < orders[i].lenOfName; k++) {
				std::cout << orders[i].name[k];
			}
			std::cout << ',' << orders[i].time << ',' << orders[i].amount << ',';
			for (int k = 0; k < orders[i].lenOfCity; k++) {
				std::cout << orders[i].city[k];
			}
			std::cout << '"';
		}
	}
	std::cout << ']' << std::endl;
	return 0;
}