// https://takeuforward.org/data-structure/rotate-array-by-k-elements/
// https://leetcode.com/problems/rotate-array/

#include<bits/stdc++.h>
using namespace std;

// rotate left (mtlb start ka k elements at right (end))
// [1,2,3,4,5,6,7] k = 3 -->[4,5,6,7,1,2,3]
 void rotate(vector<int>& nums, int k) {
    k = (k % nums.size());
    reverse( nums.begin() , nums.begin() + k );
    reverse( nums.begin() + k , nums.end() );
    reverse( nums.begin() , nums.end() );
    }
// rotate right (mtlb last ka k elements at left (end))
// [1,2,3,4,5,6,7]  (k=3) --> [5,6,7,1,2,3,4]
// isme pura array ko pehle reverse krlo phir basically upar vala chij laga do
  void rotate(vector<int>& nums, int k) {
    k = (k % nums.size());
    reverse( nums.begin() , nums.end() );
    reverse( nums.begin() , nums.begin() + k );
    reverse( nums.begin() + k , nums.end() );
    }