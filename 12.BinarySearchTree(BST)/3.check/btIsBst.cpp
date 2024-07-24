#include <bits/stdc++.h>
using namespace std;

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
//basic recursive traversal DFS type
bool checkValidBST(TreeNode* root , long minVal , long maxVal) {
    if(!root) return true;
    long x = root->val;
    if(x>=maxVal || x<=minVal) return false;//equality bhi as -->duplicates not present in BST
    return checkValidBST(root->left, minVal , x)
    && checkValidBST(root->right,x,maxVal);
}

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    bool ans = checkValidBST(root,LONG_MIN,LONG_MAX);
    return ans;
}



int main(){
 TreeNode *root = new TreeNode(11);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(13);
  root -> left -> left = new TreeNode(8);
  root -> left -> right = new TreeNode(10);
  root -> right -> left = new TreeNode(12);
  root -> right -> right = new TreeNode(15);

  bool ans = isValidBST(root);
  if(ans) cout<<"yes"<<endl;
  else cout<<"no"<<endl;

  return 0;




}