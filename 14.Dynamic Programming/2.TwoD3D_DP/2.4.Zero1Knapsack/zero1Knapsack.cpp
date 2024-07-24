#include <bits/stdc++.h>
using namespace std;
// subset sum feel hi h , W = target type , ind = index of weight array  
// bss ek val[ind] extra har index se associated
//1.Memomized
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0]; //ek hi baar le skte element ko
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp); //ni liye
    
    int taken = INT_MIN; //maximize kro
    if( W - wt[ind]  >= 0 ) //kyuki ek index h 2-d matrix ka
        taken = val[ind] + knapsackUtil(wt,val,ind-1,W-wt[ind],dp); //le liye
        
    return dp[ind][W] = max(notTaken,taken);
}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
   //2.Tabulation
   vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    //jb W = 0  mtlb kch nhi aa skta toh vo hogya initialized
    for(int i=wt[0]; i<=W; i++){ //row 0 filling wt[0] ke baad wala sara hold kr skte
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){ //row 0 filled h
        for(int cap=0; cap<=W; cap++){ //weight 0 -> w pura fill krenge
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

//3.Space Optimized
int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<int> prev(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    //single array ko hi modify kr rhe 
    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    
    return prev[W];
}

int main() {

  vector<int> wt = {1,2,4,5};
  vector<int> val = {5,4,8,6};
  int W=5;
  
  int n = wt.size();
                                 
  cout<<knapsack(wt,val,n,W);
}