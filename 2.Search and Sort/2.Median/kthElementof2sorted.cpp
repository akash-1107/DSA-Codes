#include <bits/stdc++.h>
using namespace std;
//hm ek partition bana rhe and just partition ke left me dono me se maximum wala mera ans h 
#define f(i,n) for(int i = 0;i<n;i++)
//1,2,3,4     5,6,7,8,9,10   k=5
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {  if(n>m) kthElement(arr2,arr1,m,n,k);
//     general case me arr1 se 0 (min) and k (max) elements lenge
       int low = max(0,k-m); //agr arr2 me k se kam elements hai toh k-m array1 se rakhna hi hoga minimum
       int high = min(k,n); //agr array1 me k se kam elements h toh max me sara lelo
       while(low<=high){
       int cnt1 = low + (high - low)/2; //partition ke left me arr1  ke elements
       int cnt2 = k-cnt1; //partition ke left me arr2  ke elements
       int l1 = (cnt1 == 0)? INT_MIN : arr1[cnt1-1]; //to maintsin the condition only
       int l2 = (cnt2 == 0)? INT_MIN : arr2[cnt2-1];
       int r1 = (cnt1 == n)? INT_MAX : arr1[cnt1];
       int r2 = (cnt2 == m)? INT_MAX : arr2[cnt2];
       if(l1<=r2 && l2<=r1) {
        return max(l1,l2);
       }
       else if(l1>r2){ //mtlb array 1 se element kam krna hoga
             high = cnt1-1;
       }
       else {
            low = cnt1 +1;
       }
       }
    return 0;
    }