// In object-oriented programming (OOP), an object is an instance of a class. A class defines a blueprint or template that describes the attributes (data members) and behaviors (methods) that objects created from that class will have. 

#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    
    void introduce() {
        cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
    }
};

int main() {
    // Creating objects from the Person class
    Person person1;
    person1.name = "Alice";
    person1.age = 30;
    
    Person person2;
    person2.name = "Bob";
    person2.age = 25;
    
    // Using methods on objects
    person1.introduce();
    person2.introduce();
    
    return 0;
}
//In this example, we've defined a Person class with attributes (name and age) and a method (introduce). In the main function, we create two objects, person1 and person2, from the Person class. Each object has its own set of attributes and can invoke methods defined in the class.

// When we call the introduce method on person1 and person2, they print out their respective names and ages.