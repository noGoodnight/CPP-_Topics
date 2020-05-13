#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Statement {
public :
	string operation;
	double money;
	
	inline Statement(string s,double amount) {
		operation = s;
		money = amount;
	}

	void print();
};

class Account {
public:
	string name;
	double money;
	vector<Statement*> *statements;

	inline Account() {
		money = 0.0;
		statements = new vector<Statement*>;
	}

	inline ~Account() {
		delete statements;
	}

	void deposit(double);

	void withdraw(double);

	void printStatement();

	virtual double totalInterestEarned();
};

class CheckingAccount :public Account {
public:
	CheckingAccount() {
		name = "Checking Account";
	}
	
	double totalInterestEarned();
};

class SavingsAccount :public Account {
public:
	SavingsAccount() {
		name = "Savings Account";
	}
	double totalInterestEarned();
};

class MaxiSavingsAccount :public Account {
public:
	MaxiSavingsAccount() {
		name = "Maxi-Savings Account";
	}
	double totalInterestEarned();
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
	
	inline int getAccountNum() {
		return accounts->size();
	}

	void getStatement();

	double totalInterestEarned();
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

	void linkAccount(int, string);

	void deposit(int, double);

	void withdraw(int, double);

	void sumTransactions(int);

	void numberOfAccount(string);

	void totalInterestEarned(string);

	void getStatement(string);

	void banktotalInserstPaid();

	void customsum();

	void go();
};

