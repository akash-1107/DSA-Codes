#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at index i for max-heap
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(vector<int>& arr) {  //O(N logN)
    int n = arr.size();

    // Build a max-heap from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // max element ko last me phekte jaa rhe hai
        maxHeapify(arr, i, 0); // Call maxHeapify on the reduced heap
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "Array after Heap Sort: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
