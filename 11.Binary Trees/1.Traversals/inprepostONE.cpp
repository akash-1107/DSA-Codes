#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
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

// iterative
void allTraversal(Node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
  stack<pair<Node *, int>> st;

  st.push({root , 1});

  if (root == NULL)  return;

  while (!st.empty())
  {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2
    // push the left side of the tree
    if (it.second == 1)
    {
      pre.push_back(it.first->val);
      it.second++;
      st.push(it); // push  {it.first , 2}

      if (it.first->left != NULL)
      {
        st.push({it.first->left , 1});//1 isme har jagah kyuki new node aa rha toh go in all 3
      }
    }

    // this is a part of in
    // increment 2 to 3
    // push right
    else if (it.second == 2)
    {
      in.push_back(it.first->val);
      it.second++;
      st.push(it); // push {it.first , 3}

      if (it.first->right != NULL)
      {
        st.push({it.first->right , 1});//1 isme har jagah kyuki new node aa rha toh go in all 3
      }
    }
    // don't push it back again
    else
    {
      post.push_back(it.first->val);
    }
  }
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right = new Node(3);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> pre, in, post;
  allTraversal(root, pre, in, post);

  cout << "The preorder Traversal is : ";
  for (auto NodeVal : pre)
  {
    cout << NodeVal << " ";
  }
  cout << endl;
  cout << "The inorder Traversal is : ";
  for (auto NodeVal : in)
  {
    cout << NodeVal << " ";
  }
  cout << endl;
  cout << "The postorder Traversal is : ";
  for (auto NodeVal : post)
  {
    cout << NodeVal << " ";
  }
  cout << endl;

  return 0;
}