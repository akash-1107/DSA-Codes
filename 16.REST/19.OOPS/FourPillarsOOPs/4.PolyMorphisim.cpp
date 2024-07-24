// Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common base class. It enables you to write code that can work with objects of multiple derived classes in a unified manner. Polymorphism can be achieved through both function overloading and function overriding.

// There are two types of polymorphism: compile-time (or static) polymorphism and run-time (or dynamic) polymorphism.

// Compile-time Polymorphism: This is achieved through function overloading, where multiple functions with the same name but different parameter lists are defined within the same scope. The appropriate function is chosen by the compiler based on the function call and the number and types of arguments.

// Run-time Polymorphism: This is achieved through function overriding, where a derived class provides a specific implementation of a function that is already defined in its base class. The appropriate function implementation is determined at runtime based on the actual object type.

// Here's an example using run-time polymorphism with a car example:
#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    virtual void start() {
        cout << "Starting the vehicle." << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    void start() override {
        cout << "Starting the car's engine." << endl;
    }
};

// Derived class
class Bicycle : public Vehicle {
public:
    void start() override {
        cout << "Pedaling the bicycle." << endl;
    }
};

int main() {
    Vehicle* vehicles[2];
    Car myCar;
    Bicycle myBicycle;

    vehicles[0] = &myCar;//adress of myCar
    vehicles[1] = &myBicycle;

    for (int i = 0; i < 2; ++i) {
        vehicles[i]->start(); // Polymorphic call
    }

    return 0;
}
// In this example:

// Vehicle is the base class with a virtual method start().
// Car and Bicycle are derived classes that override the start() method to provide their specific implementations.
// In the main function, we create an array of pointers to Vehicle objects, and we store both a Car object and a Bicycle object in the array.

// When we call the start() method on each object through the pointers, the appropriate implementation is selected at runtime based on the actual object type. This is an example of run-time polymorphism.


// Polymorphism allows you to write code that can work with different types of objects in a unified way, making your code more flexible and maintainable.