#include<bits/stdc++.h>
using namespace std;
//macros
#define lli             long long
#define f(i,x)          for(int i=0;i<(int)x;i++)
#define f1(i,x)         for(int i=1;i<=(int)x;i++)
#define rep(i,a,b)      for(int i=(int)a;i<=(int)b;i++)      
#define yes()           cout<<"YES"<<endl 
#define no()            cout<<"NO"<<endl
#define all(arr)        arr.begin(),arr.end()
#define print(arr)      for(auto &i:arr) cout<<i<<" "

int mod = (int)(1e9 + 7);
//only valid for nums[i]>=0
//3.SPACE OPTIMIZED
vector <int> findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0),cur(tar+1,0);;
    
    prev[0] = 1; //step 1
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1; 
    
    for(int ind = 1; ind<n; ind++){
        
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken | taken); //step2 to use as true false only
        }
        prev = cur;
    }
    return prev;
}
//basically hm cnt wala code me hi modification kr rhe kyuki bool nhi lena hmko
 int  minimumDifference(vector<int>& arr) {
          int totSum = 0;
          int n = arr.size();
    for(int i=0; i<n;i++){
        totSum += abs(arr[i]);
    }
    int mini = 1e9;
    vector <int> a = findWays(arr,totSum); //i need the last array only
    for (int i = 0; i <= totSum; i++)
    { if(a[i]>0){// i sum ka subset exist krta h
        int s1 = i;
        int s2 = totSum - i;
        mini = min(mini , abs(s2-s1));
    }
    }
    return mini;
    }


int main() {
  int n;  cin>>n;
  vector<int> arr(n,0);
  f(i,n) cin>>arr[i];
                                 
  cout<< minimumDifference(arr)<<endl;
}