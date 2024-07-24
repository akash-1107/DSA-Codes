
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

//yaha fixed starting point and variable ending point 
//so yaha purana method nhi laga skte
//yaha (0,0) -> last row tak jana hai target last row hai bss

//1.Memomized
int fxn(vector<vector<int>>& tri , int i , int  j, int &m, vector<vector<int>> &dp){
  //base Case
  if(i == m) return tri[i][j];
  if(dp[i][j] != -1) return dp[i][j];
  //kbhi gadbad nhi hoga triangle array me koi dikkat nhi hoga direction ke hisab se
  int down = tri[i][j] + fxn(tri,i+1,j,m,dp);
  int right = tri[i][j] + fxn(tri,i+1,j+1,m,dp);
  return dp[i][j] =  min(down , right);
}


int minimumTotal(vector<vector<int>>& tri) {
     int m = tri.size()-1;
     vector<vector<int>>dp;
     dp = tri;
     for(auto i : dp){
        for(auto j : i){
            j = -1; //marking triangle array as -1
        }
     }
      return fxn(tri ,0,0,m, dp);//pass as reference me +1 ,-1 type ni likhenge
}


// //2.Tabulation
// int fxn(vector<vector<int>>& tri,int i , int j,int &m ,vector<vector <int>> &dp){
//  for (int i = 0; i < m; i++) //triangle h har row me row no jitna elements hi honge
//  {
//     dp[m][i] = tri[m][i];
//  }
 
// //tabulation ulta hoga
// for (int i = m-2; i >=0; i--) 
// {
// for (int j = i; j >=0; j--)
// {
//   int down = tri[i][j] + dp[i+1][j];
//   int right = tri[i][j] + dp[i+1][j+1];
//   dp[i][j] = min(down , right);
// }
// }

// return dp[0][0]; 
// }

// int minimumTotal(vector<vector<int>>& tri) {
//      int m = tri.size();
//      vector<vector<int>>dp;
//      dp = tri;
//      for(auto i : dp){
//         for(auto j : i){
//             j = -1; //marking triangle array as -1
//         }
//      }
//       return fxn(tri ,0,0,m, dp);//pass as reference me +1 ,-1 type ni likhenge
// }

// //3.Space Optimization
// int fxn(vector<vector<int>>& tri,int i , int j,int &m ,vector<vector <int>> &dp){
//     vector<int> last(m,0),cur(m,0);
//  for (int i = 0; i < m; i++)
//  {
//     last[i] = tri[m-1][i];//initialized with last row of triangle matrix
//  }
 
// //tabulation ulta hoga
// for (int i = m-2; i >=0; i--) 
// {
// for (int j = i; j >=0; j--)
// {
//   int down = tri[i][j] + last[j];
//   int right = tri[i][j] + last[j+1]; //dono hi chij last vector se
//   cur[j] = min(down , right);
// }
// last = cur;
// }

// return last[0]; 
// }

// int minimumTotal(vector<vector<int>>& tri) {
//      int m = tri.size();
//      vector<vector<int>>dp;
//      dp = tri;
//      for(auto i : dp){
//         for(auto j : i){
//             j = -1; //marking triangle array as -1
//         }
//      }
//       return fxn(tri ,0,0,m, dp);//pass as reference me +1 ,-1 type ni likhenge
// }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin>>m;
    vector<vector<int>> grid = {
        {2} ,{3,4} ,{6,5,7},{4,1,8,3}};
   
    cout<<minimumTotal(grid);
}
