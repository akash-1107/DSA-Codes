#include <bits/stdc++.h>

using namespace std;

int prime = 1e9+7;

int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Write your code here.
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    
    return dp[n][m];
} 

//3.Space Optimized
int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Write your code here.
    
    vector<int> prev(m+1,0),cur(m+1,0); //row 0 initillize
    
    prev[0] = 1;//step1
    
    for(int i=1;i<=n;i++){
            cur[0]=1;//step2 
            //step1+step2 = initialize all 1st element of all rows
        for(int j=1;j<=m;j++){ // Reverse direction
            
            if(s1[i-1]==s2[j-1])
                cur[j] = (prev[j-1] + prev[j]);
            else
                cur[j] = prev[j]; //can omit this statemwnt
        }
        prev = cur;
    }
    
    
    return prev[m];
} 

int main() {

  string s1 = "babgbag";
  string s2 = "bag";

  cout << subsequenceCounting(s1,s2,s1.size(),s2.size());
}