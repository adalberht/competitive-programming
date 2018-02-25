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

#define newline '\n';
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

int n, m;

ll arr1[100];
ll arr2[100];

int main() {
  FAST_IO;

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> arr1[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> arr2[i];
  }

  ll ans = 2e18 + 1;
  for (int i = 0; i < n; ++i) {
    ll cur = -2e18 - 1;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < m; ++k) {
        cur = max(cur, arr1[j] * arr2[k]);
      }
    }
    ans = min(ans, cur);
  }

  cout << ans << '\n';

  return 0;
}
