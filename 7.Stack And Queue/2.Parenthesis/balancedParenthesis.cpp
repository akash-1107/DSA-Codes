#include <bits/stdc++.h>
using namespace std;

// Input: s = "()[]{}"
// Output: true

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack <char> st;
        for(char d : s){
            if(d=='(' || d=='{' || d=='[') {
                st.push(d); //opening bracket push krdo stack me
            }
            else {
                char c = st.top(); //stack top wala closing bracket usi ka opening se match hona chahiye
                if(!st.empty() && ((c=='(' && d==')' )
                 || ( c=='{' && d=='}') || ( c=='[' && d==']')))
                {
                    st.pop(); 
                }
                else return false; //uss closing ke liye opening ni h
            }
        }
        return st.empty(); //stack empty h mtlb shi h balanced h
    }
};