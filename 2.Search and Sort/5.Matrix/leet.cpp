#include <bits/stdc++.h>
using namespace std;
//Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row
//pura O(mn) eleemnts sorted
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n = arr.size();
        int m = arr[0].size();
        //o(log(m*n)) me krna hai -->linear bs
        int low = 0,high = m*n -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid/m][mid%m] == x) return true;
            else if(arr[mid/m][mid%m] > x) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};