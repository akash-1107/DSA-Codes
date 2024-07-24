#include<bits/stdc++.h>
using namespace std;


//1.Memoization
int fxn(int i , int j,vector<vector <int>> &dp){

if(i==0 && j==0) return 1;

if(i<0 || j<0) return 0;
//base cases ke baad ye line likho
if(dp[i][j] != -1) return dp[i][j];
//up(i-1,j) and left(i,j-1)
int up = fxn(i-1,j,dp);
int left = fxn(i, j-1,dp);

return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) {
vector<vector <int>> dp(m , vector <int> (n,-1));
return fxn(m-1,n-1,dp);
}


//2.Tabulation
int fxn(int m , int n,vector<vector <int>> &dp){

dp[0][0] = 1;

for (int i = 0; i < m; i++)
{ 
for (int j = 0; j < n; j++)
{
 if(i==0 && j==0) continue;
int up = 0 , left = 0;
 if(i-1>=0) up = dp[i-1][j];
 if(j-1>=0) left = dp[i][j-1];

dp[i][j] = up + left;
}
}
return dp[m-1][n-1];
}

int uniquePaths(int m, int n) {
vector<vector <int>> dp(m , vector <int> (n,-1));
return fxn(m,n,dp);
}


//3.Space Optimized
int fxn(int m , int n){
vector <int> prev(n,1) , cur(n,0); //n= column size

for (int i = 1; i < m; i++) //parameter 1 sara index fill , m = rows cnt
{
for(int j = 0; j<n; j++ ){ //ye prev array
  cur[j] = prev[j];
  if(j-1>=0) cur[j] += cur[j-1];
}
prev = cur;
}
return prev[n-1];
}

int uniquePaths(int m, int n) {
// vector<vector <int>> dp(m , vector <int> (n,-1));
return fxn(m,n);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n; cin>>m>>n;
    cout<<uniquePaths(m,n);
}
