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
     //yhi agr kisi ek v subtree me unbalanced hai toh yhi galat ho gya
     if(l==-1 || r==-1) return -1;
     
     //agr dono subtree shi hai
     // toh yaha pe check kro
     if(abs(l-r) > 1) return -1;
     //agr ye bhi shi hai toh return height
    
    return 1+max(l,r);
}

 bool isBalanced(TreeNode* root) {
      if(!root) return true;
      if(maxDepth(root) == -1) return false;
    return true;
    }







int main(){
 TreeNode * root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);
  root -> left -> left = new TreeNode(4);
  root -> left -> right = new TreeNode(5);
  root -> left -> right -> left = new TreeNode(8);
  root -> right -> left = new TreeNode(6); //removing 6 se root same balanced but
  root -> right -> right = new TreeNode(7);
  root -> right -> right -> left = new TreeNode(9);
  root -> right -> right -> right = new TreeNode(10);

//   vector < vector <int> > ans;
    int ans = maxDepth(root);
    if(isBalanced(root)) cout<<1;
    else cout<<0;
//   for (int i = 0; i < ans.size(); i++) {
//     for (int j = 0; j < ans[i].size(); j++)
//     cout << ans[i][j] << " ";
//   }


// cout<<ans;
  return 0;




}