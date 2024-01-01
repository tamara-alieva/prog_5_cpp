#include "Person.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() {
	this->name = "";
	this->balance = 0;
}

Person::Person(string name) {
	this->name = name;
	this->balance = 0;
}

Person::Person(int balance) {
	this->name = "";
	this->balance = balance;
}

Person::Person(string name, int balance) {
	this->name = name;
	this->balance = balance;
}

void Person::setName(string name) {
	this->name = name;
}

void Person::setBalance(int balance) {
	this->balance = balance;
}
string Person::getName() {
	return this->name;
}
int Person::getBalance() {
	return this->balance;
}
void Person::input() {
	string temp; bool flag;
	cout << "** Person data entry **" << endl;
	do {
		cout << "Name: ";
		cin >> this->name;
		flag = Checking::nameCheck(this->name);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	do {
		cout << "Balance: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	this->balance = stoi(temp);
	cout << "The data are entered successfully!" << endl << endl;
}
void Person::output() {
	if (!(this->name.empty()))
		cout << "Person data:" << endl << "- Name: " << this->name << endl << "- Balance: " << this->balance << endl;
	else
		throw string{"The Person name is missing!"};
}