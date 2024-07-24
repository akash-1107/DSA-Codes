#include <bits/stdc++.h>
using namespace std;
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0; // WHICH index can max reach yaha se
        int reach = 0;
        for(int i = 0 ; i<n; i++){
           if(i>maxReach) { //aisa index jispe maxreach se v nhi pahuch skte
               return false;
           }
           reach = i + nums[i];  // current index se maximum index reach
           maxReach = max(maxReach,reach); // maximize
        }
        return true;
    }
};