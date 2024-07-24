#include <iostream>
#include <vector>
using namespace std;
//max-heap = node > both child
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

// Function to build a max-heap from an array
void buildMaxHeap(vector<int>& arr) {   //O(N)
    int n = arr.size();

    // Build the heap by starting from the last non-leaf node and heapifying all nodes
    for (int i = n / 2 - 1; i >= 0; i--) //n/2 se leaf chalu
        maxHeapify(arr, n, i);
}

// Function to insert a new element into a max-heap
void insertMaxHeap(vector<int>& arr, int value) {
    arr.push_back(value); // Add the new value to the end of the array (as the last leaf)

    int index = arr.size() - 1; // Get the index of the newly added value
    while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
        // While the current value is larger than its parent (violating max-heap property)
        
        swap(arr[index], arr[(index - 1) / 2]); // Swap the current value with its parent
        index = (index - 1) / 2; // Move to the parent's index
    }
}

// Function to remove the maximum element (root) from a max-heap
void deleteMax(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Heap is empty." << endl;
        return;
    }

    int n = arr.size() ;
    swap(arr[0], arr[n-1]); //swap kro last ko udha do and heapify krdo
    arr.pop_back();

    maxHeapify(arr, arr.size(), 0);
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);

    buildMaxHeap(arr);

    cout << "Max-heap array: ";
    printArray(arr);

    return 0;
}

//min heap

// #include <iostream>
// #include <vector>

// using namespace std;

// // Function to heapify a subtree rooted at index i
// // n is the size of the heap
// void minHeapify(vector<int>& arr, int n, int i) {
//     int smallest = i; // Initialize smallest as root
//     int left = 2 * i + 1; // Left child
//     int right = 2 * i + 2; // Right child

//     // If left child is smaller than root
//     if (left < n && arr[left] < arr[smallest])
//         smallest = left;

//     // If right child is smaller than the smallest so far
//     if (right < n && arr[right] < arr[smallest])
//         smallest = right;

//     // If the smallest is not the root, then swap and heapify the affected subtree
//     if (smallest != i) {
//         swap(arr[i], arr[smallest]);
//         minHeapify(arr, n, smallest);
//     }
// }

// // Function to build a min-heap from an array
// void buildMinHeap(vector<int>& arr) {
//     int n = arr.size();

//     // Build the heap by starting from the last non-leaf node and heapifying all nodes
//     for (int i = n / 2 - 1; i >= 0; i--)
//         minHeapify(arr, n, i);
// }

// // Function to insert a new element into a min-heap
// void insertMinHeap(vector<int>& arr, int value) {
//     arr.push_back(value);

//     int index = arr.size() - 1;
//     while (index > 0 && arr[(index - 1) / 2] > arr[index]) {
//         swap(arr[index], arr[(index - 1) / 2]);
//         index = (index - 1) / 2;
//     }
// }

// // Function to remove the minimum element (root) from a min-heap
// void deleteMin(vector<int>& arr) {
//     if (arr.empty()) {
//         cout << "Heap is empty." << endl;
//         return;
//     }

//     int lastIdx = arr.size() - 1;
//     swap(arr[0], arr[lastIdx]);
//     arr.pop_back();

//     minHeapify(arr, arr.size(), 0);
// }

// // Function to print an array
// void printArray(const vector<int>& arr) {
//     for (int num : arr)
//         cout << num << " ";
//     cout << endl;
// }

// int main() {
//     vector<int> arr = {12, 11, 13, 5, 6, 7};

//     cout << "Original array: ";
//     printArray(arr);

//     buildMinHeap(arr);

//     cout << "Min-heap array: ";
//     printArray(arr);

//     return 0;
// }
