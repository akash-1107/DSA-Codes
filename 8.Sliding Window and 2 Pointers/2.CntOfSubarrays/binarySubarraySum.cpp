#include <bits/stdc++.h>
using namespace std;
 int atmostSubarray(vector<int>&nums, int goal) //all subarray sum <= k
    {
        if(goal<0)
            return 0;
        int sum=0; // For calculating the current sum
        int i = 0 ,j = 0, ans = 0; // storing the ans
        while(j<nums.size())
        {
            sum+=nums[j]; 
            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
    // eg. [1,2,3] suppose k = 7 toh 2 pahuch ke {1,2} and {2} do chij add hoga na (1-0+1) 
            ans+=(j-i+1); 
    //basically i am including all subarrays containting that elemment must and left parts jaha tak i hai
            j++;
        }
        
        return ans;
    }
//basically atleast me hm bada vala part hatate hai and 
//atmost me hm chota wala hatate hai
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostSubarray(nums,goal)  //basically sum = k, k-1, k-2...0
        -atmostSubarray(nums,goal-1); //basically sum = k-1,k-2,...0
    }