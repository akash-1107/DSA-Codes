#include <bits/stdc++.h>
using namespace std;

// Input:
// geeksforgeeks
// forgeeksgeeks
// Output: 
// 1
// Explanation: s1 is geeksforgeeks, s2 is
// forgeeksgeeks. Clearly, s2 is a rotated
// version of s1 as s2 can be obtained by
// left-rotating s1 by 5 units.

// **** (temp.find(str2) == string::npos) mtlb nhi mila str2  temp string me


/* Function checks if passed strings (str1
and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{
	/* Check if sizes of two strings are same */
	if (str1.length() != str2.length())
		return false;

	string temp = str1 + str1;  //method string 1 ko 2 times krdo
	return (temp.find(str2) != string::npos); //check krlo ki string 2 hai ki nhi usme bss
}

/* Driver code */
int main()
{
	string str1 = "AACD", str2 = "ACDA";

	// Function call
	if (areRotations(str1, str2))
		printf("Strings are rotations of each other");
	else
		printf("Strings are not rotations of each other");
	return 0;
}
