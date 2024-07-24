#include <bits/stdc++.h>
using namespace std;
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


class Solution {
public:
   int romanToInt(string s) 
{   int n = s.size();
    unordered_map<char, int> map = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = map[s[n-1]]; //last value ka value lena hi h
   for (int i = n - 2; i >= 0; --i) 
   {
       if (map[s[i]] < map[s[i + 1]])  //small-->large --> minus wala case (IV)
       {
           sum -= map[s[i]];
       }
       else  //large->small -->normal case (VI)
       {
           sum += map[s[i]];
       }
   }
   
   return sum;
}
};