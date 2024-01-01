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
    cout << endl;

    int i,j;
    Person array1[2];
    for (i = 0; i < 2; i++)
        array1[i].input();
    for (i = 0; i < 2; i++)
        array1[i].output();
    cout << endl;

    Car array2[2][2];
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++) {
            array2[i][j].setBrand("Toyota");
            array2[i][j].setRate(true);
        }
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++) {
            array2[i][j].output();
        }

    return 0;
}