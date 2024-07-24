/*
	Time Complexity: O(N*K*log(K))
	Space complexity: O(K)

	Where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists.

*/

#include <bits/stdc++.h>
using namespace std;

int kSorted(vector<vector<int>> &a, int k, int n) {
    int maxx = INT_MIN, minn = INT_MAX;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Insert the first element of each list in Min heap
    for (int i = 0; i < k; i++) {
        pq.push({a[i][0], {i, 0}});
        maxx = max(maxx, a[i][0]);
        minn = min(minn, a[i][0]);
    }

    // Initialize the answer using current min and max
    int ans = maxx - minn + 1;
    while (true) {
        // Remove the minimum element from Min heap
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int row = p.second.first;
        int col = p.second.second;
        minn = p.first;
        // Calculate new length of the range
        int len = maxx - minn + 1;
        // Update the answer with new range
        ans = min(ans, len);
        // Update the column number of new element to be inserted
        col++;
        // If this list is exhausted then we can not further improve our answer so will break the loop
        if (col == n) {
            break;
        }
        // Insert new element in Min heap
        pq.push({a[row][col], {row, col}});
        // Also update the maximum element
        maxx = max(maxx, a[row][col]);
    }

    return ans;
}
