
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        if (n == 1)
            return arr[0];
        while (left < right) //equal nhi hoga hmesha check krliye kro
        {
            int mid = left + (right - left)/2;
            if (mid % 2 == 1)
                mid--; //kyuki even pe no. and odd pe uska duplicate
            if (arr[mid] != arr[mid + 1])
            {
                right = mid; //left me gadbad hai isliye yaha tak khrab hogya h
            }
            else
            {
                left =  mid + 2; //yaha tak thik hai ye pair chod ke aage check
            }
        }
        return arr[left];
    }
};