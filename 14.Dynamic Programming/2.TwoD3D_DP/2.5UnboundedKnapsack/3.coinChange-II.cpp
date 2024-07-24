#include <bits/stdc++.h>

using namespace std;

long countWaysToMakeChange(vector<int>& arr, int n, int T){
    
    vector<long> prev(T+1,0);
    //single array optimized
    
    //Initializing
    for(int i=0;i<=T;i++){ //basically har baar row 0(mtlb i have ek array[0] element only)
    //  initiallize krte or kch nhi bss
        if(i%arr[0]==0)
            prev[i]=1;
    }
    
    for(int ind=1; ind<n;ind++){ //row 1 se
        // vector<long> cur(T+1,0);
        for(int target=0;target<=T;target++){ //taregt pura 0->k tak
            long notTaken = prev[target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = prev[target-arr[ind]];
                
            prev[target] = notTaken + taken;
        }
        // prev = cur;
    }
    
    return prev[T];
}

int main() {

  vector<int> arr ={1,2,3};
  int target=4;
  
  int n =arr.size();
                                 
  cout<<"The total number of ways is " <<countWaysToMakeChange(arr,n,target);
}