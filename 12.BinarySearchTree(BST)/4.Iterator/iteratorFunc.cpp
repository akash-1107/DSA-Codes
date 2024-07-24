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

// basically inorder dene wala iterator chahiye and next and hasnext
//Left->Node->right
class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode *root) { //constructor
        pushAll(root); //initially sara left node push krne pe process start krenge
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty(); //agr stack
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top(); //basically iska left traversal ho chuka hai toh inorder me add kro
        myStack.pop();
        pushAll(tmpNode->right); //ek right phit left->left
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) { //pushing all left nodes till not null
        for (; node != NULL; myStack.push(node), node = node->left); //do instructions in increment section
    }
};





int main(){
 TreeNode * root = new TreeNode(11);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(13);
  root -> left -> left = new TreeNode(8);
  root -> left -> right = new TreeNode(10);
  root -> right -> left = new TreeNode(12);
  root -> right -> right = new TreeNode(14);




  return 0;




}

