

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


 TreeNode* genUnique(vector<int>& preorder , vector<int>& inorder , int preStart , int preEnd
 ,int inStart , int inEnd  ,map<int , int> &m ){

if(inStart > inEnd || preStart > preEnd) return NULL;

TreeNode *root = new TreeNode(preorder[preStart]);

 int indx = m[preorder[preStart]]; //index of root in inorder array
 //this index is helpful to know how many elements left/right
 int nLeft = indx - inStart;      //no.of elements in left subtree
 int nRight =  inEnd - indx;       // no. of elements in right subtree;


root->left = genUnique(preorder , inorder , preStart 
+ 1 , preStart + nLeft ,inStart , indx - 1 , m );

root->right = genUnique(preorder , inorder , preStart + nLeft + 1
, preEnd , indx + 1, inEnd , m );

return root;
 }


 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
 int preStart = 0 , preEnd = preorder.size() - 1;     
 int inStart = 0 , inEnd = inorder.size() - 1; 
 map<int,int> m;
 for (int i = 0; i < inorder.size(); i++)
 {
   m[inorder[i]]  = i;
 }
 
 TreeNode *head = genUnique(preorder , inorder , preStart , preEnd
 ,inStart , inEnd  , m );


return head;
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


  return 0;
}



