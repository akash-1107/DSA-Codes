#include <bits/stdc++.h>
using namespace std;
// Input: N = 3, W = 50, 
// weight[] = {20,10,30} 
// values[] = {100,60,120}           //pair of <weight , value>
// Output: 240.00

// Comparator to sort items A/q to per kg value of weight
bool compare(pair<int, int>& a, pair<int, int>& b)
{
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2; //basically i need bada vala v/w pehle
    //logic (luv wala) jaisa order chahiye waise return krdo simple
}


double maximumValue(vector<pair<int,int>>& items, int n, int w)
{
    // Sort items according to value/weight.
    sort(items.begin(), items.end(), compare);
    double maxValue = 0;

    for (int i = 0; i < n; i++)
    {   //pura lelo
        if (items[i].first <= w) 
        {
            w -= items[i].first; //decrease weight of knapsack
            maxValue += items[i].second; //add pura vo vala ka value
        }

        // Pick a fraction of current item.
        else
        {   //jitta kg utta value add only
            //obviously isko pura lene se knapsack exceed so iska fraction leke sb khatam hogya so break krna hoga
            //(bacha hua knapsack ka pura weight) * (per kg value)

            maxValue += items[i].second * ((double)w/ items[i].first);
            //aisa likhe hai taki dikkat na aaye

            break; 
        }
    }

    return maxValue;
}