// Abstraction is a fundamental principle in object-oriented programming (OOP) that involves simplifying complex reality by modeling classes based on their essential features while ignoring or hiding the unnecessary details. It focuses on defining what an object does rather than how it does it

#include <iostream>
using namespace std;

// Abstract base class
class Vehicle {
public:
    string type;

    Vehicle(string _type) : type(_type) {}

    virtual void start() = 0;  // Abstract method

    void stop() {
        cout << type << " is stopping." << endl;
    }
};

// Concrete derived class
class Car : public Vehicle {
public:
    string make;

    Car(string _make) : Vehicle("Car"), make(_make) {}

    void start() override {
        cout << "Starting the " << make << " car's engine." << endl;
    }
};

int main() {
    Car myCar("Toyota");

    myCar.start();
    myCar.stop();

    return 0;
}
