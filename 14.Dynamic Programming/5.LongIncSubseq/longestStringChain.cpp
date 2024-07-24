#include<bits/stdc++.h>
using namespace std;
//comapre fxn to check ki both string me 1 letter ka diff hai yaa nhi
bool compare(string& s1, string& s2){
    //s1>s2
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){ //bada wale ka end tak jana hai
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}

static bool comp(string& s1, string& s2){ //static banana padega comparator ko
    return s1.size() < s2.size();
}


int longestStrChain(vector<string>& arr){

    int n = arr.size();
    
    //sort the array
    
    sort(arr.begin(), arr.end(),comp); //comparator pass to sort a/q to length
    //hm kisi ko bhi le skte from given list so sort A/q size
    //phir vhi LIS agr ek letter diff toh add to chain
    vector<int> dp(n,1);
    
    int maxi = 1;
    
    for(int i=0; i< n; i++){
        
        for(int j = 0; j < i; j ++){
   //sorted--> //arr[i] bada string arr[j] chota strings
            if( compare(arr[i], arr[j]) && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}
    

int main() {
	
	vector<string> words = {"a","b","ba","bca","bda","bdca"};
	
	cout<<" The length of the longest string chain is : "<<longestStrChain(words);
	
}