#include <bits/stdc++.h>
using namespace std;
//s consists of English letters, digits, symbols and spaces. --> total 256 characters hogya  ascii wise 

  int lengthOfLongestSubstring(string s) {
       int n = s.size();
 unordered_map<int , int> mpp;
 int i = 0 , j = 0 , ans = 0;
 //use unoredeed_map only to deal with --> " "
 while(j<n){
    mpp[s[j] - 'a']++; //added to window
    
    while(mpp[s[j] - 'a'] > 1) //window kharab hogya h jth ke vajah se toh i se hata rhe thk krne ke liye
    {
       mpp[s[i] - 'a']--;
       i++;
    }
    
    ans = max(ans , j-i+1); //shi h window
    
    j++; //j will move full
 }

return ans;

}
