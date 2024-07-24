

#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > ans;
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }

    //basic recursive traversal hai ye very important (feel of dfs)

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
    //dono kvi sath me null nhi hoga

        //result
        if(left == NULL) { //mtlb dono node right subtree me hai and lowest wala mila hua h hmko
            return right;
        }
        else if(right == NULL) { //mtlb dono node left subtree me hai and lowest wala mila hua h hmko
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
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


  TreeNode * cur = lowestCommonAncestor(root ,root -> left -> right -> left ,
    root -> left -> right );
  cout << cur->val;
  return 0;




}



