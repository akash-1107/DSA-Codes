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
//search kro jaha mile ye call krdo (search->left)
TreeNode* findlastRight(TreeNode *root){ //predessor
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}


//search kro jaha mile ye call krdo (search->)right
TreeNode* findlastleft(TreeNode *root){ //successor
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

vector <int> searchBST(TreeNode* root, int val) {
 vector <int> ans;
 while(root != NULL && root->val != val){

  root = (root->val > val) ? root->left : root->right;
 
 }

 TreeNode *pre ,*succ;
 pre = findlastRight(root->left);
 succ = findlastleft(root->right);
 ans.push_back(pre->val);
 ans.push_back(succ->val);
}

int main(){
 TreeNode * root = new TreeNode(11);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(13);
  root -> left -> left = new TreeNode(8);
  root -> left -> right = new TreeNode(10);
  root -> right -> left = new TreeNode(12);
  root -> right -> right = new TreeNode(14);

  vector <int> ans = searchBST(root, 11);
  for (int i = 0; i < ans.size(); i++) {
    
    cout << ans[i]<< " ";
  }
//   TreeNode *cur = findMax(root);
//   cout<<cur->val<<endl;



  return 0;




}
