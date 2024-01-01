#include "Car.h"
#include "Fuel.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

int Car::numberOfCars = 0; // static member initialization

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
	cout << "** Car data entry **" << endl;
	do {
		cout << "Brand: ";
		cin >> this->brand;
		flag = Checking::nameCheck(this->brand);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	do {
		cout << "Rate (0 - Economy, 1 - Comfort): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	this->rate = stoi(temp);
	cout << "The data are entered successfully!" << endl << endl;
}
void Car::output() {
	if (!(this->brand.empty())) {
		cout << "Car data:" << endl << "- Brand: " << this->brand << endl << "- Rate: ";
		if (this->rate)
			cout << "Comfort" << endl;
		else
			cout << "Economy" << endl;
	}
	else
		throw string{"The Car brand is missing!"};
}