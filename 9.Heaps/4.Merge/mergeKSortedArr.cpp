#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O((N * K) * log(K))  
    Space Complexity: O(N * K)
    
    Where N is the total number of elements in all the arrays, and K is the number of arrays.
*/

// #include<queue>

// vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
// {
//     vector<int> result; 
  
//     // Create a min heap to store atmost k heap nodes at a time.
//     priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > minHeap; 
  
//     for (int i = 0; i < kArrays.size(); i++)
//     {
//         minHeap.push({ kArrays[i][0], { i, 0 } }); 
//     }
  
//     while (minHeap.empty() == false) 
//     { 
    
//         // Remove the minimum element from the heap.
//         pair<int, pair<int, int> > curr = minHeap.top(); 
//         minHeap.pop(); 
  
//         // i is the array number and j is the index of the removed element in the ith array.
//         int i = curr.second.first; 
//         int j = curr.second.second; 
    
//         // Add the removed element to the output array.
//         result.push_back(curr.first); 
  
//         // If the next element of the extracted element exists, add it to the heap.
//         if (j + 1 < kArrays[i].size())
//         {
//             minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
//         }
//     } 
  
//     // Return the output array.
//     return result; 
// }

//using struct and comparator se kam syntax me kaam hota hai aaj samaj aaya 

#include <queue>
#include <vector>

using namespace std;

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;
    //constructor
    Element(int val, int arrIdx, int elemIdx) : value(val), arrayIndex(arrIdx), elementIndex(elemIdx) {}
};

struct Compare {
    //sort A/Q to array element
    bool operator()(const Element& a, const Element& b) {
        return a.value > b.value; // Min-heap based on element values
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    vector<int> result;
    priority_queue<Element, vector<Element>, Compare> minHeap; //aise comparator pass

    for (int i = 0; i < k; i++) { //har array ka first element push krdo with array number and zero
        if (!kArrays[i].empty()) {
            minHeap.push(Element(kArrays[i][0], i, 0));
        }
    }

    while (!minHeap.empty()) {
        Element curr = minHeap.top();
        minHeap.pop();

        int i = curr.arrayIndex;
        int j = curr.elementIndex;

        result.push_back(curr.value); //sbse min ko push in result arr

        if (j + 1 < kArrays[i].size()) { //jo liye uska next agr exist toh usko daal denge
            minHeap.push(Element(kArrays[i][j + 1], i, j + 1));
        }
    }

    return result;
}

int main() {
    // Example usage
    vector<vector<int>> kArrays = {{1, 3, 5}, {2, 4, 6}, {7, 8, 9}};
    int k = 3;

    vector<int> mergedArray = mergeKSortedArrays(kArrays, k);

    for (int num : mergedArray) {
        cout << num << " ";
    }

    return 0;
}
