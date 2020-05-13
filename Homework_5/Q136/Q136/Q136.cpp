#include "Q136.h"
#include <iostream>
#include <iomanip>

using namespace std;

double Product::totalMoney() {
	if (pnum >= 10) {
		return price * pnum * 0.88;
	}
	else {
		return price * pnum;
	}
}

int main() {
	int pid, pnum;
	double price;
	double totalMoney = 0.0;

	while (cin >> pid) {
		cin >> price >> pnum;
		Product *p = new Product(pid,pnum,price);
		totalMoney += p->totalMoney();
		delete p;
	}

	cout << setiosflags(ios::fixed) << setprecision(2) << totalMoney << endl;
}