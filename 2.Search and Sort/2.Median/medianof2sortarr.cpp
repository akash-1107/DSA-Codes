

#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 0;i<n;i++)

 class Solution {
public:
   double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size() , m = arr2.size();
    if(n>m) findMedianSortedArrays(arr2,arr1);
       int k = (m+n+1)/2; //odd ke liye kth (total + 1 )/2 wala

       int low = max(0,k-m) , high = min(k,n);
       while(low<=high){
       int cnt1 = low + (high - low)/2;
       int cnt2 = k-cnt1;
       int l1 = (cnt1 == 0)? INT_MIN : arr1[cnt1-1];
       int l2 = (cnt2 == 0)? INT_MIN : arr2[cnt2-1];
       int r1 = (cnt1 == n)? INT_MAX : arr1[cnt1];
       int r2 = (cnt2 == m)? INT_MAX : arr2[cnt2];
       if(l1<=r2 && l2<=r1) {
         if((n+m) & 1 )return 1.0*max(l1,l2); //odd
         else {
            return( ( max(l1,l2) + min(r1,r2) )/2.0); //even
         }
       }
       else if(l1>r2){
             high = cnt1-1;
       }
       else {
            low = cnt1 +1;
       }
       }
    return 0.0;
    }
};