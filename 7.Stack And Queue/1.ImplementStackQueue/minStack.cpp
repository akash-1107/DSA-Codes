#include <bits/stdc++.h>
using namespace std;
// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 
class MinStack {
public:
    MinStack(){}  //constructor
private:
    stack<int> s1;    
    stack<int> s2; //for containing duplicates min value at top of S2
public:
    void push(int x) {
	s1.push(x);  //normal element push krenge hi har baar
	if(s2.empty() || x<=s2.top()) s2.push(x); //har baar agr vo s2 ke top wale se chota hai toh push in s2   
    }

    void pop() {
	if(s1.top()==s2.top()) s2.pop(); //s2 ka top minimum tha agr vo s1 se out toh s2 se v bahar krna hoga na
	s1.pop();
    }

    int top() { //normal stack ka top 
	    return s1.top();
    }
    
    int getMin() { //special method to get cur min
	    return s2.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */