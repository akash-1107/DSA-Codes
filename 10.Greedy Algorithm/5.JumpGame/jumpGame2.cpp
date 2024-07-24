#include <bits/stdc++.h>
using namespace std;
// Input: nums = [2,3,1,1,4]
//[2,4,3,4,8]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

class Solution {
public:
    int jumpGame2(vector<int>& arr) {
     int n = arr.size();
     int minJump = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < arr.size()-1; i++)  //2nd last index tak hi check normal linear way 
    //AB yaha aagye toh bss curFarthest bss >= n-1 hoga toh kaam chal jayega
    {

        // Update 'curFarthest'.
        curFarthest = max(curFarthest, i + arr[i]); //har index pe ye kro

        if (i == curEnd) //basically 0 se jaha tak jaa skte usme koi v jump yaha aake cnt hoga
        {
            minJump++;

            // Update the farthest index reachable.
            curEnd = curFarthest;
        }
    }
//2nd last pe check ki last jaa skte ki nhi
    //If ImPossible to reach
    if(curFarthest < n-1) return -1;
   
    else return  minJump;;
    }
};