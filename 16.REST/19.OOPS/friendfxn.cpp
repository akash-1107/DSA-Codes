//A friend function in C++ is a function that is not a member of a class but is granted access to the private and protected members of that class. It can access the private and protected members as if they were its own, without going through the usual member access mechanisms. 
#include <iostream>
using namespace std;

class Square {
private:
    int side;

public:
    Square(int _side) : side(_side) {}

    friend int calculateArea(const Square& square);
};

int calculateArea(const Square& square) {
    return square.side * square.side; // Accessing private member
}

int main() {
    Square mySquare(5);

    // Accessing private member using the friend function
    cout << "Area of the square: " << calculateArea(mySquare) << endl;

    return 0;
}
