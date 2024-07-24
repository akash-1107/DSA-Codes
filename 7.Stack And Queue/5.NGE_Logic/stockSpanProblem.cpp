#include <bits/stdc++.h>
using namespace std;
/*

    Time complexity: O( n * n )
    Space complexity: O( 1 )

    Where 'n' is the size of the array.
    n = 7
    arr =    [100, 80, 60,70,60 , 75 ,85]
    output = [1  , 1 , 1, 2 , 1 , 4 , 6]

*/
/*
    Time comelexity: O( n )
    Space complexity: O( n )

    Where 'n' is the size of the array.
*/

//Coding Ninja version
vector<int> findStockSpans(vector<int>& brr) {
        int m = brr.size();
        //storing pges ka index
        vector <int> prevGreaterElement(m,-1) , ans(m,1);
        unordered_map <int,int> mp;
        stack <int> st;
        for(int i = 0;i<m;i++){ 
            int x = brr[i];  
            //st.top chota hai toh vo useless pop it kyuki kch bada mil gya
            while(!st.empty() && brr[st.top()]<x ) st.pop(); 
            
            if(st.empty()) prevGreaterElement[i] = i+1; //no pge for that element

            else prevGreaterElement[i] =abs(i-st.top());
            //har baar push hoga hi
            st.push(i); 
}

//simply prevGreater Element tak ka elements h sbse bada stock span simply

return prevGreaterElement;
}


//leetcode version
class StockSpanner {
public:
    StockSpanner() {
        
    }
    public:
        stack <pair<int , int>> st;
        int indx = 0;

      
    int next(int price) { //internally ek stream me elements aate jaa rha har ke liye next fxn call
           
            int x = price; 
            int ans = 0; 
            //st.top chota hai toh vo useless pop it kyuki kch bada mil gya
            while(!st.empty() && st.top().first <= x ) st.pop(); 

            if(st.empty()) ans = indx+1; //no pge for that element

            else ans =  abs(indx-st.top().second);
            //har baar push hoga hi

            st.push({price,indx}); 
            indx++;

   return ans;        
}


};

