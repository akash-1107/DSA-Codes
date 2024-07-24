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

// i ko as reference pass krna hoga kyuki hmko yaha backtrack krte waqt usi i ka 
// jarurat hoga jo uss time tha


//sirf max value dene se kaam chal jayega
TreeNode* build(vector<int>& preorder , int &i , int maxVal){
 if(i==preorder.size() || preorder[i]>maxVal) return NULL;
 TreeNode *root = new TreeNode(preorder[i++]); //isse i ka value bhi badh jata h biro
 root->left = build(preorder,i,root->val);//left subtree ka max value ye node
 root->right = build(preorder,i,maxVal); //iss node ke right subtree me max value purana maxValue is max

return root;//tree ban gya

}



TreeNode* bstFromPreorder(vector<int>& preorder) {
 int i = 0;
 return build(preorder,i,INT_MAX);

}

int main(){
 TreeNode *root = new TreeNode(7);
  root -> left = new TreeNode(3);
  root -> right = new TreeNode(6);
  root -> left -> left = new TreeNode(1);
  root -> left -> right = new TreeNode(2);
  root -> right -> left = new TreeNode(4);
  root -> right -> right = new TreeNode(5);
  
  // TreeNode *ans = bstFromPreorder(preTraversal);
//   if(ans) cout<<ans->val<<endl;
//   else cout<<"no"<<endl;
 

  return 0;




}