#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//binary subarray problem hi hai bss odd = 1 krdo and even = 0

 int atmostSubarray(vector<int>&nums, int goal)
    {
        if(goal<0)
            return 0;
        int sum=0; // For calculating the current sum
        int i=0;
        int j=0;
        int res=0; // storing the res
        while(j<nums.size())
        {
           
            sum+=nums[j]; 

            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            //this is the length of each subarray 
            res+=(j-i+1); //basically ye subaaray se itna subarrays generate hoga and sbka sum kam hi hoga na obviously
            
            j++;
        }
        
        return res;
    }
//basically atleast me hm bada vala part hatate hai and 
//atmost me hm chota wala hatate hai
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostSubarray(nums,goal)  //basically sum = k, k-1, k-2...0
        -atmostSubarray(nums,goal-1); //basically sum = k-1,k-2,...0
    }


    int numberOfSubarrays(vector<int>& nums, int goal) {
        for(int i =0;i<nums.size();i++){
        if(nums[i] & 1) nums[i] = 1;
        else nums[i] = 0;
        }
        return atmostSubarray(nums,goal)  //basically sum = k, k-1, k-2...0
        -atmostSubarray(nums,goal-1); //basically sum = k-1,k-2,...0

    }
};