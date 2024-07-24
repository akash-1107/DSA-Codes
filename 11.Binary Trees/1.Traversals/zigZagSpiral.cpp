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

//Level order me thoda modification
vector < vector <int> >  zigZag(TreeNode * root){
    vector < vector <int> > ans;
    int flag = 0 ;              //mtlb normal left->right
   queue <TreeNode*> q;
   if(root == NULL) return ans;
    TreeNode *t = root;
    q.push(t);
    while(!q.empty()){
     int n = q.size();
     vector <int> tmp(n,0);
     for(int i = 0 ; i<n;i++){
         t = q.front();
         if(flag == 0) tmp[i] = t->val;
         else  tmp[n-i-1] = t->val;
         if(t->left) q.push(t->left);
         if(t->right) q.push(t->right);
         q.pop();
     }
    ans.push_back(tmp);
    flag = flag^1;
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
 vector < vector <int> > ans = zigZag(root);
    
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
    cout << ans[i][j] << " ";
  }
  return 0;




}