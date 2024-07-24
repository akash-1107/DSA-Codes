
#include <bits/stdc++.h>
using namespace std;
//macros
#define lli             long long
#define f(i,x)          for(int i=0;i<(int)x;i++)    
#define yes()           cout<<"YES"<<endl 
#define no()            cout<<"NO"<<endl
#define all(arr)        arr.begin(),arr.end()
#define print(arr)      for(auto &i:arr) cout<<i<<" "



bool bipartiteBFS(int root, vector<vector<int>>& adj ,int col[],int color){
queue <int> q;
q.push(root);
col[root] = color;
while(!q.empty()){
    int node = q.front();
    q.pop();
  for(auto &i : adj[node]){ //i represents elements of a vector
      if(col[i] == -1){
       q.push(i);
       col[i] = 1-col[node]; //yaha color of poped node ka negation daalna hoga
      }

     if(col[node] == col[i]) return false; //mtlb visited hai agr color assigned hai toh agr same color as node

  }
}
return true;
}

bool isBipartite(vector<vector<int>>& adj) {
  int n = adj.size();
  int col[n];
  f(i,n) col[i] = -1;
  f(i,n){
    if(col[i] == -1){
      if(!bipartiteBFS(i ,adj,col,0)) return false;
    }
  } 
  return true;
}





int main() 
{   int n;      cin>>n;
    vector<vector<int>> adj(n); 
    for(int i = 0; i<n ; i++){
        int m ;  cin>>m;
        vector <int> v(m , 0);
        for(int j = 0 ; j<m ; j++){
             cin>>v[j];
        }
        adj.push_back(v);
    }
    
   if(isBipartite(adj)) yes();
   else no();
  

    return 0;
}