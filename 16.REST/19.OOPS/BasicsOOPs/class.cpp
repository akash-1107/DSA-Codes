//2.Here's a breakdown of the key components of a class:

// Attributes (Properties): These are the data members or variables that represent the (characteristics of the objects) created from the class. Attributes define the state of the object. For example, if you're creating a class for a "Car," attributes could include things like "color," "make," "model," and "year."

// Methods (Functions): These are the functions defined within a class that determine the behavior of the objects. (Methods define what actions or operations can be performed on the objects). For instance, in a "Car" class, methods might include "start_engine," "accelerate," and "brake."

// Constructor: This is a special method that is called when an object of the class is created. (It initializes the attributes of the object and sets its initial state. The constructor typically has the same name as the class) and is used to allocate memory for the object and set its initial values.

// Inheritance: A class can inherit attributes and methods from another class, known as its parent class or base class. This promotes code reuse and allows you to create specialized classes based on existing ones.

// Encapsulation: (This refers to the practice of bundling data (attributes) and methods that operate on the data within a single unit (the class) ). Encapsulation allows you to control access to the internal details of the class, promoting information hiding and abstraction.

// example -
#include <iostream>
using namespace std;

class Car {
public:
    string make;
    string model;
    int year;
    
    Car(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
    }
    
    void startEngine() {
        cout << "Engine started." << endl;
    }
    
    void accelerate() {
        cout << "Car is accelerating." << endl;
    }
    
    void brake() {
        cout << "Car is braking." << endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2023);
    Car anotherCar("Ford", "Mustang", 2022);
    
    cout << "My car: " << myCar.make << " " << myCar.model << " " << myCar.year << endl;
    cout << "Another car: " << anotherCar.make << " " << anotherCar.model << " " << anotherCar.year << endl;
    
    myCar.startEngine();
    myCar.accelerate();
    myCar.brake();
    
    return 0;
}
//In this C++ example, we've defined a Car class with attributes (make, model, year) and methods (startEngine, accelerate, brake). We then create objects myCar and anotherCar from the class, initialize their attributes, and use the methods to simulate car behavior.