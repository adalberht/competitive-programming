/*
Albertus Angga Raharja (adalberht)
1606918401

Problem B - Strange Integration
Tags: Backus Naus Form, Recursive

Solved together with Daniel Alfred, Reynaldo Widjaja and Dhipta Raditya
*/

#include <bits/stdc++.h>

#define fs first
#define sc second
#define pcc pair<string,string>
#define ppc pair<pcc,char>

using namespace std;

map<string, ppc> bnf;
int n, tt;

bool isNumber(string c) {
  int cs = c.length();
  for(int i = 0; i < cs; i++) {
    if(!('0' <= c[i] && c[i] <= '9')) {
      return false;
    }
  } 
  return true;
}

string stringify(string s, char kiri, char kanan) {
  // printf("-- %c %c --\n", s, kiri);
  string ret = "";
  bool bracket = true;
  if((kiri == ' ' && (kanan == ' ' || !(bnf[s].sc == '+' && kanan == '*'))) 
    || (kiri == '+' && bnf[s].sc == '*')) {
    bracket = false;
  }
  if(bracket) {
    ret += '(';
  }
  if(isNumber(bnf[s].fs.fs)) {
    ret += bnf[s].fs.fs;
  } else {
    if(bracket) {
      ret += stringify(bnf[s].fs.fs, ' ', bnf[s].sc);
    } else {
      ret += stringify(bnf[s].fs.fs, kiri, bnf[s].sc);
    }
  }
  ret += bnf[s].sc;
  if(isNumber(bnf[s].fs.sc)) {
    ret += bnf[s].fs.sc;
  } else {
    if(bracket) {
      ret += stringify(bnf[s].fs.sc, bnf[s].sc, ' ');
    } else {
      ret += stringify(bnf[s].fs.sc, bnf[s].sc, kanan);
    }
  }
  if(bracket) {
    ret += ')';
  }
  return ret;
}

int main() {
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    string s, a, b, trgt, d;
    char simbol;
    string ans;
    scanf("%d", &n);
    bnf.clear();
    for(int i = 1; i <= n; i++) {
      cin >> s >> d >> a >> simbol >> b;
      bnf[s] = {{a, b}, simbol};
      trgt = s;
    }
    ans = stringify(trgt, ' ', ' ');
    cout << "Expression #" << tc << ": " << ans << endl;
  }
  return 0;
}