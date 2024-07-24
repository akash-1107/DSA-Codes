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
   else { //mtlb thread hai
   //uss node se hm uska inorder predessor tak chale gye hai
   //basically uska left traverse hogya hai ab print
   //phir cur ka right traversal
   prev->right = NULL; //thread break
   ans.push_back(cur->val); //push in in order
   cur = cur->right;

   }
   }
  }
return ans;
}



vector <int> morrisPreorder(TreeNode *root){
  TreeNode * cur = root;
  vector <int> ans;
  while(cur != NULL){
   //case 1
   if(cur->left == NULL){ 
      ans.push_back(cur->val);
      cur = cur->right;
   }
   //case2
   else {
   TreeNode *prev = cur->left;
   
   while(prev->right && prev->right != cur){
    prev = prev->right;  
   }
   
   if(prev->right == NULL){ 
      prev->right = cur; 
      ans.push_back(cur->val);
      cur = cur->left; 
   }
   
   else {
   prev->right = NULL; 
  cur = cur->right;

   }
   }
  }
return ans;




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

    vector <int> ans;
    // ans =  morrisInorder(root);
    ans = morrisInorder(root);

  for (int i = 0; i < ans.size(); i++) {
    
    cout << ans[i]<< " ";
  }
  return 0;




}