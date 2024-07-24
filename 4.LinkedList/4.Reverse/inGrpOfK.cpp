// My take on how dummy->next is pointing to new head.

// Initially dummy and pre are referencing the same address so any change made to pre->next will also be reflected
// in dummy->next but after  reversing the first group pre is  assigned to a complete new address.
// Therefore changes  made to pre later do not affect the dummy->next  as the latters job was over after first reversal itself.

// C++ program for insertion in a single linked
// list at a specified position
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    // Constructor
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


ListNode *reverseKGroup(ListNode *head, int k){ 
    // O(N/k * (k)) har baar k-1 pointer reverse kro
    if (head == NULL || head->next == NULL) return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy, *curr, *nex, *tmp = head;
    int cnt = 0; //careful

    while (tmp)
    { //CountNodes
        tmp = tmp->next;
        cnt++;
    }

    while (cnt >= k)
    {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; i++)
        { // iss pura time me k-1 pointers reverse krnege
            //(-1)->1->2->3->4  (k = 3)
            curr->next = nex->next;
            nex->next = pre->next; 
            // yaha curr nhi prev->next kyuki curr same pura k-1 ke liye
            pre->next = nex; 
            //-1 node ko hm pre leke chal rhe jo niche phir aglr k ke liye change ho jaega
            nex = curr->next;
        }

        pre = curr; // ab prev hmesha next ko point krte jaega in m=next iteration
        cnt -= k;   // phir next ko next kr dena jo ki basically cur->next
    }

    return dummy->next; // top pe likha logic
}


void printList(ListNode *&head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

// Driver Code
int main()
{   
    // Creating the list 3->5->8->10
    ListNode *head = NULL;
    head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(10);

    int size = 4;

    int pos = 4;
    head = reverseKGroup(head, 2);
    printList(head);

    return 0;
}
