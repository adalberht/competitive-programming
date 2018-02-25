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

int main() {
  int n, m;

  cin >> n >> m;

  string s;

  cin >> s;

  for (int i = 0; i < m; ++i) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    --l; --r;
    for (int j = l; j <= r; ++j) {
      if (s[j] == c1) {
        s[j] = c2;
      }
    }
  }

  cout << s << '\n';

	return 0;
}
