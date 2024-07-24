#include <bits/stdc++.h>
using namespace std;
//only for directed graph
//for undirected graph = 1-2 => make it directed as (1->2 , 1<-2)
class Solution {
public:
   //-ve edge ke liye works fine
   //(total nodes - 1) baar relax krna hai har edge ko
	vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
		vector<int> dist(n, 1e8);
		dist[src] = 0;
		for (int i = 0; i < n - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
// why N-1 baar
/*
n=4  , n-1 = 3
suppose edges hai 1->2->3->4 src = 1
edges diya hai aise --> (3,4) (2,3) (1,2) 
isme kya hoga 1st iteration me (1,2) ka ans
phir next me (2,3)
phir (3,4) 3rd step
so , worst case me bhi kaam ho jayega
*/


    // Nth relaxation to check negative cycle //agr ab ghat gya toh -ve cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		return dist;
	}
};


int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}