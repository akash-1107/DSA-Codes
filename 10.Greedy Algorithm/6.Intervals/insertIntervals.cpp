#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newEnd) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i<n ; i++){
          vector <int> end = arr[i];
          
          //push hoga end kyuki vo newEnd se chota h pura
           if(end[1] < newEnd[0]){
              ans.push_back(end);
          }
          //push hoga newEnd kyuki vo chota hai end se and end ab newEnd ho jayega
          else if(newEnd[1] < end[0]){
              ans.push_back(newEnd);
              newEnd = end;
          }
          //overlap case
          //merge hoke newEnd -> new newEnd aayega and kuch bhi push nhi hoga
          //isme dikkat hai next do case mera edge cases h usko upar krke isko niche krna hoga
           else if(end[1] >= newEnd[0]){
              newEnd[0] = min(newEnd[0] , end[0]);
              newEnd[1] = max(newEnd[1] , end[1]);
          }
        }
    ans.push_back(newEnd);
    return ans;
    }
};