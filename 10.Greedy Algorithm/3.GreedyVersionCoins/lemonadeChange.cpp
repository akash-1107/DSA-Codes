#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//3 denomination only = {5,10,20} you need only 5 rs to buy lemonade
    bool lemonadeChange(vector<int>& arr) {
      int n = arr.size();
      int five = 0 , ten = 0 ,cnt=0; 
      for(int i = 0 ; i<n ; i++){
          if(arr[i] == 5) five++;

          else if(arr[i]==10) { //15
              if(five > 0) {
                  five--;//5rs return kiye
                  ten++;
              }
              else {
                  return false;
              }
          }

          else { //20
              if(ten > 0 && five>0) {
                 ten--; //10
                 five--;//5
              }

              else if(five>2){
              five -= 3; // 3 5s coin diye
              }

              else {
                  return false;
              }
          }
      }
    return true;
    }
};