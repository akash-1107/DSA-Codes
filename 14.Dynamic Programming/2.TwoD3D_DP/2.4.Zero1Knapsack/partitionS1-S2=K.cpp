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

//3.SPACE OPTIMIZED
int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0),cur(tar+1,0);;
    
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

 int findTargetSumWays(vector<int>& arr, int d) {
          int totSum = 0;
          int n = arr.size();
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
    return findWays(arr,(totSum-d)/2);;
    }


int main() {
  int n,k;  cin>>n>>k;
  vector<int> arr(n,0);
  f(i,n) cin>>arr[i];
                                 
  cout<<findTargetSumWays(arr,k)<<endl;
}