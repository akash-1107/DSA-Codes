// https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& arr) {
      int n = arr.size();
      int l = 0,h = n-1,mid =0;
      while(mid<=h) { // becoz mid and high swap krne ka mtlb ni 
       //par mid and low swap mtlb 
       // {0,1,2,1,0,2} -> {0,0,1,1,2,2}
      switch(arr[mid]){
          case 0 :swap(arr[l++],arr[mid++]) ;
                  break;
          case 1 : mid++;
                  break;
          case 2 :swap(arr[mid],arr[h--]) ;
                  break;
      }



      } 
    }
};