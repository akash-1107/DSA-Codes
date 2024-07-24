#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low]; //pehla element ko pivot le lete hai
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;//first element >= pivot (usko udhar bhejo)
        }

        while (arr[j] > pivot && j > low) {
            j--; //first element < pivot usko idhar lao
        } 
        if (i < j) swap(arr[i], arr[j]);//dono ko swap
    }
    swap(arr[low], arr[j]);//last me pivot ko swap jb j i ko cross krde ye partition rahega mera
    return j;//jaha pivot ko daale hai vo index
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high); //partition
        qs(arr, low, pIndex - 1); //left ke liye call krdo
        qs(arr, pIndex + 1, high);//right ke liye call krdo
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1); //start ke liye call
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
// Output:
// Before Using quick Sort:
// 4 6 2 5 7 9 1 3
// After Using quick sort:
// 1 2 3 4 5 6 7 9 

// Time Complexity: O(N*logN), where N = size of the array.