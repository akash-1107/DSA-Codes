#include <bits/stdc++.h>
using namespace std;
//can replace any letter with an UPPERCASE eng letter
//basically kch replce nhi krna hai bss 1 window me max k+1 hi distinct elements ho skta h ❌
//nhi hm k baar hi change kr skte leters ko and yaha 26 letters posssible
//toh basically window size - mpp[max_mpp] ka size mera k yaa k se kam ho taki sbko hm max mpp wla hi bana den 
 int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char,int>mpp;
        int i = 0,j=0;
        int maxCharCount = 0 , ans = 0;
        while(j<n){
            mpp[s[j]-'A']++; 

            if(maxCharCount < mpp[s[j]-'A']){ //check ki yhi character after adding max wala toh nhi
                maxCharCount = mpp[s[j]-'A'];
            }
//unique se mtlb nhi h max se mtlb hai
            while((j-i+1) - maxCharCount > k){ //length me se - max ka mppuency
                mpp[s[i]-'A']--;
                i++;
                for(auto &z : mpp){ //har baar check ki ab max char kon bacha hai
                    maxCharCount = max(maxCharCount , z.second);
                }
            }
            //window fixed dekh lo maximum
            ans = max(ans, j-i+1);

            j++;
        }
        return ans;
    }

