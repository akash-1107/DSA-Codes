#include<bits/stdc++.h>
using namespace std;

 void segregate0and1(int v[], int n) {
        // code here
        int i = 0,j=n-1;
        while(i<j){
            if(v[i]==0) i++;
            else if(v[j]==1) j--;
            else if(v[i]==1 && v[j]==0) swap(v[i],v[j]) ,i++,j--;
            
        }
    }