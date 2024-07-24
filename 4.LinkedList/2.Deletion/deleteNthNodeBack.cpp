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
 
 ListNode* removeNthFromEnd(ListNode* head, int n) {
        //2 pointer method
        ListNode *dummy = new ListNode(-1); //ye jb modified linked list bhjena hota h hp skta yaha head hi delete ho jaye toh head change ho rha na
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *first = pre, *secnd = pre;
        for(int i = 0; i<n;i++){
           first = first->next; //first ab start se nth node pe h 
           //last se nth delete krne ke liye total n nodes hoga hi kam se kam
           //so no need to worry about null here
        }
        while(first->next != NULL){ //basically first jb end pahuchega (k-n) steps
            first = first->next;
            secnd = secnd->next; //second start se k-n steps next wala last se nth step
            
        }

        secnd->next = secnd->next->next;



    return dummy->next; 


    }