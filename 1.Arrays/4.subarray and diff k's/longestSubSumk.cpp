#include <bits/stdc++.h> 
using namespace std;
int getLongestSubarray(vector<int> a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
    
        sum += a[i];
        //index pe nhi krke cnt of elements pe kr diye
        //-1 leke index pe v kr skte the
        
        preSumMap[0] = 0; //basically 0 sum  0  element se 
        
        int rem = sum - k;

        
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = (i+1) - preSumMap[rem]; //total elemnts - total elements  = length
            maxLen = max(maxLen, len);
        }

        //store index only first time of presum for max length
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i+1; //index se ek jada element hai na subaaray me
        }
    }

    return maxLen;
}