#include "Driver.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

Driver::Driver() : Person() {
	this->experience = 0;
	this->orderAmount = 0;
}
Driver::Driver(string name) : Person(name) {
	this->experience = 0;
	this->orderAmount = 0;
}
Driver::Driver(int balance) : Person(balance) {
	this->experience = 0;
	this->orderAmount = 0;
}
Driver::Driver(string name, int balance, int experience, int orderAmount) : Person(name, balance) {
	this->experience = experience;
	this->orderAmount = orderAmount;
}

// friend functions
void setExperience(int experience, Driver& driver) {
	driver.experience = experience;
}
void setOrderAmount(int orderAmount, Driver& driver) {
	driver.orderAmount = orderAmount;
}
int getExperience(Driver& driver) {
	return driver.experience;
}
int getOrderAmount(Driver& driver) {
	return driver.orderAmount;
}
void givePayment(int payment, Driver& driver) {
	int old_balance = driver.getBalance();
	driver.setBalance(old_balance + payment);
}
void increaseOrderAmount(Driver& driver) {
	int old_amount = getOrderAmount(driver);
	setOrderAmount(old_amount + 1, driver);
}
void input(Driver& driver) {
	string temp; bool flag;
	cout << "** Entry the data of Driver: " << driver.getName() << " **" << endl;
	do {
		cout << "Years of experience: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	driver.experience = stoi(temp);
	do {
		cout << "Amount of completed orders: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	driver.orderAmount = stoi(temp);
	cout << "The data are entered successfully!" << endl << endl;
}
void output(Driver& driver) {
	if ((driver.getName()).empty())
		cout << "The Driver data are not available!" << endl;
	else {
		cout << "Driver data:" << endl << "- Name: " << driver.getName() << endl;
		cout << "- Balance: " << driver.getBalance() << endl;
		cout << "- Years of experience: " << getExperience(driver) << endl;
		cout << "- Amount of completed orders: " << getOrderAmount(driver) << endl << endl;
	}
}

// operator overload
Driver operator + (Driver& driver1, Driver& driver2) // operator +
{
	return Driver(driver1.getBalance() + driver2.getBalance());
}
Driver& operator++ (Driver& driver) // prefix operator ++
{
	setExperience(getExperience(driver) + 1, driver);
	return driver;
}
Driver operator++ (Driver& driver, int) // postfix operator ++
{
	Driver copy(driver);
	++driver;
	return copy;
}