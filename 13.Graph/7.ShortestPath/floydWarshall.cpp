#include <bits/stdc++.h>
using namespace std;
//valid for directed graph only
//dp solution
//find -ve weight cycle
//yaha adjacency matrix is used
class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
        //initial adj matrix with edge weights
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {//setting infinity for distances taki inequality me dikkat na ho
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0; //diagonal elements ka diatance zero
			}
		}

		for (int k = 0; k < n; k++) { //k = iske through visit
			for (int i = 0; i < n; i++) { //src
				for (int j = 0; j < n; j++) { //destination
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
                if(i==j && matrix[i][j]<0) return ;  //agr diag -ve mtlb khud pe pahuchne ke liye 
                //less than 0 wala path
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1; //ab jo v infinity reh gya usko -1 phr se 
                    // bss distance matrix mil gya
				}
                
			}
		}
	}
};


int main() {

	int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortest_distance(matrix);

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}