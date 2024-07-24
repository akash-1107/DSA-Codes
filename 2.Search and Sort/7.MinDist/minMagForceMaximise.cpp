#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int>& pos, int mid,int m){
        int cnt = 1;
        int lastPlaced = pos[0];
        for(int i = 0 ; i < pos.size() ; i++){
           if(pos[i] >= (mid + lastPlaced)){
               cnt++;
               lastPlaced = pos[i];
           }
        } 
    if(cnt >= m) return 1;
    return 0 ;

    }

    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin() , pos.end());
        int low = 1 , high = pos[n-1] - pos[0], ans = 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(pos,mid,m)){
                ans = mid;
                low = mid +1;
            }
            else {
                high = mid-1;
            }
        }
    return ans;
    }
};