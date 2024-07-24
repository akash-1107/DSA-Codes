#include <bits/stdc++.h>
using namespace std;
// macros
#define lli long long
#define f(i, x) for (int i = 0; i < (int)x; i++)
#define f1(i, x) for (int i = 1; i <= (int)x; i++)
#define rep(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define yes() cout << "YES" << endl
#define no() cout << "NO" << endl
#define all(arr) arr.begin(), arr.end()
#define print(arr)   for (auto &i : arr)  cout << i << " "
//longest increasing sequence

//only length nikalne ke kaam aayega ye replacement type ki vahan kch ho hai possible
int lengthOfLIS(vector<int>& arr) {
 int n = arr.size();
 vector<int> temp;
    temp.push_back(arr[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
           // arr[i] > the last element of temp array 
           
           temp.push_back(arr[i]);
           len++; //isme size increase
           
        } 
        else{
	// replacement step
    //ist element >= arr[i] place jaha shi jagah to insert for remain sorted
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin(); 
            temp[ind] = arr[i]; //no change in size
        }
        
    }
    
    return len;
}




int main() {
	vector<int> arr = {1,5,3,7,1};
	cout<<lengthOfLIS(arr);
	return 0;
}