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
	cout << "** Fuel data entry **" << endl;
	do {
		cout << "Capacity (0 - Empty, 1 - Full): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	this->capacity = stoi(temp);
	cout << "The data are entered successfully!" << endl << endl;
}
void Fuel::output() {
	cout << "Fuel data:" << endl << "- Capacity: ";
	if (this->getCapacity())
		cout << "Full" << endl << endl;
	else
		cout << "Empty" << endl << endl;
}
void Fuel::fill() {
	this->capacity = 1;
}
void Fuel::empty() {
	this->capacity = 0;
}