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
    cout << "�����:" << endl;
    cout << "1) ����������� ���� numberOfCars � ����� getNumberOfCars" << endl;
    Car car_1("Kia Rio");
    Car car_2("Toyota");
    Car car_3{"Volvo", true};
    cout << "���������� ��������� �������� Car: " << Car::getNumberOfCars() << endl << endl;

    cout << "2) ������� �������� �� ������ rateString ������ Order ����� ��������� (*)" << endl;
    bool f = 1;
    cout << "������������ ������: " << *(Order::rateString(f, &buffer)) << endl << endl;

    cout << "3) ������� �������� �� ������ congestionString ������ Order ����� ������" << endl;
    cout << "������������ ������: " << Order::congestionString(f, buffer) << endl << endl;

    cout << "4) ������������� ������� (������ ������ Driver �������� �� ���������� ������������� �������)" << endl;
    Driver driver1("Kirill", 5000, 15, 45);
    output(driver1);

    cout << "5) ���������� ���������� + � ++" << endl << endl;
    cout << "---- �������� +:" << endl << endl;
    cout << "�������� 1:" << endl;
    output(driver1);
    cout << "�������� 2:" << endl;
    Driver driver2("Ivan", 4000, 5, 33);
    output(driver2);
    Driver driver3{ driver1 + driver2 };
    cout << "������ �������� 3: " << driver3.getBalance() << endl << endl;
    
    cout << "---- �������� ++ (����������):" << endl << endl;
    ++driver2;
    cout << "�������� 2:" << endl;
    output(driver2);

    cout << "---- �������� ++ (�����������):" << endl << endl;
    driver3 = driver2++;
    output(driver3);
    output(driver2);

    return 0;
}