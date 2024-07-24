#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
//har baar arr[low] ko array me uske shi index pe laake vo index return krna h iss fxn ka kaam
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high ) {
            i++; //kyuki i++ krne pe runtime error naa aye uske liye condition lagana hota h
        }

        while (arr[j] > pivot && j > low ) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]); //arr[low] set ho gya
    return j; //uska index 
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high){
        int pIndex = partition(arr, low, high); //basically iss index wala element apne shi jagah aa chuka h
        qs(arr, low, pIndex - 1); //iske left pe lagao
        qs(arr, pIndex + 1, high); //iske right pe lagao
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
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

// Reason: At each step, we divide the whole array, for that logN and n steps are taken for the partition() function, so overall time complexity will be N*logN.