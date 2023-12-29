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
	cout << "** ���� ������ �������� **" << endl;
	do {
		cout << "������� ���: ";
		cin >> this->name;
		flag = Checking::nameCheck(this->name);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	do {
		cout << "������� ������: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	this->balance = stoi(temp);
	cout << "������ ������� �������!" << endl << endl;
}
void Person::output() {
	if (this->name.empty())
		cout << "������ � �������� �����������!" << endl;
	else
		cout << "������ � ��������:" << endl << "-���: " << this->name << endl << "-������: " << this->balance << endl;
}