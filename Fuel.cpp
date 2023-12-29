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
	cout << "** Ввод данных о топливном баке **" << endl;
	do {
		cout << "Введите заполенность бака (0 - Пустой, 1 - Полный): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "Попробуйте ещё раз. ";
	} while (!flag);
	this->capacity = stoi(temp);
	cout << "Данные успешно введены!" << endl << endl;
}
void Fuel::output() {
	cout << "Данные о топливном баке:" << endl << "-Заполненность: ";
	if (this->getCapacity())
		cout << "Полный" << endl << endl;
	else
		cout << "Пустой" << endl << endl;
}
void Fuel::fill() {
	this->capacity = 1;
}
void Fuel::empty() {
	this->capacity = 0;
}