#include <bits/stdc++.h>
using namespace std;
//row wise sorted only
//O(m+n) constant space approach but row wise sorted hona chahiye
class Solution {
public:
    #define f(i,n) for(int i = 0;i<n;i++)
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        // sort(mat.begin(),mat.end());
        int n = mat.size() , m = mat[0].size() , j =  m-1;
        int row = -1; //default row 0 as the answer
        int one  = 0;
    f(i,n){
        while(j >= 0 && mat[i][j] == 1){
            one = m - j;
            j--;
            row = i;
        }
    }
    return {row ,one};
    }
};