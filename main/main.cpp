#define _CRT_SECURE_NO_WARNINGS
#include "../Fuel.h"
#include "../Car.h"
#include "../Driver.h"
#include "../Passenger.h"
#include "Order.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string buffer;
    cout << "ТЕСТЫ:" << endl;
    cout << "1) Статическое поле numberOfCars и метод getNumberOfCars" << endl;
    Car car_1("Kia Rio");
    Car car_2("Toyota");
    Car car_3{"Volvo", true};
    cout << "Количество созданных объектов Car: " << Car::getNumberOfCars() << endl << endl;

    cout << "2) Возврат значения из метода rateString класса Order через указатель (*)" << endl;
    bool f = 1;
    cout << "Возвращаемая строка: " << *(Order::rateString(f, &buffer)) << endl << endl;

    cout << "3) Возврат значения из метода congestionString класса Order через ссылку" << endl;
    cout << "Возвращаемая строка: " << Order::congestionString(f, buffer) << endl << endl;

    cout << "4) Дружественные функции (методы класса Driver заменены на одноимённые дружественные функции)" << endl;
    Driver driver1("Kirill", 5000, 15, 45);
    output(driver1);

    cout << "5) Перегрузка операторов + и ++" << endl << endl;
    cout << "---- Оператор +:" << endl << endl;
    cout << "Водитель 1:" << endl;
    output(driver1);
    cout << "Водитель 2:" << endl;
    Driver driver2("Ivan", 4000, 5, 33);
    output(driver2);
    Driver driver3{ driver1 + driver2 };
    cout << "Баланс Водителя 3: " << driver3.getBalance() << endl << endl;
    
    cout << "---- Оператор ++ (префиксный):" << endl << endl;
    ++driver2;
    cout << "Водитель 2:" << endl;
    output(driver2);

    cout << "---- Оператор ++ (постфиксный):" << endl << endl;
    driver3 = driver2++;
    output(driver3);
    output(driver2);

    return 0;
}