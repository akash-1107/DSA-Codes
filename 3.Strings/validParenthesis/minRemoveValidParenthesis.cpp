#include <bits/stdc++.h>
using namespace std;

// Example 1:
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack <int> st;
        string ans = "";
        //i never push closing bracket in stack
        // i will push only indices of opening bracket or closing milte pe st.top se udda denge
        for(int i = 0;i<n;i++){
            char k = s[i];
            if(k=='(') st.push(i);
            else if(k==')'){
                if( st.size() && s[st.top()]=='(') st.pop();
                else {
                    s[i] = '#'; //agr stack top nhi h mtlb ye extra closing h need to be removed 
                }
            }
        }
        while(st.size()){
            s[st.top()] = '#'; //extra opening brackets
            st.pop();
        }
        for(auto &c :s){
            if(c != '#') ans.push_back(c); //last me sara extra ko hash kiye the hata diye
        }
        return ans;
    }
};