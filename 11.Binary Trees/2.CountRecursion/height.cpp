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


 int maxDepth(TreeNode* root) {
        
     if(!root) return 0 ;

     int l = maxDepth(root->left);
     int r = maxDepth(root->right);

    return 1+max(l,r);
}


int main(){
 TreeNode * root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);
  root -> left -> left = new TreeNode(4);
  root -> left -> right = new TreeNode(5);
  root -> left -> right -> left = new TreeNode(8);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(7);
  root -> right -> right -> left = new TreeNode(9);
  root -> right -> right -> right = new TreeNode(10);

//   vector < vector <int> > ans;
    int ans = maxDepth(root);

//   for (int i = 0; i < ans.size(); i++) {
//     for (int j = 0; j < ans[i].size(); j++)
//     cout << ans[i][j] << " ";
//   }


cout<<ans;
  return 0;




}