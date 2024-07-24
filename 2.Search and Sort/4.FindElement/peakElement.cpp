#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 0;i<n;i++)
//chasing maximum value
//always a peak element
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int s = 0,e=n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if((mid==n-1 ||arr[mid]>=arr[mid+1] ) && (mid == 0 ||arr[mid]>=arr[mid-1])){
                return mid;
            }
        else if(arr[mid]<=arr[mid+1]){
          s = mid+1;//trace bigger 1
        }
        else{
          e = mid-1;
        }
   }
   
   return -1;
    }
};