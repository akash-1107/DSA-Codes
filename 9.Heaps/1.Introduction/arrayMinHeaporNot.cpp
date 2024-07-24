#include <iostream>
#include <vector>
using namespace std;

// Function to check if the given array is a valid min-heap
bool isMinHeap(const vector<int>& arr) {
    int n = arr.size();

    // Loop through each non-leaf node and check the heap property
    for (int i = 0; i <= (n / 2) - 1; i++) { //non - leaf nodes
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Compare the parent with its left child
        if (arr[i] > arr[leftChild])
            return false;

        // Compare the parent with its right child (if it exists)
        if (rightChild < n && arr[i] > arr[rightChild])
            return false;
    }

    return true; // All parent-child relationships satisfy the min-heap property
}

int main() {
    vector<int> minHeap = {2, 3, 4, 5, 10, 15};

    cout << "Array: ";
    for (int num : minHeap)
        cout << num << " ";
    cout << endl;

    if (isMinHeap(minHeap))
        cout << "The given array is a valid min-heap." << endl;
    else
        cout << "The given array is not a valid min-heap." << endl;

    return 0;
}
