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

// //1.Recursive
// int fxn(int n , vector<int>&arr){
//   if(n == 0) return arr[0]; //step1
//   int pick =  fxn(n-1 , arr) ; //ye wala nhi liye toh gye next
//   int notpick = arr[n] ; //corrected
//   if(n-2>=0) notpick += fxn(n-2,arr); //galti ye h ki agr n=1 hai toh sirf 1 element toh lenge na

//   return max(pick,notpick); 
// }

// int rob(vector<int>& arr) {
// int n = arr.size();
// return fxn(n-1,arr); //n-1 se 0 index jana
// }

// //2.Memomization
// int fxn(int n , vector<int>&arr , vector <int>&dp){
//   if(n == 0) return arr[0]; 
//   if(dp[n] != -1) return dp[n];
//   int pick =  fxn(n-1 , arr,dp) ;
//   int notpick = arr[n] ; 
//   if(n-2>=0) notpick += fxn(n-2,arr,dp); 

//   return  dp[n] =  max(pick,notpick); 
// }

// int rob(vector<int>& arr) {
// int n = arr.size();
// vector <int> dp(n,-1);
// return fxn(n-1,arr,dp); //n-1 se 0 index jana
// }

// //3.Tabulation
// int fxn(int n , vector<int>&arr , vector <int>&dp){
//   dp[0] = arr[0];
//   for (int i = 1; i < n; i++)
//   {
//     int pick =  dp[i-1] ;
//     int notpick = arr[i] ; 
//     if(i-2>=0) notpick += dp[i-2]; 

//     dp[i] =  max(pick,notpick);
//   }
  
//   return dp[n-1]; 
// }

// int rob(vector<int>& arr) {
// int n = arr.size();
// vector <int> dp(n,-1);
// return fxn(n,arr,dp); //n-1 se 0 index jana
// }

//4.Space Optimized

int fxn(vector<int> arr){
 int n = arr.size();
int prev2  = 0 ,prev = arr[0] , cur= 0;
  for (int i = 1; i < n; i++)
  {
    int pick =  prev ;
    int notpick = arr[i] ; 
    if(i-2>=0) notpick += prev2; 

    cur =  max(pick,notpick);
    prev2 = prev;
    prev = cur; 
  }
  
  return (long long int)prev;
}

int rob(vector<int>& arr) {
     vector<int> arr1;
    vector<int> arr2;
    int n = arr.size();
    if(n==1)
       return arr[0];
    
    for(int i=0; i<n; i++){

//This problem is a little tricky at first glance. However, if you have finished the House Robber problem, this problem can simply be decomposed into two House Robber problems.
// Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

// Rob houses 0 to n - 2;
// Rob houses 1 to n - 1.
        
        if(i!=0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }
    
    long long int ans1 = fxn(arr1);
    long long int ans2 = fxn(arr2);
    
    return max(ans1,ans2);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin>>n;
    vector <int> v(n,0);
    f(i,n) cin>>v[i];
    cout<<rob(v);
   

}
