#include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int n) {
   vector <int> brr = arr;
   sort(brr.begin() , brr.end()); //ab sara element apne rank pe hai
   int temp = 1;//ab sorted arr ko ek ek karke rank dete jayenge or temp++ krte jayenge
   unordered_map<int , int> mp;

   for (int i = 0; i < n; i++) {
     if (mp.find(brr[i]) == mp.end()){ //not in map toh new rank else uska rank pehle se h map me
        mp[brr[i]] = temp;
        temp++;
     }

   }

   for(int i = 0 ; i<n ; i++){
       arr[i] = mp[arr[i]];
   }

 

return arr;
}
//Time complexity: O(N * Log(N))
// Space complexity: O(N)