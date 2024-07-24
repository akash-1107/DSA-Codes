#include<bits/stdc++.h>
using namespace std;
//subset hai toh kisi v order me likh skte
vector<int> divisibleSet(vector<int>& arr){

    int n = arr.size();
    //basically 
    //sort the array phir usme LIS type lagao ki abhi tak sb divisible wla h
    //next bhi agr divisible wala hai toh add kro warna naa kro
    
    sort(arr.begin(), arr.end());

    vector<int> dp(n,1);
    vector<int> Parent(n,1);
    
    for(int i=0; i<=n-1; i++){
        
        Parent[i] = i; // initializing with current index

        for(int j = 0; j <=i-1; j ++){
            //arr[i] bada hi hoga sorted hai na
            if(arr[i]%arr[j] == 0 && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
                Parent[i] = j;
            }
        }
    }
    
    int ans = -1;
    int lastIndex =-1;
    
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i]; //max 
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while(Parent[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = Parent[lastIndex];
        temp.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());

    
    return temp;
}

int main() {
	
	vector<int> arr = {1,16,7,8,4};
	
	vector<int> ans = divisibleSet(arr);
	
	cout<<" The longest divisible subset elements are: ";
	
	for(int i=0; i<ans.size(); i++){
	    cout<<ans[i]<<" ";
	}
}