#pragma once

using namespace std;

class Product {
public :
	int pid, pnum;
	double price;
	
	inline Product(int id, int num, double money) {
		pid = id;
		pnum = num;
		price = money;
	}

	double totalMoney();
};

