// Question 1: Class and Object Basics
// Define a class named Person with private attributes name and age, and a public method displayInfo() that prints out the name and age of the person. Create an object of this class and demonstrate its usage.
#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string _name, int _age) : name(_name), age(_age) {} //constructor

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person person1("Alice", 25); //initialize object using constructor
    person1.displayInfo();
    return 0;
}