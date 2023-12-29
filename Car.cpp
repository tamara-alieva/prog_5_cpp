#include "Car.h"
#include "Fuel.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

int Car::numberOfCars = 0; // инициализация статического поля

Car::Car() {
	this->fuel = new Fuel();
	this->brand = "";
	this->rate = 0;
	numberOfCars++;
}
Car::Car(string brand) {
	this->fuel = new Fuel();
	this->brand = brand;
	this->rate = 0;
	numberOfCars++;
}
Car::Car(bool rate) {
	this->fuel = new Fuel();
	this->brand = "";
	this->rate = rate;
	numberOfCars++;
}
Car::Car(string brand, bool rate) {
	this->fuel = new Fuel();
	this->brand = brand;
	this->rate = rate;
	numberOfCars++;
}
void Car::setBrand(string brand) {
	this->brand = brand;
}
void Car::setRate(bool rate) {
	this->rate = rate;
}
string Car::getBrand() {
	return this->brand;
}
bool Car::getRate() {
	return this->rate;
}
int Car::getNumberOfCars() {
	return numberOfCars;
}
void Car::input() {
	string temp; bool flag;
	cout << "** Ввод данных автомобиля **" << endl;
	do {
		cout << "Введите марку: ";
		cin >> this->brand;
		flag = Checking::nameCheck(this->brand);
		if (!flag) cout << "Попробуйте ещё раз. ";
	} while (!flag);
	do {
		cout << "Введите класс автомобиля (0 - Эконом, 1 - Комфорт): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "Попробуйте ещё раз. ";
	} while (!flag);
	this->rate = stoi(temp);
	cout << "Данные успешно введены!" << endl << endl;
}
void Car::output() {
	if (this->brand.empty())
		cout << "Данные об автомобиле отсутствуют!" << endl;
	else {
		cout << "Данные об автомобиле:" << endl << "-Марка: " << this->brand << endl << "-Класс: ";
		if (this->rate)
			cout << "Комфорт" << endl;
		else
			cout << "Эконом" << endl;
	}
}