#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define FAST_IO ios_base::sync_with_stdio(false)
#define newline '\n'

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

ll n, d;

ll inp;

ll pref[MAX_N];
vector<int> bp;

ll sum = 0LL;

int main() {
  indexed_set s;

	cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> inp;
    if (inp == 0) {
			bp.pb(i);
			s.insert(i);
		}
    pref[i] = pref[i - 1] + inp;
    if (pref[i] > d) {
      cout << -1 << newline;
      return 0;
    }
  }

  int counter = 0;

  for (int i = 0; i < bp.size(); ++i) {
    int point = bp[i];
		if(pref[point] + sum > d) {
			cout << -1 << newline;
			return 0;
		}
    if (pref[point] + sum < 0) {
      ++counter;
      if (i < bp.size() - 1) {
        sum += d - (sum - pref[bp[i + 1]] - pref[point]);
      } else {
        sum += d - (sum - pref[point]);
      }
    }
  }
  cout << counter << newline;

  return 0;
}
