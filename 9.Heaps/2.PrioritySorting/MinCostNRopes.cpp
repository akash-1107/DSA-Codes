#include <bits/stdc++.h>>
using namespace std;

int minCost(int arr[], int n)
{
	priority_queue<int , vector<int> ,greater<int>> pq;
    int ans = 0;
	for(int i = 0 ; i<n ; i++){
		pq.push(arr[i]);
	}
    while(pq.size() > 1) { //ek element bacha mtlb jodke bacha hai vo final rope
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();

		int sum = min1 + min2;
		// cout<<sum<<endl;  
		ans += sum;
		pq.push(sum);
	}



	return ans;

// 	Time Complexity: O(N*log(N))
//  Auxiliary Space: O(N)



}
