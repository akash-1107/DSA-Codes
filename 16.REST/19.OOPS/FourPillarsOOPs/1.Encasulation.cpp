#include <iostream>
using namespace std;
// Encapsulation is one of the four fundamental principles of object-oriented programming (OOP), along with inheritance, polymorphism, and abstraction. It involves bundling data (attributes) and the methods (functions) that operate on that data into a single unit known as a class. The primary goal of encapsulation is to hide the internal details of an object's implementation from the outside world, promoting information hiding and abstraction.
class Car {
private:
    string make;  // Private attribute
    string model; // Private attribute
    int year;     // Private attribute

public:
    // Constructor
    Car(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
    }

    // Method to get the make of the car
    string getMake() {
        return make;
    }

    // Method to get the model of the car
    string getModel() {
        return model;
    }

    // Method to get the year of the car
    int getYear() {
        return year;
    }

    // Method to start the engine
    void startEngine() {
        cout << "Engine started." << endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2023);

    // Accessing attributes using methods
    cout << "Make: " << myCar.getMake() << endl;
    cout << "Model: " << myCar.getModel() << endl;
    cout << "Year: " << myCar.getYear() << endl;

    myCar.startEngine();

    return 0;
}
