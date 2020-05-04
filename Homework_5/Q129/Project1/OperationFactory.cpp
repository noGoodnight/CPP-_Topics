#include "OperationFactory.h"
#include "Operation.h"
#include "OperationAdd.h"
#include "OperationSub.h"
#include "OperationMul.h"
#include "OperationDiv.h"


Operation* OperationFactory::createOperation(char op) {
	switch (op)
	{
	case '+':
		return new OperationAdd;
		break;
	case '-':
		return new OperationSub;
		break;
	case '*':
		return new OperationMul;
		break;
	case '/':
		return new OperationDiv;
		break;
	default:
		return nullptr;
		break;
	}
}