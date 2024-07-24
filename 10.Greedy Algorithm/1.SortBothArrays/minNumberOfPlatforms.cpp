#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(vector<int> &at, vector<int> &dt, int n)
{
    // yaha hmko ek particular train ka at and dt se mtlb nhi h bss pura array se mtlb
    sort(at.begin(), at.end()); // sort at
    sort(dt.begin(), dt.end()); // sort dt

    int cur = 0;
    int mini = 0;

    int i = 0, j = 0;

    while (i < n && j < n)
    {
        // har step me ek hi pointer plus hoga

        // If the next event in sorted order is arrival, increment count of platforms needed.

        if (at[i] <= dt[j])
        { //****-> at[i] == dt [j] toh arrival is the first event
            cur++;
            i++; // i=1 hogya hai yaha pe and j=0 hi hai  -->Train 1 arrived cur =1
        }

        // Else (departure is next event) ->decrement count of platforms needed.
        else
        {
            cur--;
            j++; // dt ka pointer
        }
        mini = max(mini, cur); // har baar maximum needed
    }

    return mini;
}