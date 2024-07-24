//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
//basically kch flip nhi krna hai simply window me --> maximum k zeros ho skta baki sb 1 hoga 

//same as no repeat wala
#include <bits/stdc++.h>
using namespace std;

 int longestOnes(vector<int>& arr, int k) {
    int n = arr.size();
    int i=0, j = 0 , ans = 0;  
    int zeroCnt = 0;
    while(j<n){
    if(arr[j] == 0) zeroCnt++;

    while(zeroCnt > k){
        if(arr[i] == 0) zeroCnt--;
        i++;
    }

    ans = max(ans , j-i+1);
    j++;
    }

    return ans;
}