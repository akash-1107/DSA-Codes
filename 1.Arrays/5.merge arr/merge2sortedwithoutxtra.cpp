#include<bits/stdc++.h>
using namespace std;
//Macros
#define lli             long long int
#define ll              long long 
#define pb              push_back
#define mod             1000000007
#define f(i,x)          for(int i=0;i<(int)x;i++)
#define f1(i,x)         for(int i=1;i<=(int)x;i++)
#define rep(i,a,b)      for(int i=(int)a;i<=(int)b;i++)      
#define all(arr)        arr.begin(),arr.end()
#define print(arr)      for(auto &i:arr) cout<<i<<" "


// super simple code
 void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int last1 = n-1;
            int start2 = 0;
            while(last1>= 0 && start2 < m && arr1[last1] > arr2[start2]){
                swap(arr1[last1] , arr2[start2]);
                last1--,start2++;
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    ll arr1[n];
    f(i,n) cin>>arr1[i];
     ll arr2[m];
    f(i,m) cin>>arr2[i];
    merge(arr1,arr2,n,m);
    print(arr1); cout<<endl;
    print(arr2);
    return 0;
}

