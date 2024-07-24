#include <bits/stdc++.h>
using namespace std;

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; //initialize visited array as zero
        int start = 0;
        // create a list to store dfs
        vector<int> ans; 
        queue <int> q;
        q.push(0);
        vis[0] = 1; //queue me push krdiye mtlb vahan pahuchenge honge tbhi na queue me daale h usko

while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto &i : adj[node]){
            if(!vis[i]){
                q.push(i);
                 vis[i] = 1;
            }
        }
    }

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
    
    vector <int> ans = bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}