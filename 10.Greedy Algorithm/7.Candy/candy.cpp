#include <bits/stdc++.h>
using namespace std;

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector <int> left(n,1) , right(n,1);
        int cnt = 0 ;
        //left se right fill kr rhe 
        //becoz jis element se compare kr rhe pehle vo deal ho jana chahiye na har baar
        for(int i = 1 ; i<n ; i++){
            if(arr[i] > arr[i-1]) { //left wale neighbour se bada hai present wala
               left[i] += left[i-1];
            }
        }
        //right se left fill kr rhe
        //becoz jis element se compare kr rhe pehle vo deal ho jana chahiye na har baar
        for(int i = n-2 ; i>=0 ; i--){
            if(arr[i] > arr[i+1]) { //right se bada hai
               right[i] += right[i+1];
            }
        }

        for(int i = 0 ; i<n ; i++){
            cnt += max(left[i] , right[i]);
        }


    return cnt;
    }
};