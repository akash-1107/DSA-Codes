#include<bits/stdc++.h>
using namespace std;
//Macros
#define lli             long long
#define pb              push_back
#define mod             1000000007
#define f(i,x)          for(int i=0;i<(int)x;i++)
#define f1(i,x)         for(int i=1;i<=(int)x;i++)
#define rep(i,a,b)      for(int i=(int)a;i<=(int)b;i++)      
#define all(arr)        arr.begin(),arr.end()
#define print(arr)      for(auto &i:arr) cout<<i.first<<i.second<<" "



//Boyree Moore Voting Algo Advanced
   vector<int> majorityElement(vector<int>& nums) {
     vector <int> ans;
     int n = nums.size();
     int cnt1 = 0 , cnt2 = 0 , check1 = 0, check2 = 0;
     int ele1 = INT_MIN , ele2=INT_MIN;
     for(int i = 0; i<n ; i++){
     if(cnt1 == 0 && ele2 != nums[i]){
         cnt1 = 1;
         ele1 = nums[i];
     }
    else if(cnt2 == 0 && ele1 != nums[i]){
         cnt2 = 1;
         ele2 = nums[i];
     }
     else if(nums[i]==ele1) cnt1++;
     else if(nums[i]==ele2) cnt2++;
     else {
         cnt1--;
         cnt2--;
     }
     }

    for(int i = 0 ; i<n ; i++){
        if(ele1 == nums[i]) check1++;
        else if(ele2 == nums[i]) check2++;
    }



    if(check1 > n/3) ans.push_back(ele1);
    if(check2 > n/3) ans.push_back(ele2);
     return ans;
    }


//Driver Code


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

