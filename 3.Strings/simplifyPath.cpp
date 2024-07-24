#include <bits/stdc++.h>
using namespace std;
// Example 1:
// Input: path = "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory name.

// Example 2:
// Input: path = "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

// Example 3:
// Input: path = "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.


class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        
        for(int i = 0;  i<path.size(); ++i)
        {
            if(path[i] == '/') continue;  //first slash ko continue krna hai jbtak next slash naa aye or uske bich ka directory name na mil jaye becoz do slash ke bich 
            // . ->vhi rho
            // .. ->previous directory pe jao
            // kch v or -> mtlb vo directory h stack me push kro taki latest kon h pta rhe

            string temp; //store current do slash ke bich ka directory
			// iterate till we doesn't encounter / 
            while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }

//ab temp me current directory aa gya
            if(temp == ".")
                continue; // kch nhi vhi rho
			
            else if(temp == "..") // pop the top element from stack if exists taki piche jaa ske
            {
                if(!st.empty())
                    st.pop();  //bss hata diye top wale ko jaise vo kbhi aaya hi nhi
            }
            else //kch or tha
                st.push(temp);
        }
        
		// adding all the stack elements to res
        while(!st.empty())
        {  //aisa Kyuki hmko niche se stack elements chahiye
            res = "/" + st.top() + res; // s1+s2 direct kr skte string me wah 
            st.pop();
        }
        
		// if no directory or file is present
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};