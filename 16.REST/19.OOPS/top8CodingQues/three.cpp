// Question 3: Inheritance
// 3. Create a base class Shape with a pure virtual function calculateArea(). Derive two classes Circle and Rectangle from Shape, and implement the virtual function in each derived class. Create objects of both derived classes and demonstrate polymorphism.
#include <bits/stdc++.h>
using namespace std;

class Shape { //base class
public:
    virtual double calculateArea() = 0; //aise hi initialize
};

class Circle : public Shape { //derived class
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double calculateArea() override { //overrided based on type of object
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double calculateArea() override {
        return length * width;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 3.0);

    Shape* shapes[] = {&circle, &rectangle}; //base class mera address of overriden classes rakha h
    for (Shape* shape : shapes) {
        cout << "Area: " << shape->calculateArea() << endl;
    }
    return 0;
}
//The Shape class is an abstract base class. It has a pure virtual function calculateArea() that is declared as virtual double calculateArea() = 0;. This makes Shape an abstract class because it cannot be instantiated directly; it's meant to be a base for other classes.