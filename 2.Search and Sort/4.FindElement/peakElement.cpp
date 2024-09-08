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




//

		if(nums.length == 1) return 0; // single element
        
        int n = nums.length;
        
		// check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
		
		// search in the remaining array
        int start = 1;
        int end = n-2;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] < nums[mid-1]) end = mid - 1;
            else if(nums[mid] < nums[mid+1]) start = mid + 1;
        }
        return -1; // dummy return statement