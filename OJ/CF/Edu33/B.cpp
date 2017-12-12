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

bool is_beautiful(ll divisor) {
  const int MAX_EXP = 17;
  for (int i = 0; i < MAX_EXP; i++) {
    if ((ll)((1 << i)-1) * (ll)(1<<(i-1)) == divisor) return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> divisors;
  int root = trunc(sqrt(n));
  for (int i = 1; i <= root; ++i) {
    if (n % i == 0) {
      divisors.pb(i);
      divisors.pb(n/i);
    }
  }
  sort(divisors.begin(), divisors.end());
  for (int i = divisors.size() - 1; i >= 0; i--) {
    if (is_beautiful((ll)divisors[i])) {
      cout << divisors[i] << '\n';
      break;
    }
  }
	return 0;
}
