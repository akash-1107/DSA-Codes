#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    vector<int> dijkstra(int n , vector<vector<int>> adj[], int src)
    {

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{dist , neighbour}

        
        vector<int> distTo(n , INT_MAX);

    
        distTo[src] = 0;
        pq.push({0, src});//push {0,src} to start

        
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

           
           
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                   
                    pq.push({dis + w, v}); //dis + w push krenge kyuki yaha tak mila h src se
                }
            }
        }
       
        return distTo;
    }
};

int main()
{
    // Driver code.
    int n = 3, E = 3, S = 2;
    vector<vector<int>> adj[n];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(n , adj, S);

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}