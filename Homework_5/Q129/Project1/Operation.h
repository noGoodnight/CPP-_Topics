#pragma once
class Operation
{
protected:
	double a, b;

public:
	double virtual getResult();

	void inline setA(double x) {
		a = x;
	}

	void inline setB(double x) {
		b = x;
	}

	double inline getA() {
		return a;
	}

	double inline getB() {
		return b;
	}
};

