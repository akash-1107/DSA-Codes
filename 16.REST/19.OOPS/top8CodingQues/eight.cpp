#include <iostream>
using namespace std;

template <typename T> //data type
class Stack {
private:
    T data[100];
    int top;

public:
    Stack(){
        top = -1;
    }
    //push
    void push(T item) {
        if (top < 99) {
            data[++top] = item;
        } else {
            cout << "Stack overflow." << endl;
        }
    }
    //pop
    T pop() {
        if (top >= 0) {
            return data[top--];
        } else {
            cout << "Stack underflow." << endl;
            return T(); // Return default value for type T
        }
    }

    T topValue() {
        if (top >= 0) {
            return data[top];
        } else {
            cout << "Stack is empty." << endl;
            return T(); // Return default value for type T
        }
    }
};

int main() {
    Stack<int> intStack;
    Stack<double> doubleStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Popped value from intStack: " << intStack.pop() << endl;

    doubleStack.push(3.14);
    doubleStack.push(2.71);

    cout << "Top value of doubleStack: " << doubleStack.topValue() << endl;

    return 0;
}
