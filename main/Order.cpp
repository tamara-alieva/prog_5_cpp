#include "Order.h"
#include "../Passenger.h"
#include "../Driver.h"
#include "../Car.h"
#include <iostream>
#include <string>
using namespace std;

int min_payment = 200; // инициализация статического поля

void increasePayment();
int calculatePayment(bool rate, bool congestion);

Order::Order(bool rate, bool congestion, Passenger passenger, Driver driver, Car car) {
	cout << "ЗАКАЗ" << endl;
	int payment;
	payment = calculatePayment(rate, congestion);

	this->status = 0;
	if (passenger.getBalance() < payment) {
		cout << "На балансе пассажира недостаточно средств! (Сумма поездки: " << payment << ")" << endl;
	}
	else {
		if (car.fuel.getCapacity() == false) {
			cout << "У выбранной машины не заполнен топливный бак!" << endl;
		}
		else {
			if (rate) { // Класс поездки - Комфорт
				if (getExperience(driver) < 10 || getOrderAmount(driver) < 30) {
					cout << "У выбранного водителя недостаточно лет опыта или завершённых заказов для выполнения заказа уровня Комфорт!";
				}
				else {
					if (car.getRate() == false) {
						cout << "Выбранный автомобиль недостаточно высокого класса для выполнения заказа уровня Комфорт!" << endl;
					}
					else { // Класс поездки - Эконом
						this->status = 1;
					}
				}
			}
			else { // Класс поездки - Эконом
				this->status = 1;
			}
		}
	}
	if (this->status == 1) {
		passenger.takePayment(payment);
		givePayment(payment, driver);
		increaseOrderAmount(driver);
		car.fuel.empty();
		cout << "Заказ выполнен успешно! Информация на момент завершения заказа:" << endl << endl;
		string buffer;
		string* rate_str = Order::rateString(rate, &buffer);
		cout << "Класс поездки: " << *rate_str << endl;
		string congestion_str = Order::congestionString(congestion, buffer);
		cout << "Загруженность дорог: " << congestion_str << endl;
		cout << "Стоимость поездки: " << payment << endl << endl;
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
		price += 300; // Класс поездки - Комфорт
	}
	if (congestion) {
		price *= 2; // Если дороги загруженны
	}
	return price;
}

string* Order::rateString(bool rate, string* result) {
	if (rate)
		*result = "Комфорт";
	else
		*result = "Эконом";
	return result;
}

string& Order::congestionString(bool congestion, string& result) {
	if (congestion)
		result = "Есть";
	else
		result = "Нет";
	return result;
}