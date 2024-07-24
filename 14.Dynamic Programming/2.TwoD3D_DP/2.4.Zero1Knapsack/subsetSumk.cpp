#include <bits/stdc++.h>
using namespace std;
#define lli             long long
#define f(i,x)          for(int i=0;i<(int)x;i++)
#define f1(i,x)         for(int i=1;i<=(int)x;i++)

int mod = (int)(1e9 + 7);
//1.Memomized
int fxn(vector<int> &arr, int indx , int target , vector<vector<int>>& dp) {
    //base case
    if(target == 0){
       return 1;
    }
    if(dp[indx][target] != -1) return dp[indx][target];
    int nottake = fxn(arr,indx-1,target,dp);
    int take = 0;
    if(arr[indx]<=target) take = fxn(arr,indx-1,target-arr[indx],dp);

    return dp[indx][target] = (take | nottake);
}


bool subsetSumToK(vector<int> &arr , int tar) {
   int n = arr.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    
    if(fxn(arr , n-1 , tar , dp) >0 ) return true;

    else return false;
}

// 2.Tabulation
bool findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken | taken); //bss OR krdo + ke jagah
        }
    }
    return dp[n-1][tar]; //can return int in bool
}
//3.SPACE OPTIMIZED
bool findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0),cur(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}







int main() {

  int n,k;  cin>>n>>k;
  vector<int> arr(n,0);
  f(i,n) cin>>arr[i];
                                 
  if(findWays(arr,k)) cout<<"yes"<<endl;
  else cout<<" no"<<endl;
}