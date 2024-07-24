// C++ program for insertion in a single linked
// list at a specified position
#include <bits/stdc++.h>
using namespace std;

class ListNode{
public: 
   int data;
   ListNode* next;

//Constructor
ListNode(int data){
    this->data = data;
    this->next = NULL;
}
};

 bool hasCycle(ListNode *head) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *fast = dummy , *slow = dummy;
    while(fast != NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) return true;
    }
     return false;   
    }
 ListNode* matchPoint(ListNode *head) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *fast = dummy , *slow = dummy;
    while(fast != NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) return slow;
    } 
    }


    ListNode *detectCycle(ListNode *head) {
    if(!hasCycle) return NULL;
    ListNode *match = matchPoint(head);
    ListNode *fast = head , *slow = match,*prev ;
    while(fast != slow){
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }
    
    // prev->next = NULL; //to break
    return slow;
        
    } 

    




void printList(ListNode* &head)
{   ListNode *tmp = head;
	while (tmp!= head->next ) {
		cout << " " << head->data;
		head = head->next;
	}
	cout << endl;
}


// Driver Code
int main()
{
	// Creating the list 3->5->8->10
	ListNode* head = NULL;
	head = new ListNode(3);
	head->next = new ListNode(5);
	head->next->next = new ListNode(8);
	head->next->next->next = head;

	int size = 4;

	//before
	// printList(head);

    //at pos k
	// int data = 12, pos = 3;
	// insertPos(head, pos, data);
	// // printList(head);

	// // front of the linked list
	// data = 1, pos = 1;
	// insertPos(head, pos, data);
	// // printList(head);

	// insertion at end of the linked list
	int pos = 4;
    printList(head);
	// head = detectCycle(head);
    // cout<<head->data<<endl;
	// printList(head);

	return 0;
}
