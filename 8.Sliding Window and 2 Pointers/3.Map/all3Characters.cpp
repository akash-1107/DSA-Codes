#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
        // O(N) time , O(1) space [because hasmap size is always 3]
        int i = 0 , j = 0 , n = s.size();
        unordered_map<char,int> map;
        
        int count = 0;
        
        while(j != s.size())
        {
            map[s[j]]++; 

            while(map['a'] and map['b'] and map['c'])
            {
            //start wala lene ke liye hm (j - i +1) 
                count += 1 + (n - 1 - j); //n-1-j end wala sara lena hai including ye character
             
			// removing first element[means shrinking window from front to form new window] abhi bhi shi h
                map[s[i]]--; 
                i++;
            }
            
            j++;
        }
        return count;
    }