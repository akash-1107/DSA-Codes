
#include <bits/stdc++.h>
using namespace std;
//vector <string> = 2-D array of characters 
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

class Solution {
    #define f(i,n) for(int i = 0;i<n;i++)
    #define rep(a,j,b) for(int j = a;j<=b;j++)
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        string ans = "";
        int minSize = str[0].size();
        for(int i = 1;i<n;i++){
            if(minSize>str[i].size())
            minSize = str[i].size(); //minimum size of all strings hi max length of common prefix ho skta h
        }
        int currCol = 0;
        f(i,minSize){ //sara columns min size tak ke liye
             currCol = str[0][i]; //ye pehla row ka
             rep(1,j,n-1){
                 int currRow = str[j][i];
                 if(currRow != currCol){ //compare to rest rows
                     return ans;
                 }
                
             }
             ans.push_back(currCol);
        }
        
     return ans;   
    }
};