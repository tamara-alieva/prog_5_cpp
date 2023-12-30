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
	cout << "** Entry the data of Passenger: " << this->getName() << " **" << endl;
	do {
		cout << "Payment method (0 - Cash, 1 - Credit card): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	this->payment_method = stoi(temp);
	cout << "The data are entered successfully!" << endl << endl;
}
void Passenger::output() {
	if ((this->getName()).empty())
		cout << "The Passenger data are not available!" << endl;
	else
	cout << "Passenger data:" << endl << "- Name: " << this->getName() << endl;
	cout << "- Balance: " << this->getBalance() << endl << "- Payment method: ";
	if (this->getMethod())
		cout << "Credit card" << endl << endl;
	else
		cout << "Cash" << endl << endl;
}
void Passenger::takePayment(int payment) {
	int old_balance = this->getBalance();
	this->setBalance(old_balance - payment);
}