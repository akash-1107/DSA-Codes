#include <bits/stdc++.h>
using namespace std;

// vector < int > ans;
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
//recursive
void preOrderTrav(TreeNode *root , vector <int> &ans){
    if(root != NULL){
     
      preOrderTrav(root->left,ans);
      if(root->left == NULL && root->right == NULL) ans.push_back(root->val);
      preOrderTrav(root->right,ans);

    }
}
//iterative
// void preOrderIter(TreeNode * root){
//     stack <TreeNode*> st;
//     TreeNode *t = root; //t ko root kr diye toh initilize krne ka koi jarurat nhi h
//     while(t != NULL   || !st.empty()){
//     if(t != NULL){
//         ans.push_back(t->val);
//         st.push(t);
//         t = t -> left;
//     }
//     else{
//        t = st.top();
//        st.pop();
//        t = t -> right;
//     }
//     }
// }
// //iterative Inorder
// void inOrderIter(TreeNode * root){
//     stack <TreeNode*> st;
//     TreeNode *t = root; //t ko root kr diye toh initilize krne ka koi jarurat nhi h
//     while(t != NULL   || !st.empty()){
//     if(t != NULL){
//         st.push(t);
//         t = t -> left;
//     }
//     else{
//        t = st.top();
//        ans.push_back(t->val);
//        st.pop();
//        t = t -> right;
//     }
//     }
// }

// //iterative Postorder 
// // m-1 -->2 stack method 
// /* simply root push in st1 and while loop jbtk st1 empty na ho st1.top pop krke st2 me daal do
// and uska left and right TreeNode only push in stack1 ... stack2 me postorder aa gya pop krke print */
// //M2 - 1 stack
// void postOrderIter(TreeNode * root){
//     stack <TreeNode*> st;
//     TreeNode *t = root,*tmp;
//     while(t != NULL   || !st.empty()){
//     if(t != NULL){
//         st.push(t);
//         t = t -> left; //left left
//     }
//     else{
//        tmp = st.top() ->right; //ek baar right
       
//        if(tmp == NULL ){   //agr right null tb print -> only pop iss case me
//           tmp  = st.top();
//           st.pop();
//           ans.push_back(tmp->val);
//           //right skew type ko deal krne ke liye
//           //parent uska
//           while(!st.empty() && tmp == st.top()->right){
//             tmp = st.top();
//             st.pop();
//             ans.push_back(tmp->val);
//           }

//        } 

//        else{
//         t = tmp;
//        }


//     //    ans.push_back(t->val);
       
       
//     }
//     }
// }


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
  preOrderTrav(root,ans);  //prerecursive
//   preOrderIter(root);  //pre itertive
    //  inOrderIter(root);
    //  postOrderIter(root);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;




}