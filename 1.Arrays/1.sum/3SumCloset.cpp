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
     int closest3Sum(int arr[], int n, int x)
    {   int mini = INT_MAX,ans=0;
        sort(arr,arr+n);
        f(i,n-2){
            if(i==0 || (i>0 && arr[i] != arr[i-1]) ) {
            int tar2 = x-arr[i];
             int start = i+1,end  = n-1;
           

            while(start<end){
                int sum = arr[start] + arr[end];
                if(mini > abs(tar2 - sum)){
                    mini = abs(tar2 - sum);
                    ans = sum + arr[i];
                }
                if(sum>tar2){
                    end--;
                }
                else if(sum<tar2) start++;

                else{ //basically mil gya tar2
                    return x;
                }
            }
            
        }
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
    int arr[n];
    f(i,n) cin>>arr[i];
    //fxn call
    while (t--)
    {
       cout<<closest3Sum(arr,n,x);
    }
    return 0;
}

