#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node * left, * right;
};

struct Node * newNode(int data) {
  struct Node * Node = (struct Node * ) malloc(sizeof(struct Node));
  Node -> data = data;
  Node -> left = NULL;
  Node -> right = NULL;

  return (Node);
}

vector<int> topView(Node *root)
{
 vector <int> ans;
 queue <pair<Node*, int>> q; //node and uska vertical
 //yaha levels maintain krne ka need ni bss while loop chala ke pura traverse krdo
 map <int , int> mp;
 q.push({root , 0});

 while(!q.empty()){
    Node *curNode = q.front().first;
    int curVertical = q.front().second;
    if(mp.find(curVertical) == mp.end()) //map me nhi hai
      mp[curVertical] = curNode->data;

    q.pop();
    if(curNode->left) {
        q.push({curNode->left , curVertical -1});
    }
    if(curNode->right) {
        q.push({curNode->right , curVertical + 1});
    }
 }

 
 for(auto &i : mp){
    ans.push_back(i.second);
 }

return ans;
}




vector <int> bottomView(Node *root) {
 vector <int> ans;
 queue <pair<Node*, int>> q; //node and uska vertical
 //yaha levels maintain krne ka need ni bss while loop chala ke pura traverse krdo
 map <int , int> mp;
 q.push({root , 0});

 while(!q.empty()){
    Node *curNode = q.front().first;
    int curVertical = q.front().second;
    // if(mp.find(curVertical) == mp.end()) 
      mp[curVertical] = curNode->data; //ekdm last tak update krna hai nodes ko

    q.pop();
    if(curNode->left) {
        q.push({curNode->left , curVertical -1});
    }
    if(curNode->right) {
        q.push({curNode->right , curVertical + 1});
    }
 }
 for(auto &i : mp){
    ans.push_back(i.second);
 }

return ans;       

}


int main() {

  struct Node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6); //removing 6 se root same balanced but
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);
  vector < int > arr,brr;
  arr = topView(root);
  brr = bottomView(root);
  for (auto it: arr) {
    cout << it << " ";
  }
  cout<<endl;
  for (auto it: brr) {
    cout << it << " ";
  }

  return 0;
}