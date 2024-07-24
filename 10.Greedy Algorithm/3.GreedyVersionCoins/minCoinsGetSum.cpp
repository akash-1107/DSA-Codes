#include<bits/stdc++.h>
//greedy works here becoz khi ka v prefixSum next element se bada nhi hota h agr hoga toh fail
//min coins lena hai
using namespace std;
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; //old indian economic denominations
  int n = 9; //total 9 denomination
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];  //bohot kam h array size isiliye minus se kaam chal jaa rha
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}