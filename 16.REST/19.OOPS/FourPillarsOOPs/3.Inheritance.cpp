// Inheritance is a fundamental concept in object-oriented programming (OOP) that allows you to create a new class (the derived class) based on an existing class (the base class). 

// The derived class inherits the attributes and methods of the base class, and you can also add new attributes and methods or override existing ones in the derived class. Inheritance promotes code reuse, extensibility, and the creation of a hierarchy of related classes.

#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    string type;

    Vehicle(string _type) : type(_type) {}

    void drive() {
        cout << "Driving the " << type << "." << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    string make;

    Car(string _make) : Vehicle("Car"), make(_make) {}

    void startEngine() {
        cout << "Starting the " << make << " car's engine." << endl;
    }
};

int main() {
    Car myCar("Toyota");

    myCar.startEngine(); // Accessing Car's method
    myCar.drive();       // Accessing Vehicle's method

    return 0;
}
