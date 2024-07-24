#include <bits/stdc++.h>
using namespace std;
int allStars(string& p , int j){
    for (int i = 0; i <= j; i++)
    {
        if(p[i] != '*')  return 0;
    }
return 1; 
}
// //s1 ko given pattern se match krna hai

// // '?' Matches any single character.  character match ka 2 way -> ? or s1[i] = s2[j]
// //mismatch hai and * hai ->(i-1 , j)(star = empty sequence) OR (i,j-1) (* ek ek karke j ka letter ka barabari)
// // -->or le ek baar v true ho jaye toh shi
// //mismatch and not  *  ->tb nhi ho payega
// // '*' Matches any sequence of characters (including the empty sequence).

// //0->false and 1->true
// int fxn(string& s, string& p , int i , int j ,vector <vector<int>>& dp){
// //base case
// //s1 exhausted and s2 bhi exhausted -->true;
// if(i<0 && j<0)  return 1;
// if(i<0 && j>=0) {
// //sara bacha hua i me *** only toh shi h sbkch
// if(allStars(p,j)) return 1;
// return 0;
// }
// if(i>=0 && j<0) return 0;

// if(dp[i][j] != -1) return dp[i][j];
// if(s[i] == p[j] || p[j] == '?' ){
//     return dp[i][j] = fxn(s,p,i-1,j-1,dp);
// }
// else{

// if(p[j] == '*'){
//     return dp[i][j] = ( fxn(s,p,i-1,j,dp) ||  fxn(s,p,i,j-1,dp) );
// }

// else{
//      return dp[i][j] = 0;
// }
// }
// return 0;
// }
// //2.Tabulation
// bool isMatch(string s, string p) {
//     int n = s.length() , m = p.length();
//     vector <vector<int>> dp(n+1,vector<int>(m+1,0));
//     dp[0][0] = 1;
//     for (int i = 1; i <=n; i++)
//     {
//       dp[i][0] = 0;
//     }
//     for (int i = 1; i <=m; i++)
//     {
//         if(allStars(p,i-1)) dp[0][i] = 1; //yaha i-1 krna hoga
//         else dp[0][i] = 0;
//     }
// for (int i = 1; i <=n; i++)
// {
//   for (int j = 1; j <= m; j++)
// {
//     if(s[i-1] == p[j-1] || p[j-1] == '?' ){
//      dp[i][j] = dp[i-1][j-1];
//     }
//     else{

//     if(p[j-1] == '*'){
//     dp[i][j] = ( dp[i-1][j] ||  dp[i][j-1] );
//     }

//     else{
//       dp[i][j] = 0;
//     }
//    }

// }
  
// }

// return dp[n][m];       
// }
//3.space optimized
//2.Tabulation
bool isMatch(string s, string p) {
    int n = s.length() , m = p.length();
    vector<int> prev(m+1,0) ,cur(m+1,0);
    prev[0] = 1;
    // for (int i = 1; i <=n; i++)
    // {
    //   dp[i][0] = 0;
    // }
    for (int i = 1; i <=m; i++) //row zero
    {
        if(allStars(p,i-1)) prev[i] = 1; //yaha i-1 krna hoga
        else prev[i] = 0;
    }
for (int i = 1; i <=n; i++)
{ cur[0] = 0;
  for (int j = 1; j <= m; j++)
{
    if(s[i-1] == p[j-1] || p[j-1] == '?' ){
     cur[j] = prev[j-1];
    }
    else{

    if(p[j-1] == '*'){
    cur[j] = ( prev[j] ||  cur[j-1] );
    }

    else{
      cur[j] = 0;
    }
   }
}
prev = cur; 
}

return prev[m];       
}


int main() {

  string s,p; cin>>s>>p;

  if (isMatch(s,p))
    cout << "Match";
  else cout << "Not Match";
}