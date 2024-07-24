#include <bits/stdc++.h>
using namespace std;
//connected component in constant time 
class DisjointSet { //to reuse this code for DSU
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1); //isse works for both 0 and 1 based indexing
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]); //this one line is path compression
    } //basically ultimate parent ko hi uss node ka direct parent bana do

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return; //dono same tree me hai
        if (size[ulp_u] < size[ulp_v]) { // to not increase height and ultimate parent find kam TC me
            parent[ulp_u] = ulp_v; //we join chotu to bada 
            size[ulp_v] += size[ulp_u];
        }
        else { //equal or bada same chij kro
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);//obj of that class with 7 nodes
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}