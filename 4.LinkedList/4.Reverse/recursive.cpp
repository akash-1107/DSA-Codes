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

//Recursive
ListNode* reverseList(ListNode* head) {
ListNode *twoHead = NULL;
//base condition of recursion
 if(head==NULL || head->next ==NULL) return head;
    
 twoHead = reverseList(head->next); //bacha head node isko iss list ke last me add krdo
  //head next upar wala reversed ka last node hai  
 head->next->next = head;
 head->next = NULL;
 
 return twoHead;
}

void printList(ListNode* &head)
{
	while (head != NULL) {
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
	head->next->next->next = new ListNode(10);

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
	head = reverseList(head);
	printList(head);

	return 0;
}
