#include<bits/stdc++.h>
using namespace std;
// infinite buy and sell par pehle free krna hoga every buy ko by a sell
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for(int i = 0; i<n-1 ; i++){
        ans += max(prices[i+1] - prices[i],0); //jb v graph stline  and increasing hai]
        }
        return ans;
    }
};
// rest DP