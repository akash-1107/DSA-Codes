// Question 9: Operator Overloading
// 9. Create a class Complex to represent complex numbers. Overload the + and - operators to perform complex number addition and subtraction. Provide a method to display the complex number in the form "a + bi"
#include <iostream>
using namespace std;
//this keyword(no sense here aise hi bta rhe bss)
// Using this to distinguish between the attribute and parameter
class Complex {
private:
    double real, imaginary;

public:
    Complex(double r, double i) : real(r), imaginary(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    Complex num1(3.0, 2.0);
    Complex num2(1.5, 4.0);

    Complex sum = num1 + num2;
    Complex diff = num1 - num2;

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    return 0;
}
