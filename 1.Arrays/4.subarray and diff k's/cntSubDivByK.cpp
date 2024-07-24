#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> m;
        int curr_sum = 0,cnt=0;
        m[0] = 1;   //std method -->basically divisible wala
        for(int i= 0; i<n ; i++){
        curr_sum += nums[i];
        int r = (curr_sum)%k;
        if(r<0) r+=k;
     
        if(m.find(r) != m.end()) {
            cnt += m[r];
        }
        // cout<<-5%4<<endl;-->iska ans -1 so add krna padega

        //map
        m[r]++;

        }
        return cnt;
    }
};