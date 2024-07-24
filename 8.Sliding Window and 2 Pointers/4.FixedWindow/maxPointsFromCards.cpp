  #include <bits/stdc++.h>
  using namespace std;
  
  int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0;i<n;i++) sum += cardPoints[i];
        //n-k size ka sliding window of minimum sum
        // if(k==n) return sum;
        int i = 0,j=n-k-1;
        int curr=0 ,minSum=INT_MAX;
        for(int p = 0;p<=j;p++) curr += cardPoints[p];
        minSum=curr;
        while(j<n-1){
        curr -= cardPoints[i++]; //i=0 removed i =1
        // i++;
        // j++;
        curr += cardPoints[++j];  // j=4 added
          minSum = min(minSum,curr);
        }
        int ans = sum - minSum;
        return ans;
        
        
    }