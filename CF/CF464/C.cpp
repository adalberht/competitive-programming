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
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

const int MAX_N = 1e5 + 5;

int n;

int arr[MAX_N];

int s, f;

ll prefix_sum[MAX_N];

int main() {
  FAST_IO;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    prefix_sum[i] = prefix_sum[i - 1] + (ll)arr[i];
  }
  cin >> s >> f;

  int rentang = f - s;

  ll maks = 0LL;
  ll ans = s;
  for (int i = 1; i <= n - rentang + 1; ++i) {
    if (prefix_sum[i+rentang-1] - prefix_sum[i-1] > maks) {
      maks = prefix_sum[i + rentang - 1] - prefix_sum[i - 1];
      ll cur = (n - i + s + 1);
	  if (cur > n) cur -= n;
	  ans = cur;
    } else if (prefix_sum[i + rentang - 1] - prefix_sum[i - 1] == maks) {
      maks = prefix_sum[i + rentang - 1] - prefix_sum[i - 1];
      ll cur = (n - i + s + 1);
      if (cur > n) cur -= n;
      ans = min(ans, cur);
    }
  }

	// cout << ans << endl;
  cout << ans << '\n';

  return 0;
}
