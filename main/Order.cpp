#include "Order.h"
#include "../Passenger.h"
#include "../Driver.h"
#include "../Car.h"
#include <iostream>
#include <string>
using namespace std;

int min_payment = 200; // ������������� ������������ ����

void increasePayment();
int calculatePayment(bool rate, bool congestion);

Order::Order(bool rate, bool congestion, Passenger passenger, Driver driver, Car car) {
	cout << "�����" << endl;
	int payment;
	payment = calculatePayment(rate, congestion);

	this->status = 0;
	if (passenger.getBalance() < payment) {
		cout << "�� ������� ��������� ������������ �������! (����� �������: " << payment << ")" << endl;
	}
	else {
		if (car.fuel.getCapacity() == false) {
			cout << "� ��������� ������ �� �������� ��������� ���!" << endl;
		}
		else {
			if (rate) { // ����� ������� - �������
				if (getExperience(driver) < 10 || getOrderAmount(driver) < 30) {
					cout << "� ���������� �������� ������������ ��� ����� ��� ����������� ������� ��� ���������� ������ ������ �������!";
				}
				else {
					if (car.getRate() == false) {
						cout << "��������� ���������� ������������ �������� ������ ��� ���������� ������ ������ �������!" << endl;
					}
					else { // ����� ������� - ������
						this->status = 1;
					}
				}
			}
			else { // ����� ������� - ������
				this->status = 1;
			}
		}
	}
	if (this->status == 1) {
		passenger.takePayment(payment);
		givePayment(payment, driver);
		increaseOrderAmount(driver);
		car.fuel.empty();
		cout << "����� �������� �������! ���������� �� ������ ���������� ������:" << endl << endl;
		string buffer;
		string* rate_str = Order::rateString(rate, &buffer);
		cout << "����� �������: " << *rate_str << endl;
		string congestion_str = Order::congestionString(congestion, buffer);
		cout << "������������� �����: " << congestion_str << endl;
		cout << "��������� �������: " << payment << endl << endl;
		passenger.output();
		driver.output();
		car.output();
	}
}

void increasePayment() {
	min_payment += 300;
}

int calculatePayment(bool rate, bool congestion) {
	int price;
	price = min_payment;
	if (rate) {
		price += 300; // ����� ������� - �������
	}
	if (congestion) {
		price *= 2; // ���� ������ ����������
	}
	return price;
}

string* Order::rateString(bool rate, string* result) {
	if (rate)
		*result = "�������";
	else
		*result = "������";
	return result;
}

string& Order::congestionString(bool congestion, string& result) {
	if (congestion)
		result = "����";
	else
		result = "���";
	return result;
}