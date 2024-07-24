#include <bits/stdc++.h>
using namespace std;

int root(int N)

{

    long long int low = 1, high = N, ans = -1;

    while (low <= high)
    {

        long long int mid = (high + low) / 2;

        if (mid * mid == N)

            return mid;

        else if (mid * mid > N)

            high = mid - 1;

        else
        {

            low = mid + 1;

            ans = mid;
        }
    }

    return ans;
}