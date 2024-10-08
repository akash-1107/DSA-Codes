#include <bits/stdc++.h>

using namespace std;
// str: "abcaa"
// Keep "aaa" intact as it is itself palindromic.
// Adding Reverse of the remaining
// characters to the string
//****
// abcacba -->mtlb purana string waisa hi rahega usme bss non palindrome ko ulta krke shi jagah jod diye
int lcs(string s1, string s2) {
    //3.space optimize
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

int longestPalindromeSubsequence(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
}

int minInsertion(string s){
    int n = s.size();
    int k = longestPalindromeSubsequence(s); //common letters
    return n-k;
}

int main() {

  string s= "abcaa";
  cout<<"The Minimum insertions required to make string palindrome: "<<
  minInsertion(s);
}