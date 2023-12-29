#pragma once

#include "Person.h"
#include <string>

class Driver : public Person {
	friend void setExperience(int experience, Driver& driver);
	friend void setOrderAmount(int orderAmount, Driver& driver);
	friend int getExperience(Driver& driver);
	friend int getOrderAmount(Driver& driver);
	friend void givePayment(int payment, Driver& driver);
	friend void increaseOrderAmount(Driver& driver);
	friend void input(Driver& driver);
	friend void output(Driver& driver);
private:
	int experience, orderAmount;
public:
	Driver();
	Driver(std::string name);
	Driver(int balance);
	Driver(std::string name, int balance, int experience, int orderAmount);
};

Driver operator + (Driver& driver1, Driver& driver2);
Driver& operator++ (Driver& driver);
Driver operator++ (Driver& driver, int);