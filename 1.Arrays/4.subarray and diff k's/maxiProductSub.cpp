#include<bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=hnswaLJvr6g
// https://www.codingninjas.com/studio/problems/subarray-with-maximum-product_6890008?leftPanelTab=1
// brute force simple hi 
/*
optimised me 
1. basically total even -ves --> kch nhi krna
2. odd -ves toh 1 ve hatenge tb usko chor kr either prefix maxm product or suffix(dono even -ves)
3. zero milte hi sari chijen reset
final--> check sara prefix AND suffix product usme jo maximum ho vo ans */
int subMaxProduct(vector <int> &arr){
    int pre = 1,suff=1,ans=INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      if(pre == 0) pre = 1;
      if(suff == 0) suff = 1;

      pre = pre*arr[i];
      suff = suff*arr[n-i-1];
      ans = max(ans,max(pre,suff));
    }
    return ans;
}