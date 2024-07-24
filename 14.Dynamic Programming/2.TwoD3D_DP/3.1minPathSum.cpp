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
//1.Memomized
int fxn(vector<vector<int>>& grid , int i , int j , vector<vector <int>> &dp){
if(i==0 && j==0) return grid[0][j]; //row 0

if(i<0 || j<0 ) return 1e8;  //INT_MAX me plus se overflow isiliye ye like h
//base cases ke baad ye line likho
if(dp[i][j] != -1) return dp[i][j];
//up(i-1,j) and left(i,j-1)
int rightD = 1e8;
int up = grid[i][j] + fxn(grid,i-1,j,dp);
int leftD = grid[i][j] + fxn(grid,i-1, j-1,dp);
 rightD = grid[i][j] + fxn(grid,i-1, j+1,dp);

return dp[i][j] = min(rightD,min(leftD,up));
}

int minPathSum(vector<vector<int>>& grid) {
 int m = grid.size();
 int n = grid[0].size();
 int a = INT_MAX;
 for (int i = 0; i < n; i++)
 {
   vector<vector <int>> dp(m , vector <int>(n,-1));
     a = min(a , fxn(grid,m-1,n-1-i,dp));
 }
 
 return a;
}


// //2.Tabulation
// int fxn(vector<vector<int>>& grid,int m , int n,vector<vector <int>> &dp){
//  dp[0][0] = grid[0][0];

// for (int i = 0; i < m; i++) //tabulation me ye m-1 and n-1 wala chij
// {
// for (int j = 0; j < n; j++)
// {
//  if(i==0 && j==0) continue;
// int up = 1e8 , left = 1e8;
//  if(i-1>=0) up = grid[i][j] + dp[i-1][j];
//  if(j-1>=0) left = grid[i][j] + dp[i][j-1];

// dp[i][j] = min(up , left);

// }
// }

// return dp[m-1][n-1]; 
// }

//  int minPathSum(vector<vector<int>>& grid) {
//  int m = grid.size();
//  int n = grid[0].size();
//  vector<vector <int>> dp(m , vector <int>(n,-1));
//  return fxn(grid,m,n,dp);
// }


// //3.Space Optimized
// int fxn(vector<vector<int>>& grid,int m , int n){
// vector <int>prev(n,0), cur(n,0); //n= column size
// int sum = 0;
// for (int i = 0; i < n; i++)
// {   sum += grid[0][i];
//     prev[i] = sum;
// }

// for (int i = 1; i < m; i++) //parameter 1 sara index fill , m = rows cnt
// {
// for(int j = 0; j<n; j++ ){ //ye prev array
//   int a = grid[i][j] + prev[j];
//   int b = 1e8;
//   if(j-1>=0) b = grid[i][j] + cur[j-1];
//   cur[j] = min(a,b);
// }
// prev = cur;
// }
// return prev[n-1];
// }
// int minPathSum(vector<vector<int>>& grid) {
//  int m = grid.size();
//  int n = grid[0].size();
//  return fxn(grid,m,n);
// }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n; cin>>m>>n;
    vector<vector<int>> grid(m , vector<int>(n,0));
    f(i,m){
        f(j,n){
            cin>>grid[i][j];
        }
    }
    cout<<minPathSum(grid);
}
