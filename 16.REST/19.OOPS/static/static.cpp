// 1.Static Variables:
// A static variable is a variable that is shared among all instances of a class. It is declared using the static keyword. There's only one copy of a static variable regardless of how many instances of the class are created.

// 2.Static Methods:
// A static method is a method that belongs to the class rather than to instances of the class. It can be called using the class name directly, without creating an instance of the class. Static methods cannot access instance-specific data or methods, as they are not associated with any particular instance.

// 3.Static vs. Instance Members:

// Static Members:

// Shared across all instances of the class.
// Accessed using the class name.
// Cannot access instance-specific members.
// Useful for utility functions or attributes shared among all instances.
// Instance Members:

// Each instance has its own copy of instance members.
// Accessed using the instance name.
// Can access both static and instance members.
// Used for data and methods that are specific to individual instances.

#include <iostream>
using namespace std;

class Counter {
private:
    static int count; // Static variable

public:
    static int instances; // Static variable
    int id;

    Counter() {
        id = ++instances;
        count++;
    }

    static void displayCount() { // Static method
        cout << "Count: " << count << endl;
    }
};

int Counter::count = 0; // Initialize static variable
int Counter::instances = 0; // Initialize static variable

int main() {
    Counter obj1;
    Counter obj2;
    Counter obj3;

    Counter::displayCount(); // Access static method using class name

    cout << "Instance IDs: " << obj1.id << ", " << obj2.id << ", " << obj3.id << endl;

    return 0;
}
