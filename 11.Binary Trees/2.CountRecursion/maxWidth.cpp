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

//iterative
void levelOrder(TreeNode * root){
    queue <TreeNode*> q;
    TreeNode *t = root;
    q.push(t);
    while(!q.empty()){
     int n = q.size();
     vector <int> tmp;
     for(int i = 0 ; i<n;i++){
        TreeNode *tp = q.front();
         tmp.push_back(tp->val);
         if(tp->left) q.push(tp->left);
         if(tp->right) q.push(tp->right);
         q.pop();
     }
    ans.push_back(tmp);
    }
}
 int maxWidth(TreeNode* root) {
    if (!root) return 0;
  int ans = 0;
  queue < pair < TreeNode * , int >> q; //LEVEL ORDER ME MODIFICATION
  q.push({ root , 0 }); //2i+1 ,2i+2 -->0 based index
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;  //minimum for that level
    int leftMost, rightMost;       //for that level
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      TreeNode * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;


      if (temp -> left)
        q.push({temp -> left, (long long)cur_id * 2 + 1 }); //for surity


      if (temp -> right)
        q.push({temp -> right, (long long)cur_id * 2 + 2});

    }

    ans = max(ans, rightMost - leftMost + 1);

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


     int ans = maxWidth(root);

//   for (int i = 0; i < ans.size(); i++) {
//     for (int j = 0; j < ans[i].size(); j++)
//     cout << ans[i][j] << " ";
//   }


cout<<ans;



}