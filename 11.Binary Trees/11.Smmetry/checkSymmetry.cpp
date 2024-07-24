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
 
bool isIdentical(TreeNode * node1, TreeNode * node2) {
  if (node1 == NULL || node2 == NULL)
      return (node1 == node2); //agr ek null toh dono must null


  //any traversal at any step dono barabar hoga hi
  return ((node1 -> val == node2 -> val) && 
  isIdentical(node1 -> left, node2 -> right) &&  //mirror image me bss node1->left equal to node2->right
  isIdentical(node1 -> right, node2 -> left));
}


bool isSymmetric(TreeNode *root){
    if(!root) return true;
    if(!isIdentical(root->left , root->right)) return false;

    return true;
}



int main(){
 TreeNode * root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(2);
  root -> left -> left = new TreeNode(4);
  root -> left -> right = new TreeNode(5);
//   root -> left -> right -> left = new TreeNode(8);
  root -> right -> left = new TreeNode(4);
  root -> right -> right = new TreeNode(5);
//   root -> right -> right -> left = new TreeNode(9);
//   root -> right -> right -> right = new TreeNode(10);

//   vector <int> ans;
  bool ans = isIdentical(root->left , root->right);
    if(ans) cout<<"same"<<endl;
//   for (int i = 0; i < ans.size(); i++) {
    
//     cout << ans[i]<< " ";
//   }
  return 0;




}