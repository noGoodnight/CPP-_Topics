#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
public:
	int money;

	inline Account() {
		money = 0;
	}
};

class CheckingAccount :public Account {
public:

};

class SavingsAccount :public Account {
public:

};

class MaxiSavingsAccount :public Account {
public:

};

class Customer {
public:
	string name;
	vector<Account*> *accounts;

	inline Customer(string s) {
		name = s;
		accounts = new vector<Account*>;
	}

	inline ~Customer() {
		delete accounts;
	}
};

class Bank {
public:
	vector<Account*> *accounts;
	vector<Customer*> *customers;

	inline Bank() {
		accounts = new vector<Account*>;
		customers = new vector<Customer*>;
	}

	inline ~Bank() {
		delete accounts;
		delete customers;
	}

	void createCustomer(string);

	void createAccount(int);
};

