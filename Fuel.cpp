#include "Fuel.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

Fuel::Fuel() {
	this->capacity = 0;
}
Fuel::Fuel(bool capacity) {
	this->capacity = capacity;
}
void Fuel::setCapacity(bool capacity) {
	this->capacity;
}
bool Fuel::getCapacity() {
	return this->capacity;
}
void Fuel::input() {
	string temp; bool flag;
	cout << "** ���� ������ � ��������� ���� **" << endl;
	do {
		cout << "������� ������������ ���� (0 - ������, 1 - ������): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	this->capacity = stoi(temp);
	cout << "������ ������� �������!" << endl << endl;
}
void Fuel::output() {
	cout << "������ � ��������� ����:" << endl << "-�������������: ";
	if (this->getCapacity())
		cout << "������" << endl << endl;
	else
		cout << "������" << endl << endl;
}
void Fuel::fill() {
	this->capacity = 1;
}
void Fuel::empty() {
	this->capacity = 0;
}