

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    // Constructor
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
 //left max possible height
 int findHeightLeft(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->left; 
        }
        return hght; 
    }
   //right max possible height  O(logn)
    int findHeightRight(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->right; 
        }
        return hght; 
    }

    int countNodes(node* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        
        return 1 + leftNodes + rightNodes; 
    }


 



