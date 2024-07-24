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
void insertPos(Node* &head, int pos, int data)
{
 if(pos == 1){
    Node* tmp = new Node(data);
    tmp->next = head;
    head = tmp;
	return;
 }
 Node* tmp = head;
 int cnt = 1;
 //hmko jaha insert krna hai uske pehle wala node pe pahuchna hai
 while(cnt<pos-1){//last me temp = pos-1 hoga tb break
   tmp = tmp->next;
   cnt++;
 }

//insert at k
Node* newNode = new Node(data);
newNode->next = tmp->next;
tmp->next = newNode;
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
	int data = 12, pos = 3;
	insertPos(head, pos, data);
	// printList(head);

	// front of the linked list
	data = 1, pos = 1;
	insertPos(head, pos, data);
	// printList(head);

	// insertion at end of the linked list
	data = 15, pos = 7;
	insertPos(head, pos, data);
	printList(head);

	return 0;
}
