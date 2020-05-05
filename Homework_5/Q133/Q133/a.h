#pragma once

class Car {
protected:
	int price, sales_volumn, engine_power;
};

//ÆæÈð(Chery£©£¬±¼³Û(Benz£©£¬Tesla£¬Model_car

class Chery :public Car {

};

class Benz :public Car {

};

class Tesla :public Car {

};

class Model_car :public Car {
public:
	inline Model_car() {
		engine_power = 0;
	}

	inline void display() {
	}
};