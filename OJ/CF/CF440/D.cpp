#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7; 

vector<string> arr;

bool is_frequent_substring(string s) {
  map<char, int> count;
  for (int i = 0; i < s.length(); ++i) {
    ++count[s[i]];
  }
  bool is_all_frequency_the_same = true;
  int last = count[s[0]];
  for (int i = 0; i < 26; ++i) {
    char c = (char)((int)'a' + i);
    if (count.count(c) && count[c] != last) {
      is_all_frequency_the_same = false;
      break;
    }
  }
  return is_all_frequency_the_same;
}

bool is_substring(string s, string sub) {
  return s.find(sub) != -1;
}

int N;

string mix(string T, string P) {
  int n = T.length();
  int m = P.length();
  int i = 0, j = 0;
  while (i < n) {
    if (T[i] != P[j]) {
      j = -1;
    }
    ++i;
    ++j;
  }
  if (j != 0) {
    return T + P.substr(j);
  }
  i = 0; j = 0;
  while (j < m) {
    if (P[j] != T[i]) {
      i = -1;
    }
    ++i;
    ++j;
  }
  if (i != 0) {
    return P + T.substr(i);
  }
  return "-1";
}

string dp(int i, string cur) {
  if (i >= N) return cur;
  if (is_substring(cur, arr[i])) return dp(i+1, cur);
  string temp = mix(cur, arr[i]);
  if (temp == "-1") {
    if (!is_frequent_substring(cur + arr[i])) return "-1";
    string temp2 = dp(i+1, cur + arr[i]);
    string temp3 = dp(i+1, arr[i] + cur);
    if (temp2 == "-1" && temp3 == "-1") return "-1";
    if (temp2 != "-1" && temp3 == "-1") return temp2;
    if (temp2 == "-1" && temp3 != "-1") return temp3;
    if (temp2.length() < temp3.length()) return temp2;
    return temp3;
  }
  return dp(i+1, temp);
}

int main() {
  FAST_IO;
  cin >> N;
  arr.resize(N+5);
  bool is_all_frequent_substring = true;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    is_all_frequent_substring &= is_frequent_substring(arr[i]);
  }
  if (!is_all_frequent_substring) {
    cout << "NO\n";
    return 0;
  }
  string ans = "";
  ans = dp(0, ans);
  if (ans == "-1") cout << "NO\n";
  else cout << ans << '\n';
  return 0;
}
