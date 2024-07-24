// Question 2: Constructors and Destructors
// 2. Create a class Rectangle with private attributes length and width. Implement constructors to initialize these attributes, and a destructor to display a message when an object is destroyed. Create and manipulate objects of this class.
#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {
        cout << "Rectangle created." << endl; //any message u want to display on creation 
    }

    ~Rectangle() {
        cout << "Rectangle destroyed." << endl;
    }
};
//In Solution 2, where we're dealing with constructors and destructors for the Rectangle class, the object is destroyed at the end of its scope, which typically means when it goes out of scope or when the program execution leaves the block where the object was defined.
int main() {
    Rectangle rect(5.0, 3.0);
    return 0;
}
