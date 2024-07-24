#include <bits/stdc++.h>
using namespace std;

 int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0 ; i<n ;i++){
            int k = abs(arr[i]) - 1;//index
            if(arr[k]<0){
                return abs(arr[i]);
            }
            else {
                  arr[k] = 0 - arr[k];
            }
        }
        return 0;
    }




    int main(){
        int n ; cin>>n;
        vector <int> arr;
        for (int i = 0; i < n ; i++)
        {
            int a ; cin>>a;
            arr.push_back(a);
        }
        
        int x = findDuplicate(arr);
        cout<<x<<endl;
    }