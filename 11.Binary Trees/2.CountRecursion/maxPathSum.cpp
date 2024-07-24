#include <bits/stdc++.h>
using namespace std;
//rattta marlo isko

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int maxDepth(TreeNode* root , int &maxi) { //ye fxn mere max path sum of left right me se jo v hai vo dega js like max h
        
     if(!root) return 0 ;

     int l = max(0 , maxDepth(root->left,maxi));
     int r = max(0 , maxDepth(root->right,maxi));
     
     maxi = max(maxi , root->val + l + r); 
      
     return root->val + max(l,r);
}

int maxPathSum(TreeNode* root) {
if(!root) return 0;
int maxi = INT_MIN;
int ans = maxDepth(root,maxi);

return maxi;

}






int main(){
 TreeNode * root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);
  root -> left -> left = new TreeNode(4);
  root -> left -> right = new TreeNode(5);
//   root -> left -> right -> left = new TreeNode(8);
//   root -> right -> left = new TreeNode(6); //removing 6 se root same balanced but
//   root -> right -> right = new TreeNode(7);
//   root -> right -> right -> left = new TreeNode(9);
//   root -> right -> right -> right = new TreeNode(10);

//   vector < vector <int> > ans;
    int ans = maxPathSum(root);

//   for (int i = 0; i < ans.size(); i++) {
//     for (int j = 0; j < ans[i].size(); j++)
//     cout << ans[i][j] << " ";
//   }


//    cout<<maxi<<endl;
   cout<<ans<<endl;
  return 0;




}