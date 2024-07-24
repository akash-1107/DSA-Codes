#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check (vector<int>& piles,int mid, int h){
        long long hrs = 0; //10^9 ho array elements and sum kr rhe tb dikkat ho jata hai
        for(int i = 0 ; i<piles.size(); i++){
            hrs += ceil(piles[i]/(1.0*mid));  //m-1
            // cout<<bool(piles[i]%mid >0)<<endl; // m-2 of ceil
        }
        if(h>=hrs) return 1; //h se kam me khale
        return 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1 , high = *max_element(piles.begin(),piles.end()) , k = 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(piles,mid,h)){
              k = mid;
              high = mid-1;
            }
            else{
              low = mid+1;
            }
        }
    return k;    
    }
};