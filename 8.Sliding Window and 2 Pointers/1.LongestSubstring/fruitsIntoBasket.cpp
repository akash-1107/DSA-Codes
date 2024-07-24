#include <bits/stdc++.h>
using namespace std;
//has only 2 baskets and can put fruits of only 1 type in 1 basket
//0 to n-1 are tree indexes and arr[i] is type of fruit in that tree
//basically mera window me 2 hi distinct element hoga aisa ka max length return kro

int findMaxFruits(vector<int> &arr, int n) {
    int i = 0 , j = 0 , diffCnt = 0 , ans = 0;
    unordered_map <int , int> mp;
    while(j<n){
    if(mp[arr[j]] == 0) diffCnt++; //isme find se galat ho jayega

    mp[arr[j]]++;

    while(diffCnt > 2){
    if(mp[arr[i]] == 1) diffCnt--;
    mp[arr[i]]--;
    i++;
    }

    ans = max(ans , j-i+1);
    j++;
    }
return ans;
}

int main(){
    int n; cin>>n;
    vector <int> arr(n,0);
    for(auto &i : arr){
        cin>>i;
    }
    cout<<findMaxFruits(arr, n);

}