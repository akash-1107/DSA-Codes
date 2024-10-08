// strl: "abcd"
// str2: "anc"
// lcs = ac = 2 
// Minimum Insertions/Deletions to convert strl to str2 :
// Delete 2 characters from strl : bd(n-k)
// Insert 1 character to strl : n(m-k)
// 3 operations = anc 
//**agr replacement ka option hota toh basic se krna hota bcoz need all possibilities
#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<int> prev(m+1,0), cur(m+1,0);
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    
    return prev[m];
}

int canYouMake(string str1, string str2){
    
    int n = str1.size();
    int m = str2.size();
    
    int k = lcs(str1,str2);
    
    return (n-k)+(m-k);
}

int main() {

  string str1= "abcd";
  string str2= "anc";
                                 
  cout<<"The Minimum operations required to convert str1 to str2: "<<
  canYouMake(str1,str2);
}