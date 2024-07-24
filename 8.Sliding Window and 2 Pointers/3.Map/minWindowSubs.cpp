#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
       if (t.length() > s.length()) {
  return "";
}

if (s == t)
  return s;
unordered_map < char, int > m;

for (auto it: t) {
  m[it]++;
}

int cnt = m.size();
int i = 0;
int j = 0;
int ans = INT_MAX;
int start = -1;
int end = -1;

while (j < s.length()) {
  if (m.find(s[j]) != m.end()) { //present it in map
    m[s[j]]--;
    if (m[s[j]] == 0)
      cnt--;
  }

  if (cnt == 0) {
   //zero hote hi check
    if (j - i + 1 < ans) {
      start = i;
      end = j;
      ans = j - i + 1;
    }

    while (cnt == 0) {   //i badhate jao jb tak cnt > 0 na hi jaye mtlb kisi character ka need na aa jaye
      if (m.find(s[i]) != m.end()) {

        m[s[i]]++;
        if (m[s[i]] > 0)
          cnt++;

      }
      i++;
      //basically har baar i increment krke check kr  rhe jb cnt = 0 hai tbhi par
      if (j - i + 1 < ans && cnt == 0) {
        start = i;
        end = j;
        ans = j - i + 1;
      }
    }
  }

  j++;
}







string sans = "";
if (start == -1 && end == -1) {

  return sans;
}

for (int i = start; i <= end; i++) {

  sans += s[i];
}

return sans;
    }