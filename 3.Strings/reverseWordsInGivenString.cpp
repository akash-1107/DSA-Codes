#include <bits/stdc++.h>
using namespace std;

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

class Solution {
public:
    string reverseWords(string t) {
        int m = t.length();
        char x = ' ';
        string s;
        int p=0, q=m-1;
        while(t[p]==x) p++;
        while(t[q]==x) q--;

         for(int i = p;i<=q;i++){
            if(t[i]==x){
                s += t[i];       //ek space lena hoga
           while(t[i]==x) i++;} //multispace hatana hoga na

           s += t[i];
           
         }

        int n = s.length();
        int i = 0;
        reverse(s.begin(),s.end());
        int start = 0;
        int e = n-1;
        
        while(i<n){
           if(s[i] == x){
               reverse(s.begin()+start,s.begin()+i); //har space pe reverse
               cout<<i<<" ";
               start = i+1;
           }
           i++;
        }
        reverse(s.begin()+start,s.end());
        return s;
    }
};