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

TreeNode* findlastRight(TreeNode *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}


TreeNode* helper(TreeNode *root){
//root element to be deleted h
 if(root->left == NULL) return root->right; //leaf node dealt + 1 leftchild only dealt
 else if(root->right == NULL) return root->left;// 1 right child only dealt
 //non leaf with 2 child
 TreeNode *rightChild , *lastRight; 
 rightChild = root->right;
 lastRight = findlastRight(root->left);//predeccssor
lastRight->right = rightChild;//predeccssor is conneted to root->right
 return root->left; //root->left is head now
}





TreeNode* deleteNode(TreeNode* root, int key) {
if(root == NULL) return NULL;
//agr root hi key to delete ho jaye
if(root->val == key) return helper(root);
 
TreeNode *dummy = root;
 while(root != NULL){
  //root->left krna hoga
  if(root->val > key){ 
   if(root->left != NULL && root->left->val == key){ //root->left hi key tha
      root->left = helper(root->left);
      break;
   }
   else{
    root = root->left;
   }
  }

  else{ 
    //jb bhi hmko node ka value or as a node 
    //insert in queue wagera kch krna hota 
    //toh pehle ensure krna hoga ki vo null na ho
    if(root->right != NULL && root->right->val == key){//root->right krna hoga
      //root->left hi key tha
      root->right = helper(root->right);
      break;
   }
   else{
    root = root->right;
   }
  }
 }
return dummy;
}


int main(){
 TreeNode *root = new TreeNode(11);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(13);
  root -> left -> left = new TreeNode(8);
  root -> left -> right = new TreeNode(10);
  root -> right -> left = new TreeNode(12);
  root -> right -> right = new TreeNode(15);


  root = deleteNode(root , 11);
  cout<<root->val<<endl;
   vector <int> ans = morrisInorder(root);
  for (int i = 0; i < ans.size(); i++) {
    
    cout << ans[i]<< " ";
  }


  return 0;




}