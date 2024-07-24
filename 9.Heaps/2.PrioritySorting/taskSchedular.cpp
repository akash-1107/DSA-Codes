#include <bits/stdc++.h>
using namespace std;

// First count the number of occurrences of each element.

// Let the max frequency seen be M for element E

// We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E

// Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself

// Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.

// Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.

// If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int cnt = 0;
        for(char i : tasks)
        {
            mp[i]++;
            cnt = max(cnt, mp[i]); //max frequency cnt of any character out of all present
        }
        //AAABBBCCD , n=2 , ->cnt = 3
        int ans = (cnt-1)*(n)  + (cnt-1);//2*3
                //emptySpaces jb cnt-1 baar A chala  + A jb cnt-1 baar A chala
        //A--A--


// Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
        for(auto it : mp) if(it.second == cnt) ans++;

        //AB-AB-AB
        //kam wala khi v daal skte

        return max((int)tasks.size(), ans);
    }
