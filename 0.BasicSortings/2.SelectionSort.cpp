#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n)
{
    // selection sort - chota select kro aage bhejo next uske aage se kaam kro
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;  //aage sbse chota ka index
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;  
            }
        }
        swap(arr[mini] , arr[i]);
    }
}
