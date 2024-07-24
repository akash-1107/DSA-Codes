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

ListNode* reverse(ListNode* ptr) {
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL) return true;
        
    ListNode* slow = head;
    ListNode* fast = head , *tmp;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;  //even ye 2 me se pehle wala return krega
        fast = fast->next->next;
    }
    tmp = slow;
    slow->next = reverse(slow->next);
  
    slow = slow->next;
    ListNode* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    tmp->next = reverse(tmp->next);
    return true;
}


void printList(ListNode* &head)
{
	while (head != NULL) {
		cout << head->data<<" ";
		head = head->next;
	}
	cout << endl;
}


int main()
{
	// Creating the list 3->5->8->10
	ListNode* head = NULL;
	head = new ListNode(5);
	head->next = new ListNode(5);
	head->next->next = new ListNode(5);
	head->next->next->next = new ListNode(5);
	// head->next->next->next->next = new ListNode(1);

	int size = 4;

	
    //at pos k
	// int data = 12, pos = 3;
	// insertPos(head, pos, data);
	// // printList(head);

	
	if(isPalindrome(head)) {
        cout<<"yes"<<endl;
        printList(head);}
	else
    cout<<"no"<<endl;
	return 0;
}