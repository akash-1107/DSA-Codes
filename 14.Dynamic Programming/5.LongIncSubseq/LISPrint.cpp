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
//longest increasing sequence
// //1.Memomize
// int fxn(vector<int>& nums , int ind , int prevInd , int &n, vector<vector <int>>& dp ){
// //base case
// if(ind == n) return 0; //as length ka baat ho rha

// if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

// int nottake = 0 + fxn(nums ,ind+1 , prevInd , n , dp) ; //ni liye prevIndex vhi rahega

// int take = 0;
// if(prevInd == -1 || nums[ind] > nums[prevInd]){//yaha hm -1 already deal kr chuke h
//    take = 1 + fxn(nums ,ind+1 , ind , n , dp) ; //ab prevIndex index hi h
// }
// //max of take and not take as max length
// return dp[ind][prevInd + 1] = max(take,nottake);
// }

// int lengthOfLIS(vector<int>& nums) {
//    int n = nums.size();
//    vector<vector <int>> dp(n,vector<int>(n + 1,-1));
//    return fxn(nums,0,-1,n,dp);
//    //-1 bheje hai prevInd me toh origin shift krna hoga 
//    //n+1 krdo for prevInd 
//    //upar wala code me prevInd har jagah y coordinate me +1 krdo
// }


//iska tabulation me dikkat toh 1D Dp with Parent table to find and print LIS

int lengthOfLIS(vector<int>& nums) {
 int n = nums.size();
 vector <int> dp(n,1) , Parent(n,0);
 for (int i = 0; i < n; i++)
 {
    Parent[i] = i; //initailize with usi ka index
    //hm kruskals type feel to print
 }
 
for (int i = 1; i < n; i++)
{
 for (int j = 0; j < i; j++)
 {
   if(nums[j]<nums[i] && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j]; //1 + se length increase
                Parent[i] = j; //jb max milega tb hi modify kro isko
     }
  }
  
}

int maxi = INT_MIN;
int lastIndx = -1;
for (int i = 0; i < n; i++)
{
  if(maxi < dp[i]){
    maxi = dp[i];
    lastIndx = i;
  }
}

//to print LIS simply jo khud ka parent na ho usko daalo and usme index pe jao
vector <int> LIS;
//lastIndx se hi chalu kro
int i = lastIndx;
 LIS.push_back(nums[lastIndx]); //lastindx print kro
while (Parent[i] != i) //mst way to use for loop
{
    i = Parent[i];
    LIS.push_back(nums[i]); //uska child pe jake print kro
}
reverse(LIS.begin(),LIS.end());
// print(LIS);
// cout<<endl;
return maxi;
}




int main() {
	vector<int> arr = {1,5,3,7,1};
	cout<<lengthOfLIS(arr);
	return 0;
}