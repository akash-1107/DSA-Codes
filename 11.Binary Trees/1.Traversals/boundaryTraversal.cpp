#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  // Constructor
  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

bool leafs(Node *root){
    if(root->left == NULL && root->right == NULL) return true;

    return false;
}
void addLeft(Node *root, vector <int> &ans) {
  Node * cur = root -> left; //root push krke left wala kr rhe
  while (cur != NULL) {
    if (!leafs(cur)) ans.push_back(cur -> data); //print krke daalna left jana h
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right; //ek baar right
  } 
}

//passing arguments and handle recursion
void addLeaves(Node *root, vector <int> &ans) {
 if(root != NULL){
      addLeaves(root->left,ans);
      if(leafs(root)) ans.push_back(root->data);
      addLeaves(root->right,ans);

    }
}


void addRight(Node *root, vector <int> &ans) {
  Node * cur = root -> right; //root push krke left wala kr rhe
  vector <int> tmp;
  while (cur != NULL) {
    if (!leafs(cur)) tmp.push_back(cur -> data); //print krke daalna left jana h
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left; //ek baar right
  } 
  for (int i = tmp.size()-1; i >= 0; i--)
  {
    ans.push_back(tmp[i]);
  }
  
}





vector <int> boundary(Node *root)
{ 
  vector <int> ans;
 if(!root) return ans;
 if(root && !leafs(root)) ans.push_back(root->data); //1 hi node toh vo root v and leaf bhi 
 addLeft(root , ans );
 addLeaves(root , ans );
 addRight(root , ans );
    



return ans;
}







int main(){
 Node * root = new Node(1);
  root -> left = new Node(2);
  root -> right = new Node(3);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(5);
  root -> left -> right -> left = new Node(8);
  root -> right -> left = new Node(6);
  root -> right -> right = new Node(7);
  root -> right -> right -> left = new Node(9);
  root -> right -> right -> right = new Node(10);

    
    vector <int> ans = boundary(root);
    //  if(root==NULL)
    //  return {};//iske vajah se runtime error aa rha sample test case dekha kro and empty take care
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i]<< " ";
  }
  return 0;




}