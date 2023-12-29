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

// Дружественные функции
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
	cout << "** Ввод данных водителя: " << driver.getName() << " **" << endl;
	do {
		cout << "Введите количество лет опыта: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "Попробуйте ещё раз. ";
	} while (!flag);
	driver.experience = stoi(temp);
	do {
		cout << "Введите количество выполненных заказов: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "Попробуйте ещё раз. ";
	} while (!flag);
	driver.orderAmount = stoi(temp);
	cout << "Данные успешно введены!" << endl << endl;
}
void output(Driver& driver) {
	cout << "Данные о водителе:" << endl << "-Имя: " << driver.getName() << endl;
	cout << "-Баланс: " << driver.getBalance() << endl;
	cout << "-Количество лет опыта: " << getExperience(driver) << endl;
	cout << "-Количество выполненных заказов: " << getOrderAmount(driver) << endl << endl;
}

// Перегрузка операторов
Driver operator + (Driver& driver1, Driver& driver2) // Оператор +
{
	return Driver(driver1.getBalance() + driver2.getBalance());
}
Driver& operator++ (Driver& driver) // Префиксный оператор ++
{
	setExperience(getExperience(driver) + 1, driver);
	return driver;
}
Driver operator++ (Driver& driver, int) // Постфиксный оператор ++
{
	Driver copy(driver);
	++driver;
	return copy;
}