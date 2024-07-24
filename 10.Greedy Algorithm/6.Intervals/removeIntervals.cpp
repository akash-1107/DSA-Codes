#include <bits/stdc++.h>
using namespace std;

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]] 
//[1,2] and [2,3] are considered non - overlapping
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());//Sort all intervals in ASC order a/c to first value
        int count = 0; //Count of number of intervals to be removed
        int n = intervals.size(); //No of intervals
        int left = 0;   //left interval(pointer to maintain for left comparison)
        int right = 1;  //right interval(pointer to maintain for right comparison)
        
        while(right<n)  //Unless all intervals are compared
        {
            if(intervals[left][1] <= intervals[right][0])   //Non-overlapping case
            {
                left = right;
                right+=1;
            }
            //***upar wala if se niche aa gya h mtlb  (intervals[left][1] > intervals[right][0]) hai
            else if(intervals[left][1]<=intervals[right][1])    //Overlapping case-1 (Remove right interval)(basically right pe jo hai uska end point bada  hai isiliye usko hata rhe)
            {
                count+=1;       //Delete right
                right+=1;
            }
            else if(intervals[left][1]>intervals[right][1])     //Overlapping case-2 (Remove left interval)(basically left wala ka endpoint bada hai iss baar toh usko hata diye)
            {
                count+=1;
                left = right;
                right+=1;
            }
        }
        
        return count;
    }
};