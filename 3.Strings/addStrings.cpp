#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        string s = "";
        int i = n-1,j=m-1; //piche se add simply
        int carry = 0;
        while(i>=0 || j>=0){
        int a = (i>=0) ? ( num1[i] - '0') : 0; //ternary
        int b = (j>=0) ? ( num2[j] - '0') : 0;
        int sum = a+b+carry;
        int faceValue = sum%10;
        carry = sum/10 ;  //max 2 hi digit ka number 18 generate ho skta
        char x = '0' + faceValue; //facevalue is int and usme '0' add krne se vo character facevalue ho jayega
        s +=x;
        i--,j--;
        }
        //khatam hogya par extra digit aa gya 
        if(carry>0)
        s += '0' + carry;;//new character add

        
        reverse(s.begin(),s.end()); //last se store kr rhe the
    return s;
    }
};