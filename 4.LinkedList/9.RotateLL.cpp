#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructor
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
//utility function to rotate list by k times
ListNode* rotateRight(ListNode* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
   ListNode* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link lastListNode to firstListNode
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking lastListNode link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}