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



//Boyree Moore Voting Algo
    int majorityElement(int arr[], int n)
    {
        int cnt = 0 , cnt_check=0;
        int ele; 
        for(int i = 0 ; i<n ; i++){
            if(cnt==0){
                cnt = 1;
                ele = arr[i];
            }
            else if(arr[i]==ele) cnt++;
            else cnt--;
            
        }
       for(int i = 0 ; i < n ; i++){
           if(arr[i] == ele) cnt_check++;
       }
     if(cnt_check > n/2) return ele;  
     return -1;
    }

//Driver Code


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

