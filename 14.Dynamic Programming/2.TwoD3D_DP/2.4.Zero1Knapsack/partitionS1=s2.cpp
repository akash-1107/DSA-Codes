 #include <bits/stdc++.h>
using namespace std;
#define lli             long long
#define f(i,x)          for(int i=0;i<(int)x;i++)
#define f1(i,x)         for(int i=1;i<=(int)x;i++)

//3.SPACE OPTIMIZED using suset cnt simply
bool findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0),cur(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken | taken);
        }
        prev = cur;
    }
    return prev[tar];
}

bool canPartition(vector<int>& nums) {
     int n = nums.size();
     int sum = 0;
     for (int i = 0; i < n; i++)
     {
      sum += nums[i];
     }
    if(sum%2==1) return false;
      

    return findWays(nums , sum/2);
}





int main() {

  int n,k;  cin>>n;
  vector<int> arr(n,0);
  f(i,n) cin>>arr[i];
                                 
  if(canPartition(arr)) cout<<"yes"<<endl;
  else cout<<" no"<<endl;
}