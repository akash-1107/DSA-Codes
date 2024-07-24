#include <bits/stdc++.h>
using namespace std;
// Time: O(N^2)
// Space: O(N)

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        string t(s.rbegin(), s.rend());
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = 0; i < N; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (s[i] == t[j]) dp[j + 1] = 1 + prev;
                else dp[j + 1] = max(dp[j + 1], dp[j]);
                prev = cur;
            }
        }
        return dp[N] + k >= s.size();
    }
};