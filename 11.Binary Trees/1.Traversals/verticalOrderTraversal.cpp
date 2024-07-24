#include <bits/stdc++.h>
using namespace std;
//rattta marlo isko

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
vector < vector <int> > verticalOrder(TreeNode * root){
 vector < vector <int> > ans;
 map<int, map<int,multiset<int>>> nodes;
 // vertical -->[level , {}]
 queue <pair<TreeNode* , pair<int, int>>> todo;
  //{node , x =vertical ,y=level }--> in queue
  //level always increase 0 to last
 todo.push({root,{0,0}}); //initailize

 while(!todo.empty()){
  auto p = todo.front();
  todo.pop();
  TreeNode *node = p.first; //node
  int x = p.second.first , y = p.second.second;
  nodes[x][y].insert(node->val); //map me insert node value
  //left
  if(node->left){
    todo.push({node->left , {x-1 , y+1}});
  }
  //right
  if(node->right){
    todo.push({node->right , {x+1 , y+1}});
  }

 }
 for (auto p: nodes) { //keys of vertical
    vector < int > col;
    for (auto q: p.second) { //map<int , multiset>
      col.insert(col.end(), q.second.begin(), q.second.end());
    }//col ke end me pura multiset of 1 vertical
    ans.push_back(col);
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

  vector < vector <int> > ans;
     ans = verticalOrder(root);
    //  if(root==NULL)
    //  return {};//iske vajah se runtime error aa rha sample test case dekha kro and empty take care
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
    cout << ans[i][j] << " ";
  }
  return 0;




}