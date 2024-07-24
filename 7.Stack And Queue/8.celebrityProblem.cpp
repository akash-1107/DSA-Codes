#include <bits/stdc++.h>
using namespace std;
bool knows(int id1,int id2){
    //already implemented
}

int findCelebrity(int n) {
    // Create a stack and push all ids(indexd of all N people) in it.
    stack<int> ids;
    for(int i = 0; i < n; i++) {
        ids.push(i);
    }

    // Finding celebrity till size>= 2 pop two log
    while(ids.size() > 1) {
        int id1 = ids.top();
        ids.pop();
        int id2 = ids.top();
        ids.pop();
        
        if(knows(id1, id2)) {
            // Because person with id1 can not be celebrity. 
            ids.push(id2); 
        }
        else {
            // Because person with id2 can not be celebrity.
            ids.push(id1); 
        }
    }
    //last element left in stack (candidate of celebrity)
    int celebrity = ids.top();
    bool knowAny = false, knownToAll = true;

    // Verify whether the celebrity knows any other person.
    for(int i = 0; i < n; i++) {
        if(knows(celebrity, i)) {
            knowAny = true;
            break;
        }
    }

    // Verify whether the celebrity is known to all the other person.
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !knows(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
        // If verificatin failed, then it means there is no celebrity at the party.
        celebrity = -1;
    }

    return celebrity;
}

//OPTIMAL APPROACH
