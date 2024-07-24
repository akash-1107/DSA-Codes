#include <bits/stdc++.h>

using namespace std;
//hm dp me index 0 se start krenge , n size le liye for base case
//buy bhi 0 to 1 krenge 
long getAns(vector<int> &prices, int ind, int buy, int n, vector<vector<long>> &dp ){

    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    long profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(prices,ind+1,0,n,dp), -prices[ind] + getAns(prices,ind+1,1,n,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(prices,ind+1,1,n,dp), prices[ind] + getAns(prices,ind+1,0,n,dp));
    }
    
    return dp[ind][buy] = profit;
}


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<long> cur(2,0) , ahead(2,0);  
    //isme 1 base indexing kr rhe kyuki base case me n used h mtlb waqt n use krna hoga jo index possible nhi vaise
    for (int i = 0; i < 2; i++) ahead[i] = 0;

    for (int ind = n-1; ind >= 0; ind--)
    {
     for (int buy = 0; buy < 2; buy++)
     {
        long profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+ahead[0], -prices[ind] + ahead[1]);
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+ahead[1], prices[ind] + ahead[0]);
    }
    
        cur[buy] = profit;
     }
     ahead = cur;
     
    }
return ahead[0]; //ulta aaye na isme
}

int main() {

  int n =6;
  vector<int> Arr = {7,1,5,3,6,4};
                                 
  cout<<"The maximum profit that can be generated is "<<maxProfit(Arr);
}