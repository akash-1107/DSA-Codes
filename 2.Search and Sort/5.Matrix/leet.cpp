#include <bits/stdc++.h>
using namespace std;
//row and col both wise sorted
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