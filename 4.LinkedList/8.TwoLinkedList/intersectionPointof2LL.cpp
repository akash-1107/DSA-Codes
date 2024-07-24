
// C++ program for insertion in a single linked
// list at a specified position
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
void printList(ListNode *&head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
        
    return p1;
}


 
// Driver Code
int main()
{
    // Creating the list 3->5->8->10
    ListNode *head = NULL;
    head = new ListNode(10);
    head->next = new ListNode(3);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(9);

    int size = 4;

    // before
    //  printList(head);

    // at pos k
    //  int data = 12, pos = 3;
    //  insertPos(head, pos, data);
    //  // printList(head);

    // // front of the linked list
    // data = 1, pos = 1;
    // insertPos(head, pos, data);
    // // printList(head);

    // insertion at end of the linked list
    int pos = 4;
    // head = sortList(head);
    printList(head);

    return 0;
}
