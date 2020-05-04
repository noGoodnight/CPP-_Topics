#include<iostream>
#include"Operation.h"
#include"OperationFactory.h"
#include"OperationAdd.h"
#include"OperationSub.h"
#include"OperationMul.h"
#include"OperationDiv.h"

int main() {
	double a, b;
	char op;
	OperationFactory *of = new OperationFactory;
	Operation *o;

	std::cin >> op >> a >> b;
	o = of->createOperation(op);
	o->setA(a);
	o->setB(b);
	std::cout << o->getResult() << std::endl;

	delete of, o;
}