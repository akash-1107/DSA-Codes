// Question 4: Polymorphism
// 4. Define a base class Animal with a virtual function makeSound(). Derive classes Dog, Cat, and Cow from Animal, and override the makeSound() function in each derived class to produce an appropriate sound. Create an array of Animal pointers and call makeSound() on each element.
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(){}
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(){}
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

class Cow : public Animal {
public:
    void makeSound() override {
        cout << "Moo!" << endl;
    }
};

int main() {
   Animal* d = new Dog ;
    Cat c;
    Cow co;
    Animal* animals[] = {d, &c, &co};

    for (Animal* animal : animals) {
        animal->makeSound();
    }
    return 0;
}
