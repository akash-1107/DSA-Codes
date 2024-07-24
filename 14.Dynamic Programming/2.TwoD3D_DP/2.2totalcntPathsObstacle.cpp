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
if(i==0 && j==0 &&  grid[i][j] != 1) return 1; //agr ek hi element 1 ho

if(i<0 || j<0 || grid[i][j] == 1 ) return 0; 
//base cases ke baad ye line likho
if(dp[i][j] != -1) return dp[i][j];
//up(i-1,j) and left(i,j-1)
int up = fxn(grid,i-1,j,dp);
int left = fxn(grid,i, j-1,dp);

return dp[i][j] = up + left;
}

 int uniquePathsWithObstacles(vector<vector<int>>& grid) {
 int m = grid.size();
 int n = grid[0].size();
 vector<vector <int>> dp(m , vector <int>(n,-1));
 return fxn(grid,m-1,n-1,dp);
}

//2.Tabulation
int fxn(vector<vector<int>>& grid,int m , int n,vector<vector <int>> &dp){
if(grid[0][0] == 1) dp[0][0] = 0;
else dp[0][0] = 1;

for (int i = 0; i <= m; i++) //tabulation me ye m-1 and n-1 wala chij
{
for (int j = 0; j <= n; j++)
{
 if(i==0 && j==0) continue;
int up = 0 , left = 0;
 if(i-1>=0) up = dp[i-1][j];
 if(j-1>=0) left = dp[i][j-1];

if(grid[i][j] != 1)dp[i][j] = up + left;
else dp[i][j] = 0;
}
}

return dp[m][n]; 
}

 int uniquePathsWithObstacles(vector<vector<int>>& grid) {
 int m = grid.size();
 int n = grid[0].size();
 vector<vector <int>> dp(m , vector <int>(n,-1));
 return fxn(grid,m-1,n-1,dp);
}

//3.Space Optimized
int fxn(vector<vector<int>>& grid,int m , int n){
vector <int>prev(n,0), cur(n,0); //n= column size

for (int i = 0; i < n; i++)
{
    if(grid[0][i] != 1){
        prev[i] = 1;
    }
    else{
        break;
    }
}

for (int i = 1; i < m; i++) //parameter 1 sara index fill , m = rows cnt
{
for(int j = 0; j<n; j++ ){ //ye prev array
  cur[j] = prev[j];
  if(j-1>=0) cur[j] += cur[j-1];
  if(grid[i][j] ==1) cur[j] = 0;
}
prev = cur;
}
return prev[n-1];
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
 int m = grid.size();
 int n = grid[0].size();
 return fxn(grid,m,n);
}








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
    cout<<uniquePathsWithObstacles(grid);
}
