#define _CRT_SECURE_NO_WARNINGS
#include "../Fuel.h"
#include "../Car.h"
#include "../Driver.h"
#include "../Passenger.h"
#include "Order.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string buffer;
    cout << "TESTS:" << endl;
    Car car{};
    try {
        car.output();
    }
    catch (string error_message) {
        cout << error_message << endl << endl;
    }

    Driver driver{};
    try {
        output(driver);
    }
    catch (string error_message) {
        cout << error_message << endl << endl;
    }

    Passenger passenger{};
    try {
        passenger.output();
    }
    catch (string error_message) {
        cout << error_message << endl << endl;
    }

    Person person{ 5000 };
    try {
        person.output();
    }
    catch (string error_message) {
        cout << error_message << endl << endl;
    }

    car.setBrand("Volvo");
    try {
        car.output();
    }
    catch (string error_message) {
        cout << error_message << endl << endl;
    }

    return 0;
}