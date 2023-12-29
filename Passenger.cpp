#include "Passenger.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

Passenger::Passenger() : Person() {
	this->payment_method = 0;
}
Passenger::Passenger(string name) : Person(name) {
	this->payment_method = 0;
}
Passenger::Passenger(int balance) : Person(balance) {
	this->payment_method = 0;
}
Passenger::Passenger(string name, int balance, bool method) : Person(name, balance) {
	this->payment_method = method;
}
void Passenger::setMethod(bool method) {
	this->payment_method = method;
}
bool Passenger::getMethod() {
	return this->payment_method;
}
void Passenger::input() {
	string temp; bool flag;
	cout << "** ���� ������ � ���������: " << this->getName() << " **" << endl;
	do {
		cout << "������� ������ ������ (0 - ��������, 1 - ���������� �����): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	this->payment_method = stoi(temp);
	cout << "������ ������� �������!" << endl << endl;
}
void Passenger::output() {
	cout << "������ � ���������:" << endl << "-���: " << this->getName() << endl;
	cout << "-������: " << this->getBalance() << endl << "-������ ������: ";
	if (this->getMethod())
		cout << "���������� �����" << endl << endl;
	else
		cout << "��������" << endl << endl;
}
void Passenger::takePayment(int payment) {
	int old_balance = this->getBalance();
	this->setBalance(old_balance - payment);
}