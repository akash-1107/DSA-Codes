#include <bits/stdc++.h>
using namespace std;

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

class Solution 
{ 
    public:
    int check(int arr[], int n, int mid,int m){
        int cnt = 1; //kitna student
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum +=arr[i];
            if(sum > mid){
                sum = arr[i];
                cnt++;
            }
        }
     if(m>=cnt) return 1; //more available jitta chahiye
     return 0;
    }

    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {   if(m>n) return -1; //sbko book nhi mil paega //students jada than books.
        int low = *max_element(arr,arr+n) ;
        int high = accumulate(arr,arr+n,high);;
        
       int ans = -1;
       for(int i = 0;i<n;i++){
           low = max(arr[i],low);
           high +=arr[i];
       } 
       while(low<=high){
           int mid = low + (high - low)/2;
           if(check(arr,n,mid,m)) {
               ans = mid;
               high = mid-1;
           }
           else {
               low  = mid+1;
           }
       }
    return ans;  
    }
};