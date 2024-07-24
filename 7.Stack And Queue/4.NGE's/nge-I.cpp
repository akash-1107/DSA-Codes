#include <bits/stdc++.h>
using namespace std;

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr, vector<int>& brr) {
        int n  = arr.size();
        //n<=m always
        int m  =  brr.size(); 
        //storing nges
        vector <int> ans;
        unordered_map <int,int> mp;
        stack <int> st;
        for(int i = m-1;i>=0;i--){ 
            //last se chalu kro becoz for every element uske baad ka bada elements chahiye in stack
            //so kisi element ko process krne se pehle uske baad wala sara elements process krna padta h
            //simply brr array ka pura nge nikal ke map me store
            int x = brr[i];  
            //st.top chota hai toh vo useless pop it kyuki kch bada mil gya
            while(!st.empty() && st.top()<=x ) st.pop(); 
            
            if(st.empty()) mp[x] = -1; //no nge for that element

            else mp[x] = st.top();
            //har baar push hoga hi
            st.push(x); 
        }
        
        for(auto &i : arr){
            //map me se arr wala only nikal liye
            ans.push_back(mp[i]); 
        }
        
    return ans;
    }
};