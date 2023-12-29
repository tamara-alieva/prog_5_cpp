#include "Car.h"
#include "Fuel.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

int Car::numberOfCars = 0; // ������������� ������������ ����

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
	cout << "** ���� ������ ���������� **" << endl;
	do {
		cout << "������� �����: ";
		cin >> this->brand;
		flag = Checking::nameCheck(this->brand);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	do {
		cout << "������� ����� ���������� (0 - ������, 1 - �������): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "���������� ��� ���. ";
	} while (!flag);
	this->rate = stoi(temp);
	cout << "������ ������� �������!" << endl << endl;
}
void Car::output() {
	if (this->brand.empty())
		cout << "������ �� ���������� �����������!" << endl;
	else {
		cout << "������ �� ����������:" << endl << "-�����: " << this->brand << endl << "-�����: ";
		if (this->rate)
			cout << "�������" << endl;
		else
			cout << "������" << endl;
	}
}