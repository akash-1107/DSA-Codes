#include <bits/stdc++.h>
using namespace std;



class Solution {
	// works for multiple components -->batana hai aliens ka lexicographic order
    // agr koi alphabet kisi word me aaya hi nhi toh usko start  me daal denge as indegree zero
private:
    //toposort code
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) { //indegree bhar rhe adj list use kr rhe
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
public:
    //find
	string findOrder(string dict[], int N, int K) {
		vector<int>adj[K];//k letters
		for (int i = 0; i < N - 1; i++) {
			string s1 = dict[i]; //har baar do-do words krke uthao usme first difference jaha h
			string s2 = dict[i + 1];
			int len = min(s1.size(), s2.size());
			for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
                    //pehle string me mila letter -->(edge)   dusre string me mila letter
					adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); //making adj list Ist ka neighbour me 2nd
					break; //first diff pe hi break
				}
			}
		}

		vector<int> topo = topoSort(K, adj);
		string ans = "";
		for (auto it : topo) {
			ans = ans + char(it + 'a');//toposort se nikal ke add to ans
		}
		return ans;
	}
};

int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}