

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void markParents(Node * root , map <Node* , Node*> &parents){
    queue <Node*> q;
    Node *t = root;
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



int distanceK(Node* root, Node* target, int k) {
  map <Node* , Node*> parents;
  markParents(root , parents); //parents mark hogye
  int level = 0;
  queue <Node*> q;
  q.push(target);
  map<Node* , int> vis; //visted array
  vis[target] = 1;
  while(!q.empty()){
//    if(level++ == k) break; //0->1->2
   int n = q.size();
   for (int i = 0; i < n; i++)
    {  Node *cur = q.front(); //ye visited h already
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
    level++;
  }

//jst 1 last step jisme queue khali hoga so level ekbaar kam plus
return level -1;
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

  int ans = distanceK(root , root  , 2 );
//   for(auto &i : ans){
    cout<<ans<<" ";
//   }
  return 0;
}



