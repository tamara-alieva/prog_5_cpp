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

// ������������� �������
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
	cout << "** ���� ������ ��������: " << driver.getName() << " **" << endl;
	do {
		cout << "������� ���������� ��� �����: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	driver.experience = stoi(temp);
	do {
		cout << "������� ���������� ����������� �������: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	driver.orderAmount = stoi(temp);
	cout << "������ ������� �������!" << endl << endl;
}
void output(Driver& driver) {
	cout << "������ � ��������:" << endl << "-���: " << driver.getName() << endl;
	cout << "-������: " << driver.getBalance() << endl;
	cout << "-���������� ��� �����: " << getExperience(driver) << endl;
	cout << "-���������� ����������� �������: " << getOrderAmount(driver) << endl << endl;
}

// ���������� ����������
Driver operator + (Driver& driver1, Driver& driver2) // �������� +
{
	return Driver(driver1.getBalance() + driver2.getBalance());
}
Driver& operator++ (Driver& driver) // ���������� �������� ++
{
	setExperience(getExperience(driver) + 1, driver);
	return driver;
}
Driver operator++ (Driver& driver, int) // ����������� �������� ++
{
	Driver copy(driver);
	++driver;
	return copy;
}