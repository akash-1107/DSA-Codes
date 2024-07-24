#include <bits/stdc++.h>
using namespace std;

 int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue <int , vector<int> , greater<int>> pq; 
        //i need min priority queue
        for(int i = 0 ; i<k ;i++){
            pq.push(arr[i]); //queue me start ka k elements push pehle
        }

        for(int i = k ; i <n ; i++){
            int x = pq.top();
            if(arr[i] > x) {
                pq.pop();  //agr uske top(k me se minimum wala) se bada element hai mere pass toh top k large elements me vo ana chhaiye na or isko haata do as size max k hi rakhenge
                pq.push(arr[i]);
            }
        }
    return int(pq.top()); //last me top k hai queue me toh uska sbse chotu is my kth
    }

    // priority queue me insertion is log n  so TC = O(n log k) , sc = O(K) //thoda modify in sorting

// M2 - QuickSelect Algo --> O(n) O(1) me kr deta hai