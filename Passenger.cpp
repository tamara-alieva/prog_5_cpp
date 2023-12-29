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
	cout << "** Ввод данных о пассажире: " << this->getName() << " **" << endl;
	do {
		cout << "Введите способ оплаты (0 - Наличные, 1 - Банковская карта): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "Попробуйте ещё раз. ";
	} while (!flag);
	this->payment_method = stoi(temp);
	cout << "Данные успешно введены!" << endl << endl;
}
void Passenger::output() {
	cout << "Данные о пассажире:" << endl << "-Имя: " << this->getName() << endl;
	cout << "-Баланс: " << this->getBalance() << endl << "-Способ оплаты: ";
	if (this->getMethod())
		cout << "Банковская карта" << endl << endl;
	else
		cout << "Наличные" << endl << endl;
}
void Passenger::takePayment(int payment) {
	int old_balance = this->getBalance();
	this->setBalance(old_balance - payment);
}