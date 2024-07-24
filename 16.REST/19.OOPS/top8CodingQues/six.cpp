// Question 8: Static Members
// 8. Implement a class Counter with a static variable count and static methods increment() and getValue(). Demonstrate the usage of static members to count the number of objects created.
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;

public:
    Counter() { //constructor
        count++;
    }

    static int getValue() {
        return count;
    }
};

int Counter::count = 0;//initialize static variable 

int main() {
    Counter c1, c2, c3;
    cout << "Number of objects: " << Counter::getValue() << endl; ///call static fxn
    return 0;
}
