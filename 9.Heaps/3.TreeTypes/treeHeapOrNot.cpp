#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isHeap(struct Node* root) {
        // code here
        if (!root || (!root->left && !root->right)) //single node or empty tree
            return true;
        //rules for complete binary tree
        else if (root->right && !root->left) //sirf right child h node ka mtlb complete nhi h
            return false;

        else if (root->right && root->right->left && !root->left->right)
            return false; //all nodes as left as possible nhi h 


        //max heap property
        if (root->left->data > root->data)
            return false;

        if (root->right && root->right->data > root->data)
            return false;


        return isHeap(root->left) && isHeap(root->right); //recursion
    }

