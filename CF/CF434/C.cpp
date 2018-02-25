#include <bits/stdc++.h>

using namespace std;

bool is_vowell(char c) {
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || c == ' ') return true;
  return false;
}

bool is_typo(string s) {
  int cntConsonant = 0;
  int cntSame = 1;
  for (int i = 0; i < s.length(); i++) {
    if (is_vowell(s[i])) cntConsonant = 0;
    else {
      ++cntConsonant;
      if (i > 0 && s[i] == s[i-1]) ++cntSame;
      else cntSame = 1;
      if (cntSame == 3) {
        cntSame = 2;
        cntConsonant = 2;
        continue;
      }
      if (cntConsonant == 3) {
        return true;
      }
    }
  }
  return false;
}

int first_typo_index(string s) {
  int cntConsonant = 0;
  int cntSame = 1;
  for (int i = 0; i < s.length(); i++) {
    if (is_vowell(s[i])) cntConsonant = 0;
    else {
      ++cntConsonant;
      if (i > 0 && s[i] == s[i-1]) ++cntSame;
      else cntSame = 1;
      if (cntSame == 3) {
        cntSame = 2;
        cntConsonant = 2;
        continue;
      }
      if (cntConsonant == 3) return i-2;
    }
  }
  return -1;
}


int main() {
  string s;
  cin >> s;
  while (is_typo(s)) {
    int first = first_typo_index(s);
    s = s.substr(0, first+2) + " " + s.substr(first+2);
    // cout << s << endl;
  }
  cout << s << endl;
  return 0;
}