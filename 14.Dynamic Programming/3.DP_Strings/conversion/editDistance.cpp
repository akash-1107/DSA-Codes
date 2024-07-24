#include <bits/stdc++.h>
using namespace std;
// macros
#define lli long long
#define f(i, x) for (int i = 0; i < (int)x; i++)
#define f1(i, x) for (int i = 1; i <= (int)x; i++)
#define rep(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define yes() cout << "YES" << endl
#define no() cout << "NO" << endl
#define all(arr) arr.begin(), arr.end()
#define print(arr)   for (auto &i : arr)  cout << i << " "
//hmko s1 ko s2 banana h
/* min(
1.insert kiye s1 me (i,j-1) (j match hogya) ,
2.delete kiye s1 me (i-1,j) (j match nhi hua) ,
3.replace kr diye s1 me (i-1 , j-1) (match)
)
*/

// //1.memomize (0 based)
// int fxn(string &s1, string &s2 ,int i , int j,vector<vector<int>> &dp ){
// //base case
// //s1 exhaust
// if(i<0) return j+1; //s2 me jitta bacha h vo add krna hoga s1 me
// //s2 Exhaust
// if(j<0) return i+1; //s1 me jitta bhi bacha h usko delete krna hoga
// //agr dusra v sath me exhaust hai tb bhi -1+1 = 0 hi toh return ho rha dikkat nhi h
// if(dp[i][j] != -1) return dp[i][j];
// if(s1[i] == s2[j]){
//     return dp[i][j] =  0 + fxn(s1,s2 , i-1,j-1,dp); 
// }
// else {
//    return dp[i][j] = 1 + min(fxn(s1,s2 , i-1,j-1,dp) , min(fxn(s1,s2 , i-1,j,dp),fxn(s1,s2 , i,j-1,dp)));
// }


// return 0;
// }

// int minDistance(string s1, string s2) {
// int n = s1.length(), m =s2.length(); 
// vector<vector<int>> dp(n,vector<int>(m , -1));
// return fxn( s1, s2 ,n-1,m-1,dp);
        
// }


//2.Tabulation (origin shift as -1 index not possible for base case) i ->i-1 (-1 = 0) or 1base indexing
// int minDistance(string s1, string s2) {
// int n = s1.length(), m =s2.length(); 
// vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
// for (int i = 0; i <= n; i++) //yaha 0 mtlb dusra string empty , n mtlb last index
// {
//    dp[i][0] = i;  //basically yaha x cordinate dusra string ka len vhi ans hoga jb ye exhausted
// }
// for (int j = 0; j <= m; j++)
// {
//    dp[0][j] = j; 
// }
// for (int i = 1; i <= n; i++)
// {
//   for (int j = 1; j <= m; j++)
//   {
// if(s1[i-1] == s2[j-1]){
//  dp[i][j] =  0 + dp[i-1][j-1]; 
// }
// else {
//  dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i-1][j],dp[i][j-1]));
// }

//   }
  
// }

//   return dp[n][m] ;     
// }

//3.Space Optimized
int minDistance(string s1, string s2) {
int n = s1.length(), m =s2.length(); 
if(n==0 || m==0) return m + n; //exta to deal with empty strings
vector <int> prev(m+1,0) , cur (m+1,0);
// for (int i = 0; i <= n; i++) //yaha 0 mtlb dusra string empty , n mtlb last index
// {
//    dp[i][0] = i;  //basically yaha x cordinate dusra string ka len vhi ans hoga jb ye exhausted
// }

for (int j = 0; j <= m; j++)
{
   prev[j] = j; //row 0 i need to initailize it only
}
prev[0] = 0;//i=0

for (int i = 1; i <= n; i++)
{ //first member of cur row i.e column here krenge initailize equal to zero nhi balki row number
  cur[0] = i;
  for (int j = 1; j <= m; j++)
  {
if(s1[i-1] == s2[j-1]){
 cur[j] =  0 + prev[j-1]; 
}
else {
 cur[j] = 1 + min(prev[j-1] , min(prev[j],cur[j-1]));
}

  }
  prev = cur;
  
}

  return cur[m] ;     
}







int main() {

  string s1 = "";
  string s2 = "r";

  cout<<minDistance(s1,s2);
}
