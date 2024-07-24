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
vector <int> morrisInorder(TreeNode *root){
  TreeNode * cur = root;
  vector <int> ans;
  while(cur != NULL){
   //case 1
   if(cur->left == NULL){ //iska left nhi h mtlb add to list ye pre me bhi same
      ans.push_back(cur->val);
      cur = cur->right;
   }
   //case2
   else {
   TreeNode *prev = cur->left;
   //inorder predessor
   while(prev->right && prev->right != cur){
    prev = prev->right;  
   }
   //abhi node ka left , right kch traversal nhi hua hai
   if(prev->right == NULL){ //no thread abhi
      prev->right = cur; //make thread
      cur = cur->left;
   }
   else { 
   prev->right = NULL; //thread break
   ans.push_back(cur->val); //push in in order
   cur = cur->right;

   }
   }
  }
return ans;
}


TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
         TreeNode *newroot = root;
         while(root){
         if(root->val > val){
          if(root->left)  root = root->left;
          else {
              root->left = new TreeNode(val);
              return newroot;
          }
         }
         else if(root->val < val) {
            if(root->right)  root = root->right;
          else {
              root->right = new TreeNode(val);
              return newroot;
          } 
   }
  
   }

return newroot;
    }


int main(){
 TreeNode * root = new TreeNode(11);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(13);
  root -> left -> left = new TreeNode(8);
  root -> left -> right = new TreeNode(10);
  root -> right -> left = new TreeNode(12);
  root -> right -> right = new TreeNode(15);


  TreeNode *root = insertIntoBST(root , 14);
  cout<<root->val<<endl;
   vector <int> ans = morrisInorder(root);
  for (int i = 0; i < ans.size(); i++) {
    
    cout << ans[i]<< " ";
  }


  return 0;




}