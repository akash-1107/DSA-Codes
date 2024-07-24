#include<bits/stdc++.h>
using namespace std;
//macros
#define lli             long long
#define f(i,x)          for(int i=0;i<(int)x;i++)
#define f1(i,x)         for(int i=1;i<=(int)x;i++)
#define rep(i,a,b)      for(int i=(int)a;i<=(int)b;i++)      
#define yes()           cout<<"YES"<<endl 
#define no()            cout<<"NO"<<endl
#define all(arr)        arr.begin(),arr.end()
#define print(arr)      for(auto &i:arr) cout<<i<<" "

//2.Memomized
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      //yaha jump ko zero se and can manipulate so direct int
      int jump = solveUtil(ind-j, height, dp, k) + abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps); 
        }
    }
    return dp[ind]= mmSteps;
    
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n,-1);
    return solveUtil(n-1, height, dp, k);
}

//3.Tabulation
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n,-1);
    return solveUtil(n, height, dp, k);
}
//yaha only i-1 and i-2 nhi h or bhi h isiliye space optimize nhi kr skte

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , k ; cin>>n>>k;
    vector <int> height(n);
    f(i,n) cin>>height[i];
    // print(height);
    cout<<minimizeCost(n,k,height);
   

}
