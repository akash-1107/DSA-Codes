// C++ program for insertion in a single linked
// list at a specified position
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *next;

    // Constructor
    TreeNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void printList(TreeNode *&head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

TreeNode* segregate(TreeNode *head) {
    if(!head || !head->next)
        return head;
    
   TreeNode* zeroHead  = new TreeNode(-1);  //ye node banaye hai na isko change mtlb ek node point
   TreeNode* zeroTail = zeroHead;           //or ye pointer h
    
   TreeNode* oneHead  = new TreeNode(-1);
   TreeNode* oneTail = oneHead;
    
   TreeNode* twoHead  = new TreeNode(-1);
   TreeNode* twoTail = twoHead;
    //vhi node banake usme add krte jaa rhe values ke A/C
    while(head != NULL) {
        if(head->val == 0) {
            zeroTail->next = head;
            zeroTail = zeroTail->next; //tail update krna hoga na bro
        }
        else if(head->val == 1) {
            oneTail->next = head;
            oneTail = oneTail->next;
        }
        else if(head->val == 2) {
            twoTail->next = head;
            twoTail = twoTail->next;
        }
        
        head = head->next;
    }
    
    if(oneHead->next) {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }
    
    twoTail->next = NULL;
    
    return zeroHead->next;
}

// Driver Code
int main()
{
    // Creating the list 3->5->8->10
    TreeNode *head = NULL;
    head = new TreeNode(2);
    head->next = new TreeNode(1);
    head->next->next = new TreeNode(0);
    head->next->next->next = new TreeNode(2);

    int size = 4;

    // before
    //  printList(head);

    // at pos k
    //  int val = 12, pos = 3;
    //  insertPos(head, pos, val);
    //  // printList(head);

    // // front of the linked list
    // val = 1, pos = 1;
    // insertPos(head, pos, val);
    // // printList(head);

    // insertion at end of the linked list
    int pos = 4;
    head = segregate(head);
    printList(head);

    return 0;
}
