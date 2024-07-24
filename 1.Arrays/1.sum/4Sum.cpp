#include<bits/stdc++.h>
using namespace std;
//Macros
#define lli             long long
#define pb              push_back
#define mod             1000000007
#define f(i,x)          for(int i=0;i<(int)x;i++)
#define f1(i,x)         for(int i=1;i<=(int)x;i++)
#define rep(i,a,b)      for(int i=(int)a;i<(int)b;i++)      
#define all(arr)        arr.begin(),arr.end()
// #define print(arr)      for(auto &i:arr) cout<<i.first<<i.second<<" "



//function
 vector<vector<int>> fourSum(vector <int> &arr, int x)
    {   vector<vector<int>> ans;
        sort(all(arr));
        int n = arr.size();
        f(i,n-3){
            int tar3 = x - arr[i];
            rep(j,i+1,n-2){
                int tar2 = tar3-arr[j];
                //tar2 is my target 
                int start = j+1,end=n-1;
                while( start<end){ //2 numbers needed so equality nhi hoga
                 int sum = arr[start] + arr[end];
                 if(sum>tar2) end--;
                 else if(sum<tar2) start++;
                 else {
                    vector <int> quad;
                    quad.pb(arr[i]);
                    quad.pb(arr[j]);
                    quad.pb(arr[start]); 
                    quad.pb(arr[end]);
                    ans.pb(quad);
                    while(arr[start+1] == arr[start] && start<end) start++;
                    while(arr[end-1] == arr[end] && start<end) end--;

                    start++;
                    end--;
                 }
                }
                while(arr[j+1] == arr[j] && j+1<n-2) j++;
            }
           while(arr[i+1] == arr[i] && i+1<n-3) i++; 
        }
    return ans;
    }


//Driver Code


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //basic input
    int n,x ;  cin>>n>>x;
    vector <int> arr(n);
    vector<vector<int>> p;
    f(i,n) cin>>arr[i];
    //fxn call
    while (t--)
    {
       p = fourSum(arr,x);
    }
    for(auto i : p){
        for(auto j : i){
             cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

