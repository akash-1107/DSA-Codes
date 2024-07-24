#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string zigZag(string s, int r) {
        int n = s.length();
        string ans = "";
        int f=2*r-4,l=2;
        if(r == 1) return s;
        for(int i= 0;i<r;i++){
            if(i==0 || i== r-1){
                int j = i;
                while(j<n){
                    ans += s[j];
                    j = j + 2*r-2;
                }
                
            }
            
         else {
             int j = i;
             int k = 0;
                while(j<n){
                    // cout<<f<<endl;
                    ans += s[j];
                    if(k%2==0) j+=f;
                    else j+=l;
                    k++;
                    // cout<<j<<endl;
                }
                k=0;
                f -=2;
                l +=2;
                // cout<<ans<<endl;
         }
        }
    return ans;
    }
};