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

int mod = (int)(1e9 + 7);

// 1.Memomized
int fxn(vector<int> &arr, int indx , int target , vector<vector<int>>& dp) {
    //base case
    if(indx == 0){
       if(target == 0 && arr[0] == 0) return 2; //ans me +
       if(target == 0 || target == arr[0]) return 1;//ans me +
       //no contri
       return 0; //hm generalise kr rhe ki last index pe hi ans nikale  
    }
    if(dp[indx][target] != -1) return dp[indx][target];
    int nottake = fxn(arr,indx-1,target,dp);
    int take = 0;
    if(arr[indx]<=target) take = fxn(arr,indx-1,target-arr[indx],dp);

    return dp[indx][target] = (take + nottake)% mod;
}

int findWays(vector<int> &arr, int target){
     int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return fxn(arr , n-1 , target , dp);
}

// 2.Tabulation
int findWays(vector<int> &num, int tar){
     int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  //2 cases pick and not pick
    else dp[0][0] = 1;  // 1 case not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}
//3.Space Optimized 1 
int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
   
    for(int ind = 1; ind<n; ind++){
         vector<int> cur(tar+1,0);
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

//3.SPACE OPTIMIZED 2
// int findWays(vector<int> &num, int tar){
//      int n = num.size();
// //single array optimization
//     vector<int> prev(tar+1,0);
    
//     if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
//     else prev[0] = 1;  // 1 case - not pick
    
//     if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
//     for(int ind = 1; ind<n; ind++){
//         for(int target= tar; target>=0; target--){ //bss yaha ulta fill krne se kaam ho jayega
//           //wow only prev use krke ans mil jaa rha har baar  
//             int notTaken = prev[target];
    
//             int taken = 0;
//                 if(num[ind]<=target)
//                     taken = prev[target-num[ind]];
        
//             prev[target]= (notTaken + taken)%mod;
//         }
//         // prev = cur;
//     }
//     return prev[tar];
// }


int main() {
  int n,k;  cin>>n>>k;
  vector<int> arr(n,0);
  f(i,n) cin>>arr[i];
                                 
  cout<<findWays(arr,k)<<endl;
}