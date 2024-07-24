#include <iostream>
using namespace std;

class Shape {
protected:
    double width;
    double height;

public:
    Shape(double _width, double _height) : width(_width), height(_height) {}

    double getWidth() {
        return width;
    }

    double getHeight() {
        return height;
    }
};

class Rectangle : public Shape { //derieved class
public:
    Rectangle(double _width, double _height) : Shape(_width, _height) {}

    double getArea() {
        return width * height;  // Accessing protected members in the derived class
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);

    // Accessing the protected members indirectly through the methods
    cout << "Width: " << rectangle.getWidth() << endl;
    cout << "Height: " << rectangle.getHeight() << endl;

    cout << "Area: " << rectangle.getArea() << endl;

    return 0;
}

//In summary, the protected access specifier allows members to be accessible within the class and its subclasses, promoting a level of encapsulation while still allowing derived classes to use and modify those members. (Inheritance)


//syntax for derieved class - 

// //Base class
// class BaseClass {
// // Members and methods of the base class
// };

// // Derived class
// class DerivedClass : access-specifier BaseClass {
//     // Members and methods of the derived class
// };


