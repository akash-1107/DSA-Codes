#include <bits/stdc++.h>
using namespace std;

// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

class Solution {
public:
   bool isValid(string k,int i,int j){
    int n = k.length();
    while(i<j){
        if(k[i]==k[j]) i++,j--;
        else return false;
    }
    return true;
   }

    bool validPalindrome(string s) {
        int n = s.length();
    int i = 0,j=n-1;
    while(i<j){
        if(s[i]==s[j]) i++,j--;
        else{
         if(isValid(s,i+1,j) || isValid(s,i,j-1)) return true;
         else return false;
        }
    }
    return true;
        
    } 

   
};


