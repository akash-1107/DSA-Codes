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

//1.Recusive
int climb(int index) {
  //base
  if(index == 0) return 1; //pahuch gye 
  int one = 0 , two = 0;
  one = climb(index-1);
  if(index-2 >= 0) two = climb(index-2);

return one + two;//cnt all possible ways

}


//2.Memomized or top-down approach
int fxn(int index , vector <int>& dp){
if(index == 0) return 1;
if(dp[index] != -1)  return dp[index];
      int one = 0 , two = 0;
      one = fxn(index-1,dp);
      if(index-1 > 0) two = fxn(index-2,dp);

return dp[index] = one + two;
}

int climbStairs(int n) {
  vector <int>dp(n+1,-1); 
  return fxn(n,dp);
}


// 3.Bottom-Up or Tabulation
int climbStairs(int n) {
  vector <int> dp(n+1,-1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  { 
    int one = 0 , two = 0;
      one = dp[i-1];
      if(i-2>=0) two = dp[i-2];

      dp[i] = one + two;
  }
  
  return dp[n];
}

//4.Space Optimization -->only when i-1 and i-2 terms present
int climbStairs(int n) {
  int prev2 = 0;
  int prev = 1; //base case
  int cur = 0;
  for (int i = 1; i <= n; i++)
  { 
    cur = prev + prev2;
    prev2 = prev;
    prev = cur;
  }
  
  return prev;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin>>n;
    cout<<climbStairs(n);
   

}
