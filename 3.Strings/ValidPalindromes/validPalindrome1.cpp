#include <bits/stdc++.h>
using namespace std;

// Example
// Input: s = "A man, a plan, a canal: Panama" //alphanumeric ke alawa sb hatake check krenge palindrome
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
//isalnum(s[i]) == false --> mtlb a,A,1,2 ke alawa kch h
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if not alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }

    return true;
}
};


