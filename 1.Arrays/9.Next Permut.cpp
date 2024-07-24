#include<bits/stdc++.h>

using namespace std;
/*
brute force O(N!*N)
using Swaps
https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/#
https://leetcode.com/problems/permutations/solutions/1257633/backtracking-solution-c-easy-to-understand-with-explanation/
class Solution {
public:
    vector<vector<int>> result;
    
    // Backtracking
    void permutation(vector<int> &nums,int i,int n){
        if(i==n){
            result.push_back(nums);
            return ;
        }

        for(int j=i;j<=n;j++){
            swap( nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap( nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permutation(nums,0,nums.size()-1);
        
        return result;
    }
};
result me given ko search krke uske previous vale ko return krdo
*/

/*



optimesd version-
O(3*N)
https://leetcode.com/problems/next-permutation/*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int  index = -1; 
        // taki jb naa mile koi index tb reverse pura array ho +1-1 ==0  krde
        // first time jaha chota aage --> yaha se permu mil jayega  
        // 1,2 ,3,4  --> 1,2,4,3
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i; 
                break;
            }
        }
//piche se pehla greater element hi aayega aage        
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
// index shi ho chuka hai ab aage sara dec order me aa gya hai reverse krke inc kr do
        reverse(nums.begin() + index + 1, nums.end());
    }
}; 


