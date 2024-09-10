#include <bits/stdc++.h>
using namespace std;

// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.

//The largest number that can be represented in Roman numerals is 3,999, or MMMCMXCIX

class Solution {
public:
    // M-1
    // string intToRoman(int num) {
    //     string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    //     string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    //     string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    //     string ths[]={"","M","MM","MMM"};
        
    //     return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    // }
  

    //M-2
     string intToRoman(int num) {
        string roman;
        vector<string> notations = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int pos = 0; num>0; ++pos){ //pointer tb tak move kro jb tak num se chota yaa equal wala na mil jaye
            while(num >= value[pos]){
                roman += notations[pos];
                num -= value[pos];
            }
        }
        return roman;
    }
};