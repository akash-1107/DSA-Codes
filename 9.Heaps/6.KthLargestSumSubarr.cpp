/*
    Time Complexity: O(N ^ 2 * log(K)
    Space Complexity: O(K)

    where ‘N’ is the length of the given array/list.
	And 'K' is the given number.
*/

#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	int n = arr.size();

	//	To store the subarray sums.
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++)
	{ //start of subarray
		//	To store the current subarray sum.
		int sum = 0;
		for (int j = i; j < n; j++)
		{ //i se last tak
			sum = sum + arr[j];

			if (minHeap.size() < k)
			{
				minHeap.push(sum); //pq ka size k se kam h
			}
			else
			{
				if (minHeap.top() < sum)
				{
					//	Pop the minimum element. jo top pe hai usse bada hai mere pass
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}

	//	Top-most element is the k-th largest subarray sum.
	return minHeap.top();
}