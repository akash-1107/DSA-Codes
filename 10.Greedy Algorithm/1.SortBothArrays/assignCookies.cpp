#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end()); //greed of students ki itta size milega kam se kam tb hi khush
        sort(s.begin() , s.end()); //candy ka size 
        int n = g.size() , m = s.size();
        int i = 0 , j=0 , cnt =0 ;
        while(i<n && j<m){
            if(s[j] >= g[i]) {
                cnt++; //we need min number of candies
                i++;
                j++;
                //ye size chalega so increase both pointers
            }
            else{
                j++; //isse bada size chaiye
            }
        }


    return cnt;
    }
};