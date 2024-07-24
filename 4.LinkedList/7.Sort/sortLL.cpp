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

ListNode *findMid(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next; // even ye 2 me se pehle wala return krega
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *a, ListNode *b)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *ptr = dummy;
    while (a != NULL && b != NULL)
    {
        if (a->val < b->val)
        {
            ptr->next = a;
            a = a->next;
        }
        else
        {
            ptr->next = b;
            b = b->next;
        }
        ptr = ptr->next; // brother ye krna hoga na har baar
    }
    if (a != NULL)
    {
        ptr->next = a;
    }
    else
    {
        ptr->next = b;
    }

    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    // bhai recursion ka base case likhega ki nhi
    // bhai code ko ek sample test ke liye dry run krte jaya kro copy me
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *mid = findMid(head), *left, *right;

    ListNode *midnext = mid->next;
    mid->next = NULL;
    left = sortList(head);
    right = sortList(midnext);

    return merge(left, right);
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
    head = sortList(head);
    printList(head);

    return 0;
}
