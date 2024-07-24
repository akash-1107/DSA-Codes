#include <bits/stdc++.h>

using namespace std;
//2.Tabulation
int lcs(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //n+1,m+1

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1]; //length += 1
                dp[i][j] = val;
                ans = max(ans,val);
            }
            else //agr character same nhi toh simply dp zero krdo bss
                dp[i][j] = 0;
        }
    }
    
    return ans;
    
}
//3.Space Optimized
int lcs(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector<int> prev(m+1,0), cur(m+1,0);

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans,val);
            }
            else
                cur[j] = 0;
        }
        prev=cur;
    }
    
    return ans;
    
}

int main() {

  string s1= "abcjklp";
  string s2= "acjkp";
                                 
  cout<<"The Length of Longest Common Substring is "<<lcs(s1,s2);
}