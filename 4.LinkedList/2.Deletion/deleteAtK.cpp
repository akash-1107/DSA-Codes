// C++ program for insertion in a single linked
// list at a specified position
#include <bits/stdc++.h>
using namespace std;

class Node{
public: 
   int data;
   Node* next;

//Constructor
Node(int data){
    this->data = data;
    this->next = NULL;
}
};

// function to insert a Node at required position
void deletePos(Node* &head, int pos)
{
 if(pos == 1){
    Node *tmp = head;
    head = head->next;
    //
    tmp->next = NULL;
    delete tmp;
    return;
 }
//middle or at k toh mere ko dono chahiye vo node and usse pehle wala 
Node *cur = head , *prev = NULL;
int cnt = 1;
while(cnt < pos){
    prev = cur;
    cur = cur->next;
    cnt++;
}
prev->next = cur->next;
cur->next = NULL;
delete cur;



}

void printList(Node* &head)
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
	Node* head = NULL;
	head = new Node(3);
	head->next = new Node(5);
	head->next->next = new Node(8);
	head->next->next->next = new Node(10);

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
	deletePos(head, pos);
	printList(head);

	return 0;
}
