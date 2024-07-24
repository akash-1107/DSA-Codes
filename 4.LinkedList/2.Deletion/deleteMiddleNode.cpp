#include <bits/stdc++.h>
using namespace std;

class ListNode{
public: 
   int data;
   ListNode *next;

//Constructor
ListNode(int data){
    this->data = data;
    this->next = NULL;
}
};

ListNode* findMiddle(ListNode* &head){ 
ListNode *fast = head,*slow = head,*prev = NULL;
while(fast != NULL && fast->next != NULL){  //take example of 3 and 4 ListNodes
    prev = slow;  //i needed previous pointer
    slow = slow->next;
    fast = fast->next->next;
}
return prev;
}

 ListNode* deleteMiddle(ListNode* head) {
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    ListNode *preMid = findMiddle(head) , *mid = preMid->next;
    preMid->next = mid->next;
    mid->next = NULL;
    return head;

}

void printList(ListNode* &head)
{
	while (head != NULL) {
		cout << " " << head->data;
		head = head->next;
	}
	cout << endl;
}




int main()
{
	// Creating the list 3->5->8->10
	ListNode* head = NULL;
	head = new ListNode(3);
	head->next = new ListNode(5);
	head->next->next = new ListNode(8);
	head->next->next->next = new ListNode(10);

	int size = 4;

	
    //at pos k
	// int data = 12, pos = 3;
	// insertPos(head, pos, data);
	// // printList(head);

	
	ListNode *ans = deleteMiddle(head);
    // cout<< ans->data <<endl;
	printList(ans);

	return 0;
}