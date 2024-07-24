// 3 variations of pascal triangle
#include <bits/stdc++.h>
using namespace std;
/*
1
1 2 1
1 3 6 3 1
*/

//1. given row(n) and column(r) number print particular value = n-1Cr-1 -
int nCr(int n, int r) {
    long long res = 1; //long long hmesha aise factorial me krna h

    // calculating nCr this is way so ek loop se ho jayega
    //ncr = n!/r!*(n-r)! = n/1*n-1/2*...*n-(r-1)/r
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    //1 base indexing se row and col mila hai so
    int element = nCr(r - 1, c - 1);  //O(r)
    return element;
}

//2.given row number pura row print kro 5th row 4! wala hota h
/*
1 5/1 5*4/2  ()*3/3
*/

        