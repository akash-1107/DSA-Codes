#include <iostream>
#include <vector>
using namespace std;
// simply given array pe build max heap krdo call

void maxHeapify(vector<int>& arr, int n, int i) {  //o(logn)
    //0-based indexing
    int largest = i; // Initialize largest as root   0
    int left = 2 * i + 1; // Left child of root      1
    int right = 2 * i + 2; // Right child of root    2

    
    if (left < n && arr[left] > arr[largest])
        largest = left; //as node should be largest

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest); //for pura tree
    }
}



vector<int>MinToMaxHeap(int n, vector<int>&arr)
{

    // Build the heap by starting from the last non-leaf node and heapifying all nodes
    for (int i = n/2 -1; i >= 0; i--) //n/2 se leaf chalu
        maxHeapify(arr, n, i);


	return arr;
}