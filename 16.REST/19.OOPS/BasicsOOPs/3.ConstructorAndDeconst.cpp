//Certainly! Constructors and destructors are special methods in object-oriented programming (OOP) that are used to initialize and clean up objects, respectively. 
#include <iostream>
using namespace std;

class Car {
public:
    string make;
    string model;
    int year;

    // Constructor
    Car(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
        cout << "A new car object has been created!" << endl;
    }

    // Destructor
    ~Car() {
        cout << "The car object is being destroyed!" << endl;
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
    
    myCar.startEngine();
    myCar.accelerate();
    myCar.brake();

    // free myCar;
    return 0;
}
// Constructor: The constructor is a special method with the same name as the class. It is automatically called when an object of the class is created. In this case, the constructor takes three parameters (_make, _model, _year) and initializes the object's attributes. It also displays a message to indicate that a new car object has been created.

// Destructor: The destructor is a special method with the same name as the class, preceded by a tilde (~). It is automatically called when an object is about to be destroyed (usually when it goes out of scope or when delete is called on a dynamically allocated object). In this case, the destructor displays a message to indicate that the car object is being destroyed.

// In more complex scenarios, like when objects are dynamically allocated using new and delete, destructors play a crucial role in freeing up resources and performing cleanup tasks.