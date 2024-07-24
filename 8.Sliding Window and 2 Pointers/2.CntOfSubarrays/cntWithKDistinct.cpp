#include <bits/stdc++.h>
using namespace std;
//exact k me hmesha ye approach soch skta hai  
int subarraysWithAtMostKDistinct(vector<int>& s, int k) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0, unique = 0, res = 0;
        while (j < s.size()){
            mpp[s[j]]++;
            if (mpp[s[j]] == 1) {
                unique++;
            }
         
            while (unique > k) {
                mpp[s[i]]--;
                if (mpp[s[i]] == 0) {
                    unique--;
                }
                i++;
            }
            res += j - i + 1; //Vhi all substring jisme ye character hai usse piche wale included
            j++;
        }
        return res;
    }

int subarraysWithKDistinct(vector<int>& A, int K) {
    return subarraysWithAtMostKDistinct(A, K) - subarraysWithAtMostKDistinct(A, K - 1);
}