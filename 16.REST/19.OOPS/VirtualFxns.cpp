// In C++, a virtual function is a function declared in the base class that can be overridden by a derived class. The primary purpose of using virtual functions is to achieve runtime polymorphism, where the appropriate function implementation is determined at runtime based on the actual object type.

// To declare a virtual function, you use the virtual keyword in the base class. Derived classes can then override the virtual function using the override keyword.

// Here's an example using a virtual function:
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    Shape* shapes[2];
    Circle circle;
    Square square;

    shapes[0] = &circle;
    shapes[1] = &square;

    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw(); // Polymorphic call
    }

    return 0;
}
// Abstract Class:

// An abstract class is a class that cannot be instantiated on its own but is meant to serve as a base for other classes. It can have one or more pure virtual functions, which are functions declared as virtual and specified with = 0. An abstract class provides a common interface for its derived classes and enforces that each derived class implements the required pure virtual functions.
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    Shape* shapes[2];
    Circle circle;
    Square square;

    shapes[0] = &circle;
    shapes[1] = &square;

    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw(); // Polymorphic call
    }

    return 0;
}
