

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
void markParents(TreeNode * root , map <TreeNode* , TreeNode*> &parents){
    queue <TreeNode*> q;
    TreeNode *t = root;
    q.push(t);
    while(!q.empty()){
     int n = q.size();
     vector <int> tmp;
     for(int i = 0; i<n ;i++){
         t = q.front();
         q.pop();
    if(t->left) {
         q.push(t->left);
         parents[t->left] = t;
                }

    if(t->right){ 
         q.push(t->right);
         parents[t->right] = t;
                } 
     }
    }
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  map <TreeNode* , TreeNode*> parents;
  markParents(root , parents); //parents mark hogye
  int level = 0;
  queue <TreeNode*> q;
  q.push(target);
  map<TreeNode* , int> vis; //visted array
  vis[target] = 1;
  while(!q.empty()){
   if(level++ == k) break; //0->1->2
   int n = q.size();
   for (int i = 0; i < n; i++)
    {  TreeNode *cur = q.front(); //ye visited h already
       q.pop();
    //tino push krenge to check    
       //left  
       if(cur->left && !vis[cur->left]){
        q.push(cur->left);
        vis[cur->left] = 1;
       }
       //right
       if(cur->right &&  !vis[cur->right]){
        q.push(cur->right);
        vis[cur->right] = 1;
       }
      //parent
        if(parents[cur] &&  !vis[parents[cur]]){
        q.push(parents[cur]);
        vis[parents[cur]] = 1;
       }
     }
    // level++;
  }
vector <int> ans;
//ab jo bhi elements bache hai queue
  while(!q.empty()){
  ans.push_back(q.front()->val);
  q.pop();
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

  vector <int> ans = distanceK(root , root  , 2 );
  for(auto &i : ans){
    cout<<i<<" ";
  }
  return 0;
}



