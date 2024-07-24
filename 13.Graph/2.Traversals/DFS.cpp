#include <bits/stdc++.h>
using namespace std;


    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans) {
        vis[node] = 1; 
        ans.push_back(node + 1); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ans); 
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; //initialize visited array as zero
        int start = 0;
        // create a list to store dfs
        vector<int> ans; 
        // call dfs for starting node
        dfs(start, adj, vis, ans); //dfs(0,adj,vis,ans)
        return ans; 
    }


void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{  //array is collection of items of same data type like--> int arr[n]-->collection of int
    vector <int> adj[5]; //int arr[n]-->collection of vector<int>
   //always go for zero based code and make modifications if needed 1 based
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);

    vector <int> ans = dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}