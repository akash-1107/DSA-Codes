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



//function
 vector<pair<int,int>> allPairs(int arr[], int brr[], int n, int m, int x)
    {   vector<pair<int ,int>> p;
        unordered_map <int,int> mp;
        f(i,n) {
          mp[arr[i]]++;
        }
        f(i,m){
          int a = x - brr[i];//x=target
          if(mp.find(a) != mp.end()){
            p.pb({a,brr[i]});
          }
        }
    sort(all(p));
    return p;
    }


//Driver Code


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //basic input
    int n,m,x ;  cin>>n>>m>>x;
    int arr[n];
    int brr[m];
    vector<pair<int ,int>> p;
    f(i,n) cin>>arr[i];
    f(i,m) cin>>brr[i];
    //fxn call
    while (t--)
    {
       p = allPairs(arr,brr,n,m,x);
    }
    print(p);
    return 0;
}

