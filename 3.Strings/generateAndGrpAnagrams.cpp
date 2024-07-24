#include <bits/stdc++.h>
using namespace std;

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        int n = arr.size();
        map <string,vector<string>> ans; //map ka key sorted basic string hoga har baar
        vector<vector<string>> final;
        for(auto &i : arr){
            string s = i; //isko sort krne ke liye use
            string t = i; //ye original ko map me push krne ke
            sort(s.begin(),s.end());
            if(ans.find(s) != ans.end()){
                ans[s].push_back(t);
            }
            else{
                ans[s].push_back(t);
            }
        }
        for(auto &m :ans){
            final.push_back(m.second);
        }
        return final;
    }
};