#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}


void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  //node me enter krte hue dono left right traversal nhi hua h avi
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }
  
  // pitaji ki baat chalegi
  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }
  //bachon ka sum dominant
  else {
    root->data = child;
  }
 //basic recursive dfs traversal feel

  reorder(root -> left);
  reorder(root -> right);
 
 //node se return krte hue dono left right traversal ho chuka h avi
  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
    //i am making it happen
  reorder(root);
}

void levelOrder(node * root){
    queue <node*> q;
    node *t = root;
    q.push(t);
    while(!q.empty()){
     int n = q.size();
     vector <int> tmp;
    
         t = q.front();
         cout<<(t->data)<<" ";
         if(t->left) q.push(t->left);
         if(t->right) q.push(t->right);
         q.pop();
     
    }
    cout<<endl;
}


int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);

  levelOrder(root);
  changeTree(root);
  levelOrder(root);

  return 0;
}