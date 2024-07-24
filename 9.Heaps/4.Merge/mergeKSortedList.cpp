// Merge K sorted linked lists
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    
    struct compare {  //way to define comparator
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val; 
    }
    };

ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> q;  //apna comparator dene ke liye aise likho waha greater int ke jagah
    for(auto l : lists) { //total k list tha sbka head daal diye ab jiska v minimum head->val vo top 
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    ListNode* result = q.top(); //minimum node
    q.pop();
    if(result->next) q.push(result->next); //minimum vale ke next ka list push
    ListNode* tail = result;//tail me add krte jayenge            
    while(!q.empty()) {  //jb tak pq empty na ho jaye krte raho
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next) q.push(tail->next); //push krte check null each time
    }
    return result;//ye final head hai
}

//T.C. = O(KLog(k))  S.C. = O(k)
 //k baar push in priority queue har baar log k lega

};