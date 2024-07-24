#include<bits/stdc++.h>
using namespace std;
// ye 90 degree yaa phir clockwise hai
/*basically transpose lagana hai and har row wise reverse krna hai*/
//TC = O(N*N) + O(N*N) 
//SC = O(1)


/* Brute Force dummy 2d matrix requirement ke hisab se bhar lo original se
yaha pe last column me 1st row daal rhe
yaha pura do loop toh chalega hi
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
*/
class Solution {
#define f(i,n) for(int i = 0;i<n;i++)
public:
    
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        f(i,n){
            for(int j = i+1 ; j<n ; j++){
    // har row me diagonal element ke baad swap(mat[i][j] , mat[j][i]) till last element
            swap(mat[i][j] , mat[j][i]);
            }
        }
        f(i,n){
            reverse(mat[i].begin(),mat[i].end());
        }
        
    }
};
//ANTICLOCKWISE ME ---> transpose + reverse every column
// reverse direct nhi kr payenge so
 /* Reverse every column ********
  int ind = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      int temp = matrix[j][i];
      matrix[j][i] = matrix[ind][i];
      matrix[ind][i] = temp;
      ind--;
    }
  }
  */
