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
int totalnodes(TreeNode* root) {
  TreeNode * cur = root;
  int cnt = 0;
  while(cur != NULL){
   //case 1
   if(cur->left == NULL){ //iska left nhi h mtlb add to list ye pre me bhi same
      cnt++;
    //   if(cnt == k) ans = (cur->val);
      
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
   prev->right = NULL; //thread break
   cnt++;
//    if(cnt == k) ans = (cur->val);

   cur = cur->right;

   }
   }
  }
return cnt;        
}


int morrisInorder(TreeNode* root, int k) {
  TreeNode * cur = root;
  int cnt = 0 , ans = -1;
  while(cur != NULL){
   //case 1
   if(cur->left == NULL){ //iska left nhi h mtlb add to list ye pre me bhi same
      cnt++;
      if(cnt == k) ans = (cur->val);
      
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
   prev->right = NULL; //thread break
   cnt++;
   if(cnt == k) ans = (cur->val);

   cur = cur->right;

   }
   }
  }
return ans;        
}

int kthSmallest(TreeNode* root, int k) {
 int ans = morrisInorder(root,k);
 return ans;
}
int kthLargest(TreeNode* root, int k) { //kth largest = n-k+1 th smallest //1 based 1 pe nth aaye
 int n = totalnodes(root);
 int ans = morrisInorder(root,n-k+1);
 return ans;
}




int main(){
 TreeNode * root = new TreeNode(11);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(13);
  root -> left -> left = new TreeNode(8);
  root -> left -> right = new TreeNode(10);
  root -> right -> left = new TreeNode(12);
  root -> right -> right = new TreeNode(14);

cout<<kthLargest(root,1)<<endl; //sbse bada 
cout<<kthSmallest(root,1)<<endl; //sbse chota

//   for (int i = 0; i < ans.size(); i++) {
    
//     cout << ans[i]<< " ";
//   }
  return 0;




}