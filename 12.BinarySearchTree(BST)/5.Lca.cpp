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
//vo point jaha pe ek x se bada and ek x se chota aisa first point is my LCA
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
 if(!root) return NULL; 
 int x = root->val;
 if(x>p->val && x>q->val){ //x dono se bada hai
    return lowestCommonAncestor(root->left,p,q); //left subtree me hai dono
 }
 if(x<p->val && x<q->val){ //x dono se bada hai
    return lowestCommonAncestor(root->right,p,q); //right subtree me hai dono 
 }
 
 return root; //ek x se bada ek usse chota
}

int main(){
 TreeNode *root = new TreeNode(11);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(13);
  root -> left -> left = new TreeNode(8);
  root -> left -> right = new TreeNode(10);
  root -> right -> left = new TreeNode(12);
  root -> right -> right = new TreeNode(15);

  TreeNode *ans = lowestCommonAncestor(root,root -> left -> right,  root -> right -> left);
  if(ans) cout<<ans->val<<endl;
  else cout<<"no"<<endl;

  return 0;




}