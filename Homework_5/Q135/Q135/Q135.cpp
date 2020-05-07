#include "Q135.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void Statement::print() {
	cout << "  " << operation << " $" << setiosflags(ios::fixed) << setprecision(2) << money << endl;
}

void Account::deposit(double amount) {
	money += amount;
	Statement *statement = new Statement("deposit", amount);
	statements->push_back(statement);
}

void Account::withdraw(double amount) {
	if (money < amount) {
		cout << "sumTransactions must be greater than zero" << endl;
	}
	else {
		money -= amount;
		Statement *statement = new Statement("withdrawal", amount);
		statements->push_back(statement);
	}
}

void Account::printStatement(){
	cout << name << endl;
	vector<Statement*>::iterator it = statements->begin();
	while (it != statements->end()) {
		(*it)->print();
		it++;
	}
	cout << "Total $" << setiosflags(ios::fixed) << setprecision(2) << money << endl << endl;
}

double Account::totalInterestEarned() {
	return 0.0;
}

double CheckingAccount::totalInterestEarned() {
	double interest = 0.0;
	interest = money * 0.001;
	return interest;
}

double SavingsAccount::totalInterestEarned() {
	double interest = 0.0;
	interest = min(1000.0, money)*0.001 + max(0.0, money - 1000.0)*0.002;
	return interest;
}

double MaxiSavingsAccount::totalInterestEarned() {
	double interest = 0.0;
	if (money <= 1000.0) {
		interest += money * 0.02;
	}
	else if (1000.0 <money && money <= 2000) {
		interest += 20;
		interest += (money - 1000)*0.05;
	}
	else {
		interest += 70;
		interest += (money - 2000.0) * 0.1;
	}
	return interest;
}

double Customer::totalInterestEarned() {
	double interest = 0.0;
	vector<Account*>::iterator it = accounts->begin();
	while (it != accounts->end()) {
		interest += (*it)->totalInterestEarned();
		it++;
	}
	return interest;
}

void Customer::getStatement() {
	double totalMoney = 0.0;
	cout << "Statement for " << name << endl << endl;
	vector<Account*>::iterator it = accounts->begin();
	while (it != accounts->end()) {
		if ((*it)->name == "Checking Account") {
			(*it)->printStatement();
			totalMoney += (*it)->money;
		}
		it++;
	}
	it = accounts->begin();
	while (it != accounts->end()) {
		if ((*it)->name == "Savings Account") {
			(*it)->printStatement();
			totalMoney += (*it)->money;
		}
		it++;
	}
	cout << "Total In All Accounts $" << setiosflags(ios::fixed) << setprecision(2) << totalMoney << endl;
}

void Bank::go() {
	string instr;

	cin >> instr;
	while (instr != "end") {
		if (instr == "createAccount") {
			int type;
			cin >> type;
			createAccount(type);
		}
		else if (instr == "createCustomer") {
			string name;
			cin >> name;
			createCustomer(name);
		}
		else if (instr == "addToCustomer") {
			int index;
			string name;
			cin >> index >> name;
			linkAccount(index, name);
		}
		else if (instr == "accountDeposit") {
			int index;
			double money;
			cin >> index >> money;
			if (money < 0) {
				cout << "amount must be greater than zero" << endl;
			}
			else {
				deposit(index, money);
			}
		}
		else if (instr == "accountWithdraw") {
			int index;
			double money;
			cin >> index >> money;
			if (money < 0) {
				cout << "amount must be greater than zero" << endl;
			}
			else {
				withdraw(index, money);
			}
		}
		else if (instr == "sumTransactions") {
			int index;
			cin >> index;
			sumTransactions(index);
		}
		else if (instr == "numberOfAccount") {
			string name;
			cin >> name;
			numberOfAccount(name);
		}
		else if (instr == "totalInterestEarned") {
			string name;
			cin >> name;
			totalInterestEarned(name);
		}
		else if (instr == "getStatement") {
			string name;
			cin >> name;
			getStatement(name);
		}
		else if (instr == "banktotalInserstPaid") {
			banktotalInserstPaid();
		}
		else if (instr == "customsum") {
			customsum();
		}
		cin >> instr;
	}
}

void Bank::createAccount(int type) {
	Account *act;
	switch (type)
	{
	case 0:
		act = new CheckingAccount;
		break;
	case 1:
		act = new SavingsAccount;
		break;
	case 2:
		act = new MaxiSavingsAccount;
		break;
	default:
		break;
	}
	accounts->push_back(act);
}

void Bank::createCustomer(string name) {
	Customer *c = new Customer(name);
	customers->push_back(c);
}

void Bank::linkAccount(int index, string name) {
	vector<Customer*>::iterator it = customers->begin();
	while (it != customers->end()) {
		if ((*it)->name == name) {
			(*it)->accounts->push_back(accounts->at(index));
			break;
		}
		it++;
	}
}

void Bank::deposit(int index, double money) {
	accounts->at(index)->deposit(money);
}

void Bank::withdraw(int index, double money) {
	accounts->at(index)->withdraw(money);
}

void Bank::sumTransactions(int index) {
	cout << setiosflags(ios::fixed) << setprecision(1) << accounts->at(index)->money << endl;
}

void Bank::numberOfAccount(string name) {
	vector<Customer*>::iterator it = customers->begin();
	while (it != customers->end()) {
		if ((*it)->name == name) {
			cout << (*it)->getAccountNum() << endl;
			break;
		}
		it++;
	}
}

void Bank::totalInterestEarned(string name) { 
	double interest = 0.0;
	vector<Customer*>::iterator it = customers->begin();
	while (it != customers->end()) {
		if ((*it)->name == name) {
			interest += (*it)->totalInterestEarned();
			break;
		}
	}
	std::cout << setiosflags(ios::fixed) << setprecision(1) << interest << endl;
}

void Bank::getStatement(string name) {
	vector<Customer*>::iterator it = customers->begin();
	while (it != customers->end()) {
		if ((*it)->name == name) {
			(*it)->getStatement();
			break;
		}
	}
}

void Bank::banktotalInserstPaid() {
	double totalInterest = 0.0;
	vector<Customer*>::iterator it = customers->begin();
	while (it != customers->end()) {
		totalInterest += (*it)->totalInterestEarned();
		it++;
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << totalInterest << endl;
}

void Bank::customsum() {
	vector<Customer*>::iterator it = customers->begin();
	cout << "Customer Summary" << endl;
	while (it != customers->end()) {
		cout << " - " << (*it)->name << " (" << (*it)->getAccountNum() << (((*it)->getAccountNum() == 1) ? " account" : " accounts") << ")" << endl;
		it++;
	}
}

int main() {
	Bank *bank = new Bank;
	bank->go();
}