//GLOBAL LEKE
//https://takeuforward.org/data-structure/count-inversions-in-an-array/ (local)
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
#define print(arr)      for(auto &i:arr) cout<<i.first<<i.second<<" "
ll res = 0;//res is cnt of inversions //global variable hai
//merge 
ll mergeit(ll arr[],ll low,ll mid,ll high){
     vector <ll> temp;
     //start pointer of both arrays
     ll a1 = low; //left
     ll a2 = mid+1; //right
     ll cnt = 0; //modified


     while(a1<=mid && a2<=high){
        if(arr[a1] <= arr[a2]){ //bada index se bada chij
            temp.pb(arr[a1]);
            a1++;
        }
        else {           //kaam ka chij
            temp.pb(arr[a2]);
            cnt += mid - a1 + 1;//all subarray after a1 to mid ke liye a2 vala element is inversion
            a2++;
        }
     }




     while(a1<=mid){
        temp.pb(arr[a1++]);
     }
      while(a2<=high){
        temp.pb(arr[a2++]);
     }
     // temp arary done
     for (ll i = low; i <= high; i++)
     {
       arr[i] = temp[i-low]; // origin shift taki at arr[low] = temp[0];
     }
     
 return cnt;

}
void mergesort(ll arr[] , ll low ,ll high){
    //recursion base case
    if(low>=high) return;
    //low high deal ho gya
        ll mid  = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
       res += mergeit(arr,low,mid,high);
    
}

//function
lli inversionCount(ll arr[], ll n)
{   int low = 0,high = n-1;
    mergesort(arr,low,high);
    return (lli)res;
    
}
//ye global variable leke chale the agr local krna hai toh all 3 recursive calls me cnt+ krke return kro

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n ; cin>>n;
    ll arr[n];
    f(i,n) cin>>arr[i];
    lli ans = inversionCount(arr,n);
    cout<<ans<<endl;
    return 0;
}

