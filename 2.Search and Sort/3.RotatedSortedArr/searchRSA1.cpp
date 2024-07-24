#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
         int start = 0,end=n-1;
          while(start<=end){
           int mid = start + (end-start)/2;
           if(arr[mid] == x) return mid;
           else if(arr[start]<=arr[mid]) { //sorted part at left //unsorted part at right
           // can apply binary search only on sorted array
           if(arr[start]<=x && arr[mid]>=x) {
               end = mid-1;
           }
           else {
            start = mid + 1;
           }
           }
           else{  //sorted part at right
               if(arr[mid]<=x && x<=arr[end]) {
               start = mid+1;
           }
           else {
            end = mid - 1;
           }
           }
         }
        return -1;
    }
};