#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween))
        { // agr exact multiple h toh 1 kam krna hoga
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    // Find the maximum distance:
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }
    long double ans = 0;
    // Apply Binary search:
    long double diff = 1e-6;
    while (high - low > diff)
    { // long double ka pattern h ye
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k)
        { // suppose 0.1 liye toh wo maintain krne ke liye bohot station needed jo nhi h toh increase dist
            low = mid;
        }
        else
        {
            ans = high; // mtlb isse bada sbpe ab kaam ho jayega toh value chota kro kyuki hmko high ko ans tak le jana h na
            high = mid;
        }
    }
    return high;
    // OR
    // return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
