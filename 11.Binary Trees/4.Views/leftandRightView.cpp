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

void leftView(TreeNode *root , int level , vector <int> &ds){
 if(!root) return;
 //node->left->right
 if(level == ds.size()){
    ds.push_back(root->val);
 }
 leftView(root->left , level + 1 , ds);
 leftView(root->right , level + 1 , ds);
 
}


void rightView(TreeNode *root , int level , vector <int> &ds){
 if(!root) return;
 //node->right->left
 if(level == ds.size()){
    ds.push_back(root->val);
 }
 rightView(root->right , level + 1 , ds);
 rightView(root->left , level + 1 , ds);
 
}

vector<int> rightSideView(TreeNode* root) {
  vector <int> ds; 
  rightView(root , 0 , ds);
  return ds;
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

  vector <int> ans,arr;
     ans = rightSideView(root);

    
  for (int i = 0; i < ans.size(); i++) {
    
    cout << ans[i]<< " ";
  }
  return 0;




}