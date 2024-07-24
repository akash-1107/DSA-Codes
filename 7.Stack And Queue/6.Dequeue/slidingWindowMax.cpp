#include <bits/stdc++.h>
using namespace std;

// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {   //aage piche dono daal and remove kr skte
        deque<int> dq; 
        vector<int> ans;
        //front pe hmesha window ka max element ka index rakhte hai
        for (int i = 0; i < nums.size(); i++)
        {   
        //poping front element
        //agr jo max element tha abhi tak usko window paar kr liya h
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            
        //last element of deque agr chota h cur se toh vo useless h usko pop krke pheko
        //equal h toh rehne do
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

        //last me push it
            dq.push_back(i);
        
        //agr i>(window size) tb hi front element print kro
            if (i >= k - 1)
              ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};