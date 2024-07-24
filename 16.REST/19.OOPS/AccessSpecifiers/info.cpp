#include <iostream>
using namespace std;

class Car {
public:    // Public access specifier
    string make;   // Public attribute
    string model;  // Public attribute
    int year;      // Public attribute

    // Constructor
    Car(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
    }

    // Method to start the engine
    void startEngine() {
        cout << "Engine started." << endl;
    }

private:   // Private access specifier
    int odometer;  // Private attribute

    // Private method to update odometer
    void updateOdometer(int distance) {
        odometer += distance;
    }

public:    // Public access specifier
    // Method to drive the car and update odometer
    void drive(int distance) {
        updateOdometer(distance);
        cout << "Car driven " << distance << " miles." << endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2023);

    // Accessing public attributes and methods
    cout << "Make: " << myCar.make << endl;
    cout << "Model: " << myCar.model << endl;
    cout << "Year: " << myCar.year << endl;

    myCar.startEngine();
    myCar.drive(100);

    // Uncommenting the following line will result in an error,
    // since 'odometer' is private and cannot be accessed directly.
    // cout << "Odometer: " << myCar.odometer << endl;

    return 0;
}

// Public Access Specifier: Members declared as public are accessible from anywhere, including outside the class. In the Car class, attributes like make, model, and year are declared as public, and methods like startEngine and drive are also public. These members can be accessed directly from the main function.

// Private Access Specifier: Members declared as private are only accessible within the class itself. In the Car class, the odometer attribute and the updateOdometer method are declared as private. This means they cannot be accessed directly from the main function. The drive method, which uses the updateOdometer method, can access it because it's within the same class.

// In summary, access specifiers provide control over the encapsulation and visibility of class members. Public members are accessible from anywhere, private members are only accessible within the class, and protected members (not used in this example) have a more complex usage related to inheritance. Using access specifiers effectively helps maintain the integrity and encapsulation of your classes.