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

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

string s;

int ans = 0;

int main() {
  FAST_IO;

  cin >> s;
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      for (int k = j + 1; k < len; ++k) {
        if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
          ++ans;
        }
      }
    }
  }

  cout << ans << '\n';

	return 0;
}
