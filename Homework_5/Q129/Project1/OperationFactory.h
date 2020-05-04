#pragma once
#include "Operation.h"
class OperationFactory
{
public:
	Operation* createOperation(char op);
};

