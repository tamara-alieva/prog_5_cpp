#pragma once

#include "Fuel.h"
#include <string>

class Car {
private:
	std::string brand;
	bool rate;
	static int numberOfCars;
public:
	Fuel fuel;
	Car();
	Car(std::string brand);
	Car(bool rate);
	Car(std::string brand, bool rate);
	void setBrand(std::string brand);
	void setRate(bool rate);
	std::string getBrand();
	bool getRate();
	static int getNumberOfCars();
	void input();
	void output();
};