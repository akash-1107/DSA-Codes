#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
//Two stacks maintain dono me index hi push krna
//ek stack for open bracket and ek for stars 
        stack<int> open,star;
        int len = s.length();
        
        for(int i=0; i<len ;++i)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else //close bracket
            {
                if(!open.empty()) //open se balance
                    open.pop();
                else if(!star.empty()) //star se balance
                    star.pop();
                else
                    return false; //false kyuki aage ka star se piche ka ) deal nhi ho skta
            }
        }
        
        //Now process leftover opening brackets
        while(!open.empty())
        {
            if(star.empty())
                return false;
            else if(open.top() < star.top()) //open wala apne baad wale * se hi balance ho skta
            {
                open.pop();
                star.pop();
            }
            else    //CASE: open.top() > star.top()
                return false;
        }
        return true;
    }
};