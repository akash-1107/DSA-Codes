#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

/*
    Time Complexity  :   O(N)
    Space Complexity :   O(N)

   	Where 'N' is the number of nodes in the tree.
*/
/*
The main idea is to maintain an array that contains nodes in sorted order. Then traverse the tree again and assign the current node the data in array serial-wise.

 

Maintain an array ‘ARRAYWITHNODES’, which will contain all the nodes.
Do an ‘INORDERTRAVERSAL’ and push the elements in the array, since for a BST inorder traversal gives elements in sorted order, the elements in the array will be sorted by default.
Use a helper function ‘CONVERTTOHEAP’ which has the following parameter :
Address of the current node denoted by ‘ROOT’
‘ARRAYWITHNODES’
‘IDX’ to point to the element we assign to the node.
Then return the ‘ROOT’ of the heap.
Time Complexity
O(N), where ‘N’ is the number of nodes in the given tree.

 

Since we are traversing all the nodes of the tree, therefore O(N).

Space Complexity
O(N), where ‘N’ is the number of nodes in the given tree.

 

Since we are using an array to store all the nodes of the tree, therefore O(N).
*/

void inorder(BinaryTreeNode* root, vector<int> &arrayWithNodes) //recursive inorder
{
	if (root == NULL)
	{
		return;
	}
	inorder(root -> left, arrayWithNodes);
	arrayWithNodes.push_back(root -> data);  //nodes in sorted order

	inorder(root -> right, arrayWithNodes);
}


void convertToHeap(BinaryTreeNode* root, vector<int> &arrayWithNodes, int &idx)
{ //preorder traverse krke increasing order me node bhar dena sara condition satisfy kr rha
	if (root == NULL)
	{
		return;
	}

	root -> data = arrayWithNodes[idx] ; //sbse chota node at top

	idx++;

	convertToHeap(root -> left, arrayWithNodes, idx);

	convertToHeap(root -> right, arrayWithNodes, idx);
}



BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arrayWithNodes;

	inorder(root, arrayWithNodes);
	int idx = 0;

	convertToHeap(root, arrayWithNodes, idx);
	return root;
}