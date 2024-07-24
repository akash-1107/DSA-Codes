#include <bits/stdc++.h>
using namespace std;

// Example 1:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

class Solution {
public:
    int check(vector<int>& bloom,int mid, int m, int k){
        int cnt = 0,flow = 0;
        for(int i = 0; i < bloom.size() ; i++){
         if(bloom[i] <= mid){
                    cnt++;
                if(cnt == k) {
                    flow++; //k flower se 1 bouqeut bana
                    cnt = 0; //ab cnt reset
                }
         }
         else {  //consequtive hi le skte bich me nhi khila hua h toh vo ni lenge
             cnt = 0;
         }
        }
        if(flow >= m) return 1; // 
        return 0;
    }


    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        //max element wala day pe sara phool khil jaega
        int low = 1 , high = *max_element(bloom.begin(),bloom.end()),ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(bloom, mid, m, k)){
               ans = mid;
               high = mid-1;
            }
        else {
            low = mid + 1;
        }
        } 
        return ans;
    }
};