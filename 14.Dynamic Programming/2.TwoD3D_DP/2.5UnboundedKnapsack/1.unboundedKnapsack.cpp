#include <bits/stdc++.h>

using namespace std;
//sinle array space optimized
int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<int> prev(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int)i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
        // prev = cur;❌
    }
    
    return prev[W];

}

int main() {

  vector<int> wt = {2,4,6};
  vector<int> val = {5,11,13};
  int W=10;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<unboundedKnapsack
  (n,W,val,wt);
}